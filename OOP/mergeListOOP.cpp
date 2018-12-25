#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class DanhMuc{
    char nhande[1000], tacgia[50];
    protected:
        int tk;
    public:
        virtual void nhap();
        virtual void xuat();
};
class BaiBao: public DanhMuc{
    char tentapchi[1000];
    int sotapchi;
    public:
        void nhap();
        void xuat();
};
class Sach : public DanhMuc{
    char nxb[1000];
    int version;
    public:
        void nhap();
        void xuat();
};
void DanhMuc::nhap(){
    cout << "Nhap nhan de:"<<endl;
    cin.getline(nhande,1000);
    
    cout << "Nhap Tac gia: "<<endl;
    cin.getline(tacgia,50);
    cout << "Nhap lan tham khao:"<<endl;
    cin >> tk;
    cin.ignore();
}
void DanhMuc::xuat(){
    cout <<"Nhan de: "<< nhande<<endl;
    cout <<"Tac Gia: " << tacgia << endl;
    cout << "So lan tham khao: "<<tk<<endl;

}
void BaiBao::xuat(){
    DanhMuc::xuat();
    cout << "Ten Tap Chi: "<<tentapchi<<endl;
    cout << "So tap chi: "<< sotapchi << endl; 
}
void BaiBao::nhap(){
    DanhMuc::nhap();
    cout << "Nhap ten tap chi "<<endl;
    cin.getline(tentapchi,1000);
    cout << "Nhap so tap chi"<<endl;
    cin >> sotapchi;
}
void Sach::nhap(){
    DanhMuc::nhap();
    cout << "Nhap nxb "<<endl;
    cin.getline(nxb,1000);
    cout << "Nhap version"<<endl;
    cin >> version;
}
void Sach::xuat(){
    DanhMuc::xuat();
    cout << "NXB: "<<nxb<<endl;
    cout << "Version: "<< version << endl; 
}
int main(){
    DanhMuc *a[50];
    for (int i = 0 ; i < 2; i++){
        int status;
        cout << "Nhap trang thai: ";
        cin >> status;
        cin.ignore();
        if (status == 1){
            BaiBao *p = new BaiBao;
            p->nhap();
            a[i] = p;

        }else if (status == 2){
            Sach *p = new Sach;
            p->nhap();
            a[i] = p;
        }
    }
    for (int i = 0 ; i < 2; i++){
        a[i]->xuat();
    }
    return 0;
}