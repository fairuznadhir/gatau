#include "GameManager.h"
#include <iostream>

GameManager::GameManager(int boardSize, const std::string& playerName) : board(boardSize), player(playerName) {}

void GameManager::startGame() {
    std::cout << "Welcome to Sudoku, " << player.getName() << "!" << std::endl;

    while (!board.isFull() && !board.isWin()) {
        board.printBoard();
        getPlayerInput();
    }

    if (board.isWin()) {
        std::cout << "Congratulations! You completed the puzzle!" << std::endl;
    } else {
        std::cout << "Game over! You didn't complete the puzzle." << std::endl;
    }
}

void GameManager::getPlayerInput() {
    int row, col, value;
    do {
        std::cout << "Enter row, column, and value (1-" << board.getSize() << ") separated by space: ";
        std::cin >> row >> col >> value;
    } while (!board.isValidMove(row - 1, col - 1, value));

    board.setValue(row - 1, col - 1, value);
}
