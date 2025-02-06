#ifndef TARIF_HPP
#define TARIF_HPP

/**
 * @class Tarif
 * @brief Classe représentant un tarif associé à une classe de réservation.
 */
class Tarif {
public:
    char classeReservation; ///< Classe de réservation 

    /**
     * @brief Constructeur de la classe Tarif.
     * @param classe Caractère représentant la classe de réservation.
     * @param net Valeur Net du tarif.
     * @param taxe Montant de la taxe associée.
     */
    Tarif(char classe, long net, long taxe);

    /**
     * @brief Accesseur pour obtenir la valeur Net du tarif.
     * @return Valeur Net du tarif.
     */
    long getNet() const;

    /**
     * @brief Accesseur pour obtenir la taxe du tarif.
     * @return Valeur de la taxe.
     */
    long getTaxe() const;

    /**
     * @brief Affiche les informations du tarif (classe, Net, Taxe).
     */
    void afficher() const;

private:
    long net;  ///< Tarif Net 
    long taxe; ///< Montant de la taxe appliquée
};

#endif
