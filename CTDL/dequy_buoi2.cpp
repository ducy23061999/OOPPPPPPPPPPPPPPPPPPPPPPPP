#include <iostream>
using namespace std;
int A[100], size = 3;
int max(int n, int &m){
    if (n == 0) {
        return m;
    } else {
        if (m < A[n]) {
            return max(n-1,A[n]);
        } else {
            return max(n-1, m);
        }
    }
}
void dao(int n) {
    if (n >= size / 2) {
        int temp = A[n];
        A[n] = A[size-n -1];
        A[size-n -1] = temp;
        dao(n-1);
    }
}
int demNghichDao(int n, int i, int dem = 0) {
    cout << n << "|" << i<<"|"<<dem<<endl;
    if (n == i) {
        cout << "hi: "<<dem<< endl;
        return dem;   
    } else {
        if (i == n -1) demNghichDao(n-1,0, dem);
        if (A[i] > A[n]) {
            demNghichDao(n, ++i, ++dem);
        } else {
            demNghichDao(n, ++i, dem);
        }
    }
}
void in() {
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
int main() {
    int m = A[size];
    for (int i = 0; i < size; i++) {
        cin >> A[i];
    }
    cout << demNghichDao(size-1, 0);
    

    
}