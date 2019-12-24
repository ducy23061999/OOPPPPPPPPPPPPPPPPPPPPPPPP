#include <fstream>
#include<iostream>
#include<string.h>
using namespace std;

typedef char St25[25];
struct Sach {
	St25 TenSach;
	Sach *TiepTheo;
};
struct TG {
	TG *Trai, *Phai;
	Sach *Dau, *Cuoi;
	St25 TenTG;
};

TG *Goc;


void BSNut(TG *&T, char tenTG[]) {
	if (T == NULL) {
		T = new TG;
		strcpy(T->TenTG, tenTG);
		T->Trai = T->Phai = NULL;
		T->Dau = T->Cuoi = NULL;
	} else {
		if (strcmp(T->TenTG, tenTG) > 0) {
			BSNut(T->Trai,tenTG);
		} else {
			BSNut(T->Phai, tenTG);
		}
	}
}
int kiemTraSach(TG *Ten, St25 TuaDe){
	Sach *rem = Ten->Dau;
	while(rem != NULL){
		if(strcmp(rem->TenSach, TuaDe) == 0) return 0; // Neu tim thay sach da co thi return 0(ko the add)
		else rem = rem->TiepTheo;
	}
	return 1;
}

void boSungTacGia(TG *&Goc, TG *a){ 
    if (Goc == NULL) 
		Goc = a;
    else if (strcmp(Goc->TenTG, a->TenTG) > 0) 
		boSungTacGia(Goc->Trai, a);
    else boSungTacGia(Goc->Phai, a);
}
 
TG *Nut(TG *Goc, St25 Ten) {
	if (Goc != NULL) {
		if (strcmp(Goc->TenTG, Ten) == 0) {
			return Goc;
		} else {
			if (strcmp(Goc->TenTG, Ten) > 0) {
				return Nut(Goc->Trai, Ten);
			} else {
				return Nut(Goc->Phai, Ten);
			}
		}
	} else {
		return NULL;
	}
}



TG *NutMoi(St25 Ten, char *TuaDe){
  	TG *a = new TG; 
 	strcpy(a->TenTG, Ten);
	a->Trai = NULL;
	a->Phai = NULL;
	Sach *x = new Sach;
	x->TiepTheo = NULL;
	strcpy(x->TenSach, TuaDe);	
	a->Dau = x;
	a->Cuoi = x;
 
	return a;
}

void Bosung(TG *&T, St25 tenTG, St25 TuaDe) {
	if (T == NULL) {
		T = NutMoi(tenTG, TuaDe);
	}  else {
		// Nut k phai null, tim sach theo tac gia
		TG *tg = Nut(T, tenTG);
		if (tg == NULL) {
			// khong tim thay -> bo sung tac gia 
			tg = NutMoi(tenTG, TuaDe);
			
			boSungTacGia(T, tg);
			TG *tg2 = Nut(T, TuaDe);
			// cout << endl <<tg2->Dau->TenSach; Loi
		} else {
			// Bo Sung Sach
			if (kiemTraSach(tg, TuaDe) == 1) {
				Sach *s = new Sach;
				strcpy(s->TenSach, TuaDe);
				s->TiepTheo = NULL;
				tg->Cuoi->TiepTheo = s;
				tg->Cuoi = s;
			} 
		}
	}	
}


void InTrungTT(TG *T) {
    if (T != NULL) {
        InTrungTT(T->Trai);
        cout << T->TenTG << " ";
        InTrungTT(T->Phai);
    }
}


void InSach(Sach *f) {
	if (f == NULL) {
		cout << "Danh Sach Rong";
	}
	for (Sach *p = f; p != NULL; p = p->TiepTheo) {
		cout << p->TenSach << ", ";
	}
	cout << endl;
}


int main(){
	Goc = NULL;
	BSNut(Goc, "B");
	BSNut(Goc, "C");
	BSNut(Goc, "A");
	BSNut(Goc ,"E");
	BSNut(Goc, "D");
	BSNut(Goc, "F");

	Bosung(Goc, "G", "HoaHoa");
	Bosung(Goc, "G", "Hoa Nhuoc Phi");
	Bosung(Goc, "G", "|A");

	TG *tg = Nut(Goc, "G");
	if (tg == NULL) {
		cout << "Khong Tim thay";
	} else {
		cout << endl;
		InSach(tg->Dau);

	}
	// InTrungTT(Goc);
	
}
