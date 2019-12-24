#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define KH KhachHang
#define L List
class KhachHang{
    char hoten[100];
    char diachi[200];
    int chisocu, chisomoi;
    public:
        KhachHang *next;
        KhachHang();
        void nhap();
        void nhaphoten();
        void xuat();
        char *getHoTen();
        char *getDiaChi();
        int getChiSoCu();
        int getChiSoMoi();
        int getChiSoTieuThu();
        long long TinhTien();

};
/* 
Implement Khach Hang
*/
KH::KH(){
    next = NULL;
}
void KH::nhap(){
    cout << "Nhap Dia Chi"<<endl;
    cin.getline(diachi,200);
    cout << "Nhap Chi So Cu: "<<endl;
    cin >> chisocu;
    cout << "Nhap Chi So Moi"<<endl;
    cin>>chisomoi;
}
void KH::nhaphoten(){
    cout << "Nhap Ho Ten Khach Hang: "<<endl;
    cin.getline(hoten,100); 
}
void KH::xuat(){
    cout <<"Ho Ten: "<< hoten<<endl;
    cout <<"Dia Chi:  "<<  diachi<<endl;;
    cout << "Chi So Cu: "<< chisocu<<endl;
    cout << "Chi So Moi: " << chisomoi<<endl;
}
char *KH::getHoTen(){
    return this->hoten;
}
char *KH::getDiaChi(){
    return this->diachi;
}
int KH::getChiSoCu(){
    return chisocu;
}
int KH::getChiSoMoi(){
    return chisomoi;
}
int KH::getChiSoTieuThu(){
    return abs(chisomoi - chisocu);
}
long long KH::TinhTien(){
    long dongia;
    int tieuthu = this->getChiSoTieuThu();
    if (tieuthu <= 50) dongia = 1000;
    else if (tieuthu <= 100) dongia = 1500;
            else dongia = 2000;
    return tieuthu * dongia;
}
/*
 List Manager
*/
class List{
    KhachHang *first;
    public:
    List();
    void Chen(KhachHang *node);
    void ChenCuoi(KhachHang *node);
    void nhap();
    void xuat();
    void XuatLonNhat();
};
L::L(){
    first = NULL;
}
void L::Chen(KhachHang *node){
    if (first == NULL) {
            first = node;
        }else{
            node->next = first;
            first = node;
        }
}
void L::ChenCuoi(KhachHang *node){
    KhachHang *p = first;
    if (first == NULL){
        first = node;
    }else{
        while(p->next != NULL){
            p = p->next;
        }
        p->next = node;
    }

}
void L::nhap(){
    do{
        KhachHang *node = new KhachHang();
        node->nhaphoten();
        if (strlen(node->getHoTen()) == 0) break;
        else {
            node->nhap();
            cin.ignore();
        }
        ChenCuoi(node);
    }while(1);
}
void L::xuat(){
    for (KhachHang *kh = first; kh != NULL; kh= kh->next){
        kh->xuat();
    }
}
void L::XuatLonNhat(){
    long long max = 0;
    for (KhachHang *kh = first; kh != NULL; kh= kh->next){
        if (max < kh->TinhTien()) max = kh->TinhTien();
    } 
    for (KhachHang *kh = first; kh != NULL; kh= kh->next){
        if (kh->TinhTien() == max){
            kh->xuat();
        }
    }
}
int main(){
    L ds;
    ds.nhap();
    cout << "Lon nhat"<<endl;
    ds.xuat();
    return 0;
}