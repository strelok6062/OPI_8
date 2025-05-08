#include "display_board.hpp"
#include <iostream>
#include <iomanip>

void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "\nПоле игры:" << std::endl;
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << std::setw(2) << cell << " ";
        }
        std::cout << std::endl;
    }
}