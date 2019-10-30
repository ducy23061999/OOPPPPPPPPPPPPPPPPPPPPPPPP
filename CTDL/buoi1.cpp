#include <iostream>
using namespace std;
void nhap(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
}
void xuat(int A[], int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout <<A[i] << " ";
    }
    cout<<endl;
}
void daoNguoc(int A[], int n)
{
	int *B = new int[n],j=0;
	for (int i=n-1;i>=0;i--) {
			B[j]=A[i]; 
            j++;
	}
	for (int i=0; i<n; i++)
		A[i] = B[i];
}
int max(int A[], int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (max < A[i]) {
            max = A[i];
        };
    };
    return max;
};
bool doiXung(int A[], int n) {
    for (int i = 0; i < n / 2; i++) {
        if (A[i] != A[n - i - 1]) {
            return false;
        }
    }
    return true;
    
}
int demCap(int A[], int n, int x) {
    int dem = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if ( (A[i] + A[j]) == x) {
                dem++;
            }
        }
    return dem;
}
int demNghichDao(int A[],int n)
{
	int i,j,dem=0;
	for(i = 0;i < n-1; i++)
		for(j= i + 1; j < n; j++)
			if(i < j && A[i] > A[j])
				dem++;
	return dem;	
}
void inD(int A[], int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        int dem = 0;
        for (int j = i + 1; j < n; j++) {
            if (A[j] <= A[i]) {
                dem++;
            }
        }
        cout << dem << " ";
    }
        
}
int main() {
    int A[100];
    int n;
    cout << "Nhap n: "<<endl;
    cin >> n;
    nhap(A, n);
    // 1
    cout << "Max: " << max(A,n)<<endl;
    // 2
    daoNguoc(A,n);
    xuat(A,n);
    // 3
    if (doiXung(A, n)) {
        cout << "Doi Xung Ne "<<endl;
    } else {
        cout << "Khong doi xung "<<endl;
    }
    // 4
    cout << "So Cap Nghich Dao "<<demNghichDao(A,n)<<endl;
    // 5 
    cout << "So cap bang co tong 5: "<< demCap(A,n, 5)<<endl;
    // 6
    inD(A,n);
    return 0;
}