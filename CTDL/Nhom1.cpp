#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
struct Nut
		{
			char Tu[7];
			Nut *Tiep;
		};
Nut *TD[26];

//Cau 1: Khoi tao tu dien tu file TD.D�T
void KhoiTao()
{
	for (int i=0;i<26;i++)
		TD[i]=NULL;		// Khoi tao cac gia tri bang NULL
	FILE *File;
	File = fopen("TD.DAT","rt");	// Mo file TD.DAT
	char s[7];
	while (fscanf(File,"%s",s)>0)		// Doc chuoi tu file vao bien s , ham fscanf se tra ve gia tri la -1 neu con tro o cuoi file 
	{
		Nut *p= new Nut,
		*q = TD[s[0]-'A'];	//Xac dinh phan tu TD[i] de luu cho dung van, vi du: s la tu AN thi TD[s[0]-'A'] = TD[0]
		strcpy(p->Tu,s);
		p->Tiep = NULL;
		if (q==NULL)	//Neu van nay ko co tu nao
			TD[s[0]-'A'] = p;	//thi bo sung vao
		else
		{	//con ko thi duyet den nut cuoi cua van nay roi chen vao cuoi
			while (q->Tiep!=NULL) 	q=q->Tiep;
			q->Tiep = p;
		}
	}
	cout<<"Nhap du lieu thanh cong!"<<endl;
	fclose(File);	//Dong file
}

void GhiTD()
{
	for (int i=0;i<26;i++)
	{
		Nut *p = TD[i];
		while (p!=NULL)
		{
			cout<<"-->"<<p->Tu;
			p=p->Tiep;
		}
		cout<<endl;
	}
}

//Cau 2: Liet ke cac tu phu hop voi noi dung tim kiem trong tu dien 
void LietKe()
{
	char c;
	cout<<"Go vao 1 ky tu : ";
	fflush(stdin);
	c = getchar();
	Nut *p = TD[c-'A'];	//Xac dinh TD[i], danh sach van muon liet ke, vi du: go vao B thi TD[c-'A'] = TD[1] vi B co ma asccii la 66, A co ma ascii la 65
	while (p!=NULL)
	{
		cout<<p->Tu<<endl;
		p=p->Tiep;
	}
	cout<<endl;
}

//Kiem tra tu da co trong tu dien hay chua
Nut *KiemTra(char s[7])
{	//Cau nay sao ko xac dinh van i = s[0] roi tim trong TD[i] thoi cho nhanh
	for (int i=0;i<26;i++)	//duyet tung van
	{
		Nut *p = TD[i];
		while (p!=NULL)
		{
			if (strcmp(s,p->Tu)==0) return p;	//Neu 1 tu trong tu dien = vs tu kiem tra thi return nut chua tu nay
			p=p->Tiep;
		}
	} //duyet den cuoi van ko tim thay thi tra ve NULL
	return NULL;
}

//Cau 3: Bo sung mot tu da nhap vao trong tu dien, neu co roi thi in ra tu nay da co trong tu dien  
void BoSung()
{
	char s[7];
	cout<<"Go tu can bo sung  : ";
	cin>>s;
	if (KiemTra(s)!=NULL)
		cout<<"Tu nay da co trong tu dien!"<<endl;
	else
	{
		Nut *p= new Nut,*q = TD[s[0]-'A'];
		strcpy(p->Tu,s);
		if (q==NULL)	//Neu van nay ko co tu nao thi bo sung
		{
			p->Tiep = NULL;
			TD[s[0]-'A'] = p;
		}
		else
		{
			if (strcmp(q->Tu,s)>0)	//Neu tu nay nho hon tu dau tien cua danh sach van thi bo sung dau. vi du: s="AN" < q->Tu="ANH"
			{
				p->Tiep = q;
				TD[s[0]-'A'] = p;
			}
			else
			{	//con ko duyet de tim vi tri de chen vao sao cho van dam bao su tang dan. Neu tu tiep sau q >= tu s thi dung, hoac den nut cuoi cung thi dung
				while ((q->Tiep!=NULL)&&(strcmp(q->Tiep->Tu,s)<0)) q=q->Tiep;
				if (q->Tiep == NULL)	//Neu q dang tro den nut cuoi cung thi bo sung cuoi tu moi
				{
					p->Tiep = NULL;
					q->Tiep = p;
				}
				else	//con ko thi chen tu nay vao vi tri thich hop de dam bao su tang dan
				{
					p->Tiep = q->Tiep;
					q->Tiep = p;
				}
			
			}
		}
	cout<<"Bo sung tu thanh cong!"<<endl;	
	}
}

//Cau 4: Xoa mot tu trong tu dien
void XoaTu()
{
	char s[7];
	cout<<"Go vao tu can xoa : ";
	cin>>s;
	Nut *p = KiemTra(s);
	if (!p)
		cout<<"Tu nay khong co trong tu dien!"<<endl;
	else
	{
		Nut *q = TD[s[0]-'A'];	//xac dinh TD[i]: danh sach van chua tu can xoa
		if (q == p)	//Neu tu can xoa nam dau danh sach thi xoa dau
		{
			TD[s[0]-'A']=p->Tiep;
			delete q;
		}
		else
		{
			if (p->Tiep==NULL)	//Neu tu can xoa nam cuoi danh sach thi xoa cuoi
			{
				while (q->Tiep!=p)	q=q->Tiep;
				q->Tiep = NULL;
				delete p;
			}
			else
			{
				while (q->Tiep!=p)	q=q->Tiep;
				q->Tiep = p->Tiep;
				delete p;		
			}
		}
		cout<<"Da xoa tu thanh cong!"<<endl;
	}
}

//Cau 5: Cap nhap tu dien tu mot file van ban DATA.DAT
void CapNhat()
{
	FILE *File;
	File = fopen("DATA.DAT","rt");	//Mo file muon cap nhat
	char s1[7] = {};	//khoi tao mot chuoi rong
	while (fscanf(File,"%s",s1)>0)	//Doc tu file mot chuoi, dung khi gap khoan trang, roi luu vao chuoi s1
	{
		char s[7];						
		int j=0;
		//Chuan hoa, xoa bot cac ky tu thua
		for (int i=0;i<(int)strlen(s1);i++)	//Duyet tung ky tu cua chuoi s1
			if ((s1[i]>='A')&&(s1[i]<='Z'))	//Neu la ky tu chu cai thi luu vao chuoi s
				s[j++] = s1[i];
		s[j] = '\0';
		if (KiemTra(s)==NULL)	//Kiem tra tu nay co trong TD chua, = NULL tuc la chua co
		{	
			Nut *p= new Nut,*q = TD[s[0]-'A'];	//xac dinh danh sach van de luu tu nay vao
			strcpy(p->Tu,s);
			if (q==NULL)	//Neu danh sach van nay ko co tu nao thi TD[i] = p
			{
				p->Tiep = NULL;
				TD[s[0]-'A'] = p;
			}
		else
		{	//Neu tu doc duoc nho hon tu dau tien trong danh sach van thi bo sung dau
			if (strcmp(q->Tu,s)>0)
			{
				p->Tiep = q;
				TD[s[0]-'A'] = p;
			}
			else
			{	//ko thi tim vi tri de chen vao sao cho van dam bao su tang dan
				while ((q->Tiep!=NULL)&&(strcmp(q->Tiep->Tu,s)<0)) q=q->Tiep;
				if (q->Tiep == NULL)	//Neu duyet den nut cuoi thi bo sung cuoi
				{
					p->Tiep = NULL;
					q->Tiep = p;
				}
				else
				{	//con ko thi bo sung vao vi tri thich hop
					p->Tiep = q->Tiep;
					q->Tiep = p;
				}
			
			}
		}
		}
	cout<<"Cap nhat du lieu thanh cong!"<<endl;
	}
}

//Cau 6: Luu tu dien vao file TD.DAT
void LuuTD()
{
	FILE *File;
	File = fopen("TD.DAT","w"); //mo file de luu
	for (int i=0;i<26;i++)	//duyet tung van
	{
		Nut *p = TD[i];
		while (p!=NULL)	//duyet tu dau den cuoi danh sach van
		{
			fprintf(File,"%s\n",p->Tu);	//ghi tung tu vao file
			p=p->Tiep;
		}
	}
	cout<<"Luu du lieu thanh cong!"<<endl;
	fclose(File);
}

int main()
{
	//Tao menu chuong trinh
	while (1)
	{
		
		cout<<endl<<"----------------QUAN LY TU DIEN-------------------"<<endl<<endl;
		cout<<		"  BAM 1:   Khoi tao TD tu TD.DAT"<<endl;
		cout<<		"  BAM 2:   Liet ke van"<<endl;
		cout<<		"  BAM 3:   Bo sung tu"<<endl;
		cout<<		"  BAM 4:   Xoa tu"<<endl;
		cout<<		"  BAM 5:   Cap nhat tu file van ban bat ky"<<endl;
		cout<<		"  BAM 6:   Luu vao TD.DAT"<<endl;
		cout<<		"  BAM 0:   Thoat"<<endl;
		int n;
		cin >> n;

		switch (n)
		{
			case 0:	    cout<<endl<<"Thanks !"<<endl;		// Nhan 0 de thoat
						exit(1);
			case 1:							// Nhan 1 de nhap tu dien tu file
						KhoiTao();
						break;
			case 2:						// Nhan 2 de liet ke nhung ten bat dau bang ky tu da nhap
						LietKe();
						break;
			case 3:						// Bo sung ten vao tu dien neu co thi in ra da co, con chua thi bo sung vao tu dien ma van giu nguyen thu tu
						BoSung();
						break;
			case 4:						// Xoa ten da nhap ra khoi tu dien, neu khong co thi thong bao
						XoaTu();
						break;
			case 5:						// Cap nhap tu dien tu file DATA.DAT
						CapNhat();
						break;
			case 6:						// Luu tu dien vao file TD.DAT
						LuuTD();
						break;
			default :	cout<<"BAM? _"<<endl;
		}

	}
	return 0;
}
