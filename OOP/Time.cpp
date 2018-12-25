#include <iostream>
using namespace std;
class Time{
    int gio, phut,giay;
    public: void nhap();
            void xuat();
            Time tong(Time t);
};
void Time::nhap(){
    bool ktra;
    do{
        cout << "\nGio - phut - giay"<< endl;
        cin >> gio >> phut >> giay;
        if (gio >= 0 && gio < 24 && phut >= 0 && phut <60 && giay >= 0 && giay < 60){
             
             ktra = false;
        }
        else {
            cout << "So Nhap Khong Hop Le\n";
            ktra = true;
        }
            
    }while(ktra);
      
}
void Time::xuat(){
    cout << gio << " gio " << phut << " phut " << giay << " giay"<<endl;
}
Time Time::tong(Time t){
    Time result;
    int nho;
    result.giay = (t.giay + giay) % 60;
    nho = (t.giay + giay) / 60;
    result.phut = (t.phut + phut + nho) % 60;
    nho = (t.phut + phut + nho) / 60;
    result.gio = (t.gio + gio + nho) % 24;  
    return result;
}
int main(){
    Time a,b,c;
    a.nhap();
    b.nhap();
    c = a.tong(b);
    c.xuat();
    return 0;
}