#include "save_stat.hpp"
#include "constants.hpp"
#include <fstream>

void saveStat(const std::string& record) {
    std::ofstream file(STATS_FILE, std::ios::app);
    if (file.is_open()) {
        file << record << std::endl;
        file.close();
    }
}
