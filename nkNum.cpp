#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    if(k == 1) cout<<1<<endl;
    else{
        k--;
        int base = 10;
        int res;
        while(k > 0){
            res = base;
            while(res<n && k>0){
                res*=10;
                k--;
            }
            res=res/10;
            while(res<n && k>0){
                res++;
                k--;
            }
            base++;
        }
        cout<<res<<endl;
    }
}