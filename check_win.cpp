#include "check_win.hpp"
#include <algorithm>

bool checkWin(const std::vector<std::vector<char>>& board, char mark) {
    int size = board.size();
    for (int i = 0; i < size; ++i) {
        if (std::all_of(board[i].begin(), board[i].end(), [mark](char c) { return c == mark; }) ||
            std::all_of(board.begin(), board.end(), [i, mark](const auto& row) { return row[i] == mark; }))
            return true;
    }
    bool diag1 = true, diag2 = true;
    for (int i = 0; i < size; ++i) {
        diag1 &= (board[i][i] == mark);
        diag2 &= (board[i][size - 1 - i] == mark);
    }
    return diag1 || diag2;
}