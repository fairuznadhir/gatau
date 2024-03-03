#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"
#include "Board.h"

class GameManager {
private:
    Board board;
    std::vector<Player> players;
    int currentPlayerIndex;

public:
    GameManager(int boardSize);
    void startGame();
    bool checkWin();
    void getPlayerInput(Player& player);
};

#endif
