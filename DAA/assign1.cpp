#include<bits/stdc++.h>
using namespace std;

int fib_iter(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    int a=0,b=1;
    int fib;
    for(int i=2; i<=n; i++){
        fib=a+b;
        a=b;
        b=fib;
    }
    return fib;
}

int fib_rec(int n){
    if(n<=1) return n;
    return fib_rec(n-1)+fib_rec(n-2);
}

int main(){
    for(int i=0; i<=5; i++){
        cout<<fib_iter(i)<<" ";
    }
    cout<<endl;
    for(int i=0; i<=5; i++){
        cout<<fib_rec(i)<<" ";
    }
    cout<<endl;

    return 0;
}