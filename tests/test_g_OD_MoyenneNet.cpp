/**
 * @file test_g_OD_MoyenneNet.cpp
 * @brief Fichier de test pour le calcul de la moyenne des valeurs Net dans un itinéraire.
 * 
 * Ce fichier teste l'ajout de plusieurs tarifs à un itinéraire (`OD`) et le calcul de la moyenne des valeurs Net.
 * 
 * @details
 * Les tests effectués incluent :
 * - La création d'un itinéraire `OD`.
 * - L'ajout de plusieurs tarifs dans différentes classes de réservation.
 * - L'affichage des tarifs stockés.
 * - Le calcul et l'affichage de la moyenne des valeurs Net.
 */

#include "../include/OD.hpp"
#include <iostream>
#include <iomanip>

/**
 * @brief Fonction principale du programme de test.
 * 
 * Ce test vérifie la gestion des tarifs dans un itinéraire :
 * - Création d'un objet `OD`.
 * - Ajout de plusieurs tarifs avec différentes classes de réservation.
 * - Affichage des tarifs après ajout.
 * - Calcul et affichage de la moyenne des valeurs Net.
 * 
 * @return Retourne 0 si le test est exécuté avec succès.
 */
int main() {
    try {
        // Création d'un itinéraire
        OD itineraire("AMS", "BER");

        // Ajout de plusieurs tarifs avec différentes classes de réservation
        itineraire.ajouterTarif(Tarif('E', 500, 50));
        itineraire.ajouterTarif(Tarif('B', 1200, 100));
        itineraire.ajouterTarif(Tarif('F', 2500, 200));
        itineraire.ajouterTarif(Tarif('E', 450, 40));    // Nouveau tarif Économie avec Net plus bas
        itineraire.ajouterTarif(Tarif('B', 300, 90));   // Nouveau tarif Business avec Net plus bas

        // Affichage de tous les tarifs associés à l'itinéraire
        std::cout << "=== Test OD : Affichage de la moyenne des valeurs Net ===" << std::endl;
        itineraire.afficher();

        // Calcul et affichage de la moyenne des valeurs Net
        double moyenneNet = itineraire.calculerMoyenneNet();
        std::cout << "=== Moyenne des valeurs Net ===" << std::endl;
        std::cout << "Moyenne : " << std::fixed << std::setprecision(2) << moyenneNet << std::endl;
    } 
    
    catch (const std::exception& e) {
        // Gestion des erreurs en cas d'exception levée par le programme
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0; 
}
