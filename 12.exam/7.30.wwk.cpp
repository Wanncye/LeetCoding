#include<iostream>
#include<vector>

using namespace std;

vector<int> path;
vector<int> minPaht;
int res = __INT_MAX__;
int maxDist = -1;
int maxDistLeft = 0;
int maxDistRight = 0;

int getDist(vector<int> location, vector<int> path){
    int res = 0;
    for(int i = 0; i < location.size(); i++){
        int minDist = __INT_MAX__;
        for(int j=0; j < path.size(); j++){
            minDist = min(minDist, abs(location[i] - path[j]));
        }
        res += minDist;
    }
    return res;
}

void backtracing(vector<int> location, int areaNum, int acidNum, int index){
    if(path.size() == acidNum){
        int tmp = getDist(location, path);
        if(tmp < res){
            res = tmp;
            minPaht = path;
        }
        return;
    }

    for(int i = index; i <= location.size(); i++){
        path.push_back(location[i]);
        backtracing(location, areaNum, acidNum, i+1);
        path.pop_back();
    }
}


int main(){
    int areaNum;
    int acidNum;
    cin >> areaNum >> acidNum;
    vector<int> location(areaNum, 0);

    for(int i=0; i<areaNum; i++){
        cin >> location[i];
    }

    vector<vector<int>> dp(areaNum, vector<int>(areaNum, 0));
    for(int i=0; i<areaNum; i++){
        for(int j=0; j<areaNum; j++){
            dp[i][j] = abs(location[i] - location[j]);
        }
    }
    for(vector<int> i : dp){
        for(int j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    vector<int> sumVec(areaNum, 0);
    for(int i=0; i<areaNum; i++){
        sumVec[i] = sum()
    }
    // backtracing(location, areaNum, acidNum, 0);
    // for(int i : minPaht) cout << i << " ";
    // cout << endl;
    // cout << res << endl;
}
