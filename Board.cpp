#include "Board.h"
#include <iostream>

Board::Board(int boardSize) : size(boardSize), grid(boardSize, std::vector<int>(boardSize, 0)) {}

int Board::getSize() const {
    return size;
}

bool Board::setValue(int row, int col, int value) {
    if (isValidMove(row, col, value)) {
        grid[row][col] = value;
        return true;
    }
    return false;
}

int Board::getValue(int row, int col) const {
    return grid[row][col];
}

bool Board::isFull() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool Board::isValidMove(int row, int col, int value) const {
    if (row < 0 || row >= size || col < 0 || col >= size || value < 1 || value > size) {
        return false;
    }
    // Implementasi validasi langkah
    return true;
}

bool Board::isWin() const {
    // Implementasi logika untuk memeriksa apakah permainan sudah dimenangkan
    return false;
}

void Board::printBoard() const {
    // Implementasi untuk mencetak papan permainan
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
