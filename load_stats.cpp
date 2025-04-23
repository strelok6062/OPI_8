#include "load_stats.hpp"
#include "constants.hpp"
#include <fstream>

std::vector<std::string> loadStats() {
    std::ifstream file(STATS_FILE);
    std::vector<std::string> stats;
    std::string line;
    while (getline(file, line)) stats.push_back(line);
    return stats;
}
