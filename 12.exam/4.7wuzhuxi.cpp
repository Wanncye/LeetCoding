#include<iostream>
#include<sstream>
using namespace std;


int main(){
    string str;
    getline(cin, str);
    string x;
    stringstream ss(str);
    while(ss >> x){
        cout << x << endl;
    }
}

// //下面这个方法也能够实现上面的要求
// #include <iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;

// int main () {
//     vector<string> strVector;
//     string tmp;
//     while(cin>>tmp){
//         strVector.push_back(tmp);
//         if(cin.get()=='\n'){
//             sort(strVector.begin(), strVector.end());
//             for(string i:strVector) cout<<i<<" ";
//             cout<<endl;
//             strVector.clear();
//         }
//     }
// }