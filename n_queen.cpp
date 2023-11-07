#include <iostream>
using namespace std;

const int N = 4; 

void printChessboard(int chessboard[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (chessboard[i][j] == 1) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int chessboard[N][N], int row, int col) {
    // Check the left side of the current row
    for (int i = 0; i < col; i++) {
        if (chessboard[row][i] == 1) {
            return false;
        }
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 1) {
            return false;
        }
    }

    // Check the lower left diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (chessboard[i][j] == 1) {
            return false;
        }
    }
    return true;
}

bool solveNQueens(int chessboard[N][N], int col) {
    if (col == N) {
        printChessboard(chessboard);
        return true;
    }

    bool solutionFound = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(chessboard, i, col)) {
            chessboard[i][col] = 1;

            if (solveNQueens(chessboard, col + 1)) {
                solutionFound = true;
            }
            chessboard[i][col] = 0;
        }
    }
    return solutionFound;
}

int main() {
    int chessboard[N][N] = {0}; 
    
    if (!solveNQueens(chessboard, 0)) {
        cout << "No solution exists for the " << N << "-Queens problem." << endl;
    }

    return 0;
}
