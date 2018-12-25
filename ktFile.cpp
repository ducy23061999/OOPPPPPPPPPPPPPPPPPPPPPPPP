#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
class mytime
{
	int h,m,s;
	public:
		mytime()
		{	h=m=s=0;
		}
		void nhap_time()
		{
			do
			{
				cout<<"Nhap gio, phut, giay:"; cin>>h>>m>>s;
		    }while(h<0||h>24||m<0||m>60||s<0||s>60);
		}
		void xuat_time()
		{
			cout<<(h<10?"0":"")<<h<<":"<<(m<10?"0":"")<<m<<":"<<(s<10?"0":"")<<s<<endl;
		}
};
class mydate
{
	int d,m,y;
	public:
		mydate()
		{	d=m=y=0;
		}
		int nhuan()
		{
			if((y%4==0 && y%100!=0)&&y%400==0)
				return 1;
			return 0;
		}
		int ngaythang()
		{
			if(m==4||m==6||m==9||m==11)
				return 30;
			else if(m==2)
					return 28+nhuan();
				 else return 31;
		}
		void nhap_date()
		{	int s=ngaythang();
			do
			{
				cout<<"Nhap ngay, thang, nam:"; cin>>d>>m>>y;
			}while(d<0||d>s||m<0||m>12||y<0);
		}
		void xuat_date()
		{
			cout<<d<<"/"<<m<<"/"<<y<<endl;
		}
};
class myfile:public mytime, public mydate
{
	char *filename;
	int filesize, n;
	public:
		myfile()
		{	filename=NULL; 
		}
		myfile(char *fn, int fs)
		{
			filename=new char[strlen(fn)+1];
			strcpy(filename, fn);
			filesize=fs;
		}
		char *getfn()
		{	return filename;
		}
		int getfs()
		{	return filesize;
		}
		void nhap_file()
		{
			cout<<"Nhap ten file:"; fflush(stdin); gets(filename);
			cout<<"Nhap kich thuoc:"; cin>>filesize;
		}
		void xuat()
		{
			cout<<"\nTen file:"<<getfn();
			cout<<"\nKich thuoc file:"<<getfs();
			xuat_time();
			xuat_date();
		}
		void operator > (myfile fs2)
		{
			if(getfs()>fs2.getfs())
				cout<<getfs()<<"lon hon";
			else cout<<fs2.getfs()<<"lon hon";
		}
};
int main()
{
	
	myfile *DS = new myfile[10]; 
	int n;
	cout<<"Nhap so file: "; 

	cin >> n;
	cout << "Fucking this bug ";
	for(int i=0; i<n; i++)
	{
		DS[i]->nhap_file();
		DS[i]->nhap_time();
		DS[i]->nhap_date();
	}
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(DS[i]->getfs() < DS[i]->getfs())
			{
				myfile *tam=DS[i];
				DS[i]=DS[j];
				DS[j]=tam;
			}
	for(int i=0; i<n; i++)
		DS[i]->xuat();
	return 0;
}
