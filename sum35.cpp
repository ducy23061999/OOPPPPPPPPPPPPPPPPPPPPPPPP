#include <iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    for (int q = 1; q <= T; q++){
        int start3,end3,start5,end5,start15,end15;
        int count3,count5,count15;
        long long sum; int n;
        long long MOD = 10e9 + 7;
        start3 = 3; start5=5;start15 = 15; int flag = 0;
        cin >>n;
        if (n < 0) {
            n = -n;
            flag = 1;
        }
        end3 = n/3 *3;
        end5 = n/5 * 5;
        end15= n/15 * 15;
        // cout << end3 << "|"<<end5<<"|"<<end15<<end15<<endl; 
        count3 = (end3 - start3) / 3  + 1;
        count5 = (end5 - start5) / 5  + 1;
        count15 = (end15 - start15) / 15  + 1;
        sum = ((start3 + end3) * count3 / 2) % MOD+ ((start5 + end5) * count5 / 2) % MOD- ((start15 + end15) * count15 / 2)% MOD;
        if (flag !=1) cout << sum % MOD<<endl;
        else cout << - (sum % MOD)<<endl;
    }
}