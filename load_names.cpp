#include "load_names.hpp"
#include "constants.hpp"
#include <fstream>

std::pair<std::string, std::string> loadNames() {
    std::ifstream file(PARAMS_FILE);
    std::string p1 = "Игрок 1", p2 = "Игрок 2";
    if (file.is_open()) {
        int temp;
        file >> temp;
        file.ignore();
        getline(file, p1);
        getline(file, p2);
        file.close();
    }
    return {p1, p2};
}