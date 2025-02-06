/**
 * @file test_i_FlightNbr_csv.cpp
 * @brief Fichier de test pour la lecture des vols depuis un fichier CSV.
 * 
 * Ce fichier teste la lecture d'un fichier CSV.
 * 
 * @details
 * Les tests effectués incluent :
 * - La lecture d'un fichier CSV (`sample.csv`).
 * - Affichage d'un message de confirmation si les informations ont bien été chargées.
 * - La libération de la mémoire allouée dynamiquement après utilisation.
 */

#include "../include/GestionnaireCSV.hpp"
#include <iostream>

/**
 * @brief Fonction principale du programme de test.
 * 
 * Ce test vérifie l'extraction d'informations depuis un fichier CSV :
 * - Lecture d'un fichier `sample.csv` et extraction des données.
 * - Affichage d'un message confirmant le bon chargement des informations.
 * - Libération de la mémoire après usage.
 * 
 * @return Retourne 0 si le test est exécuté avec succès.
 */
int main() {
    // Lecture du fichier CSV et création des objets FlightNbr
    std::cout << "=== Test GestionnaireCSV : Lecture du fichier CSV ===" << std::endl;
    std::vector<FlightNbr*> vols = GestionnaireCSV::lireFichierCSV("data/sample.csv");

    // Vérification et message de confirmation
    if (vols.empty()) {
        std::cerr << "Erreur : Aucun vol n'a été chargé depuis le fichier CSV." << std::endl;
        return 1;
    } 
    
    else {
        std::cout << "Les vols ont été chargés avec succès." << std::endl;
    }

    // Libération de la mémoire allouée dynamiquement
    std::cout << "=== Libération de la mémoire ===" << std::endl;
    for (auto& vol : vols) {
        delete vol->itineraire;
        delete vol;
    }

    return 0;
}
