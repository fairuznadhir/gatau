#include "Player.h"

Player::Player() : score(0) {}

Player::Player(const std::string& playerName) : name(playerName), score(0) {}

void Player::setName(const std::string& playerName) {
    name = playerName;
}

std::string Player::getName() const {
    return name;
}

void Player::increaseScore(int points) {
    score += points;
}

int Player::getScore() const {
    return score;
}
