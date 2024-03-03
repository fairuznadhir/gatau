#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Player {
private:
    string name;
    int score;

public:
    Player(const string& name) : name(name), score(0) {}

    void setName(const string& playerName) {
        name = playerName;
    }

    string getName() const {
        return name;
    }

    void increaseScore(int points) {
        score += points;
    }

    int getScore() const {
        return score;
    }
};

class GameManager {
private:
    int board[9][9];
    vector<Player> players;

public:
    GameManager() {}

    void startGame() {
        // Initialize the Sudoku board with zeros
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                board[i][j] = 0;
            }
        }
    }

    bool checkWin() {
        // Implement Sudoku win condition checking here
        return false;
    }

    void getPlayerInput(Player& player) {
        // Implement player input handling here
    }
};

class Board {
private:
    int size;
    vector<vector<int>> grid;

public:
    Board(int size) : size(size), grid(size, vector<int>(size, 0)) {}

    int getSize() const {
        return size;
    }

    void setValue(int row, int col, int value) {
        if (row >= 0 && row < size && col >= 0 && col < size && value >= 1 && value <= size) {
            grid[row][col] = value;
        }
    }

    int getValue(int row, int col) const {
        if (row >= 0 && row < size && col >= 0 && col < size) {
            return grid[row][col];
        }
        return -1; // Return -1 for out-of-bounds indices
    }

    bool isValid() const {
        // Check if the board is valid (no duplicate values in rows, columns, and boxes)
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (grid[i][j] != 0 && !isValidPlacement(i, j, grid[i][j])) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isFull() const {
        // Check if the board is completely filled
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (grid[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isWin() const {
        // Check if the board is in a winning state (completely filled and valid)
        return isFull() && isValid();
    }

    void printBoard() const {
        // Print the Sudoku board
        for (int i = 0; i < size; ++i) {
            if (i != 0 && i % int(sqrt(size)) == 0) {
                cout << "------+-------+------" << endl;
            }
            for (int j = 0; j < size; ++j) {
                if (j != 0 && j % int(sqrt(size)) == 0) {
                    cout << "| ";
                }
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

private:
    bool isValidPlacement(int row, int col, int value) const {
        // Check if placing a value at a specific position is valid (no duplicates in row, column, and box)
        for (int i = 0; i < size; ++i) {
            if (grid[row][i] == value && i != col) {
                return false; // Check row
            }
            if (grid[i][col] == value && i != row) {
                return false; // Check column
            }
        }
        int boxSize = sqrt(size);
        int boxRow = row / boxSize * boxSize;
        int boxCol = col / boxSize * boxSize;
        for (int i = boxRow; i < boxRow + boxSize; ++i) {
            for (int j = boxCol; j < boxCol + boxSize; ++j) {
                if (grid[i][j] == value && (i != row || j != col)) {
                    return false; // Check box
                }
            }
        }
        return true;
    }
};

int main() {
    // You can test the classes here
    return 0;
}
