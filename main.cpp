#include "lib/create_file.hpp"
#include "lib/start_game.hpp"
#include "lib/config_params.hpp"
#include "lib/show_stats.hpp"
#include "lib/constants.hpp"
#include <iostream>
#include <limits>

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    createFile(PARAMS_FILE);
    createFile(STATS_FILE);
    while (true) {
        std::cout << "Привет это крестики нолики от Марченко и Назаренко. Приятной игры <3\n"
                     "1. Начать игру\n2. Настройки\n3. История игр\n4. Выход\nВаши действия: ";
        int choice;
        while (!(std::cin >> choice) || choice < 1 || choice > 4) {
            std::cout << "Ошибка выбора. Введите число от 1 до 4: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch (choice) {
            case 1: startGame(); break;
            case 2: configParams(); break;
            case 3: showStats(); break;
            case 4: std::cout << "Выход из игры." << std::endl; return 0;
        }
    }
}
