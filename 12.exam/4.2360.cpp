// #include<iostream>
// using namespace std;

// int main(){
//     int a='A';
//     int b='z';
//     cout<<a<<" "<<b<<endl;
//     int n;
//     cin>>n;
//     int ans=0;
//     for(int i=0; i<n; i++){
//         string name;
//         cin>>name;
//         int nameLength=0;
//         bool flag=true;
//         for(char j : name){
//             if(j >= 'A' && j <= 'z'){
//                 nameLength++;
//             }
//             else{
//                 flag=false;
//                 break;
//             }
//         }
//         if(flag==true && nameLength <= 10) ans++;
//         cout<<ans<<endl;
//     }
//     cout<<ans<<endl;
// }

#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int zhuN,weiN,binN;
    cin>>zhuN>>weiN>>binN;
    unordered_set<string> zhuSet;
    unordered_set<string> weiSet;
    unordered_set<string> binSet;
    for(int i=0; i<zhuN; i++){
        string tmp;
        cin>>tmp;
        zhuSet.insert(tmp);
    }
    for(int i=0; i<weiN; i++){
        string tmp;
        cin>>tmp;
        weiSet.insert(tmp);
    }
    for(int i=0; i<binN; i++){
        string tmp;
        cin>>tmp;
        binSet.insert(tmp);
    }
    for(string j:zhuSet) cout<<j<<" ";
    cout<<endl;
    for(string j:weiSet) cout<<j<<" ";
    cout<<endl;
    for(string j:binSet) cout<<j<<" ";
    cout<<endl;
    int juN;
    cin>>juN;
    for(int i=0; i<juN+1; i++){
        string tmp;
        getline(cin,tmp);
        if(tmp=="") continue;
        int start=0;
        vector<string> word;
        for(int j=0; j<tmp.size(); j++){
            if(tmp[j]==' '){
                string substr = tmp.substr(start, j-start);
                start=j+1;
                word.push_back(substr);
            }
        }
        word.push_back(tmp.substr(start, 100));
        // for(string j:word) cout<<j<<" ";
        // cout<<endl;
        vector<int> record(word.size(),0);
        for(int j=0; j<word.size(); j++){
            // cout<<word[j]<<endl;
            if(zhuSet.find(word[j]) != zhuSet.end()){
                // cout<<"zhu"<<endl;
                record[j] = 1;
            }
            else if(weiSet.find(word[j]) != weiSet.end()){
                // cout<<"wei"<<endl;
                record[j] = 2;
            }
            else if(binSet.find(word[j]) != binSet.end()){
                // cout<<"bin"<<endl;
                record[j] = 3;
            }
        }
        bool tag=true;
        // for(int j:record) cout<<j<<" ";
        // cout<<endl;
        for(int i=0; i<record.size()-1; i++){
            // cout<<record[i]<<endl;
            if(record[i]==2 && record[i+1]==2){
                tag=false;
                break;
            }
            else if(record[i]>record[i+1]){
                tag=false;
                break;
            }
            else if(record[i] == 0 ){
                tag=false;
                break;
            }

        }
        if(tag==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
}


// 3 3 3
// i you he
// am is are
// yours his hers
// 5
// i am yours
// you is his
// he are hers yours
// i am am yours
// is his