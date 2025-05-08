#include "load_size.hpp"
#include "constants.hpp"
#include <fstream>

int loadSize() {
    std::ifstream file(PARAMS_FILE);
    int size = 3;
    if (file.is_open()) {
        file >> size;
        file.close();
    }
    return size;
}
