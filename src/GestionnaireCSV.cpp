#include "../include/GestionnaireCSV.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <iomanip>

// Lecture du fichier CSV et extraction des informations
std::vector<FlightNbr*> GestionnaireCSV::lireFichierCSV(const std::string& nomFichier) {

    std::vector<FlightNbr*> vols; ///< Liste des vols créés
    std::unordered_map<std::string, OD*> itineraireMap; ///< Associe "Origine-Destination" à un objet OD

    std::ifstream fichier(nomFichier); ///< Ouvre le fichier CSV en lecture

    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << nomFichier << std::endl;
        return vols;
    }

    std::string ligne;
    std::getline(fichier, ligne); // Ignore la première ligne (qui est l'en-tête du CSV)

    while (std::getline(fichier, ligne)) {
        std::stringstream ss(ligne); // Transforme la ligne en flux pour faciliter l'extraction
        std::string numeroVol, origine, destination, classeRes, netStr, taxeStr;
        long net, taxe;

        // Extraction des valeurs
        if (!(std::getline(ss, numeroVol, ',') &&
              std::getline(ss, origine, ',') &&
              std::getline(ss, destination, ',') &&
              std::getline(ss, classeRes, ',') &&
              std::getline(ss, netStr, ',') &&
              std::getline(ss, taxeStr, ','))) {
            std::cerr << "Erreur de lecture de la ligne : " << ligne << std::endl;
            continue;
        }

        // Conversion des valeurs Net et Taxe en long
        try {
            net = std::stol(netStr);
            taxe = std::stol(taxeStr);
        } 
        
        catch (const std::exception& e) {
            std::cerr << "Erreur de conversion Net/Taxe : " << e.what() << " sur la ligne : " << ligne << std::endl;
            continue;
        }

        // Création de la clé unique pour identifier l'itinéraire pour permettre de réutiliser les itinéraires existants plutôt que d’en recréer à chaque vol
        std::string cleItineraire = origine + "-" + destination;

        // Vérifie si l'itinéraire existe déjà, sinon on le crée
        OD* itineraire;
        if (itineraireMap.find(cleItineraire) == itineraireMap.end()) {
            itineraire = new OD(origine, destination);
            itineraireMap[cleItineraire] = itineraire;
        } 
        
        else {
            itineraire = itineraireMap[cleItineraire];
        }

        // Ajoute le tarif à l'itinéraire
        itineraire->ajouterTarif(Tarif(classeRes[0], net, taxe));

        // Vérifie si le vol existe déjà pour éviter les doublons
        bool volExistant = false;
        for (FlightNbr* vol : vols) {
            if (vol->numeroVol == numeroVol) {
                volExistant = true;
                break;
            }
        }

        // Si le vol n'existe pas encore, l'ajoute à la liste
        if (!volExistant) {
            vols.push_back(new FlightNbr(numeroVol, itineraire));
        }
    }

    fichier.close();
    return vols;
}

// Exporte dans un rapport CSV les statistiques analytiques des vols
void GestionnaireCSV::exporterRapportCSV(const std::vector<FlightNbr*>& vols, const std::string& nomFichier) {

    std::ofstream fichier(nomFichier); ///< Ouvre le fichier CSV en écriture
    
    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible de créer le fichier " << nomFichier << std::endl;
        return;
    }

    // Écriture de l'en-tête du fichier CSV
    fichier << "Numéro de vol,Origine,Destination,Classe Min,Net Min,Taxe Min,"
               "Classe Max,Net Max,Taxe Max,Moyenne Net\n";

    // Parcours des vols et écriture des valeurs dans le fichier
    for (const auto& vol : vols) {
        if (!vol->itineraire) continue;

        try {
            Tarif tarifMin = vol->itineraire->obtenirTarifNetMinimum();
            Tarif tarifMax = vol->itineraire->obtenirTarifNetMaximum();
            double moyenneNet = vol->itineraire->calculerMoyenneNet();

            fichier << vol->numeroVol << ","
                    << vol->itineraire->origine << ","
                    << vol->itineraire->destination << ","
                    << tarifMin.classeReservation << ","
                    << tarifMin.getNet() << ","
                    << tarifMin.getTaxe() << ","
                    << tarifMax.classeReservation << ","
                    << tarifMax.getNet() << ","
                    << tarifMax.getTaxe() << ","
                    << std::fixed << std::setprecision(2) << moyenneNet
                    << "\n";
        } 
        
        catch (const std::exception& e) {
            std::cerr << "Erreur lors du traitement du vol " << vol->numeroVol << " : " << e.what() << std::endl;
        }
    }

    fichier.close();
    std::cout << "Rapport genere : " << nomFichier << std::endl;
}
