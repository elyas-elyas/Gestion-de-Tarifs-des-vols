#ifndef GESTIONNAIRECSV_HPP
#define GESTIONNAIRECSV_HPP

#include "FlightNbr.hpp"
#include <vector>
#include <string>

/**
 * @class GestionnaireCSV
 * @brief Classe utilitaire pour la gestion de l'importation et de l'exportation de fichiers CSV.
 */
class GestionnaireCSV {
public:
    /**
     * @brief Lit un fichier CSV contenant des informations sur les vols et tarifs puis crée les objets FlightNbr et OD correspondants.
     * @param nomFichier Nom du fichier CSV à lire.
     * @return Un vecteur de pointeurs vers les objets FlightNbr créés.
     */
    static std::vector<FlightNbr*> lireFichierCSV(const std::string& nomFichier);

    /**
     * @brief Exporte un rapport CSV contenant les informations analytiques.
     * @param vols Liste des vols à inclure dans le rapport.
     * @param nomFichier Nom du fichier CSV à générer.
     */
    static void exporterRapportCSV(const std::vector<FlightNbr*>& vols, const std::string& nomFichier);
};

#endif
