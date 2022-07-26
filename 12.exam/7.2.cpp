#include<iostream>
#include<vector>
using namespace std;
int n = 10005; 
int father[10005][2];

// 并查集初始化
void init() {
    for (int i = 0; i < n; ++i) {
        father[i][0] = i;
    }
}
// 并查集里寻根的过程
int find(int u) {
    if(u == father[u][0]){
        return u;
    }
    int v = father[u][0];
    if(father[u][1] >= father[v][1]){
        return find(v);
    }
    father[v][0] = u;
    return u;
    // return u == father[u][0] ? u : father[u][0] = find(father[u][0]);
}
// 将v->u 这条边加入并查集
void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return ;
    father[u][1] += 2;
    father[v][1] += 2;
    int m = father[u][1];
    int n = father[v][1];
    if(m > n){
        father[u][0] = v;
    }else{
        father[v][0] = u;
    }
    // cout << father[u][1]
}
// 判断 u 和 v是否找到同一个根
bool same(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}
int main(){
    init();
    int n;
    cin >> n;
    vector<int> ref(n);
    for(int i = 0; i < n; ++i){
        cin >> ref[i];
        father[i][1] = ref[i];
    }
    int m;
    cin >> m;
    vector<vector<int> > path(m, vector<int>(2));
    for(int i = 0; i < m; ++i){
        cin >> path[i][0] >> path[i][1];
    }
    for(int i = 0; i < m; ++i){
        int u = path[i][0] - 1, v = path[i][1] - 1;
        if(same(u, v)){
            continue;
        }
        join(u, v);
    }
    int res = father[0][1];
    for(int i = 1; i < n; ++i){
        if(res > father[i][1]){
            res = father[i][1];
        }
    }
    cout << res << endl;

    return 0;
}