# Projet de Gestion de Tarifs des vols

![C++](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Doxygen](https://img.shields.io/badge/Documentation-Doxygen-green)

## Introduction

Ce projet a été développé dans le cadre de gestion de tarifs aériens. Il vise à concevoir un système permettant de :  

- Gérer les tarifs en fonction des classes de réservation et des composantes tarifaires.
- Lire des fichiers CSV contenant des données de vol et de tarification.
- Analyser et exporter des rapports optimisés pour des analyses stratégiques.

## Objectifs

- [x] Modélisation des itinéraires (O&D)
- [x] Gestion des tarifs associés aux itinéraires  
- [x] Association des tarifs aux itinéraires 
- [x] Gestion et analyse des tarifs
- [x] Modélisation des vols
- [x] Lecture des données des vols et des tarifs
- [x] Génération d'un rapport d'analyse

## Prise en main

Pour faciliter l'utilisation et la compilation du projet, plusieurs scripts batch (`.bat`) sont fournis :

### Scripts de compilation et nettoyage

- **`build_and_doc.bat`** : Compile le projet et génère la documentation (nécessite Doxygen).
- **`clean_build_and_doc.bat`** : Supprime les fichiers de compilation et la documentation générée.
- **`build_without_doc.bat`** : Compile le projet sans générer de documentation.
- **`clean_only_build.bat`** : Supprime uniquement les fichiers de compilation sans toucher à la documentation.

## Fichier d'entrée

Le projet utilise un fichier CSV en entrée pour lire les données de vol et de tarification.  

- **Fichier par défaut** : [`data/sample.csv`](./data/)
- **Structure du fichier CSV** : Assurez-vous que votre fichier contient les colonnes suivantes :
  - **Numéro de vol**  
  - **Origine**  
  - **Destination**  
  - **Classe de réservation**  
  - **Net**  
  - **Taxe**  

Si vous souhaitez utiliser un autre fichier CSV, modifiez le chemin du fichier dans le `main` en remplaçant `"data/sample.csv"` (ligne 19) par le chemin de votre propre fichier.


## Résultats

Une fois l'exécution du programme terminée, plusieurs fichiers sont générés :

- **Rapport d'analyse** : Le programme génère un fichier CSV contenant les résultats de l'analyse à partir de `sample.csv`.
  - [rapport_analyse.csv](./data/)

- **Résultats des tests** :  
  - [test_results.txt](./tests/results/) – Résultat des tests effectués.  
  - [test_export.csv](./tests/results/) – Résultat du dernier test (test j).

- **Documentation** : La documentation générée par Doxygen est disponible en HTML.
  - [documentation](./doc/) - Pour y acceder lancer le fichier `Documentation.html`
  Il est possible de générer d'autres formats en modifiant les options dans le fichier `Doxyfile`.


**Arborescence du projet final** :

```
Projet/
├── bin/
├── data/
│   ├── rapport_analyse.csv
│   ├── sample.csv
├── doc/
│   ├── html/
│   ├── Documentation.html
├── include/
│   ├── FlightNbr.hpp
│   ├── GestionnaireCSV.hpp
│   ├── OD.hpp
│   ├── Tarif.hpp
├── obj/
├── src/
│   ├── FlightNbr.cpp
│   ├── GestionnaireCSV.cpp
│   ├── OD.cpp
│   ├── Tarif.cpp
├── tests/
│   ├── test_a_OD.cpp
│   ├── test_b_Tarif.cpp
│   ├── test_c_OD_Tarif.cpp
│   ├── test_d_OD_AjoutTarif.cpp
│   ├── test_e_OD_TarifMin.cpp
│   ├── test_f_OD_TarifMax.cpp
│   ├── test_g_OD_MoyenneNet.cpp
│   ├── test_h_FlightNbr.cpp
│   ├── test_i_GestionnaireCSV_lireCSV.cpp
│   ├── test_j_GestionnaireCSV_exportCSV.cpp
│   ├── results/
│   │   ├── test_export.csv
│   │   ├── test_results.txt
├── build_and_doc.bat
├── clean_build_and_doc.bat
├── build_without_doc.bat
├── clean_only_build.bat
├── Doxyfile
├── main.cpp
├── Makefile
├── README.md
```
