#include "../include/GestionnaireCSV.hpp"
#include <iostream>

/**
 * @brief Main du projet.
 * 
 * Ce programme lit un fichier CSV contenant des informations sur les vols et les tarifs et génère un rapport en sortie.
 * 
 * @return Retourne 0 si l'exécution est réussie.
 */
int main() {
    /**
     * @brief Lecture du fichier CSV et création des objets FlightNbr.
     * 
     * Lecture du fichier `sample.csv`. Modifier le chemin pour tester avec d'autres fichiers 
     */
    std::vector<FlightNbr*> vols = GestionnaireCSV::lireFichierCSV("data/sample.csv");

    /**
     * @brief Exportation du rapport d'analyse au format CSV.
     * 
     * Génère un fichier `rapport_analyse.csv` qui contient :
     * - Numéro de vol 
     * - Origine 
     * - Destination 
     * - ClasseReservation associée à l’objet Tarif avec la valeur Net minimum 
     * - Net minimum 
     * - Taxe associée à l’objet Tarif avec la valeur Net minimum 
     * - ClasseReservation associée à l’objet Tarif avec la valeur Net maximum 
     * - Net maximum 
     * - Taxe associée à l’objet Tarif avec la valeur Net maximum 
     * - Moyenne des valeurs Net (arrondi à 2 décimales) 
     */
    GestionnaireCSV::exporterRapportCSV(vols, "data/rapport_analyse.csv");

    /**
     * @brief Libération de la mémoire allouée dynamiquement.
     * 
     * Pour éviter les fuites mémoire, on libère :
     * - Les objets `OD* itineraire` car ils ont été créés dynamiquement dans `lireFichierCSV`
     * - Les objets `FlightNbr*` stockés dans le vecteur `vols`
     */
    for (auto& vol : vols) {
        delete vol->itineraire;
        delete vol;
    }

    /**
     * @brief Indication de succès.
     * 
     * Un message est affiché pour informer que le rapport a été généré avec succès.
     */
    std::cout << "Le fichier rapport_analyse.csv a ete genere avec succes !" << std::endl;

    return 0;
}
