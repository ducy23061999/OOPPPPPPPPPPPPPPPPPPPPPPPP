#include <iostream>
using namespace std;
struct Nut {
    int Info;
    Nut *Left;
    Nut *Right;
};

void BS(Nut *&T, int x) {
    if (T == NULL) {
        T = new Nut;
        T->Info = x;
        T->Left = T->Right = NULL;
    } else {
        if (T->Info > x) {
            BS(T->Left, x);
        } else {
            BS(T->Right, x);
        }
    }
}
void InTrungTT(Nut *T) {
    if (T != NULL) {
        InTrungTT(T->Left);
        cout << T->Info << " ";
        InTrungTT(T->Right);
    }
}
int SoLa(Nut *T) {
    if (T != NULL) {
        return 1 + SoLa(T->Left) + SoLa(T->Right);
    };
    return 0;
}

void InGocTT(Nut *T) {
    if (T != NULL) {
        cout << T->Info << " ";
        InGocTT(T->Left);
        InGocTT(T->Right);
    }
}
void InHauTT(Nut *T) {
    if (T != NULL) {
        InHauTT(T->Left);
        InHauTT(T->Right);
        cout << T->Info << " ";
    }
}
void XoaTree(Nut *&T) {
    if (T != NULL) {
        XoaTree(T->Left);
        XoaTree(T->Right);
        delete T;
        T = NULL;
    }
}
int max(Nut *T) {
    if (T->Right != NULL) {
        return max(T->Right);
    } else {
        return T->Info;
    }
}
int max2(Nut *T) {
   if (T->Left == NULL && T->Right == NULL) {
       return T->Info;
   } else {

       if (T->Left = NULL) {
           return Max2So(T->Info, max2(T->Right));
       } else {

           if (T->Right == NULL) {
            return Max2So(T->Info, max2(T->Left));
           } else {
               return Max3So(T->Info, max2(T->Left), max2(T->Right));
           }

       }
   }
}
int sum(Nut *T) {
    if (T == NULL) {
        return 0;
    }

    int s = T->Info;
    int lsum = sum(T->Left);
    int rsum = sum(T->Right);

    return s + lsum + rsum;
    
}
int dem(Nut *T) {
    if (T == NULL) {
        return 0;
    }
    int trai = dem(T->Left);
    int phai = dem(T->Right);

    return 1 + trai + phai;
}
int nutNhanh(Nut *T) { // cau 5
    if (T == NULL || (T->Left == NULL && T->Right == NULL)) {
        return 0;
    }else {
        return 1 + nutNhanh(T->Left) + nutNhanh(T->Right);
    }
}

int demNutNhanh(Nut *T) {
    if (T == NULL) {
        return 0;
    }
    int trai = 0, phai = 0;
    if (T->Left != NULL) {
        trai = 1 + demNutNhanh(T->Left);
    }
    if (T->Right != NULL) {
        phai = 1 + demNutNhanh(T->Right);
    }
    if (T->Left != NULL && T->Right != NULL) {
        return trai + phai - 1;
    }

    return trai + phai;
    
}
Nut *timNutCha(Nut *T, Nut *p) {
    // dung ki thuat de quy xoa dau ??
    if (T == NULL || T == p)
        return NULL;
    else {
        if (T->Left == p || T->Right == p) return T;
        else {
            if (timNutCha(T->Left, p) != NULL)
                return timNutCha(T->Left, p);
            else return timNutCha(T->Right, p);
        }
    }
    
}
// tim nut cha bang phuong phap duyet
Nut *timNutChaCach2(Nut *T, Nut *p) {
    Nut *kq = NULL;
    Duyet(T, p ,kq);
    return kq;
}
// implement ham Duyet
void Duyet(Nut *T, Nut *p, Nut *&kq) {
     if (T != NULL) {
         if ((T->Left != NULL && T->Left == p) || T->Right != NULL && T->Right == p) {
             kq = T;
         } 
         Duyet(T->Left, p, kq);
         Duyet(T->Right, p, kq);
     }
}

int main() {
    Nut *f = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        BS(f,x);
    }
    
    // InHauTT(f); // cau 8
   cout <<  timNutCha(f,3)->Info;
    // cout << nutNhanh(f);
    

    
    return 0;
}