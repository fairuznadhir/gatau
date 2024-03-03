#include "GameManager.h"
#include <iostream>

GameManager::GameManager(int boardSize) : board(boardSize), currentPlayerIndex(0) {}

void GameManager::startGame() {
    std::cout << "Welcome to Sudoku!" << std::endl;
    Player player1("Player 1");
    Player player2("Player 2");
    players.push_back(player1);
    players.push_back(player2);

    while (!checkWin() && !board.isFull()) {
        Player& currentPlayer = players[currentPlayerIndex];
        board.printBoard();
        std::cout << currentPlayer.getName() << "'s turn:" << std::endl;
        getPlayerInput(currentPlayer);
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }

    if (checkWin()) {
        std::cout << "Congratulations! " << players[currentPlayerIndex].getName() << " wins!" << std::endl;
    } else {
        std::cout << "It's a draw!" << std::endl;
    }
}

bool GameManager::checkWin() {
    return board.isWin();
}

void GameManager::getPlayerInput(Player& player) {
    int row, col, value;
    do {
        std::cout << "Enter row, column, and value (1-" << board.getSize() << ") separated by space: ";
        std::cin >> row >> col >> value;
    } while (!board.isValidMove(row - 1, col - 1, value));

    board.setValue(row - 1, col - 1, value);
}
