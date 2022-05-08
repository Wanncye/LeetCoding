#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int main(){
    
    // string str;
    // getline(cin, str);
    // stringstream ss(str);
    // string x;
    // vector<string> strVector;
    // while(ss >> x){
    //     strVector.push_back(x);
    // }
    // cout << strVector.back().size() << endl;

    string str;
    while(cin>>str){
        if(cin.get()=='\n'){
            cout<<str.size()<<endl;
        }
    }

}