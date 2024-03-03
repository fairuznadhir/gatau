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

    // Cek apakah nilai sudah ada di baris, kolom, atau kotak 3x3 yang sama
    for (int i = 0; i < size; ++i) {
        if (grid[row][i] == value || grid[i][col] == value) {
            return false;
        }
    }

    int boxRow = row / 3 * 3;
    int boxCol = col / 3 * 3;
    for (int i = boxRow; i < boxRow + 3; ++i) {
        for (int j = boxCol; j < boxCol + 3; ++j) {
            if (grid[i][j] == value) {
                return false;
            }
        }
    }

    return true;
}

bool Board::isWin() const {
    // Implementasi logika untuk memeriksa apakah permainan sudah dimenangkan
    return false;
}

void Board::printBoard() const {
    // Implementasi untuk mencetak papan permainan
    std::cout << "  ";
    for (int i = 0; i < size; ++i) {
        std::cout << i + 1 << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < size; ++i) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] == 0) {
                std::cout << ". ";
            } else {
                std::cout << grid[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}
