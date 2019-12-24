#include  <iostream>
#include "math.h"
using namespace std;
int main(){
    int N;
    cin >> N;
    // int *A = new int[(int)pow(2,15)];
    int A[1000000] = {0};
    for (int i = 1; i < N -1; i++){
        int k;
        cin >> k;
        A[k]++;
    }
    for (int i = 1; i < N; i++){
        cout << A[i]<<" ";
    }
    cout << endl;
    for (int i = 1; i < N -1; i++){
        if (A[i] == 0)
        cout << i;
        break;
    }
    
    
    
}