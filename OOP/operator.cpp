#include <iostream>
#include <typeinfo>
using namespace std;
class SoNguyen{
    
    public: int n;
            friend ostream &operator <<(ostream &stream, SoNguyen &sn);
            friend istream &operator >>(istream &stream, SoNguyen &sn);
            SoNguyen operator+(SoNguyen b);
            // friend SoNguyen operator+(SoNguyen a, SoNguyen b);
            friend SoNguyen operator+(int n, SoNguyen b);
            SoNguyen operator+(float b);
            SoNguyen operator-(int);
            SoNguyen operator++();
            SoNguyen operator++(int);
            int operator[](int a){
               
                return a;
            }
        
    
};
ostream &operator <<(ostream &stream, SoNguyen &sn){
    stream<<sn.n<<endl;
    return stream;
}
istream &operator >> (istream &stream, SoNguyen &sn){
    cout<<endl<<"\nNhap so nguyen: ";
    stream>>sn.n;
    return stream;
}
SoNguyen SoNguyen::operator+(SoNguyen b){
    SoNguyen d;
    d.n= n + b.n;
    return d;
}
SoNguyen SoNguyen::operator+(float b){
    SoNguyen d;
    d.n= n + b;
    return d;
}
SoNguyen operator+(int n, SoNguyen b){
    SoNguyen d;
    d.n = n + b.n;
    return d;
}
SoNguyen SoNguyen::operator++(){
    this->n++;
    return *this;
}
SoNguyen SoNguyen::operator++(int){
    SoNguyen c = *this;
    ++(*this);
    return c;
}
SoNguyen SoNguyen::operator-(int){
    this->n = -this->n;
    return this;

}
int main(){
    SoNguyen a,b,c,d;
    
    cout << "Nhap a"<<endl;
    cin >> a;
    cout << -a;
}