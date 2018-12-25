#include <iostream>

using namespace std;
class SoNguyen
{
    private: int n;

    public: void nhap();
            void xuat();
            bool soNguyenTo();
            void chuyenCoSo();
            friend istream &operator >>(istream &stream, SoNguyen &p);
            friend ostream &operator << (ostream &stream, SoNguyen &p);

};
istream& operator >>(istream &in, SoNguyen &p){
    cout << "Nhap n: ";
    in >> p.n;
    return in;
}
ostream &operator << (ostream &stream, SoNguyen &p){
    stream << p.n;
    return stream;
}
void SoNguyen::nhap(){
    cout << "Nhap n: ";
    cin >> n;
}
void SoNguyen::xuat(){
    cout << n;
}
bool SoNguyen::soNguyenTo(){
    for (int i = 2; i <= n; i++){
        if (n % 2 == 0) return false;
    }
    return true;
}

void SoNguyen::chuyenCoSo(){
    int A[100] = {-1};
    int cpy = n,pos = 0;
    while (cpy != 0){
        A[pos] = (cpy % 2 == 0) ? 0 : 1;
        cpy /= 2; pos++;
    }
    for (int i = pos -1; i >= 0; i--){
        cout << A[i];
    }
    cout << endl;
}
int main(){
    SoNguyen ob1;
    cin>>ob1;
    if (ob1.soNguyenTo()) cout <<endl<< "La so nguyen to!"<<endl;
                else cout <<endl<< "Khong phai so nguyen to"<<endl;
    ob1.chuyenCoSo();
    cout << ob1;

}