/**
 * @file test_h_FlightNbr.cpp
 * @brief Fichier de test pour la classe FlightNbr.
 * 
 * Ce fichier teste la création d'un vol (`FlightNbr`) associé à un itinéraire (`OD`).
 * 
 * @details
 * Les tests effectués incluent :
 * - La création d'un itinéraire `OD`.
 * - L'ajout de tarifs pour différentes classes de réservation.
 * - La création d'un vol `FlightNbr` associé à cet itinéraire.
 * - L'affichage des informations du vol.
 * - La libération de la mémoire allouée dynamiquement.
 */

#include "../include/FlightNbr.hpp"
#include <iostream>

/**
 * @brief Fonction principale du programme de test.
 * 
 * Ce test vérifie la gestion des vols et des itinéraires :
 * - Création d'un itinéraire.
 * - Ajout de tarifs à cet itinéraire.
 * - Création d'un vol `FlightNbr` associé à cet itinéraire.
 * - Affichage des informations du vol.
 * - Nettoyage de la mémoire après usage.
 * 
 * @return Retourne 0 si le test est exécuté avec succès.
 */
int main() {
    // Création d'un itinéraire
    OD* itineraire = new OD("AMS", "BER");

    // Ajout de plusieurs tarifs à l'itinéraire
    itineraire->ajouterTarif(Tarif('E', 500, 50));
    itineraire->ajouterTarif(Tarif('B', 1200, 100));

    // Création d'un vol associé à l'itinéraire
    FlightNbr vol1("KL1771", itineraire);

    // Affichage des informations du vol (numéro + tarifs associés)
    std::cout << "=== Test FlightNbr : Affichage des informations du vol ===" << std::endl;
    vol1.afficher();

    // Nettoyage mémoire : suppression de l'itinéraire alloué dynamiquement
    delete itineraire;

    return 0;
}
