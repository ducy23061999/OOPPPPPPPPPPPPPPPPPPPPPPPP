// quick sort asc
#include <iostream>
using namespace std;
void swap(int *a, int *b){
    int  c = *a;
    *a = *b;
    *b = c;
}
int partition(int A[], int low, int hight){
    int pivot = A[hight];
    int i = (low - 1);
    for (int j = low; j <= hight-1;j++){
        if (A[j] <= pivot){
            i++;
            swap(&A[i],&A[j]);
        }
    }
    swap(A[i + 1], A[hight]);
    return (i  +1);
}
void quicksort(int A[], int low, int hight){
    if (low < hight){
        int pi = partition(A,low,hight);
        quicksort(A,low, pi -1);
        quicksort(A,pi+1,hight);
    }
}
void pri(int A[], int n){
    
    for(int i = 0; i < n; i++)
    {
        cout << A[i]<<" ";
    }
    cout << endl;
    
}
int main(){
    int A[] = {3,7,12,8,23,42,12,43,6,10};
    int n = sizeof(A)/sizeof(A[0]) - 1; 
    quicksort(A,0,n);
    pri(A,n);
}
