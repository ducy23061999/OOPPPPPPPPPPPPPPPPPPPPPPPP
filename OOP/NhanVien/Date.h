#include <iostream>
using namespace std;
class Date{
    int ngay,thang,nam;
    public: Date(int ngay,int thang,int nam);
            void nhap();
            void xuat();  
            friend int maxDay(int thang, int nam);
            Date();
            int getNgay();
            int getThang();
            int getNam();
};
/* Implement Date 
 Bai Thay Tuan Dai Vl :(

*/
int maxDay(int thang ,int nam){
    int max;
    if (thang <= 0 && nam <= 0) return 0;
    switch (thang){
        case 1 : case 3 : case 5 : case 7: case 8: case 10: case 12:
            max = 31;
            break;
        case 4 : case 6: case 9: case 11:
            max = 30;
            break;
        case 2:
            if (nam % 4 == 0)
                max = 29;
            else max = 28;
            break;
    };
    return max;
    
}
Date::Date(int ngay, int thang, int nam){
    this->nam = (nam > 0) ? nam : 0;
    this->thang = (thang > 0 && thang <= 12) ? thang : 0;
    this->ngay = (ngay > 0 && ngay <= maxDay(this->nam,this->thang)) ? ngay : 0;
    if (nam == 0 || thang == 0 || nam == 0)
        cout << endl <<  "Throw Error Exception: Du Lieu Truyen Vao Bi Loi"<< endl;
}
Date::Date(){
    
}
void Date::nhap(){

    do{
        cout << endl << "Nhap nam: "<<endl;
        cin >> this->nam;
    }while(this->nam <= 0);

    do{
        cout << endl << "Nhap thang:"<<endl;
        cin >> this->thang;
    }while(this->thang <= 0 || this->thang > 12);

    do{
        cout << endl<< "Nhap ngay:" << endl;
        cin >> this->ngay;
    }while(this->ngay <= 0 || this->ngay > maxDay(this->thang,this->nam));

}
void Date::xuat(){
    cout << ngay <<"/"<< thang<<"/"<< nam;
}
int Date::getNgay(){
    return ngay;
}
int Date::getThang(){
    return thang;
}
int Date::getNam(){
    return nam;
}