#include <string.h>
#include <iostream>
using namespace::std;

struct Node{
	int Info;
	Node *Next;
};Node *F;
void BSDau(Node *&F,int x){
	Node *p = new Node;
	p->Info=x;
	p->Next=F;
	F=p;
}

void Swap(int &a,int &b)
{
	int x=a;a=b;b=x;
}
void BS(Node *&F)
{
	F=NULL;
	int x,n;
	cout<<"n = ";cin>>n;
	for(int i=1;i<=n;i++)
	{
		cout<<endl<<"x"<<i<<" = ";
		cin>>x;
		BSDau(F,x);
	}
}
void LietKe(Node *F)

{
	while(F!=NULL)
	{
		cout<<F->Info<<"  ";
		F=F->Next;
	}
}
int Tong();

void Sort(Node *F)
{
	if(F!=NULL&&F->Next!=NULL)
	{
		Sort(F->Next);
		if((F->Info)>(F->Next->Info))
		{
			Swap(F->Info,F->Next->Info);
			Sort(F->Next);
		}
	}
}
// cau 1: Tim so Node trong danh sach F co truong Info be hon so nguyen X cho truoc
void TimBeHonX_KDQ(Node *F,int X)
{
	int i=0;
	cout<<"X = "<<X<<endl;
	while(F!=NULL)
	{
		i++;
		if(F->Info < X)
		{
			cout<<"x"<<i<<" = "<<F->Info<<endl;
		}
		F=F->Next;
	}
}
void TimBeHonX_DQ(Node *F,int X,int i)
{
	if(F!=NULL)
	{
		if(F->Info < X)
		{
			cout<<"x"<<i<<" = "<<F->Info<<endl;
			TimBeHonX_DQ(F->Next,X,i+1);	
		}
		else
			TimBeHonX_DQ(F->Next,X,i+1);
	}
}
/* cau 2: Chen mot Node co gia tri truong Info bang X vao danh sach F
da duoc sap xep theo thu tu tang dan cua truong Info */
void Insert_KDQ(Node *&F,int X)
{
	Node *p=F;
	while(p!=NULL)
	{
		if(p->Next->Info>=X)
		{
			Node *q=new Node;
			q->Info=X;
			q->Next=p->Next;
			p->Next=q;
			return;	
		}
		p=p->Next;
	}
}
void Insert_DQ(Node *&F,int X)
{
	
}
//cau 3 Xoa mot Node co gia tri truong Info bang X trong danh sach F duoc sap xep theo thu tu tang dan
void Delete_KDQ(Node *&F,int X)
{
	Node *p=F;
	while(p!=NULL)
	{
		if(p->Next->Info>=X)
		{
			Node *q=p->Next;
			p->Next=q->Next;
			delete q;
			return;	
		}
		p=p->Next;
	}
}
void Delete_DQ(Node *&F,int X)
{

}
/*Cau 4: Tim max cua truong Info cua cac Node thuoc danh sach
F voi gia thiet rang danh sach F co it nhat mot Node(F khac NULL)*/
int Max_KDQ(Node *F)
{
	int Max=0;
	while(F!=NULL)
	{
		if(F->Info>Max)
			Max=F->Info;
		F=F->Next;
	}
	return Max;
}
int Max_DQ(Node *F)
{
	if(F==NULL)
		return -1;
	if(F->Info>Max_DQ(F->Next))
			return F->Info;
		else
			return Max_DQ(F->Next);
}
//cau 5 Bo sung mot Node moi co gia tri truong Info bang X vao cuoi danh sach
void BSCuoi_KDQ(Node *&F,int X)
{
	Node *p=F,*q = new Node;
	q->Info=X; q->Next=NULL;
	while(p->Next!=NULL)
		p=p->Next;
	p->Next=q;
}
void BSCuoi_DQ(Node *&F,int X)
{
	if(F->Next==NULL)
	{
		Node *p= new Node;
		p->Info=X;p->Next=NULL;
		F->Next=p; return;
	}
	else
		BSCuoi_DQ(F->Next,X);	
}
// cau 6 Xoa Node cuoi danh sach F
void XoaCuoi_KDQ(Node *&F)
{
	Node *p=F;
	while(p->Next->Next!=NULL)
		p=p->Next;
	p->Next=NULL;
}
void XoaCuoi_DQ(Node *&F)
{
	if(F->Next->Next==NULL)
		F->Next=NULL;
	else
		XoaCuoi_DQ(F->Next);
}
/* Cau 7
Tìm dia chi cua mot Node thuoc danh sách F có giá tri truong Info bang X (neu co), hoac tro ve giá tri NULL neu tìm không có, trong 2 truong hop sau:
	a) Danh sách F không duoc sap xep
	b) Danh sách F duoc sap xep theo thu tu tang dan cua truong Info.
*/
//cau a)
Node *TimDiaChi_KhongSapXep_KDQ(Node *F,int X)
{
	Node *p=F;
	while(p!=NULL)
	{
		if(p->Info==X)
			return p;
		else
			return NULL;
		p=p->Next;
	}
}
Node *TimDiaChi_KhongSapXep_DQ(Node *F,int X)
{
	if(F==NULL)
		return NULL;
	else
		if(F->Info==X)
			return F;
	else
		if(F->Info!=X)
			return TimDiaChi_KhongSapXep_DQ(F->Next,X);
}
//Cau 8: In gia tri cua truong Info cac Node cua danh sach F theo thu tu nguoc(tu Node cuoi den Node dau)
void InNguoc_DQ(Node *F)
{
	if(F!=NULL)
	{
		InNguoc_DQ(F->Next);
		cout<<F->Info<<" ";
	}
}
void InNguoc_KDQ(Node *F)
{
	int A[100],i=1,j;
	while(F!=NULL)
	{
		A[i]=F->Info;
		i++;
		F=F->Next;
	}
	for(j=i-1;j>=1;j--)
		cout<<A[j]<<" ";
}
/*Cau 9: Tao ra mot danh sách moi L (Node dau tro boi L) có du lieu truong Info lan
luot duoc sao chép tu danh sach F */
void Tao_danh_sach_L(Node *F,Node *&L)
{
	L=NULL;	Node *p=NULL;
	while(F!=NULL)
	{
		p=L;
		p = new Node;	
		p->Info=F->Info;
		F=F->Next;
		p=p->Next;
	}
}
int main()
{
	int X=5;
	BS(F);
	cout<<endl;
	//LietKe(F); cout<<endl; 
//	Sort(F);
	//TimBeHonX_KDQ(F,X);
	//TimBeHonX_DQ(F,X,1);
	//Insert_KDQ(F,4);
	//Delete_KDQ(F,4);
//	LietKe(F); cout<<endl;
	//cout<<Max_KDQ(F)<<" "<<Max_DQ(F)<<endl;
	//BSCuoi_KDQ(F,10);
	//XoaCuoi_DQ(F);
//	LietKe(F);cout<<endl;
//	InNguoc_KDQ(F);
	/*
	Node *q=TimDiaChi_KhongSapXep_DQ(F,2);
	if(q!=NULL)
		cout<<q->Info;
	else 
		cout<<"NULL";*/
	Node *L;
	Tao_danh_sach_L(F,L);
	//LietKe(L);
	cout<<L->Info;
	return 1;
}

