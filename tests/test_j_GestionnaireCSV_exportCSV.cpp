/**
 * @file test_j_ExporterRapportCSV.cpp
 * @brief Fichier de test pour l'écriture dans un fichier CSV.
 *
 * Ce test valide la génération correcte du rapport CSV.
 */

#include "../include/GestionnaireCSV.hpp"
#include <iostream>
#include <vector>

/**
 * @brief Fonction principale du programme de test.
 *
 * Ce test :
 * - Crée des objets FlightNbr associés à des itinéraires avec plusieurs tarifs.
 * - Appelle la fonction exporterRapportCSV pour générer un fichier.
 * - Vérifie qu'aucune erreur ne se produit et affiche un message de confirmation.
 *
 * @return Retourne 0 si le test est exécuté avec succès.
 */
int main() {
    std::cout << "=== Test GestionnaireCSV : Export dans un fichier CSV ===" << std::endl;

    // Création des itinéraires
    OD* itineraire1 = new OD("AMS", "BER");
    OD* itineraire2 = new OD("CDG", "BER");

    // Ajout des tarifs aux itinéraires
    itineraire1->ajouterTarif(Tarif('E', 450, 50));
    itineraire1->ajouterTarif(Tarif('B', 1200, 100));
    itineraire2->ajouterTarif(Tarif('E', 500, 60));
    itineraire2->ajouterTarif(Tarif('F', 3000, 200));

    // Création des vols associés
    FlightNbr* vol1 = new FlightNbr("KL1771", itineraire1);
    FlightNbr* vol2 = new FlightNbr("AF1014", itineraire2);

    // Stockage des vols dans un vecteur
    std::vector<FlightNbr*> vols = { vol1, vol2 };

    // Test de l'exportation
    try {
        GestionnaireCSV::exporterRapportCSV(vols, "./tests/results/test_export.csv");
        std::cout << "Test réussi : le fichier a été généré avec succès !" << std::endl;
    } 
    
    catch (const std::exception& e) {
        std::cerr << "Erreur : Exception levée lors de l'exportation - " << e.what() << std::endl;
        return 1;
    }

    // Nettoyage de la mémoire
    delete itineraire1;
    delete itineraire2;
    delete vol1;
    delete vol2;

    return 0;
}