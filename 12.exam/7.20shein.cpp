#include<iostream>
#include<string>
#include<set>
#include<vector>

using namespace std;

const set<string> numMap = {
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
    "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
    "21", "22", "23", "24", "25", "26"
};

int main(){
    string numStr;
    cin >> numStr;
    vector<int> dp(numStr.size(), 0);
    if(numStr[0] != '0') dp[0] = 1;
    else{
        cout << 0 << endl;
        exit(0);
    }
    if(numStr[1] == '0') dp[1] = 1;
    for(int i=1; i<numStr.size(); i++){
        if(i==1 && numStr[i] == '0') continue;
        string tmp = numStr.substr(i-1, 2);
        // cout << tmp << endl;
        if(i+1 < numStr.size() && numStr[i+1] == '0'){
            if(numStr[i] == '1' || numStr[i] == '2'){
                dp[i] = dp[i-1];
                dp[i+1] = dp[i];
                i++;
                continue;;
            }
            cout << 0 << endl;
            exit(0);
            
        }
        else if(numMap.find(tmp) != numMap.end()){
            dp[i] = dp[i-1] + 1;
        }
        else{
            dp[i] = dp[i-1];
        }
    }
    cout << dp[numStr.size()-1] << endl;
}