#include <iostream>
using namespace std;
#define MAX 6;
class HinhTron{
    int x,y;
    float R;
    public: 
        HinhTron *next;
        HinhTron();
        HinhTron(int x,int y, float R);
        void nhap();
        void xuat();
        int getX();
        int getY();
        void setAllProperties(int x, int y, float R);
        float getR();
};
class QuanLi{
    HinhTron *first;
    public:
        void nhap();
        void sapxep();
        HinhTron *timkiem();
        QuanLi();
        void in();
};
/*
 - Implement Hinh Tron
 - Hate this shit :(

*/
HinhTron::HinhTron(){
    this->next = NULL;
}
HinhTron::HinhTron(int x, int y, float R){
    this->x = x;
    this->y = y;
    this->R = R;
}
void HinhTron::nhap(){
    cout << "Nhap toa do dinh x , y va R "<< endl;
    cin >> x >> y >> R;
}
void HinhTron::xuat(){
    cout << "("<< x<<","<<y<<")"<<"=> R: "<<R << endl;
}
int HinhTron::getX(){
    return x;

}
int HinhTron::getY(){
    return y;
}
float HinhTron::getR(){
    return R;
}
void HinhTron::setAllProperties(int x, int y, float R){
    this->x = x;
    this->y= y;
    this->R = R;
}

/*
 - Implement Quan Li

*/
QuanLi::QuanLi(){
    first = NULL;
}
void QuanLi::nhap(){
    int dem = 0;
    do{
        if (dem == 3) break;
        HinhTron *node = new HinhTron();
        node->nhap();
        if (first == NULL)
        {
            first = node;
        }else{
            node->next = first;
            first = node;
        };

        dem++;
    } while(true);
};
void QuanLi::in(){
    
    for(HinhTron *q = this->first; q != NULL; q = q->next)
    {
        q->xuat();
    }
    
}
void QuanLi::sapxep(){
    for(HinhTron *q = this->first; q != NULL; q = q->next)
        for(HinhTron *p = q->next; p != NULL; p = p->next)
        {
            // sap xep giam dan theo toa do x. 
            if (q->getX() < p->getX()){
            
                // temp = q;
                // HinhTron temp(q->getX(),q->getY(),q->getR());
                // // q = p
                // q->setAllProperties(p->getX(),p->getY(),p->getR());
                // // p = temp;
                // p->setAllProperties(temp.getX(),temp.getY(),temp.getR());
                HinhTron temp= *(p);
                *p = *q;
                *q = temp;
            }
        }
}

int main(){
    
    QuanLi q;

    q.nhap();
    cout << "IN"<< endl;
    q.in();
    cout << "Sap Xep"<< endl;
    q.sapxep();
    q.in();
    return 0;
}