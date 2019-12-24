#include <iostream>
using namespace std;
int A[1000], n;


int main() {
    A[0] = -100000;
    cin >> n;
    for (int i = 1 ; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        int x = A[i], j = i - 1;
        while (x < A[j])
        {
            A[j + 1] = A[j];
            j = j + 1;
        };
        A[j + 1] = x;
        
    }
    cout << endl;
    for ( int i =1 ; i <= n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}