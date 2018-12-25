#include <iostream>
using namespace std;
class PhanSo{
    int tu,mau;
    public: PhanSo cong(PhanSo p);
            PhanSo tru(PhanSo p);
            PhanSo nhan(PhanSo p);
            PhanSo chia(PhanSo p);
            void nhap();
            void xuat();
};
PhanSo PhanSo::cong(PhanSo p){
    PhanSo result;
    result.tu = this->tu * p.mau + p.tu * this->mau;
    result.mau = this->mau * p.mau;
    return result;
}
PhanSo PhanSo::tru(PhanSo p){
    PhanSo result;
    result.tu = this->tu * p.mau - p.tu * this->mau;
    result.mau = this->mau * p.mau;
    return result;
}
PhanSo PhanSo::nhan(PhanSo p){
    PhanSo result;
    result.tu = this->tu * p.tu;
    result.mau = this->mau * p.mau;
    return result;
}
PhanSo PhanSo::chia(PhanSo p){
    PhanSo result;
    result.tu = this->tu * p.mau;
    result.mau = this->mau * p.tu;
    return result;
}
void PhanSo::nhap(){
    cin >> this->tu >> this->mau;
}
void PhanSo::xuat(){
    cout << endl << this->tu << "/"<< this->mau<<endl;
}
int main(){
    PhanSo a,b,c;
    a.nhap();
    b.nhap();
    c = a.cong(b);
    c.xuat();
    return 0;

}