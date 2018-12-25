#include<stdio.h>
#include<iostream>
using namespace std;
class sinhvien{
    private:
        char *hoten;
        int namsinh;
        float diemtrungbinh;
    public:
        sinhvien *next;
        sinhvien();
        sinhvien(char *ht,int ns,float dtb);
        char *layhoten();
        int laynamsinh();
        float laydiem();
        void nhap();
        void xuat();
        void update(char *ht,int ns,float dtb);
        friend class quanly;
};
sinhvien::sinhvien(){
    hoten=NULL;
    namsinh=0;
    diemtrungbinh=0;
    next=NULL;
}
sinhvien::sinhvien(char *ht,int ns,float dtb){
    hoten=new char[strlen(ht)+1];
    strcpy(hoten,ht);
    namsinh=ns;
    diemtrungbinh=dtb;
    next=NULL;
}
char *sinhvien::layhoten(){
    return hoten;
}
int sinhvien::laynamsinh(){
    return namsinh;
}
float sinhvien::laydiem(){
    return diemtrungbinh;
}
void sinhvien::update(char *ht,int ns,float dtb){
    hoten=new char[strlen(ht)+1];
    strcpy(hoten,ht);
    namsinh=ns;
    diemtrungbinh=dtb;
}
 void sinhvien::xuat(){
     cout << " ----Thong Tin Cua Sinh Vien -----"<<endl;
     cout<<"Ho Va Ten : ";cout<<hoten<<endl;
     cout<<"Nam Sinh : ";cout<<namsinh<<endl;
     cout<<"Diem Trung Binh : "<<diemtrungbinh<<endl;
     cout<<"------------------------------------"<<endl;
 }
class quanly{
    private:
        sinhvien *first;
    public:
        quanly();
        void nhap();
        void hienthi();
        void sapxep();
        int kiemtra();
        sinhvien *topsinhvien();
};
int quanly::kiemtra(){
sinhvien *p,*q;
     for(p=first;p->next!=NULL;p=p->next)
        for(q=p->next;q!=NULL;q=q->next){
        	if(p->laydiem()<q->laydiem())
        		return 1;
		}
			return 0;
}
quanly::quanly(){
	first=NULL;
}
void quanly::nhap(){
         char *ht;
         int ns;
         float dtb;
     ht=new char[30];
     sinhvien *p;
     do {
     cout<<"Nhap Ho Ten Sinh Vien : ";fflush(stdin);
     gets(ht);
     if(strlen(ht)!=0){
         cout<<"Nhap Nam Sinh : "; cin>>ns;
         cout<<"Nhap diem trung binh : "; cin>>dtb;
         p=new sinhvien(ht,ns,dtb);
         p->next=first;
         first=p;
    	 }
     }while (strlen(ht)!=0);
 }
 void quanly::hienthi(){
     sinhvien *p;
     p=first;
     while(p!=NULL){
         p->xuat();
         p=p->next;
     }
 }
 void quanly::sapxep(){
     sinhvien *p,*q;
     for(p=first;p->next!=NULL;p=p->next)
        for(q=p->next;q!=NULL;q=q->next)
            if(p->laydiem()<q->laydiem()){
                sinhvien *tam=new sinhvien(p->layhoten(),p->laynamsinh(),p->laydiem());
                p->update(q->layhoten(),q->laynamsinh(),q->laydiem());
                q->update(tam->layhoten(),tam->laynamsinh(),tam->laydiem());
            }
 }
 sinhvien *quanly::topsinhvien(){
 	sinhvien *p;
 	p=first;
 	int luu=0;
 	float max=0;
 	while(p!=NULL){
 		if(p->laydiem()>max)
 			max=p->laydiem();
 			luu=p->laydiem();
 	
	 }
     for (sinhvien *q = first; q != NULL; q = q->next){
         if (q->laydiem() == max){
             return q;
         }
     }
	 return q;
 }
 int main(){
     char *ht;
     ht=new char[30];
     quanly ql;
     sinhvien *n;
     n=new sinhvien;
     ql.nhap();
     cout<<"Danh Sach Nhan Vien Sau Khi Nhap !"<<endl;
     ql.hienthi();
     cout<<"Sinh Vien Co Diem Trung Binh Cao Nhat la :"<<endl;
   //  n=ql.topsinhvien();
    if(ql.kiemtra()!=1)
    	ql.sapxep();
    cout<<"Danh Sach Sinh Vien Sau Khi Sap Xep!"<<endl;
    ql.hienthi();
 }