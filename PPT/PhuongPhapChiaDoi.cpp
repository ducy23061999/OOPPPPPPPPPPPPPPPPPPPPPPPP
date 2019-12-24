#include <iostream>
#include <math.h>
#define E 0.0000001
#define MAX_LOOP 10000
using namespace std;
double f(float x) {
    return x + 3;
}
int main() {
    cout << "Nhap a < b" << endl;
    float a, b;
    cin >> a >> b;
    int i = 0;
    while (i < MAX_LOOP) {
        float p = (a + b) / 2;
        if (f(p) == 0 || (b-a) / 2 < E) {
            cout << p;
            break;
        }
        if (f(a) * f(p) > 0) {
            a = p;
        } else {
            b = p;
        }
        printf("%f | %f | %f | %f | %f \n", i,a,b,p,(b-a) / 2);
        i++;
    }
    return 0;
}