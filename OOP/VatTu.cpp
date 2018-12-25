#include <iostream>
using namespace std;
class VatTu{
     char *mavt;
     char *tenvt;
     int soluong;
     public: 
        VatTu *next;
        VatTu();
        VatTu(char *ma,char *ten, int soluong);
        char *getMa();
        char *getTen();
        int getSoluong();
};
VatTu::VatTu(){
    next = NULL;
}
VatTu::VatTu(char *ma, char *ten, int soluong){
    mavt = new char[strlen(ma) + 1];
    ten = new char[strlen(ten) + 1];
    this->soluong = soluong;
    mavt = strcpy(mavt,ma);
    tenvt = strcpy(tenvt,ten);
    next = NULL;
}
char* VatTu::getMa(){
    return mavt;
}
char* VatTu::getTen(){
    return tenvt;
}
int VatTu::getSoluong(){
    return soluong;
}
class List{
    VatTu *first;
    public:
    List();
    void BoSung(VatTu *vt);
    void nhap();
    void xuat();
    VatTu *find(char *ma);
};
List::List(){
    first = NULL;
}
void List::BoSung(VatTu *vt) {
    if (first == NULL){
        first = vt;
    }else{
        vt->next = first;
        first = vt;
    }
}
void List::xuat(){
    for (VatTu *p = first; p != NULL; p = p->next){
        cout << p->getMa();
        cout << p->getTen();
        cout << p->getSoluong();
    }
}
VatTu* List::find(char *ma){
    for (VatTu *p = first; p != NULL; p = p->next){
        if (strcmp(p->getMa(),ma) == 0)
        return p;

    }
    return NULL;
}

void List::nhap(){
    do{
        char ma[10];
        char ten[100];
        int soluong;
        cin.getline(ma,10);
        if (strlen(ma) == 0) break;
        cin.getline(ten,100);
        cin >> soluong;
        cin.ignore(1);
        VatTu *node = new VatTu(ma,ten,soluong);
        this->BoSung(node);

    }while(true);
    
    
}
int main(){
    List l;
    l.nhap();
    l.xuat();
}