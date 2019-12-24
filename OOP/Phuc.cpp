#include <stdio.h>
#include "math.h"
#include <iostream>
using namespace std;
long long S(int n){
    if (n == 1 ||  n == 0) return 1;
    else{
        return pow(n,n) * S(n-1);
    } 
}

int Tong(int n){
    int sum = 1,d;
    while(n != 0){
        d = n % 10;
        sum *= d;
        n /= 10;
    }

    return sum;
}

void nhiphan(int n){
   if ( n == 0) cout<<"";
        else if ( n % 2 == 0) {
            nhiphan(n/2);
            cout << 0;
            
        }else
            {
                nhiphan(n/2);
                cout <<1;
                
            }
        
}
float AVG(int A[], int n){

    // Sum
    float Sum = 0;
    for(int i = 0; i < n; i++)
    {
        Sum+= A[i];
    }
    return Sum / n;

    
    
}
int main(){
//    printf("%lld",S(4));
    // int n ;
    // printf("%d",Tong(234));
    int A[] = {1,2,3,5,6};
    printf("%2.2f",AVG(A,5));

    nhiphan(234);

    return 0;
}