#include "Date.h"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class NhanVien{
    public: 
        char hodem[100];
        char ten[10];
        Date ngaysinh;
        void nhap();
        void xuat();
};
void NhanVien::nhap(){
    ngaysinh.nhap();
    cout << endl << "Nhap Ho: "<< endl;
    cin.ignore();
    cin.getline(hodem,100);
    cin.ignore();
    cout << endl << "Nhap Ten: "<< endl;
    cin.getline(ten,20);
    cin.ignore();

}
void NhanVien::xuat(){
    cout << hodem << " | " << ten << "| Ngay Sinh: ";
    ngaysinh.xuat();
    cout << endl;
}

int main(){
    NhanVien nv[50];
    int n;
    cin >> n;
    for (int i = 0 ; i < n; i++){
        nv[i].nhap();
        cin.ignore();
    }
        
    

    for (int i = 0 ; i < n; i++){
        nv[i].xuat();
    }
}
