#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    char str;
    int w11 = 0;
    int l11 = 0;
    int w21 = 0;
    int l21 = 0;
    multimap<int, int> score11;
    multimap<int, int> score21;
    while(cin >> str){
        if(str=='W'){
            w11++;
            w21++;
        }else if(str == 'L'){
            l11++;
            l21++;
        }
        if(abs(w11-l11)>=2 && w11+l11 >= 11 ||  str == 'E'){
            score11.insert(make_pair(w11, l11));
            w11 = 0;
            l11 = 0;
        }
        if(abs(w21-l21)>=2 && w21+l21 >= 21 ||  str == 'E'){
            score21.insert(make_pair(w21, l21));
            w21 = 0;
            l21 = 0;
        }
        if(str == 'E') break;
    }
    for(auto i : score11){
        cout << i.first << ":" <<  i.second << endl; 
    }
    
    cout << endl;

    for(auto i : score21){
        cout << i.first << ":" <<  i.second << endl; 
    }
}