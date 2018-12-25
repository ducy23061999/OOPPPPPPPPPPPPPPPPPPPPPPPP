#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
//#define n 5
class Diem
{     private: int *a;
                int n;
      public: void nhap();
              void xuat();
              Diem tong(Diem m);
//              float KhoangCach(Diem m);
            
	
};
void Diem::nhap()
{  // int n;
	cout<<"\n nhap so chieu n:";
	cin>>n;
	a=new int[n];
	cout<<"\n nhap toa do diem:";
	for(int i=0;i<n;i++)
	  cin>>a[i];
}
void Diem::xuat()
{
   cout<<"\n Diem can biet: ";
   for(int i=0;i<n;i++)
     cout<<a[i]<<" ";	
}
Diem Diem::tong(Diem m)
{   if(n!=m.n)
       {  cout <<"\nkhong the tinh tong";
		 // return NULL;
		 exit(1);
		  }
    else{
	
	Diem b;
	cout<<"\n tong hai diem: ";
    b.n=n;
	// b.a=new int[n];
	for(int i=0;i<n;i++)
	  b.a[i]=a[i]+m.a[i];
	return b;  
}}
int main()
{
	Diem a1,a2,a3;
/*	int n;
	cout<<"\n nhap n: ";
	cin>>n;
	cout<<"\n nhap diem:";
*/	a1.nhap();
	a2.nhap();
	a1.xuat();
	a2.xuat();
	a3=a1.tong(a2);
	a3.xuat();
	return 0;
}
