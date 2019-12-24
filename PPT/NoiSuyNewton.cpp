#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

struct GT {
    double x;
    double fx;
};

GT A[1000]; // input
double B[1000]; // duong cheo
double temp[1000] ;// tam

int n;

double fx(double x) {
    return x*x - sqrt(x);
}

void resetAndCopyTemp(double *F, int n) {
    // temp[1000] = {0};
    for (int i = 0; i < n; i++) {
        temp[i] = F[i];
    }
    temp[n] = -1;

}
void in (GT A[]) {
    for (int i = 0; i < n-1; i++) {
        cout << A[i].x << " | " << A[i].fx << endl;
    }
}

void inFloat(double a[], int _n) {
    for (int i =0; i < _n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void lapBangTySaiPhan(int step, int n_copy) {
    if (n_copy > 0) {
        double *store = new double[n_copy - 1];
        for (int i = 0; i < n_copy - 1; i++) {
            int j = i + step;
            store[i] = (temp[i+1] - temp[i]) / (A[j].x - A[i].x);
        }
        inFloat(store, n_copy - 1);
        B[step] = store[0];
        resetAndCopyTemp(store, n_copy);
        lapBangTySaiPhan(++step, --n_copy);
    }   
}



int main() {
    FILE *fp;
    cout << "Nhap Mode:"<<endl;
    cout << "1: Nhap Tu File"<<endl;
    cout << "2: Nhap Tu Ban Phim Voi TH Da Co Ham F(x)" << endl;
    cout << "3: Nhap x va f(x) bang tay"<<endl;
    cout << "Nhap Lua Chon: ";
    int mode;
    cin >> mode;

    switch (mode)
    {
        case 1: {
            char str[1000];
            cout << endl<< "Nhap ten file: ";
            cin >> str;
            fp = freopen(str, "r", stdin);
            if (fp == NULL) {
                cout << "File Khong Ton Tai";
                exit(1);
            }   
            break;
        }
            
        case 2: {
            break;
        }
        case 3: {
            break;
        }
        default:
            cout << "Lua Chon Khong Hop Le";
            return 0;
    }
    
    cout << "Nhap N: ";
    cin >> n;
    // nhap x1, x2
    cout << "Nhap danh sach x" << endl;

    for (int i = 0; i < n; i++) {
        cin >> A[i].x;
    }
    if (mode == 2) {
        // nhap f(x) tu x
        for (int i = 0; i < n; i++) {
            A[i].fx = fx(A[i].x);
        }
    } else {
         // nhap fx1, fx2
        cout << "Nhap Danh Sach Fx: "<<endl;
        for (int i = 0; i < n; i++) {
            cin >> A[i].fx;
        }
    }
   
    // first copy;
    for (int i =0; i < n; i++) {
        temp[i] = A[i].fx;
    }
    cout << "=========BANG TY SAI PHAN=============="<<endl;
    // inFloat(temp, n);
    lapBangTySaiPhan(1, n);

    cout << "=========BANG TY SAI PHAN=============="<<endl<<endl;

    cout << "Result Duong Cheo" << endl;

    // in duong cheo
    B[0] = A[0].fx;
    for (int i = 0; i < n; i++) {
        cout << B[i] << " ";
    }
    cout << endl;
    double Sum = A[0].fx;
    double x;
    cout << "Nhap X: " << endl; 
    cin >> x;

    cout << "X la "<<x<<endl;
    for (int i = 1; i < n; i++) {
        double T = B[i];
        for (int j = 0; j < i; j ++) {
            T *= (x - A[j].x);
        }
        Sum += T;
    }
    


    fclose(fp);
    printf("Tong la: %.10g\n", Sum);

    return 0;
}