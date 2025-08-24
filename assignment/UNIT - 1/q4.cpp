#include <iostream>
using namespace std;

struct Term {
    int row;
    int col;
    int val;
};

int main() {
    int m, n;
    cout << "Enter number of rows and columns of matrix: ";
    cin >> m >> n;

    int mat[20][20];
    cout << "Enter elements of matrix (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

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

    Term transpose[100];
    for (int i = 0; i < count; i++) {
        transpose[i].row = compact[i].col;
        transpose[i].col = compact[i].row;
        transpose[i].val = compact[i].val;
    }

    cout << "\nSimple Transpose (row col value):\n";
    for (int i = 0; i < count; i++) {
        cout << transpose[i].row << " " << transpose[i].col << " " << transpose[i].val << endl;
    }

    return 0;
}
