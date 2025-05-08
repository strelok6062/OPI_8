#include "start_game.hpp"
#include "display_board.hpp"
#include "is_valid_move.hpp"
#include "check_win.hpp"
#include "is_board_full.hpp"
#include "load_size.hpp"
#include "load_names.hpp"
#include "save_stat.hpp"
#include "constants.hpp"
#include <iostream>
#include <vector>
#include <limits>

void startGame() {
    int size = loadSize();
    auto players = loadNames();
    std::vector<std::vector<char>> board(size, std::vector<char>(size, EMPTY_CELL));

    std::string p1 = players.first, p2 = players.second;
    char mark1 = X_MARK, mark2 = O_MARK;

    std::cout << "Кто будет ходить первым? (1 - " << p1 << ", 2 - " << p2 << "): ";
    int choice;
    while (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
        std::cout << "Некорректный выбор. Введите 1 или 2: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (choice == 2) {
        std::swap(p1, p2);
        std::swap(mark1, mark2);
    }

    bool firstTurn = true;
    while (true) {
        displayBoard(board);
        std::string currentPlayer = firstTurn ? p1 : p2;
        char currentMark = firstTurn ? mark1 : mark2;

        int row, col;
        std::cout << currentPlayer << " (" << currentMark << "), введите координаты строки и столбца через пробел: ";
        while (!(std::cin >> row >> col) || !isValidMove(board, row - 1, col - 1)) {
            std::cout << "Некорректный ход. Попробуйте снова: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        board[row - 1][col - 1] = currentMark;

        if (checkWin(board, currentMark)) {
            displayBoard(board);
            std::cout << currentPlayer << " выиграл!" << std::endl;
            saveStat(currentPlayer + " выиграл.");
            break;
        }

        if (isBoardFull(board)) {
            displayBoard(board);
            std::cout << "Ничья!" << std::endl;
            saveStat("Ничья.");
            break;
        }
        firstTurn = !firstTurn;
    }

    std::cout << "Хотите начать новую игру или выйти в меню? (1 - Новая игра, 2 - Меню): ";
    int next;
    while (!(std::cin >> next) || (next != 1 && next != 2)) {
        std::cout << "Некорректный выбор. Введите 1 или 2: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (next == 1) startGame();
}