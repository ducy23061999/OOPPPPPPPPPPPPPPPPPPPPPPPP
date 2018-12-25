#include <iostream>
using namespace std;
class Chuoi{
    char *st;
    int n;
    public:
        Chuoi();
        Chuoi(char *st);
        void nhap();
        void xuat();
};
Chuoi::Chuoi(){
    
};
Chuoi::Chuoi(char *st){
    this->st = new char[strlen(st)];
    strcpy(this->st,st);
};
void Chuoi::nhap(){
    cout << "Nhap n toi da co the chua "<<endl;
    cin >> n;
    cin.ignore(1);
    cout << "Nhap Chuoi: ";
    this->st = new char[n];
    cin.getline(this->st,n); 
}
void Chuoi::xuat(){
    cout << st;
}
int main(){
    Chuoi a;
    a.nhap();
    a.xuat();
};