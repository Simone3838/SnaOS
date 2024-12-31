#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// Constants for the game dimensions and mine count
const int WIDTH = 10;
const int HEIGHT = 10;
const int MINES = 10;

struct Cell {
    bool hasMine;
    bool revealed;
    int adjacentMines;

    Cell() : hasMine(false), revealed(false), adjacentMines(0) {}
};

std::vector<std::vector<Cell>> board(WIDTH, std::vector<Cell>(HEIGHT));

// Function to initialize the game board
void initializeBoard() {
    std::srand(std::time(0));
    int minesPlaced = 0;

    while (minesPlaced < MINES) {
        int x = std::rand() % WIDTH;
        int y = std::rand() % HEIGHT;
        if (!board[x][y].hasMine) {
            board[x][y].hasMine = true;
            minesPlaced++;
        }
    }

    // Calculate adjacent mines
    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            if (board[x][y].hasMine) continue;
            int mineCount = 0;

            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && ny >= 0 && nx < WIDTH && ny < HEIGHT && board[nx][ny].hasMine) {
                        mineCount++;
                    }
                }
            }

            board[x][y].adjacentMines = mineCount;
        }
    }
}

// Function to display the game board
void displayBoard() {
    std::cout << "   ";
    for (int x = 0; x < WIDTH; ++x) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    for (int y = 0; y < HEIGHT; ++y) {
        std::cout << y << " ";
        for (int x = 0; x < WIDTH; ++x) {
            if (board[x][y].revealed) {
                if (board[x][y].hasMine) {
                    std::cout << "* ";
                } else {
                    std::cout << board[x][y].adjacentMines << " ";
                }
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

// Function to reveal a cell
bool revealCell(int x, int y) {
    if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT || board[x][y].revealed) {
        return false;
    }

    board[x][y].revealed = true;

    if (board[x][y].hasMine) {
        return true;
    }

    if (board[x][y].adjacentMines == 0) {
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                revealCell(x + dx, y + dy);
            }
        }
    }

    return false;
}

// Function to check if the player has won
bool checkWin() {
    int revealedCount = 0;

    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            if (board[x][y].revealed && !board[x][y].hasMine) {
                revealedCount++;
            }
        }
    }

    return revealedCount == (WIDTH * HEIGHT - MINES);
}

// Function to run the Minesweeper game
void minesweeper() {
    initializeBoard();

    while (true) {
        displayBoard();
        int x, y;
        std::cout << "Enter coordinates to reveal (x y): ";
        std::cin >> x >> y;

        if (revealCell(x, y)) {
            std::cout << "Game Over! You hit a mine." << std::endl;
            displayBoard();
            break;
        }

        if (checkWin()) {
            std::cout << "Congratulations! You cleared the minefield." << std::endl;
            displayBoard();
            break;
        }
    }
}

extern "C" void start_minesweeper() {
    minesweeper();
}
