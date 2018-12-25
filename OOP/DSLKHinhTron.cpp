#include <iostream>
using namespace std;
class HinhTron{
    int x, y;
    float R;
    public: 
        HinhTron *next;
        void nhap();
        void xuat();
        int getX();
        int getY();
        HinhTron(int x, int y, float R); 
};
HinhTron::HinhTron(int x, int y, float R){
    this->x = x;
    this->y = y;
    this->R = R;
};
void HinhTron::nhap(){
    cin  >>  x >> y >> R;
}
void HinhTron::xuat(){
    cout <<endl<< "("<<x<<","<<y<<")"<<"\n R = "<< R<<endl;
}
int HinhTron::getX(){
    return x;
}
int HinhTron::getY(){
    return y;
}

class QuanLi{
    HinhTron *first;
    public:
        void nhap();
        void xuat();
        void SapXep();
        void Chen();
        void HienThi();
        QuanLi();
};
QuanLi::QuanLi(){
    this->first = NULL;
}
int main(int argc, char const *argv[])
{
    cout << "Hello World!";
    return 0;
}
