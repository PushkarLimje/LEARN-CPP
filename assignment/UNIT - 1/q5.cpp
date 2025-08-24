#include <iostream>
using namespace std;

struct Term {
    int row, col, val;
};

int main() {
    int m, n;
    cout << "Enter number of rows and columns of matrix: ";
    cin >> m >> n;

    int mat[20][20];
    cout << "Enter elements of matrix (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    int count = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] != 0)
                count++;

    Term compact[100];
    int k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != 0) {
                compact[k].row = i;
                compact[k].col = j;
                compact[k].val = mat[i][j];
                k++;
            }
        }
    }

    cout << "\nCompact Representation (row col value):\n";
    for (int i = 0; i < count; i++) {
        cout << compact[i].row << " " << compact[i].col << " " << compact[i].val << endl;
    }

    Term trans[100];
    int rowTerms[20] = {0}, startPos[20] = {0};

    for (int i = 0; i < count; i++) {
        rowTerms[compact[i].col]++;
    }

    startPos[0] = 0;
    for (int i = 1; i < n; i++) {
        startPos[i] = startPos[i - 1] + rowTerms[i - 1];
    }

    for (int i = 0; i < count; i++) {
        int pos = startPos[compact[i].col]++;
        trans[pos].row = compact[i].col;
        trans[pos].col = compact[i].row;
        trans[pos].val = compact[i].val;
    }

    cout << "\nFast Transpose (row col value):\n";
    for (int i = 0; i < count; i++) {
        cout << trans[i].row << " " << trans[i].col << " " << trans[i].val << endl;
    }

    return 0;
}
