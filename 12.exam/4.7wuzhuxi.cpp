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