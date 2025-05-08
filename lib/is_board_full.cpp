#include "is_board_full.hpp"
#include "constants.hpp"
#include <algorithm>

bool isBoardFull(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board)
        if (std::any_of(row.begin(), row.end(), [](char c) { return c == EMPTY_CELL; }))
            return false;
    return true;
}