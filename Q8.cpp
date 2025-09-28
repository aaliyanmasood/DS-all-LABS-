#include <iostream>
#include <cmath>
using namespace std;

#define N 4

bool isSafe(int row, int col, int positions[]) {
    for (int i = 0; i < row; i++) {
        if (positions[i] == col || abs(positions[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

bool solve(int row, int positions[]) {
    if (row == N)
        return true;

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col, positions)) {
            positions[row] = col;
            if (solve(row + 1, positions))
                return true;
            positions[row] = -1; // backtrack
        }
    }
    return false;
}

int main() {
    int positions[N];
    for (int i = 0; i < N; i++)
        positions[i] = -1;

    if (solve(0, positions)) {
        cout << "Maximum flags placed: " << N << "\n";
        cout << "Flag positions (row : column):\n";
        for (int i = 0; i < N; i++)
            cout << i << " : " << positions[i] << "\n";
    } else {
        cout << "No solution found.\n";
    }

    return 0;
}
