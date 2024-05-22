#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE = 3; //Value for the board size
vector<vector<char>> board(SIZE, vector<char>(SIZE, ' '));

void drawBoard() {
    cout << " ";
    for (int i = 1; i <= SIZE; ++i) {
        cout << " " << i << " ";
    }
    cout << endl;

    for (int i = 0; i < SIZE; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < SIZE; ++j) {
            cout << " " << board[i][j];
            if (j < SIZE - 1) cout << " |";
        }
        cout << endl;

        if (i <SIZE - 1) {
            cout << " ";
            for (int j = 0; j < SIZE; ++j) {
                cout << "---";
                if (j < SIZE - 1) cout << "+";
            }
            cout << endl;
        }
    }

}

bool checkWin(char player) {
    // Check rows and columns
    for(int i = 0; i < SIZE; ++i) {
        if (all_of(board[i].begin(), board[i].end(), [player](char c) { return c == player; })) return true;
        bool columnWin = true;
        for (int j = 0; j < SIZE; ++j) {
            if (board[j][i] != player) {
                columnWin = false;
                break;
            }
        }
        if (columnWin) return true;
    }

// Check diagonals

bool diag1 = true, diag2 = true;
for(int i = 0; i < SIZE; ++i) {
    if (board[i][i] != player) diag1 = false;
    if (board[i][SIZE - i - 1] != player) diag2 = false;
}
return diag1 || diag2;
}

bool checkDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}


int main() {
    char currentPlayer = 'X';
    int row, col;

    while(true) {
        drawBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        row--; col--; //Adjust for zero based indexing

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            if (checkWin(currentPlayer)) {
                drawBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            } else if (checkDraw()) {
                drawBoard();
                cout << "It's a draw!" << endl;
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move!" << endl;
        }
    }
    return 0;
}
