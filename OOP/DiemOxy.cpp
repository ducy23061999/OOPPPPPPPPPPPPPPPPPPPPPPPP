#include <iostream>
#include <math.h>
using namespace std;
class Diem{
    int n,A[100];
    public: void nhap();
            void xuat();
            long long khoangcach(Diem d);
};
void Diem::nhap(){
    cout <<endl<<"Nhap n"<<endl;
    cin >> this->n;
    cout << endl<<"Nhap cac phan tu cua mang"<<endl;
    for (int i =0 ; i < this->n; i++){
        cin >> A[i];
    }
}
void Diem::xuat(){
    cout << "Cac Diem toa do" <<endl;
   for (int i =0 ; i < this->n; i++){
        cout << A[i]<< " ";
    } 
    cout << endl;
}
long long Diem::khoangcach(Diem d){
    long long S = 0;
    if (this->n != d.n) return -1;
    for (int i = 0 ; i < this->n ; i++){
        S += pow(this->A[i] - d.A[i],2);
    }
    return S;
}
int main(){
    Diem a,b;
    a.nhap();
    b.nhap();
    long long S = a.khoangcach(b);
    cout << S;
}