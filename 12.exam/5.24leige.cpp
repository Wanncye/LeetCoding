#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int INF = 10000 * 101 + 1;

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> f(k + 2, vector<int>(n, INF));
        f[0][src] = 0;
        for (int t = 1; t <= k + 1; ++t) {
            for (auto&& flight: flights) {
                int j = flight[0], i = flight[1], cost = flight[2];
                f[t][i] = min(f[t][i], f[t - 1][j] + cost);
            }
        }
        int ans = INF;
        for (int t = 1; t <= k + 1; ++t) {
            ans = min(ans, f[t][dst]);
        }
        return (ans == INF ? -1 : ans);
    }
};


int main(){
    Solution stl;
    int n = 3;
    vector<vector<int>> flights = {
        {0,1,600},
        {1,2,500},
        {0,2,1300}
    };
    int src = 0;
    int dst = 2;
    cout << stl.findCheapestPrice(n, flights, src, dst, 0) << endl;;
}