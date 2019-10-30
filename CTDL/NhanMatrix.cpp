#include <iostream>
using namespace std;
int main() {
    int n, m , l;
    int A[100][100], B[100][100];
    cout << "Nhap n , m , j" << endl;;
    cin >> n >> m >> l;
    cout << "Nhap Ma Tran nxm: "<< endl;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    cout << "Nhap Ma Tran m x l" << endl;
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < l; j++) {
            cin >> B[i][j];
        };

    int D[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < l; j++) 
            for (int k = 0; k < m; k++)
            {
                D[i][j] += A[i][k] * B[k][j];
            }
    cout << "KQ: "<< endl;
    for (int i = 0; i < n; i++)
        for (int j =0; j < l; j++)
        {
            cout << D[i][j] << " ";
            if (j == l -1)
                cout << endl;
        }

    return 0;
}