#include <iostream>
using namespace std;
struct Nut {
    int info;
    Nut *next;
};
void insertFirst(Nut *&f, int x) {
    Nut *p = new Nut;
    p->info = x;
    p->next = f;
    f = p;
}
void nhap(Nut *&f) {
    while (true)
    {
        int a;
        cin >> a;
        if (a < 0) {
            break;
        };
        insertFirst(f,a);
    }
}
void xuat(Nut *f) {
    cout << endl;
    if (f == NULL) {
        cout << "Danh Sach Rong Hihi";
    }
    for (Nut *p = f; p != NULL; p = p->next) {
        cout << p->info << " ";
    }
    cout << endl;
}
void insertData(Nut *&f, int x) {
    Nut *node = new Nut;
    node->info = x;
    node->next = NULL;
    if (f == NULL) {
       f = node;
    } else {
        Nut *p = f;
        Nut *save = f;
        while (p != NULL && node->info > p->info) {
            save = p;
            p = p->next;
        }
        save->next = node;
        node->next = p;
    }
}
void xoa(Nut *&f, int x) {
    if (f == NULL) {
        cout << "KHong the xoa" << endl;
        return;
    }else {
        if (f->info == x) {
            Nut *p = f;
            f = f->next;
            delete p;
        } else {
            Nut *p = f;
            Nut *save = f;
            while (p != NULL && p->info != x)
            {
                save = p;
                p = p->next;
            }
            save->next = p->next;
            delete p;
        
        } 
    }
}
void xoaAll(Nut *&f, int x) {
    if (f == NULL) {
        cout << "KHong the xoa" << endl;
        return;
    }else {
        Nut *p = f;
        Nut *save = f;
        while (true)
        {   
            if (p == NULL) {
                break;
            };
            if (p->info != x) {
                save = p;
            } else {
                if (f == p) {
                    f= f->next;
                    delete p;
                }
                save->next = p->next;
                // delete p;
            }
            p = p->next;
            
        }
    }
}
int main() {
    Nut *f = NULL;
    nhap(f);
    // insertData(f, 3);
    // xoa(f,3);
    xoaAll(f,3);
    xuat(f);
    return 0;
}