#include <iostream>
using namespace std;

int findLength(char str[]) {
    int i = 0;
    while (str[i] != '\0') { 
        i++;
    }
    return i;
}

void copyString(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; 
}

void reverseString(char str[]) {
    int n = findLength(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void concatString(char str1[], char str2[]) {
    int i = findLength(str1);
    int j = 0;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

int main() {
    char str1[100], str2[100], result[200];

    cout << "Enter first string: ";
    cin.getline(str1, 100);

    cout << "Enter second string: ";
    cin.getline(str2, 100);

    cout << "\nLength of first string = " << findLength(str1) << endl;
    cout << "Length of second string = " << findLength(str2) << endl;

    copyString(result, str1);
    cout << "Copy of first string = " << result << endl;

    reverseString(str1);
    cout << "Reverse of first string = " << str1 << endl;

    copyString(result, str1);    
    concatString(result, str2);  
    cout << "Concatenation = " << result << endl;

    return 0;
}
