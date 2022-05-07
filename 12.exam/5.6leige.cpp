#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > myMap;
    for(int i=0; i<n; i++){
        int time, value;
        cin >> time >> value;
        myMap.push_back(make_pair(time, value));
    }
    int value = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int time = myMap[i].first + myMap[j].first;
            if(time <= m){
                value = max(value, myMap[i].second + myMap[j].second);
            }
        }
    }
    cout << value <<endl;
}