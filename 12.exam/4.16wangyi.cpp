// #include<iostream>
// #include<math.h>
// using namespace std;

// #define emin5 1e-05
// int main(){
//     int a, b, c;
//     int n;
//     cin >> n;
//     while(n--){
//         cin >> a >> b >> c;
//         float x = (float)__INT_MAX__;
//         while(true){
//             float tmp = a * sqrt(x) + b * log(x);
//             //cout << tmp << endl;
//             //cout<<emin5<<endl;
//             cout<<tmp<<endl;
//             if(abs(tmp) < emin5){
//                 cout << float(x) << endl;
//                 break;
//             }
//             x = x / 2;
//             //cout << x << endl;
//         }
        
//     }
// }



// #include<iostream>
// #include<math.h>
// #include<vector>
// #include<map>
// #include<unordered_set>
// using namespace std;

// int ans=0;

// bool isSmallerThanK(string str, int k){
//     map<char,int> myMap;
//     for(char i : str){
//         myMap[i]++;
//     }
//     for(auto &i :myMap){
//         if(i.second>k) return false;
//     }
//     return true;
// }

// unordered_set<string> seenSet;

// void backtracking(string str, int k){
//     for(int i=0; i<str.size(); i++){
//         char tmp = str[i];
//         str.erase(str.begin()+i, str.begin()+i+1);
//         if(seenSet.find(str) != seenSet.end()){
//             return;
//         }else{
//             seenSet.insert(str);
//         }
//         // cout<<str<<endl;
//         if(str.size()==1){
//             ans++;
//             return;
//         }
//         if(isSmallerThanK(str, k)){
//             ans++;
//         }
//         backtracking(str, k);
//         str.insert(str.begin()+i, tmp);
//     }
// }

// int main(){
//     int n=5,k=1;
//     string myStr="abcab";
//     backtracking(myStr, k);
//     cout<<ans<<endl;
//     for(auto& i:seenSet){
//         cout<<i<<endl;
//     }
// }




#include<iostream>
#include<math.h>
#include<vector>
#include<map>
using namespace std;

bool isSix(long long n){
    int sum=0;
    for(int i=1; i<=n; i++){
        if(n%i == 0) sum++;
        if(sum > 6) return false;
    }
    if(sum==6) return true;
    else return false;
}

int main(){
    // int n;
    // cin>>n;
    vector<int> vec = {2 ,6 ,3, 9};
    // for(int i=0; i<n; i++){
    //     int tmp;
    //     cin>>tmp;
    //     vec.push_back(tmp);
    // }

    int ans=0;
    for(int i=0; i<vec.size(); i++){
        for(int j=0; j<i; j++){
            long long multply = vec[i] * vec[j];
            if(isSix(multply)) ans++;
        }
    }
    cout << ans << endl;
}