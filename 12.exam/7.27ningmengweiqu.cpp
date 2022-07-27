#include<iostream>
#include<map>
#include<set>

using namespace std;

int main(){
    int nPeople, nOperator;
    cin >> nPeople >> nOperator;
    map<int, set<int>> siteAndQue;
    for(int i=0; i<nPeople; i++){
        siteAndQue[i] = {i};
    }
    
    for(int i=0; i<nOperator; i++){
        char op;
        int op1, op2;
        cin >> op >> op1 >> op2;
        op1 -= 1;
        op2 -= 1;
        if(op == 'C'){
            set<int> nullSet;
            for(int i : siteAndQue[op1]){
                siteAndQue[op2].insert(i);
            }
            siteAndQue[op1] = nullSet;
        }
        if(op == 'Q'){
            bool tag = false;
            for(int i=0; i<nPeople; i++){

                if(siteAndQue[i].find(op1) != siteAndQue[i].end() 
                && siteAndQue[i].find(op2) != siteAndQue[i].end()){
                    tag = true;
                    break;
                }
            }
            if(tag == true) cout << "YES" << endl;
            else cout << "NO" << endl;
        }   
    }
}