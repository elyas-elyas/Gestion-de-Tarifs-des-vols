/**
 * @file test_a_OD.cpp
 * @brief Fichier de test pour la classe OD.
 * 
 * Ce fichier teste la création d'un objet de la classe `OD`.
 * 
 * @details
 * Les tests effectués incluent :
 * - La création d'un itinéraire avec une origine et une destination.
 * - L'affichage des informations de l'itinéraire via la méthode `afficher()`.
 */

#include "../include/OD.hpp"
#include <iostream>

/**
 * @brief Fonction principale du programme de test.
 * 
 * Ce test crée un objet `OD` représentant un itinéraire entre deux villes, puis affiche ses informations.
 * 
 * @return Retourne 0 si le test est exécuté avec succès.
 */
int main() {
    // Création d'un objet O&D représentant un itinéraire Amsterdam -> Berlin
    OD itineraire("AMS", "BER");

    // Affichage des informations de l'itinéraire
    std::cout << "=== Test OD : Affichage de l'itinéraire ===" << std::endl;
    itineraire.afficher();

    return 0; 
}
