#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int score;

public:
    Player();
    Player(const std::string& playerName);
    void setName(const std::string& playerName);
    std::string getName() const;
    void increaseScore(int points);
    int getScore() const;
};

#endif
