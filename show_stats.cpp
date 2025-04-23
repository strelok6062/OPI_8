#include "show_stats.hpp"
#include "load_stats.hpp"
#include <iostream>

void showStats() {
    auto stats = loadStats();
    if (stats.empty()) {
        std::cout << "История чиста." << std::endl;
    } else {
        std::cout << "История игры" << std::endl;
        for (const auto& record : stats) {
            std::cout << record << std::endl;
        }
    }
}
