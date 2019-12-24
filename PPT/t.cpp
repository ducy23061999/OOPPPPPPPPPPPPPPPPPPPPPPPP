#include "Matrix.h"

int main() {
    int n;
    int * a = Matrix::readFileFromMatrix("input.txt", n);
    for (int i =0 ; i < n; i++) {
        cout << a[i]<< " "; 
    }
    return 0;
}