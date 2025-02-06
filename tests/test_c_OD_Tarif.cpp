/**
 * @file test_c_OD_Tarif.cpp
 * @brief Fichier de test pour l'ajout de tarifs à un itinéraire.
 * 
 * Ce fichier teste l'ajout de plusieurs tarifs à un itinéraire (`OD`).
 * 
 * @details
 * Les tests effectués incluent :
 * - La création d'un itinéraire `OD`.
 * - L'ajout de plusieurs tarifs pour différentes classes de réservation.
 * - L'affichage des tarifs ajoutés.
 */

#include "../include/OD.hpp"
#include <iostream>

/**
 * @brief Fonction principale du programme de test.
 * 
 * Ce test vérifie la gestion des tarifs dans un itinéraire :
 * - Création d'un objet `OD`.
 * - Ajout de plusieurs tarifs avec différentes classes de réservation.
 * - Affichage des tarifs après ajout.
 * 
 * @return Retourne 0 si le test est exécuté avec succès.
 */
int main() {
    // Création d'un itinéraire
    OD itineraire("AMS", "BER");

    // Ajout de plusieurs tarifs avec différentes classes de réservation
    itineraire.ajouterTarif(Tarif('E', 500, 50));     // Classe Économie
    itineraire.ajouterTarif(Tarif('B', 1200, 100));  // Classe Business
    itineraire.ajouterTarif(Tarif('F', 2500, 200)); // Classe Première classe

    // Affichage de tous les tarifs associés à l'itinéraire
    std::cout << "=== Test OD : Affichage des tarifs ajoutés ===" << std::endl;
    itineraire.afficher();

    return 0; 
}
