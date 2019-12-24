#include <fstream>
#include<iostream>
#include<string.h>
using namespace std;
typedef char St25[50];
struct Sach{
	St25 TenSach;
	Sach *TiepTheo;
};

struct TG{
	TG *Trai, *Phai;
	Sach *Dau, *Cuoi;
	St25 TenTG;
};


//Lâm: tìm tác gi?
TG *Nut(TG *Goc, St25 Ten){
	if(Goc == NULL) return NULL;
	else if(strcmp(Goc->TenTG, Ten)==0) return Goc;
	else if (strcmp(Goc->TenTG, Ten) > 0) return Nut(Goc->Trai,Ten);
	else return Nut(Goc->Phai,Ten); 
}

// Thùy Trang: T?o 1 nút tác gi? + cu?n sách d?u tiên c?a tác gi? dó
TG *NutMoi(St25 Ten, char *TuaDe){
  	TG *a = new TG; // Khoi tao 1 tac gia moi
 	strcpy(a->TenTG, Ten);
	a->Trai = NULL;
	a->Phai = NULL;
	
	Sach *x = new Sach; // khoi tao 1 sach moi
	x->TiepTheo = NULL;
	strcpy(x->TenSach, TuaDe);
	
	// Luc bat dau: Dau = Cuoi = x
	a->Dau = x;
	a->Cuoi = x;
	
	return a;
}

// M? Trang: B? sung tác gi? vào cây
void boSungTacGia(TG *&Goc, TG *tacGia){ 
    if (Goc == NULL) Goc = tacGia; 
    else if (strcmp(Goc->TenTG, tacGia->TenTG) > 0) 
		boSungTacGia(Goc->Trai, tacGia);
    else boSungTacGia(Goc->Phai, tacGia);
}

int kiemTraSach(TG *Ten, St25 TuaDe){
	Sach *rem = Ten->Dau;
	while(rem != NULL){
		if(strcmp(rem->TenSach, TuaDe) == 0) return 0; // Neu tim thay sach da co thi return 1(ko the add)
		else rem = rem->TiepTheo;
	}
	return 1;
}

// Ð?c Ý: B? sung 1 sách
void boSung(TG *&T, St25 tenTG, St25 TuaDe) {
	if (T == NULL) {
		T = NutMoi(tenTG, TuaDe);
	}  else {
		// Nut k phai null, tim sach theo tac gia
		TG *tg = Nut(T, tenTG);
		if (tg == NULL) {
			// khong tim thay -> bo sung tac gia 
			tg = NutMoi(tenTG, TuaDe);
			boSungTacGia(T, tg);
			//TG *tg2 = Nut(T, TuaDe);
			// cout << endl <<tg2->Dau->TenSach; Loi
		} else {
			// Bo Sung Sach neu kiem tra sach chua co trong tg
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

void docFile(TG *&Goc, char *tenfile){
	ifstream input;
	input.open(tenfile);
 
	if(input.fail()){
		cout << "Mo file that bai. Xin kiem tra lai duong dan file!" << endl;
		return;
	}
	St25 text, tacGia;
	while(!input.eof()){
		fflush(stdin);
		input.getline(text, 100);
		if(text[0] == '*') { // neu text[0] = * thi dong nay la tac gia
			strcpy(tacGia, strchr(text, text[1])); // ham strchr tra ve 1 con tro
		}
		else boSung(Goc, tacGia, text);
	}
	input.close();
	cout << "Da khoi tao file!" << endl;
}


// Công Tru?ng: Li?t kê tên các tác gi? theo th? t? alphabet
void lietKeTacGia(TG *Goc){
	if(Goc != NULL){
		lietKeTacGia(Goc->Trai);
		cout << Goc->TenTG << endl;
		lietKeTacGia(Goc->Phai);
	}
}


void inSachCuaTacGia(TG *Goc, St25 Ten){
	if(Goc==NULL) cout<< "Cay rong!"<< endl;
	else{
		TG *timKiem = Nut(Goc, Ten);
		if(timKiem == NULL) cout << "Ko co tac gia "<< Ten << " trong cay!" << endl;
		else{
			cout << "Sach cua tac gia " << Ten << ":" << endl;
			for(Sach *i=timKiem->Dau; i!=NULL; i=i->TiepTheo){
				cout << " - " << i->TenSach << endl;
			}
		}
	}
}

// Rôn: Nh?p vào tên m?t cu?n sách, t? dó cho bi?t các tác gi? dã vi?t cu?n này.
void inTacGiaCuaSach(TG *T, St25 TuaDe) {
	if(T!=NULL) {
		inTacGiaCuaSach(T->Trai, TuaDe);
		for(Sach *p = T->Dau; p!=NULL; p=p->TiepTheo) {
			if(strcmp(TuaDe, p->TenSach) == 0) {
				cout << T->TenTG << endl;
				break;
			}
		}
		inTacGiaCuaSach(T->Phai, TuaDe);
	}
}
//Thanh Phu?c: In toàn b? thông tin trong cây
void inToanBo(TG *Goc){
	if (Goc != NULL){
		inToanBo(Goc->Trai);
		cout << Goc->TenTG << endl;
		for (Sach *G = Goc->Dau; G != NULL; G=G->TiepTheo)
			cout << G->TenSach << endl;
		inToanBo(Goc->Phai);
	}
}



void menu(){
	cout << "--------------------MENU--------------------" << endl;
	cout << "1. Khoi tao cay." << endl;
	cout << "2. Liet ke tac gia theo alphabet." << endl;
	cout << "3. Liet ke sach cua 1 tac gia." << endl;
	cout << "4. Liet ke cac tac gia cua 1 cuon sach." << endl;
	cout << "5. Bo sung 1 sach vao cay." << endl;
	cout << "6. In toan bo cay." << endl;
	cout << "0. exit." << endl;
}

int main(){
	TG *Goc = NULL;
	int select;
	St25 text;
	while(1){
		menu();
		cout << "Lua chon cua ban la: ";
		cin >> select;
		fflush(stdin); // refresh bo nho dem
		cout << "--------------------------------------------" << endl;
		if(select == 0) break;
		else if(select == 1){
			char filename[50];
			cout << "Nhap ten file:";
			cin >> filename;
			docFile(Goc, filename);
		}
		else if(select == 2){
			cout << "Danh sach tac gia:" << endl;
			lietKeTacGia(Goc);
		}
		else if(select == 3){
			cout << "Nhap ten 1 tac gia:";
			cin.getline(text, 100);
			inSachCuaTacGia(Goc, text);
		}
		else if(select == 4){
			cout << "Nhap ten 1 cuon sach:";
			cin.getline(text, 100);
			if(Goc == NULL) cout << "Cay rong!" << endl;
			else inTacGiaCuaSach(Goc, text);
		}
		else if(select == 5){
			St25 tenSach, tacGia;
			cout << "Nhap ten sach:";
			cin.getline(tenSach, 100);
			cout << "Nhap ten tac gia:";
			cin.getline(tacGia, 100);
			boSung(Goc, tacGia, tenSach);
			cout << "Da cap nhat!" << endl;
		}
		else if(select == 6){
			cout << "In toan bo:" << endl;
			inToanBo(Goc);
		}
		else cout << "Lua chon cua ban khong co trong menu!" << endl;
		cout << "--------------------------------------------" << endl;
		cout << "Nhan Enter de tiep tuc...";
		if(getchar() != '\n') break;
	}
	
	
	return 0;
}