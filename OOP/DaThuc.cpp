#include <iostream>
using namespace std;
class DaThuc{
    int SoMu, A[100];
    public: void nhap();
            void xuat();
            DaThuc cong(DaThuc d);
            DaThuc tru(DaThuc d);
};
void DaThuc::nhap(){
    cout <<endl<<"Nhap n"<<endl;
    cin >> this->SoMu;
    cout << endl<<"Nhap cac phan tu cua mang"<<endl;
    for (int i =0 ; i < this->SoMu; i++){
        cin >> A[i];
    };
}
void DaThuc::xuat(){
    cout << "Result" <<endl;
   for (int i =0 ; i < this->SoMu; i++){
        cout << A[i]<<"x^"<<i<<" + ";
    } 
    cout << endl;
}
DaThuc DaThuc::cong(DaThuc d){
    DaThuc result;
    if (this->SoMu == d.SoMu){
        for (int i = 0; i < this->SoMu; i++){
            result.A[i] = this->A[i] + d.A[i];
        }
        result.SoMu = this->SoMu;
    }else 
        if (this->SoMu > d.SoMu){
            for (int i = 0; i < d.SoMu; i++){
                result.A[i] = this->A[i] + d.A[i];
            };
            for (int i = d.SoMu; i < this->SoMu; i++){
                result.A[i] = this->A[i];
            };
            result.SoMu = this->SoMu;
        }else if (this->SoMu < d.SoMu){
            for (int i = 0; i < this->SoMu; i++){
                result.A[i] = this->A[i] + d.A[i];
            };
            for (int i = this->SoMu; i < d.SoMu; i++){
                result.A[i] = d.A[i];
            };
            result.SoMu = d.SoMu;
        }
        return result;
}
DaThuc DaThuc::tru(DaThuc d){
    DaThuc result;
    if (this->SoMu == d.SoMu){
        for (int i = 0; i < this->SoMu; i++){
            result.A[i] = this->A[i] - d.A[i];
        }
        result.SoMu = this->SoMu;
    }else 
        if (this->SoMu > d.SoMu){
            for (int i = 0; i < d.SoMu; i++){
                result.A[i] = this->A[i] - d.A[i];
            };
            for (int i = d.SoMu; i < this->SoMu; i++){
                result.A[i] = this->A[i];
            };
            result.SoMu = this->SoMu;
        }else if (this->SoMu < d.SoMu){
            for (int i = 0; i < this->SoMu; i++){
                result.A[i] = this->A[i] - d.A[i];
            };
            for (int i = this->SoMu; i < d.SoMu; i++){
                result.A[i] = d.A[i];
            };
            result.SoMu = d.SoMu;
        }
        return result;
}
int main(){
    DaThuc a,b;
    a.nhap();
    b.nhap();
    DaThuc c =  a.cong(b);
    c.xuat();
    return 0;
}