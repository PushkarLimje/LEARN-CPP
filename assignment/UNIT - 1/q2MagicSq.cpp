#include <iostream>
#include <vector>
using namespace std;

// Function to display the magic square
void printSquare(vector<vector<int>> &square, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << square[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to verify magic square
bool verifyMagicSquare(vector<vector<int>> &square, int n) {
    int magicConstant = n * (n * n + 1) / 2;

    // Check rows
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) rowSum += square[i][j];
        if (rowSum != magicConstant) return false;
    }

    // Check columns
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) colSum += square[i][j];
        if (colSum != magicConstant) return false;
    }

    // Check diagonals
    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < n; i++) {
        diag1 += square[i][i];
        diag2 += square[i][n - i - 1];
    }
    if (diag1 != magicConstant || diag2 != magicConstant) return false;

    return true;
}

// Construct magic square for odd n (Siamese method)
vector<vector<int>> oddMagicSquare(int n) {
    vector<vector<int>> square(n, vector<int>(n, 0));
    int i = 0, j = n / 2; // start position
    for (int num = 1; num <= n * n; num++) {
        square[i][j] = num;
        int newI = (i - 1 + n) % n;
        int newJ = (j + 1) % n;
        if (square[newI][newJ] != 0) {
            i = (i + 1) % n;
        } else {
            i = newI;
            j = newJ;
        }
    }
    return square;
}

// Construct magic square for doubly even n (n % 4 == 0)
vector<vector<int>> doublyEvenMagicSquare(int n) {
    vector<vector<int>> square(n, vector<int>(n, 0));
    int num = 1;
    int num2 = n * n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // condition for diagonals
            if ( (i % 4 == j % 4) || ((i + j) % 4 == 3) ) {
                square[i][j] = num2;
            } else {
                square[i][j] = num;
            }
            num++;
            num2--;
        }
    }
    return square;
}

int main() {
    int n;
    cout << "Enter order of Magic Square (n): ";
    cin >> n;

    if (n < 3) {
        cout << "Magic square not possible for n < 3" << endl;
        return 0;
    }

    vector<vector<int>> square;

    if (n % 2 == 1) {
        square = oddMagicSquare(n);
    } else if (n % 4 == 0) {
        square = doublyEvenMagicSquare(n);
    } else {
        cout << "Singly even order (like 6, 10) is complex and not handled here.\n";
        return 0;
    }

    cout << "\nMagic Square of order " << n << ":\n";
    printSquare(square, n);

    cout << "\nVerification: ";
    if (verifyMagicSquare(square, n)) {
        cout << "Valid Magic Square!" << endl;
    } else {
        cout << "Invalid Magic Square!" << endl;
    }

    return 0;
}
