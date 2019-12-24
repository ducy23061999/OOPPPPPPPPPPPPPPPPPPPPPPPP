#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

/* TODO: Tim 1 Tu cho truoc co nam trong danh sach hay khong
    @strs: Mang danh sach string can tim
    @n: so luong phan tu cua mang strs
    @a: string can tim
*/
bool findWordInList(string strs[] ,int n, string a);

/* TODO: Doc Tat ca cac tu trong file
    @filename: Ten file
    @n: tham chieu cua n, cho biet so luong cac tu cua mang sau khi ra khoi ham
*/
string *readWordFromFile(char *fileName, int &n);

int main () {
    
    string *newList;
    int n;
    newList = readWordFromFile("TD2.dat", n);

    // TODO: Loc tat ca cac tu trung nhau, gan vao mang filterList
    string filterList[10000];
    int count = 0;
    for (int i = 0; i < n; i++) {
        string str = newList[i];

        if (!findWordInList(filterList, count, str)) {
            filterList[count] = str;
            count++;
        }
    }

    //TODO: IN DANH SACH CHUA LOC
    for (int i = 0; i < n; i++) {
        cout << newList[i] << endl;
    }

    //TODO: IN DANH SACH DA LOC
    for (int i = 0; i < count; i++) {
        cout << filterList[i] << endl;
    }
    
    return 0;
}
string *readWordFromFile(char *fileName, int &n) {
    ifstream textFile(fileName);
    if (textFile == NULL) {
        cout << "Loi mo file"  <<endl;
        return NULL;
    }
    string data[100000];
    string s;
    n = 0;
    while (getline(textFile, s))
    {
        regex prefix("[A-Za-z]+");
        smatch matchs;
        
        while(regex_search(s, matchs, prefix)) {
            data[n] = matchs.str();
            n++;
            s = matchs.suffix().str();
        }
    }
    return data;
}

bool findWordInList(string strs[] ,int n, string a) {
    for (int i = 0; i < n; i++) {
        if (a == strs[i]) {
            return true;
        }
    }
    return false;
}