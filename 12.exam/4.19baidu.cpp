// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     string str;
//     cin>>str;
//     for(int i=0; i<str.size(); i++){
//         if(str[i]>='A' && str[i]<='Z'){
//             str[i] = str[i]+32;
//         }
//     }
//     vector<char> want = {'e', 'a', 's', 'y'};
//     int wantIndex = 0;
//     int count = 0;
//     for(int i=0; i<str.size();i++){
//         char c = str[i];
//         if(c == want[wantIndex]){
//             wantIndex++;
//             if(c == 'y'){
//                 wantIndex=0;
//             	count++;
//             }
//         }
//     }
//     cout<<count<<endl;
// }


// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int attack,defence;
//     vector<int> attackVec;
//     vector<int> defenceVec;
//     for(int i=0; i<n; i++){
//         cin>>attack>>defence;
//         attackVec.push_back(attack);
//         defenceVec.push_back(defence);
//     }
//     int attackSum=0;
//     int defenceSum=0;
//     vector<int> ansIndex;
//     for(int i=0; i<n; i++){
//         if(attackVec[i]<0 && defenceVec[i]<0) continue;
//         if(attackVec[i] + defenceVec[i] > 0){
//             if(ansIndex.size()==0 || (attackSum + attackVec[i] > 0 && defenceSum + defenceVec[i])){
//                 ansIndex.push_back(i);
//                 attackSum += attackVec[i];
//                 defenceSum += defenceVec[i];
//             }
//         }
//     }
//     int sum=0;
//     for(int i:ansIndex){
//         sum += attackVec[i] + defenceVec[i];
//     }
//     cout<<sum<<endl;
    
// }



#include<iostream>
#include<vector>
using namespace std;
using pii = pair<int,int>;
vector<pii> data;
int ans=0;
int n;


void dfs(int depth, int current_attack, int current_defence){
    if(depth == (int)data.size()){
        if(current_attack>0 && current_defence>0){
            ans = max(ans, current_defence + current_attack);
        }
        return;
    }
    dfs(depth+1, current_attack+data[depth].first, current_defence+data[depth].second);
    dfs(depth+1, current_attack, current_defence);
}

void solve(){
    dfs(0,0,0);
    cout<<ans<<endl;
}


int main() {
//  cin >> n;
n=5;
 data.resize(n);
 data[0].first = -5;
data[1].first = 8;
data[2].first = 6;
data[3].first = 2;
data[4].first = -8;
data[0].second = 7;
data[1].second = -6;
data[2].second = -3;
data[3].second = 1;
data[4].second = -5;
 solve();
 return 0;
}

