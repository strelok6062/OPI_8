#include "save_params.hpp"
#include "constants.hpp"
#include <fstream>

void saveParams(int size, const std::string& p1, const std::string& p2) {
    std::ofstream file(PARAMS_FILE);
    if (file.is_open()) {
        file << size << '\n' << p1 << '\n' << p2 << std::endl;
        file.close();
    }
}