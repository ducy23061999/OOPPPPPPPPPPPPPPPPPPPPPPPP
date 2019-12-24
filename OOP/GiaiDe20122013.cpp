#include <iostream>
using namespace std;
class NhanVien{
    private:
        char *manv;
        char *tennv;
        int sodt;
    public:
        NhanVien *next;
        void xuat();
        NhanVien();
        NhanVien(char manv[20],char tennv[200], int sodt);
        char * getManv();
        char * getTennv();
        int getSodt();
        void SetNhanVien(char manv[20],char tennv[200], int sodt);
};
NhanVien::NhanVien(){
    this->next = NULL;
}
NhanVien::NhanVien(char manv[20],char tennv[200], int sodt){
    this->manv = new char[strlen(manv) + 1];
    this->tennv = new char[strlen(tennv) + 1];
    strcpy(this->manv, manv);
    strcpy(this->tennv, tennv);
    this->sodt = sodt;
    this->next = NULL;
}
char *NhanVien::getManv(){
    return this->manv;
}
char *NhanVien::getTennv(){
    return this->tennv;
}
int NhanVien::getSodt(){
    return this->sodt;
}
void NhanVien::xuat(){
    cout << "Ma: "<< manv<<endl;
    cout << "Ten: "<< tennv<<endl;
    cout << "SDT: "<< sodt<<endl;
}
void NhanVien::SetNhanVien(char manv[20],char tennv[200], int sodt){
    this->manv = new char[strlen(manv) + 1];
    this->tennv = new char[strlen(tennv) + 1];
    strcpy(this->manv, manv);
    strcpy(this->tennv, tennv);
    this->sodt = sodt;
}
class DanhBa{
    NhanVien *first;
    public:
        DanhBa();
        void nhap();
        void xuat();
        void sapxep();
        NhanVien *timkiem(char masv[20]);
};
DanhBa::DanhBa(){
    first = NULL;
}
void DanhBa::nhap(){
    char ma[20];
    char ten[200];
    int sdt;
    do{
        cout << "Nhap Ma SV: ";
        cin.getline(ma,20);
        
        if (strlen(ma) == 0) break;
        cout << "Nhap Ten SV :";
        cin.getline(ten,200);
        cout << "Nhap so dt: ";
        cin>>sdt;
        cin.ignore(1);
        NhanVien *node = new NhanVien(ma,ten,sdt);
        if (first == NULL){
            first = node;
        }else{
            node->next = first;
            first = node;
        };
    }while(1);
}
void DanhBa::xuat(){
    NhanVien *p = first;
    while(p != NULL){
        p->xuat();
        p = p->next;
    }
}
void DanhBa::sapxep(){
    
    for(NhanVien *p  = first; p != NULL; p = p->next)
        for(NhanVien *q = p->next; q != NULL; q = q->next)
        {
            if (strcmp(p->getManv(),q->getManv()) > 0){
                NhanVien temp;
                temp.SetNhanVien(p->getManv(),p->getTennv(),p->getSodt());
                p->SetNhanVien(q->getManv(),q->getTennv(),q->getSodt());
                q->SetNhanVien(temp.getManv(),temp.getTennv(),temp.getSodt());
            }
        }
    
    
}
int main(){
    DanhBa db;
    db.nhap();
    db.xuat();
    db.sapxep();
    cout << "Da Sap Xep"<<endl;
    db.xuat();
    return 0;
}