#ifndef FLIGHTNBR_HPP
#define FLIGHTNBR_HPP

#include <string>
#include <vector>
#include "OD.hpp"

/**
 * @class FlightNbr
 * @brief Classe représentant un vol avec un numéro et un itinéraire associé.
 */
class FlightNbr {
public:
    std::string numeroVol; ///< Numéro du vol
    OD* itineraire; ///< Pointeur vers l'itinéraire correspondant au vol

    /**
     * @brief Constructeur de la classe FlightNbr.
     * @param numero Numéro du vol.
     * @param od Pointeur vers l'itinéraire correspondant.
     */
    FlightNbr(const std::string& numero, OD* od);

    /**
     * @brief Affiche les informations du vol et ses tarifs associés.
     */
    void afficher() const;
};

#endif
