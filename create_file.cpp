#include "create_file.hpp"
#include <fstream>

void createFile(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::ofstream createFile(fileName);
        createFile.close();
    }
}
