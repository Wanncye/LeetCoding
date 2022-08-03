// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int a=2;
int f(int n){
    static int a=3;
    int t=0;
    if(n%2){
        static int a=4;
        t+=a++;
    }else{
        static int a=5;
        t+=a++;
    }
    return t+a++;
}
int main()
{
    int x=3;
    if(a<=x<100) cout << "true" <<endl;
}