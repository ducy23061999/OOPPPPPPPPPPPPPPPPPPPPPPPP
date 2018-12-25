#include <iostream>
using namespace std;
struct phanso{
    int tu,mau;
};
float tong(phanso a, phanso b){
    phanso p;
    p.tu = (a.tu*b.mau) + (b.tu * a.mau);
    p.mau = (a.mau * b.mau);
    return float(p.tu) / p.mau;
}
long tong(int a[],int na, int b[], int nb){
    long sum = 0;
    for (int i = 0 ; i < na; i++)
        sum+= a[i];
    for (int i = 0; i < nb; i++)   
        sum+= b[i];
    return sum;
}
int main(){
    phanso a,b;
    a.tu = 2; a.mau = 4;
    b.tu = 6; b.mau = 12;
    cout << tong(a,b)<<endl;
    int A[5] = {1,2,3,4,5};
    int B[8] = {1,2,3,4,5,6,7,8};
    cout << tong(A,5,B,8);
    return 0;
}