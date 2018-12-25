#include<iostream>
#include<string>
using namespace std;

class Information
{
    public:
        char *ho_ten = new char[30];
        int m_day;
        int m_month;
        int m_year;
        int tuoi;
        
    public:
        Information(char *hoten, int day, int month, int year, int t)
        {
            cout<<"Constructor called"<<endl;
            ho_ten=hoten;
            m_day=day;
            m_month=month;
            m_year=year;
            tuoi=t;
        }
    ~Information()
        {
            cout<<"Destructor called for Information Friends"<<endl;
        }
        virtual void Display()
        {
            cout<<"Information Friends"<<endl;
            cout<<"Ho ten ban be: "<<this->ho_ten<<endl;
            cout<<"Ngay sinh: "<<this->m_day<<"/"<<this->m_month<<"/"<<this->m_year<<endl;
            cout<<"Tuoi: "<<this->tuoi<<endl;
        }
};

class SinhVien: public Information
{
    public:
        char MAsv[20];
    
    public:    
    SinhVien(char *hoten, int day, int month, int year, int t,char MA[20]) : Information(hoten, day, month, year, t)
        {
            
            strcpy(MA,MAsv);
           
        }
    ~SinhVien()
        {
            cout<<"Destructor called for Information Friends"<<endl;
        }
    void Display()
        {
            cout<<"Information Friends"<<endl;
            cout<<"Ho ten ban be: "<<this->ho_ten<<endl;
            cout<<"Ma Sinh Vien: "<<this->MAsv<<endl;
            cout<<"Ngay sinh: "<<this->m_day<<"/"<<this->m_month<<"/"<<this->m_year<<endl;
            cout<<"Tuoi: "<<this->tuoi<<endl;
        }    
};
int main()
{
    char hoten[]="Vo Van Manh Tien";
    int day=2, month=4, year=1999;
    int t=15;
    Information banbe(hoten, day, month, year, t);
    banbe.Display();
    char MA[]="17T1021273";
    SinhVien sv(hoten, day, month, year, t,MA);
    sv.Display();
    
}
