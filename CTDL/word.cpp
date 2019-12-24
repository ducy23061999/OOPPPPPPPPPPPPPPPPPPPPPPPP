#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;
/* TODO: kiem tra 1 ki tu co phai la 1 tu hay khong?
  @para c: ki tu can kiem tra
*/
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
            char tam[20];

            int j = 0;
            for (int i = start; i < end; i++, j++) {
                tam[j] =  toupper(tu[i]);
            }
            tam[j] = '\0';

            //  Da loc tu, xu li , them vao list o day
            // Neu chua nam trong list thi bo sung


            cout << "["<<tam <<"]"<< endl;    
        }
    }
    file.close();
}
int main() {
    boSungFile("TuDien.cpp");
    
    return 0;
}