#ifndef OD_HPP
#define OD_HPP

#include <string>
#include <vector>
#include "Tarif.hpp"

/**
 * @class OD
 * @brief Classe représentant un itinéraire Origine-Destination avec des tarifs associés.
 */
class OD {
public:
    std::string origine;      ///< Origine du trajet
    std::string destination;  ///< Destination du trajet

    /**
     * @brief Constructeur de la classe OD.
     * @param ori Origine du trajet.
     * @param dest Destination du trajet.
     */
    OD(const std::string& ori, const std::string& dest);

    /**
     * @brief Affiche la liste des tarifs associés à l'OD pour une meilleur visualisation.
     */
    void afficher() const;

    /**
     * @brief Ajoute un tarif à la liste en respectant certaines règles :
     * - Si un tarif avec la même classe de réservation existe déjà :
     *   - Remplace l’ancien tarif si le nouveau a une valeur Net inférieure.
     *   - Si les valeurs Net sont égales, garde celui avec la taxe la plus faible.
     * - Sinon, ajoute simplement le tarif.
     * 
     * @param tarif Objet Tarif à ajouter.
     */
    void ajouterTarif(const Tarif& tarif);

    /**
     * @brief Retourne le tarif net minimum parmi la liste des tarifs.
     * @throws std::runtime_error Si aucun tarif n'est disponible.
     * @return Tarif ayant la plus petite valeur nette.
     */
    Tarif obtenirTarifNetMinimum() const;

    /**
     * @brief Retourne le tarif net maximum parmi la liste des tarifs.
     * @throws std::runtime_error Si aucun tarif n'est disponible.
     * @return Tarif ayant la plus grande valeur nette.
     */
    Tarif obtenirTarifNetMaximum() const;

    /**
     * @brief Calcule la moyenne des tarifs nets.
     * @throws std::runtime_error Si aucun tarif n'est disponible.
     * @return Moyenne des tarifs nets.
     */
    double calculerMoyenneNet() const;

private:
    std::vector<Tarif> tarifs; ///< Liste des tarifs associés à l'OD.
};

#endif
