#include <iostream>
using namespace std;
int binsearch(int a[], int n, int x,int pre,int next){
    int mid = pre + (next - pre)/2;
    while(next >= pre){
        if (a[mid] == x) return mid;
        if (a[mid] > x) return binsearch(a,n,x,pre,mid-1);
        if (a[mid] < x) return binsearch(a,n,x,mid +1,next);
    }
    return -1;
    
}
int main(){
    int arr[]  = {3,4,7,8,11,12,15,20,22,29,40,45,46,48,49,50,52,56,66,76,81,84,92,98,100};
    cout << binsearch(arr,25,10,0,25);
}