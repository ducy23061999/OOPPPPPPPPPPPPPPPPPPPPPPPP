#include<iostream>
#import<string.h>
#import<string>
using namespace std;

struct Nut{
	int Info;
	Nut * next;
};

void chen(Nut *&F, int x){
	Nut * a = new Nut;
	a->Info = x;
	a->next = F;
	F = a;
}

void lietke(Nut *F){
	for(Nut *p=F; p!=NULL; p=p->next){
		cout << p->Info << " ";
	}
}

int tinhtong(Nut *F){
	int tong = 0;
	for(Nut *p=F; p!=NULL; p=p->next){
		tong += p->Info;
	}
	return tong;
}

int max(Nut *F){
	int max = 0;
	for(Nut *p=F; p!=NULL; p=p->next){
		if(max < p->Info) {
			max = p->Info;
		}
		
	}
	return max;
}

bool ktdstang(Nut *F){
	for(Nut *p=F; p->next!=NULL; p=p->next){
		if(p->Info > p->next->Info){
			return false;
		}
	}
	return true;
}

int demsonut(Nut *F){
	int dem = 0;
	for(Nut *p=F; p!=NULL; p=p->next){
		dem++;
	}
	return dem;
}

int main(){
	Nut * F = NULL;
	int n, x;
	cout << "Nhap n:";
	cin >> n;
	for(int i=0; i<n; i++){
		cout << "Nhap x[" << i << "]: ";
		cin >> x;
		chen(F, x);
	}
	
	lietke(F);
	cout << "Sum: "<< tinhtong(F) <<endl;
	cout << "Max: "<< max(F)<<endl;
	string str = ktdstang(F) ? "DS TANG" : "DS KHONG TANG";
	cout << str << endl;
	cout << "So nut: " << demsonut(F)<<endl;
	chen(F, 6);
}
