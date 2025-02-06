/**
 * @file test_e_OD_TarifMin.cpp
 * @brief Fichier de test pour la récupération du tarif Net minimum dans un itinéraire.
 * 
 * Ce fichier teste l'ajout de plusieurs tarifs à un itinéraire (`OD`) et la récupération du tarif avec la valeur Net minimale.
 * 
 * @details
 * Les tests effectués incluent :
 * - La création d'un itinéraire `OD`.
 * - L'ajout de plusieurs tarifs dans différentes classes de réservation.
 * - L'affichage des tarifs stockés.
 * - La récupération et l'affichage du tarif avec la valeur Net minimale.
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
 * - Recherche et affichage du tarif avec la plus faible valeur Net.
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
        std::cout << "=== Test OD : Affichage du Net Min ===" << std::endl;
        itineraire.afficher();

        // Récupération et affichage du tarif Net minimum
        Tarif tarifMin = itineraire.obtenirTarifNetMinimum();
        std::cout << "=== Tarif avec Net minimum ===" << std::endl;
        tarifMin.afficher();
    } 
    
    catch (const std::exception& e) {
        // Gestion des erreurs en cas d'exception levée par le programme
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0; 
}
