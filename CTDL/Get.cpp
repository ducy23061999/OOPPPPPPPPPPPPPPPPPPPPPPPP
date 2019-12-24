#include <iostream>
#include <fstream>

using namespace std;
void boSungFile1(char *fileName) {
    fstream file;
    file.open(fileName,ios::in);
 
    if (file.fail()) {
        cout << "Khong the mo file!" << endl;
        return;
    }
    char FS[1000];
    while (!file.eof()) // Doc File theo tu, cach nhau boi dau " ", chuyen tu moi doc duoc vao bien tu
    {   
        file.getline(FS, 1000);

        cout << FS << endl;
       
    }
    file.close();
}

void boSungFile2(char *fileName) {
    fstream file;
    file.open(fileName,ios::in);
 
    if (file.fail()) {
        cout << "Khong the mo file!" << endl;
        return;
    }
    char FS[1000];
    while (!file.eof()) // Doc File theo tu, cach nhau boi dau " ", chuyen tu moi doc duoc vao bien tu
    {   
        file >> FS;
        cout << FS<< endl;
       
    }
    file.close();
}
 
int main() {
    // getcline
    boSungFile1("tree.txt");
    cout << "------------------------------------------"<< endl;
    boSungFile2("tree.txt");
    return 0;
}