#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target){
        if(target == "0000") return 0;
        unordered_set<string> deadendsSet(deadends.begin(), deadends.end());
        if(deadendsSet.count("0000")) return -1;

        unordered_set<string> seen = {"0000"};
        auto num_pre = [] (char x) -> char {
            return (x == '0' ? '9' : x - 1);
        };
        auto num_suc = [] (char x) -> char {
            return (x == '9' ? '0' : x + 1);
        };
        auto get = [&] (string& x) -> vector<string> {
            vector<string> next;
            for(int i = 0; i < x.size(); i++){
                char num = x[i];
                x[i] = num_pre(num);
                next.push_back(x);
                x[i] = num_suc(num);
                next.push_back(x);
                x[i] = num;
            }
            return next;
        };

        queue<pair<string, int>> q;
        q.emplace("0000", 0);

        while (!q.empty()) {
            auto [status, step] = q.front();
            q.pop();
            for (auto&& next_status: get(status)) {
                if (!seen.count(next_status) && !deadendsSet.count(next_status)) {
                    if (next_status == target) {
                        return step + 1;
                    }
                    q.emplace(next_status, step + 1);
                    seen.insert(move(next_status));
                }
            }
        }

        return -1;
    }
};

int main(){
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    Soultion stl;
    stl.openLock(deadends, target);
}