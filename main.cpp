#include "GameManager.h"
#include <iostream>

int main() {
    std::string playerName;
    std::cout << "Enter your name: ";
    std::cin >> playerName;

    GameManager gameManager(9, playerName);
    gameManager.startGame();
    return 0;
}
