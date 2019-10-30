#include <iostream>
using namespace std;
int dequy_ucln(int n, int m) {
    if (m <= n && n % m == 0) {
        return m;
    } else {
        if (n < m) {
            return dequy_ucln(m,n);
        } else {
            return dequy_ucln(m, n % m);
        }
    }
}
int lap_ucln(int n, int m) {
    while (n % m != 0)
    {
        if (n < m) {
            int temp = n;
            n = m;
            m = temp;
        }
        if (n % m == 0) {
            return m;
        };
        n = n % m;
    };
    return -1;
}
int main() {
    cout << dequy_ucln(6,9)<<endl;
    cout << lap_ucln(6,9);
    return 1;
}