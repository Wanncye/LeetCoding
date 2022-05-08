#include<iostream>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n==0) break;
        int ans = 0;
        int rem = 0;
        while(n){
            ans += n / 3;
            rem = n % 3;
            if(rem == 2 && n/3 == 0){
                ans++;
                break;
            }else if(rem == 1 && n/3 == 0) break;
            n = n / 3 + rem;
        }
        cout<<ans<<endl;
    }
}