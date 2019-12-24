#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
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
 

int kiemTra(char word[])
{
	int vt = word[0]-'A';
	if(TD[vt] == NULL) return 1; // co the them vao ds
	for(Nut * i = TD[vt]; i != NULL; i = i->Tiep)
		if(strcmp(i->Tu, word) == 0) return 0; // ko the them vao ds
	return 1; // co the them vao ds
}
 
 
// Chen cuoi ds
void chenCuoi(char word[])
{
	int vt = word[0]-'A';
	Nut * a = new Nut;
	strcpy(a->Tu, word);
	a->Tiep = NULL;
 
	if(TD[vt] == NULL) TD[vt] = a;
	else
	{
		Nut * i = TD[vt];
		while(i->Tiep != NULL) i = i->Tiep;
		i->Tiep = a;
	}
}
 
void lietKe(char c){
	int vt = toupper(c) - 'A'; // chuyển ký tự C thành chữ hoa rồi trừ cho 'A'
	if(TD[vt] == NULL) cout << "Co 0 ket qua." << endl;
	else
	{
		for(Nut *i=TD[vt]; i!=NULL; i=i->Tiep)
			cout << i->Tu << endl;
	}
}


bool isWord(char c) {
    return (c >= 65 && c <= 90) // A->Z
            || (c >=97 && c<=122) ;// a->z
}
/* TODO: Bo sung list TD[7] tu file
  @para fileName: ten file
*/
void boSungFile(char *fileName) {
    fstream file;
    file.open(fileName,ios::in);

    if (file == NULL) {
        cout << "Khong the mo file!";
        return;
    }

    int start, end;
    char tu[1000];
    while (!file.eof() && file >> tu) // Doc File theo tu, cach nhau boi dau " ", chuyen tu moi doc duoc vao bien tu
    {   

        start = 0;
        end = 0;
        // TODO:  Loc tu (cac tu co chua ? | , ?,... Noi chung la cac ki tu khong phai tu)
        while (end < strlen(tu))
        {
            start = end;
            // Tim diem bat dau tu cua tu lay duoc tu file
            while (!isWord(tu[start]) && start < strlen(tu))
            {
                start++;
            }
            // Tim diem ket thuc cua tu + cho tu tiep theo
            end = start;
            while (isWord(tu[end]))
            {
                end++;
            } 
            // TH nay xu li 2 vong lap tren khong xay ra -> tu khong chua ki tu can loc
            if (start == end) {
                break;
            }
            

            //TODO: Gan vao bien tam sau nay xu li
            char tam[1000];

            int j = 0;
            for (int i = start; i < end; i++, j++) {
                tam[j] = toupper(tu[i]);
            }
            tam[j] = '\0';
            
            //  Da loc tu, xu li , them vao list o day
            // Neu chua nam trong list thi bo sung
            if (kiemTra(tam)) {

                chenCuoi(tam);
            }

            // cout << tam << endl;    
        }
    }
    file.close();
}
void inToanBo() {
	int vt = 0;
	for (;vt<26; vt++) {
		for(Nut *p=TD[vt]; p!=NULL; p=p->Tiep) {
            if (p->Tiep != NULL) {
                cout << p->Tu << "  ";
            } else {
                cout << p->Tu << endl;
            }
			// cout << p->Tu << "  ";
		}
		// cout << endl;
	}
}
 
// Menu
void Menu()
{
	cout<<"  Bai thuc hanh - Nhom 1 "<<endl;
	cout<<"=========================="<<endl;
	cout<<"-----------MENU-----------"<<endl;
	cout<<"Nhan 1 de: Khoi tao tu dien."<<endl;
	cout<<"Nhan 2 de: Liet ke tu."<<endl;
	cout<<"Nhan 3 de: Bo sung tu."<<endl;
	cout<<"Nhan 4 de: Xoa 1 tu."<<endl;
	cout<<"Nhan 5 de: Cap nhat tu file van ban."<<endl;
	cout<<"Nhan 6 de: Luu file."<<endl;
	cout<<"Nhan 0 de: Thoat."<<endl;
}
 
 
int main() 
{   
    boSungFile("TD2.dat");
    inToanBo();
	
	return 0;
}