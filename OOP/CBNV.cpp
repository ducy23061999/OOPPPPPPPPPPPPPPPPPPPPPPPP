#include <iostream>
using namespace std;
#define xx cout<<
class CanBo
{
private:
    char hoten[200];
    char ngaysinh[20];
    char KhoaPhong[100];
    

public:
    CanBo();
    ~CanBo();
    void NhapCB();
    void XuatCB();
    virtual bool tinhSoGio();
};

CanBo::CanBo()
{
}

CanBo::~CanBo()
{
}
void CanBo::NhapCB(){
    cout << "Nhap ten: "<<endl;
    cin.getline(hoten,200);
    cout << "Nhap Ngay Sinh: "<<endl;
    cin.getline(ngaysinh,200);
    cout << "Nhap Khoa Phong: "<<endl;
    cin.getline(KhoaPhong,100);
}
void CanBo::XuatCB(){
    cout <<hoten<<endl;
    xx ngaysinh<<endl;
    xx KhoaPhong<<endl;
}
bool CanBo::tinhSoGio(){
    return 0;
}
class HanhChinh: public CanBo{
    int GioHanhChinh;
    public:
        void NhapHC();
        void XuatHC();
         bool tinhSoGio();
};
void HanhChinh::NhapHC(){
    NhapCB();
    xx "Nhap so gio hanh chinh: ";
    cin>>GioHanhChinh;
    cin.ignore(1);
}
void HanhChinh::XuatHC(){
    XuatCB();
    xx GioHanhChinh;
    xx endl;
}
bool HanhChinh::tinhSoGio(){
    
    if (GioHanhChinh > 700) {
        return 1;
    }
    return 0;    
}
class GiangDay: public CanBo{
    int GioGiangDay;
    public:
        void NhapGD();
        void XuatGD();
        bool tinhSoGio();
};
void GiangDay::NhapGD(){
    NhapCB();
    xx "Nhap So Gio Giang Day"<<endl;
    cin >> GioGiangDay;
    cin.ignore(1);
}
void GiangDay::XuatGD(){
    XuatCB();
    xx GioGiangDay;
    xx endl;
}
bool GiangDay::tinhSoGio(){
    if (GioGiangDay >= 280) {
        return 1;
    }
    return 0;
}
int main(){
    CanBo *DS[100];
    cout <<"Nhap so can bo: ";
    int n;
    cin >> n;
    cin.ignore(1);
    cout << "Loai Can Bo: "<<endl;
    cout << "1: Hanh Chinh"<<endl;
    cout << "2: Giang Day"<<endl;
    for(int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        cin.ignore(1);
        if (type == 1){
            HanhChinh *hc = new HanhChinh();
            hc->NhapHC();
            DS[i] = hc;
        }
        if (type == 2){
            GiangDay *gd = new GiangDay();
            gd->NhapGD();
            DS[i] = gd;
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        if (DS[i]->tinhSoGio()){
            HanhChinh *hc = (HanhChinh *)DS[i];
            hc->XuatHC();
        }
    }
    
    
}