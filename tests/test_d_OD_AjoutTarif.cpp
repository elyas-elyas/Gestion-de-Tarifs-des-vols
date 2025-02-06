/**
 * @file test_d_OD_AjoutTarif.cpp
 * @brief Fichier de test pour la gestion des règles d'ajout des tarifs dans un itinéraire.
 * 
 * Ce fichier teste l'ajout de tarifs à un itinéraire (`OD`) en appliquant différentes régles.
 * 
 * @details
 * Les tests effectués incluent :
 * - La création d'un itinéraire `OD`.
 * - L'ajout de tarifs en respectant les règles de gestion.
 * - L'affichage des tarifs finaux après application des règles.
 */

#include "../include/OD.hpp"
#include <iostream>

/**
 * @brief Fonction principale du programme de test.
 * 
 * Ce test vérifie le respect des règles métier lors de l'ajout des tarifs :
 * - Un tarif est remplacé s'il appartient à la même classe mais avec un Net plus bas.
 * - En cas d'égalité de Net, le tarif avec la taxe la plus faible est conservé.
 * - Une nouvelle classe de réservation est ajoutée sans remplacement.
 * 
 * @return Retourne 0 si le test est exécuté avec succès.
 */
int main() {
    // Création d'un itinéraire
    OD itineraire("AMS", "BER");

    // Ajout d'un tarif initial pour chaque classe
    itineraire.ajouterTarif(Tarif('E', 500, 50));    // Classe Économie initiale
    itineraire.ajouterTarif(Tarif('B', 1200, 100)); // Classe Business initiale

    // Ajout de tarifs avec application des règles métier
    itineraire.ajouterTarif(Tarif('E', 450, 40));       // Remplace le précédent (Net plus bas)
    itineraire.ajouterTarif(Tarif('E', 450, 60));      // Ignoré (Taxe plus élevée)
    itineraire.ajouterTarif(Tarif('E', 450, 35));     // Remplace le précédent (Taxe plus faible)
    itineraire.ajouterTarif(Tarif('B', 1300, 80));   // Ignoré (Net plus élevé)
    itineraire.ajouterTarif(Tarif('F', 2500, 200)); // Nouvelle classe ajouté 

    // Affichage des tarifs finaux après application des règles
    std::cout << "=== Test OD : Affichage des tarifs après application des règles ===" << std::endl;
    itineraire.afficher();

    return 0;
}
