#include <iostream>
#include <fstream>

using namespace std;
 
struct Nut{
	char Tu[7];
	Nut *Tiep;
};
 
 
// Từ điển...TD[0] lưu các từ bắt đầu bằng ký tự 'A', TD[25] lưu các từ bắt đầu bằng ký tự 'Z'
Nut * TD[26]; 
 
 
/* Giải thích (int vt = word[0]-'A';)
TD[0] lưu các từ bắt đầu vs ký tự 'A'...vd: AI, ANH, AN
TD[1] lưu các từ bắt đầu vs ký tự 'B'...vd: BE, BI, BENH, BAN, BAO, BANH, BO :v
TD[25] lưu các ký tự bắt đầu vs 'Z'
 
=>vd: có 1 từ "ANH" muốn lưu vào từ điển thì mình phải biết nó phải lưu vào TD[mấy]
bắt đầu vs A thì tất nhiên phải lưu vào TD[0] rồi
cách lấy đc cái số "mấy" đó là: int vt = word[0] - 'A';
với word = "ANH" => word[0] = 'A'
vt = 'A' - 'A' = 0
 
=>vd: thêm từ BAN
word = "BAN" => word[0] = 'B'
vt = word[0]-'A' = 'B'-'A' = 1
=> lưu vào TD[1]
*/
 
 
int kiemTra(char word[]){
	int vt = word[0]-'A';
	if(TD[vt] == NULL) return 1; // co the them vao ds
	for(Nut * i = TD[vt]; i != NULL; i = i->Tiep)
		if(stricmp(i->Tu, word) == 0) return 0; // ko the them vao ds
	return 1; // co the them vao ds
}
 
 
// Chen cuoi ds
void chenCuoi(char word[]){
	int vt = word[0]-'A';
	Nut * a = new Nut;
	strcpy(a->Tu, word);
	a->Tiep = NULL;
 
	if(TD[vt] == NULL) TD[vt] = a;
	else{
		Nut * i = TD[vt];
		while(i->Tiep != NULL) i = i->Tiep;
		i->Tiep = a;
	}
}
 
int khoiTao(){
	ifstream input;
	input.open("TD.DAT");
 
	if(input.fail()){
		cout << "Loi mo file." << endl;
		return 0;
	}
 
	char word[7];
	while(!input.eof()){
		input >> word;
		if(kiemTra(word)) chenCuoi(word);
	}
	input.close();
	return 1;
}
 
void lietKe(char c){
	int vt = toupper(c) - 'A'; // chuyển ký tự C thành chữ hoa rồi trừ cho 'A'
	if(TD[vt] == NULL) cout << "Co 0 ket qua." << endl;
	else{
		for(Nut *i=TD[vt]; i!=NULL; i=i->Tiep)
			cout << i->Tu << endl;
	}
}
 
void boSungDau(Nut*&TD,char Tu[]) {
	Nut* p = new Nut;
	strcpy(p->Tu,Tu);
	p->Tiep=TD;
	TD=p;
}
 
void boSung(char Tu[]){
	int vt = Tu[0]-'A';
	if(TD[vt]==NULL || strcmp(TD[vt]->Tu,Tu)>0)  // neu list rong hoac các tu trong list deu lon hon tu can chen thi bosung
		boSungDau(TD[vt],Tu);	
	//bo sung vao dau danh sach
	else { //tim vi tri thich hop de chen vao danh sach sao cho danh sach van tang dan
		Nut* p = TD[vt];
		while(p->Tiep!=NULL && strcmp(p->Tiep->Tu,Tu)<0 ){//duyet tung phan tu trong list 
			p=p->Tiep;//neu khong tim thay vi tri can chen thi tim vi tri tiep theo
		}
		//khi  dieu kien strcmp(p->Tiep->Tu,Tu)<0 sai
		//tuc la  strcmp(p->Tiep->Tu,Tu)>0  tim thay vi tri can chen
		Nut* q = new Nut;
		strcpy(q->Tu,Tu);
		q->Tiep = p->Tiep;
		p->Tiep = q;	
	}
}
 
void xoaTu(char word[]){
	int vt = word[0]-'A';
	if(TD[vt] == NULL) return;
 
	Nut *i = TD[vt];
 
	if(strcmp(TD[vt]->Tu, word) == 0){
		TD[vt] = i->Tiep;
		delete i;
		return;
	}
 
	for(Nut *p = TD[vt]->Tiep; p != NULL; p=p->Tiep){
		if(strcmp(p->Tu, word) == 0){
			i->Tiep = p->Tiep;
			delete p;
			return;
		}
		else i = p;
	}
}
 
void boSungFile(char *fileName) {
    fstream file;
    file.open(fileName,ios::in);
 
    if (file.fail()) {
        cout << "Khong the mo file!" << endl;
        return;
    }
	// -> start, end
	// 28AGSF## POS

	// %%@@@UIAO))

	// -> AGSF, POS
	// 5
	// 1 2 3 4 5
	// -> STREAM STDIO INPUT,cin , STREAM OUTPUT , cout, STD ERROR
    int start, end;
    char tu[100];
    while (!file.eof()) // Doc File theo tu, cach nhau boi dau " ", chuyen tu moi doc duoc vao bien tu
    {   
		file >> tu; // STDIN. DOC CHuoi ki tu file -> tu theo khoang cach hoac dau enter
        start = 0, end = 0;
        // TODO:  Loc tu (cac tu co chua ? | , ?,... Noi chung la cac ki tu khong phai tu)
        while (end < strlen(tu)){
            start = end;
            // Tim diem bat dau tu cua tu lay duoc tu file
			// isalpha(char)                           <-start i = start, j = 0 tam[] = 'AS'
			// 'A', 'B', 'C', '\0' -> char a[4] = "&727ASFIAUAT8ASS32"
															 //<-end
            while (!isalpha(tu[start]) && start < strlen(tu)) start++;
            // Tim diem ket thuc cua tu + cho tu tiep theo
            end = start;
            while (isalpha(tu[end])) end++;
            // TH nay xu li 2 vong lap tren khong xay ra -> tu khong chua ki tu can loc
            if (start == end) break;
            //TODO: Gan vao bien tam sau nay xu li
            char tam[7] = "";
            int j = 0;
			int max = 6;
            for (int i = start; i < end; i++) {
				if (j >= max)  break;
                tam[j] = toupper(tu[i]); // 'i' -> 'I'
				j++;
            }
            tam[j] = '\0';
 
            // Neu chua nam trong list thi bo sung
            if (kiemTra(tam)) boSung(tam);
        }
    }
    file.close();
}
 
int luuFile(){
	ofstream output;
	output.open("TD.DAT");
 
	if(output.fail()){
		cout << "Loi mo file." << endl;
		return 0;
	}
 
	for(int vt=0; vt<26; vt++){
		for(Nut *i=TD[vt]; i!=NULL; i=i->Tiep){
			output << i->Tu;
			output << endl;
		}
	}
	output.close();
	return 1;
}
 
 
// Menu
void Menu(){
	cout<<"----------------MENU----------------"<<endl;
	cout<<"Nhan 1 de: Khoi tao tu dien."<<endl;
	cout<<"Nhan 2 de: Liet ke tu."<<endl;
	cout<<"Nhan 3 de: Bo sung tu."<<endl;
	cout<<"Nhan 4 de: Xoa 1 tu."<<endl;
	cout<<"Nhan 5 de: Cap nhat tu file van ban."<<endl;
	cout<<"Nhan 6 de: Luu file."<<endl;
	cout<<"Nhan 0 de: Thoat."<<endl;
	cout<<"------------------------------------"<<endl;
}
 
void inTuDien(){
	for(int vt=0; vt<26; vt++){
		int dem = 0; // Chi in ra 7 tu dau tien
		for(Nut *i=TD[vt]; i!=NULL; i=i->Tiep){
			cout << i->Tu << " ";
			dem++;
			if(dem == 7){
				cout << "...";
				break;
			}
		}
		// Neu TD[vt] != NULL thi cho xuong hang
		if(dem != 0) cout << endl;
	}
}
 
 
int main() {
	cout<<"\t   BAI THUC HANH\n\n";
	for(int i=0; i<26; i++) TD[i] = NULL;
	int luaChon;
	while(1){
		Menu();
		cout << "Nhap lua chon:";
		cin >> luaChon;
		if(luaChon == 0) return 0;
		else if(luaChon == 1) {
			if(khoiTao() == 1)
				cout << "Da khoi tao tu dien." << endl;
		}	
		else if(luaChon == 2){
			char c;
			cout << "Nhap ky tu dau tien:";
			cin >> c;
			lietKe(c); // Nếu từ điển rỗng in ra thông báo từ điển rỗng
		}	
		else if(luaChon == 3){
			char word[7];
			cout << "Nhap tu can bo sung:";
			cin >> word; 
			strupr(word); // Từ in hoa
			if(kiemTra(word) == 1)
			{
				boSung(word);
				cout << "Da cap nhat tu dien." << endl;
			}
			else cout << "Tu da ton tai." << endl;
		}
		else if(luaChon == 4){
			char word[7];
			cout << "Nhap tu can xoa:";
			cin >> word; 
			strupr(word); // Từ in hoa
			xoaTu(word);
			cout << "Da cap nhat tu dien." << endl;
		}
		else if(luaChon == 5){
			char filename[50];
			cout << "Nhap ten file:";
			cin >> filename;
			boSungFile(filename);
			cout << "Da bo sung tu file." << endl;
		}
		else if(luaChon == 6){
			if(luuFile() == 1)
				cout << "Da luu file." << endl;
		}
		else if(luaChon == 7) inTuDien();
	}
	return 0;
}