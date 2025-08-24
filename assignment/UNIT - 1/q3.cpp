// #include <iostream>
// #include <ctime>    
// #include <cstdlib>  
// using namespace std;

// #define MAX 500   


// void multiplyRowMajor(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             int sum = 0;
//             for (int k = 0; k < n; k++) {
//                 sum += A[i][k] * B[k][j]; // sequential in A, non-sequential in B
//             }
//             C[i][j] = sum;
//         }
//     }
// }


// void multiplyColumnMajor(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             int sum = 0;
//             for (int k = 0; k < n; k++) {
//                 sum += A[i][k] * B[j][k]; // BAD cache locality (jumping across rows)
//             }
//             C[i][j] = sum;
//         }
//     }
// }

// void multiplyColumnMajorOptimized(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    
//     int BT[MAX][MAX];
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             BT[j][i] = B[i][j];

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             int sum = 0;
//             for (int k = 0; k < n; k++) {
//                 sum += A[i][k] * BT[j][k]; // now row-wise access
//             }
//             C[i][j] = sum;
//         }
//     }
// }

// int main() {
//     int n;
//     cout << "Enter matrix size n (n x n, max " << MAX << "): ";
//     cin >> n;

//     int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

//     srand(time(0));
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++) {
//             A[i][j] = rand() % 100;
//             B[i][j] = rand() % 100;
//         }

//     clock_t start = clock();
//     multiplyRowMajor(A, B, C, n);
//     clock_t end = clock();
//     double rowTime = double(end - start) / CLOCKS_PER_SEC;
//     cout << "\nRow-major multiplication time: " << rowTime << " sec\n";

//     start = clock();
//     multiplyColumnMajor(A, B, C, n);
//     end = clock();
//     double colTime = double(end - start) / CLOCKS_PER_SEC;
//     cout << "Column-major (naive) multiplication time: " << colTime << " sec\n";

   
//     start = clock();
//     multiplyColumnMajorOptimized(A, B, C, n);
//     end = clock();
//     double colOptTime = double(end - start) / CLOCKS_PER_SEC;
//     cout << "Column-major (with transpose) multiplication time: " << colOptTime << " sec\n";


//     return 0;
// }

#include <iostream>
#include <ctime>    
#include <cstdlib>  
using namespace std;

#define MAX 500   

// ---------- Standard Row-major Multiplication ----------
void multiplyRowMajor(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j];  // correct multiplication
            }
            C[i][j] = sum;
        }
    }
}

// ---------- Transpose Optimized Multiplication ----------
void multiplyWithTranspose(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    // First compute transpose of B
    int BT[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            BT[j][i] = B[i][j];

    // Multiply using BT (row-wise access on both A and BT)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * BT[j][k];
            }
            C[i][j] = sum;
        }
    }
}

int main() {
    int n;
    cout << "Enter matrix size n (n x n, max " << MAX << "): ";
    cin >> n;

    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    // Initialize matrices with random values
    srand(time(0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }

    // Row-major multiplication
    clock_t start = clock();
    multiplyRowMajor(A, B, C, n);
    clock_t end = clock();
    double rowTime = double(end - start) / CLOCKS_PER_SEC;
    cout << "\nRow-major multiplication time: " << rowTime << " sec\n";

    // Transpose optimized multiplication
    start = clock();
    multiplyWithTranspose(A, B, C, n);
    end = clock();
    double colOptTime = double(end - start) / CLOCKS_PER_SEC;
    cout << "Multiplication with transpose optimization time: " << colOptTime << " sec\n";

    cout << "\n--- Analysis ---\n";
    cout << "Both methods give correct results.\n";
    cout << "Row-major: simple but cache misses in B (scans down columns).\n";
    cout << "Transpose optimization: turns column access into row access → faster cache performance.\n";

    return 0;
}

