#include <iostream>
#include <string.h>
using namespace std;
const long long phongA = 5000;
const long long phongB = 2000;
const long long phongC = 1000;
class Phong{
    char loaiphong[2];
    protected: 
        int songaythue;
    public: 
        Phong(char *loai);
        Phong();
        virtual void nhap();
        virtual long long tinhtien();
        virtual void xuat();
};
class Vip: public Phong{ 
    long long tiendichvu;
    public: 
        Vip();
        Vip(char *loai):Phong(loai){
            
        };
        void nhap();
        long long tinhtien();
        void xuat();
};
Phong::Phong(){
    
};
Vip::Vip(){

}
Phong::Phong(char *loai){
    strcpy(loaiphong,loai);
}


long long Phong::tinhtien(){
    long long dongia;
    if (strcmp(loaiphong,"B") == 0) dongia = phongB;
    else if (strcmp(loaiphong,"C") == 0) dongia = phongC;
    return songaythue * dongia;
}
void Phong::nhap(){
    cout << "Nhap So Ngay Thue"<<endl;
    cin >> songaythue;
    cin.ignore();
}
void Phong::xuat(){
    cout <<endl<<"Loai Phong "<< loaiphong<<endl;
    cout << "So Ngay THue "<<songaythue<<endl;
    cout << "Thanh Tien: "<<tinhtien()<<endl;
}
void Vip::nhap(){
    cout <<endl;
    cout << "Nhap So Ngay Thue ";
    cin >> songaythue;
    cout << "Nhap Tien Dich Vu: ";
    cin >> tiendichvu;
    cin.ignore();
    cout <<endl;
}
long long Vip::tinhtien(){
    if (songaythue > 5)
        return (tiendichvu + songaythue * phongA) * 0.9;
    else  (tiendichvu + songaythue * phongA);

}
void Vip::xuat(){
    cout << "Loai Phong: A"<<endl;
    cout << "So Ngay Thue "<<songaythue<<endl;
    cout << "Tien Dich Vu: "<<tiendichvu<<endl;
    cout << "Thanh Tien: "<<tinhtien()<<endl;
}
int main(){
    Phong *phong[100];
    for (int i = 0 ; i < 4; i++){
        cout << "Nhap Loai Phong"<<endl;
        char loai[2];
        cin.getline(loai,2);
        if (strcmp(loai,"A") == 0){
            Vip a;
            a.nhap();
            phong[i] = &a;
        }else{
            if (strcmp(loai,"B") == 0){
                Phong *b = new Phong("B");
                b->nhap();
                phong[i] = b;
            } else
                if (strcmp(loai,"C") == 0){
                    Phong *c = new Phong("C");
                    c->nhap();
                    phong[i] = c;
                } else cout << "Loai Phong Khong Nam Trong danh sach"<<endl;
        };
    }
    for (int i = 0; i < 4; i++){
        phong[i]->xuat();
    }
    
}