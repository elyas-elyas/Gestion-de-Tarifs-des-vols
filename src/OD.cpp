#include "../include/OD.hpp"
#include <iostream>
#include <stdexcept>
#include <numeric> 

// Constructeur de la classe OD
OD::OD(const std::string& ori, const std::string& dest) 
    : origine(ori), destination(dest) {}

// Affiche les informations de l'itinéraire
void OD::afficher() const {

    std::cout << "Itinéraire : " << origine << " -> " << destination << std::endl;
    
    if (tarifs.empty()) {
        std::cout << "Aucun tarif disponible." << std::endl;
    } 
    
    else {
        for (const auto& tarif : tarifs) {
            tarif.afficher();
        }
    }
}

// Ajoute un tarif à la liste en respectant certaines règles
void OD::ajouterTarif(const Tarif& tarif) {

    for (auto it = tarifs.begin(); it != tarifs.end(); ++it) {
        if (it->classeReservation == tarif.classeReservation) {
            
            // Remplacement si la nouvelle valeur Net est inférieure
            if (tarif.getNet() < it->getNet()) {
                *it = tarif; 
            }

            // Remplacement si les valeurs Net sont égales mais avec une taxe plus faible
            else if (tarif.getNet() == it->getNet() && tarif.getTaxe() < it->getTaxe()) {
                *it = tarif; 
            }

            return; // Fin de la méthode si remplacement effectué
        }
    }

    // Ajout du tarif si aucun remplacement n’a été effectué
    tarifs.push_back(tarif);
}

// Obtention du tarif avec la valeur Net minimale
Tarif OD::obtenirTarifNetMinimum() const {

    if (tarifs.empty()) {
        throw std::runtime_error("Aucun tarif disponible.");
    }

    const Tarif* tarifMin = &tarifs[0]; // Initialise un pointeur vers le premier tarif comme référence de comparaison

    // Parcourt tous les tarifs pour trouver celui avec la plus petite valeur Net
    for (const auto& tarif : tarifs) {
        if (tarif.getNet() < tarifMin->getNet()) {
            tarifMin = &tarif;
        }
    }

    return *tarifMin; 
}

// Obtention du tarif avec la valeur Net maximale
Tarif OD::obtenirTarifNetMaximum() const {

    if (tarifs.empty()) {
        throw std::runtime_error("Aucun tarif disponible.");
    }

    const Tarif* tarifMax = &tarifs[0];

    // Parcourt tous les tarifs pour trouver celui avec la plus grande valeur Net
    for (const auto& tarif : tarifs) {
        if (tarif.getNet() > tarifMax->getNet()) {
            tarifMax = &tarif;
        }
    }

    return *tarifMax;
}

// Calcule de la moyenne des valeurs Net
double OD::calculerMoyenneNet() const {
    
    if (tarifs.empty()) {
        throw std::runtime_error("Aucun tarif disponible.");
    }

    // Somme de toutes les valeurs Net des tarifs
    long somme = std::accumulate(tarifs.begin(), tarifs.end(), 0L,
        [](long acc, const Tarif& tarif) {
            return acc + tarif.getNet();
        });

    // Calcule et retourne de la moyenne
    return static_cast<double>(somme) / tarifs.size();
}