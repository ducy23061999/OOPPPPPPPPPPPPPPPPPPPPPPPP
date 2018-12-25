#include<iostream>
 using namespace std;
 
 class Mang
 {
 	private: int *a;
 	         int n;
 	public: void nhap();
	         void xuat();
			 int KT(Mang m);
			 Mang tong(Mang m);         
 };
 void Mang::nhap()
 {
 	cout<<"\n nhap so phan tu: ";
 	cin>>n;
 	a=new int[n];
 	cout<<"\n nhap cac phan tu mang:";
 	for(int i=0; i<n;i++)
       cin>>a[i];
 }
 void Mang::xuat()
 {
 	cout<<"\n mang can biet:";
 	for(int i=0; i<n;i++)
 	  cout<<a[i]<<" ";
 }
 int Mang::KT( Mang m)
 {
 	if(n!=m.n)
 	  return 0;
 	else
	  for(int i=0; i<n;i++)
	    if(a[i]!=m.a[i])
	        return 0;
	return 1;	   
 }
 Mang Mang::tong(Mang m)
 {  if(n!=m.n){
      cout<<"\n khong tinh duoc tong!"; 
      exit(1);
  	}
	   Mang b;
	   b.a=new int[n];
	   b.n=n;
 	   cout<<"\n tong hai mang:";
       for(int i=0;i<n;i++)
     	{
	    	b.a[i]=a[i]+m.a[i];
		}  
	return b;
 
 }
 int main()
 {
 	Mang a1,a2,a3;
 	a1.nhap();
 	a2.nhap();
 	a1.xuat();
 	a2.xuat();
 	a3=a1.tong(a2);
 
 	a3.xuat();
 	int k=a1.KT(a2);
 	if(k==0)
 	   cout<<"\n hai mang khong bang nhau!";
 	else 
	    cout<<"\n hai mang bang nhau!";   
	
	
	return 0;
// 	getch();    
 }
