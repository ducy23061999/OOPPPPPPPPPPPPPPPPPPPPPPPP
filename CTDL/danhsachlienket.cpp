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
        if (p == save) {
            insertFirst(f,x);
        } else {
            save->next = node;
            node->next = p;
        }
       
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
                } else {
                    save->next = p->next;
                    delete p;
                }
                
            }
            p = p->next;
            
        }
    }
}
void BSCuoi(Nut *&f, int X) {
    if (f == NULL) {
        f = new Nut;
        f->info  = X;
        f->next = NULL;
    } else {
        BSCuoi(f->next, X);
    }
}
void XoaCuoi(Nut *&f) {
    if (f != NULL) {
        if (f->next == NULL) {
            delete f;
            f = NULL;
        } else {
            XoaCuoi(f->next);
        }
    }
}
Nut *timDSChuaDuocSapXep(Nut *f, int x) {
    if (f != NULL) {
        if (f->info == x) {
            return f;
        } else {
            return timDSChuaDuocSapXep(f->next, x);
        }
    } else {
        return NULL;
    }
}
Nut *timDSDaDuocSapXep(Nut *f, int x) {
    if (f == NULL || x < f->info)
        return NULL;
     if (f->info == x) {
            return f;
     } else {
            return timDSChuaDuocSapXep(f->next, x);
     }
}
void SaoChep(Nut *F, Nut *&L) {
    if (F == NULL) {
        L == NULL;
    } else {
        L = new Nut;
        L->info = F->info;
        SaoChep(F->next, L->next);
    }
    
}
void GiaoHaiDanhSach(Nut *F1, Nut *F2, Nut *&F3) {
   if (F1 != NULL && F2 != NULL) {
       if (F1->info == F2->info) {
           F3 = new Nut;
           F3->info = F1->info;
           GiaoHaiDanhSach(F1->next, F2->next, F3->next);
       } else {
           if (F1->info < F2->info) {
               GiaoHaiDanhSach(F1->next, F2, F3);
            
           } else 
                GiaoHaiDanhSach(F1, F2->next, F3);
       }
       
   } else {
       F3 = NULL;
   }
}

void HopHaiDanhSach(Nut *F1, Nut *F2, Nut *&F3) {
    if (F1 != NULL && F2 != NULL) {
        if (F1->info == F2->info) {
            F3 = new Nut;
            F3->info = F1->info;
            HopHaiDanhSach(F1->next, F2->next, F3->next);
        } else {
            if (F1->info < F2->info) {
                F3 = new Nut;
                F3->info = F1->info;
                HopHaiDanhSach(F1->next, F2, F3->next);
            } else {
                F3 = new Nut;
                F3->info = F2->info;
                HopHaiDanhSach(F1, F2->next, F3->next);
            }
        }
    } else {
        if (F1 == NULL && F2 != NULL) {
            SaoChep(F2, F3);
        } 
        if (F2 == NULL && F1 != NULL) {
            SaoChep(F1, F3);
        }
    }
}

int main() {
    Nut *f = NULL;
    // nhap(f);
    cout << "??";
    // xuat(f);
    insertData(f,3);
    insertData(f,4);
    insertData(f,5);
    insertData(f,6);
    insertData(f,7);
    insertData(f,8);
    insertData(f,10);
    BSCuoi(f, 10);
    // xoaAll(f,3);
    xuat(f);
    return 0;
}