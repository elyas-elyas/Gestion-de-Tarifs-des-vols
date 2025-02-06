/**
 * @file test_f_OD_TarifMax.cpp
 * @brief Fichier de test pour la récupération du tarif Net maximum dans un itinéraire.
 * 
 * Ce fichier teste l'ajout de plusieurs tarifs à un itinéraire (`OD`) et la récupération du tarif avec la valeur Net maximale.
 * 
 * @details
 * Les tests effectués incluent :
 * - La création d'un itinéraire `OD`.
 * - L'ajout de plusieurs tarifs dans différentes classes de réservation.
 * - L'affichage des tarifs stockés.
 * - La récupération et l'affichage du tarif avec la valeur Net maximale.
 */

#include "../include/OD.hpp"
#include <iostream>

/**
 * @brief Fonction principale du programme de test.
 * 
 * Ce test vérifie la gestion des tarifs dans un itinéraire :
 * - Création d'un objet `OD`.
 * - Ajout de plusieurs tarifs.
 * - Affichage des tarifs après ajout.
 * - Recherche et affichage du tarif avec la plus grande valeur Net.
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
        std::cout << "=== Test OD : Affichage du Net Max ===" << std::endl;
        itineraire.afficher();

        // Récupération et affichage du tarif Net maximum
        Tarif tarifMax = itineraire.obtenirTarifNetMaximum();
        std::cout << "=== Tarif avec Net maximum ===" << std::endl;
        tarifMax.afficher();
    } 
    
    catch (const std::exception& e) {
        // Gestion des erreurs en cas d'exception levée par le programme
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}
