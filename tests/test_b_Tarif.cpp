/**
 * @file test_b_Tarif.cpp
 * @brief Fichier de test pour la classe Tarif.
 * 
 * Ce fichier teste la création d'un objet de la classe `Tarif`.
 * 
 * @details
 * Les tests effectués incluent :
 * - La création d'un objet `Tarif`
 * - L'affichage des valeurs
 */

#include "../include/Tarif.hpp"
#include <iostream>

/**
 * @brief Fonction principale du programme de test.
 * 
 * Cette fonction crée un objet `Tarif` et affiche ses valeurs.
 * 
 * @return Retourne 0 si le test est exécuté avec succès.
 */
int main() {
    // Création d'un objet Tarif
    Tarif tarif('E', 500, 50);

    // Affichage des valeurs initiales du tarif
    std::cout << "=== Test Tarif : Affichage des informations ===" << std::endl;
    tarif.afficher();

    return 0; 
}
