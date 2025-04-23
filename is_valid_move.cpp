#include "is_valid_move.hpp"
#include "constants.hpp"

bool isValidMove(const std::vector<std::vector<char>>& board, int row, int col) {
    int size = board.size();
    return row >= 0 && row < size && col >= 0 && col < size && board[row][col] == EMPTY_CELL;
}