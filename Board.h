#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
private:
    int size;
    std::vector<std::vector<int>> grid;

public:
    Board(int boardSize);
    int getSize() const;
    bool setValue(int row, int col, int value);
    int getValue(int row, int col) const;
    bool isFull() const;
    bool isValidMove(int row, int col, int value) const;
    bool isWin() const;
    void printBoard() const;
};

#endif
