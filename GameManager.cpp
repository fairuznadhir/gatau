#include "GameManager.h"
#include <iostream>

GameManager::GameManager(int boardSize) : board(boardSize) {}

void GameManager::startGame() {
    std::cout << "Welcome to Sudoku!" << std::endl;
    // Implementasi logika permainan
}

bool GameManager::checkWin() {
    return board.isWin();
}

void GameManager::getPlayerInput(Player& player) {
    std::cout << "Player " << player.getName() << ", enter row, column, and value (separated by space): ";
    int row, col, value;
    std::cin >> row >> col >> value;

    if (board.isValidMove(row, col, value)) {
        board.setValue(row, col, value);
        player.increaseScore(10); // Skor pemain naik 10 setiap langkah yang valid
    } else {
        std::cout << "Invalid move. Try again." << std::endl;
    }
}
