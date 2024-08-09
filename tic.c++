#include <iostream>
using namespace std;

// Function prototypes
void displayBoard(const char board[3][3]);
void initializeBoard(char board[3][3]);
bool isValidMove(const char board[3][3], int row, int col);
void makeMove(char board[3][3], int row, int col, char player);
bool checkWin(const char board[3][3], char player);
bool checkDraw(const char board[3][3]);
void switchPlayer(char& player);
void playGame();
bool playAgain();

int main() {
    do {
        playGame();
    } while (playAgain());

    return 0;
}

void displayBoard(const char board[3][3]) {
    cout << "Current board state:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << (board[i][j] == ' ' ? '.' : board[i][j]) << " ";
        }
        cout << endl;
    }
}

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

bool isValidMove(const char board[3][3], int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}

void makeMove(char board[3][3], int row, int col, char player) {
    board[row][col] = player;
}

bool checkWin(const char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

bool checkDraw(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer(char& player) {
    player = (player == 'X') ? 'O' : 'X';
}

void playGame() {
    char board[3][3];
    initializeBoard(board);
    char currentPlayer = 'X';
    bool gameEnded = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (!gameEnded) {
        displayBoard(board);
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column, 1-3): ";
        cin >> row >> col;

        // Convert to 0-based indexing
        row--;
        col--;

        if (isValidMove(board, row, col)) {
            makeMove(board, row, col, currentPlayer);

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameEnded = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "The game is a draw!" << endl;
                gameEnded = true;
            } else {
                switchPlayer(currentPlayer);
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
}

bool playAgain() {
    char response;
    cout << "Do you want to play again? (y/n): ";
    cin >> response;
    return response == 'y' || response == 'Y';
}
