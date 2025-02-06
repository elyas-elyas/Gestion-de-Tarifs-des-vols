#include "../include/FlightNbr.hpp"
#include <iostream>

// Constructeur de la classe FlightNbr.
FlightNbr::FlightNbr(const std::string& numero, OD* od)
    : numeroVol(numero), itineraire(od) {}

// Affiche les informations du vol et ses tarifs.
void FlightNbr::afficher() const {

    std::cout << "Numero de vol : " << numeroVol << std::endl;
    
    // Vérifie si un itinéraire est associé au vol
    if (itineraire) {
        itineraire->afficher(); // Affiche les tarifs de l'itinéraire
    } 
    
    else {
        std::cout << "Aucun itineraire associé." << std::endl;
    }
}