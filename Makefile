# /**
#  * @file Makefile
#  * @brief Fichier de compilation du projet.
#  * 
#  * Ce fichier Makefile gère la compilation, l'exécution et les tests du projet.
#  * Il organise la compilation des fichiers sources, la gestion des tests et le nettoyage des fichiers générés.
#  * 
#  * @details
#  * - `make all` : Compile le programme principal.
#  * - `make run` : Exécute le programme principal.
#  * - `make test` : Compile et exécute les tests.
#  * - `make clean` : Supprime les fichiers objets et les exécutables.
#  */

# Définition des variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -Iinclude
SRC_DIR = src
TEST_DIR = tests
OBJ_DIR = obj
DATA_DIR = data
BIN_DIR = bin
EXEC = $(BIN_DIR)/main
TEST_RESULTS = $(TEST_DIR)/results/test_results.txt

# Fichiers source et objets
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Fichiers de test et exécutables de test
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_EXECS = $(patsubst $(TEST_DIR)/%.cpp, $(BIN_DIR)/%, $(TEST_SRCS))
TEST_OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(TEST_SRCS))

# Création des répertoires avant compilation
create_dirs:
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	if not exist $(OBJ_DIR)\src mkdir $(OBJ_DIR)\src
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	if not exist $(DATA_DIR) mkdir $(DATA_DIR)
	if not exist $(TEST_DIR)\results mkdir $(TEST_DIR)\results

# Compilation du programme principal
all: create_dirs $(EXEC)

$(EXEC): $(OBJS) obj/main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilation des fichiers source en objets
$(OBJ_DIR)/%.o: %.cpp | create_dirs
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Exécution du programme principal
run: all
	@echo "Execution du programme principal..."
	@$(EXEC)

# Compilation des tests
$(BIN_DIR)/%: $(TEST_DIR)/%.cpp $(OBJS) | create_dirs
	$(CXX) $(CXXFLAGS) $< $(OBJS) -o $@

# Exécution des tests et sauvegarde des résultats dans un fichier test_results.txt
test: $(TEST_EXECS)
	@echo "Execution des tests..."
	if exist $(TEST_RESULTS) del $(TEST_RESULTS)
	@for %%t in ($(TEST_EXECS)) do ( \
		echo test %%~nt >> $(TEST_RESULTS) & \
		$(BIN_DIR)\%%~nt.exe >> $(TEST_RESULTS) 2>&1 & \
		echo. >> $(TEST_RESULTS) \
	)
	@echo "Les resultats des tests sont sauvegardes dans $(TEST_RESULTS)."

# Nettoyage des fichiers objets et exécutables
clean:
	if exist $(OBJ_DIR) rmdir /S /Q $(OBJ_DIR)
	if exist $(BIN_DIR) rmdir /S /Q $(BIN_DIR)
	if exist $(TEST_DIR)\results rmdir /S /Q $(TEST_DIR)\results
	if exist $(DATA_DIR)\rapport_analyse.csv del $(DATA_DIR)\rapport_analyse.csv
	if exist $(TEST_RESULTS) del $(TEST_RESULTS)
