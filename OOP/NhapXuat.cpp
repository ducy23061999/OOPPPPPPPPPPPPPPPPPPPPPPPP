#include <iostream>
using namespace std;

int main(){
    char a[100];
    cin.get(a,100);
    char b[100];
    cin.ignore();
    cin.get(b,100);
    cout << a;
    cout << b;
}