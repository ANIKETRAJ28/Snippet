#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

int Stack[10], top = -1;

void push(int val) {
    top++;
    if(top >= 10) {
        cout<<"Stack Overflow\n";
        return;
    }
    Stack[top] = val;
    return;
}

void pop() {
    if(top == -1) {
        cout<<"Stack Underflow\n";
        return;
    }
    top--;
    return;
}

void display() {
    if(top == 10)
        for(int i = top-1; i >= 0 ; i--)
            cout<<Stack[i]<<" ";
    else
        for(int i = top; i >= 0 ; i--)
            cout<<Stack[i]<<" ";
    cout<<"\n";
}


int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    push(8);
    push(9);
    push(10);
    push(10);
    display();
    pop();
    pop();
    display();
    pop();
    pop();
    display();
    return 0;
}