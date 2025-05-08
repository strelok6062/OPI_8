#include "config_params.hpp"
#include "save_params.hpp"
#include <iostream>
#include <string>

void configParams() {
    int size;
    std::string p1, p2;
    std::cout << "Розмер поля (> 3): ";
    std::cin >> size;
    if (size < 3) size = 3;
    std::cin.ignore();
    std::cout << "Имя игрока 1: ";
    getline(std::cin, p1);
    std::cout << "Имя игрока 2: ";
    getline(std::cin, p2);
    saveParams(size, p1, p2);
    std::cout << "Сохранено" << std::endl;
}
