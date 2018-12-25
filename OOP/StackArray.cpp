#include <iostream>
using namespace std;
const int MAX = 100;
class Stack{
    int A[MAX],pos;
    public: bool isEmpty();
            bool isFull();
            void pop();
            void push(int n);
            void in();
            Stack();
};
Stack::Stack(){
    this->pos = -1;
}
bool Stack::isEmpty(){
    if (pos == -1)
        return true;
    else 
        return false;
} 
bool Stack::isFull(){
    if (pos == 100)
    return true;
    else return false;
}
void Stack::push(int n){
    A[++pos] = n;
}
void Stack::pop(){
    pos--;
}
void Stack::in(){
    cout << endl;
    for (int i = pos; i >= 0; i--){
        cout << A[i] <<" ";
    }
    cout << endl;
}
int main(){
    Stack st;
    if (st.isEmpty()) cout << "Empty"<<endl;
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.pop();
    if (st.isEmpty()) cout << "Empty"<<endl;
    st.in();

    return 0;
}