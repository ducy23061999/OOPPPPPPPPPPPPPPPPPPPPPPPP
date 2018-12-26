#include <iostream>
using namespace std;
class PhanSo{
    int tu,mau;
    public: PhanSo cong(PhanSo p);
            PhanSo tru(PhanSo p);
            PhanSo nhan(PhanSo p);
            PhanSo chia(PhanSo p);
            int UCLN(int m, int n);
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
int PhanSo::UCLN(int m, int n){
    m = abs(m);
    n = abs(n);
    if(m == 0 || n == 0) return m + n;
    while( m != n){
        if(m < n) n -= m;
        else m -= n;
    }
    return m;
}
void PhanSo::nhap(){
    cin >> this->tu >> this->mau;
    if(this->mau == 0) {
        cout << "Phan so khong hop le" << endl;
    }
}
void PhanSo::xuat(){
    if(this->mau == 0) {
        cout << "Phan so khong hop le" << endl;
    }
    else {
        int UCLN = this->UCLN(this->tu, this->mau);
        if(this->mau < 0) UCLN = (-1) * UCLN;
        cout << endl << this->tu/UCLN << "/"<< this->mau/UCLN<<endl;
    }
}
int main(){
    PhanSo a,b,c;
    a.nhap();
    b.nhap();
    c = a.cong(b);
    c.xuat();
    return 0;

}
