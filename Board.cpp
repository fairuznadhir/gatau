#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Board::Board(int boardSize) : size(boardSize), grid(boardSize, std::vector<int>(boardSize, 0)) {
    // Generate a random initial board state for single player
    srand(time(0));
    // Generate random positions to be filled initially (30% of the board)
    int filledCells = boardSize * boardSize * 0.3;
    for (int i = 0; i < filledCells; ++i) {
        int row = rand() % boardSize;
        int col = rand() % boardSize;
        int value = rand() % boardSize + 1;
        while (!isValidMove(row, col, value)) {
            row = rand() % boardSize;
            col = rand() % boardSize;
            value = rand() % boardSize + 1;
        }
        grid[row][col] = value;
    }
}

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

    // Check if value already exists in row or column
    for (int i = 0; i < size; ++i) {
        if (grid[row][i] == value || grid[i][col] == value) {
            return false;
        }
    }

    // Check if value already exists in the same 3x3 box
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
    // Check if the player has successfully completed the Sudoku puzzle
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] == 0) {
                return false; // If there's still an empty cell, the game is not won yet
            }
        }
    }
    return true; // If no empty cell is found, the game is won
}

void Board::printBoard() const {
    // Implementation for printing the game board
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
