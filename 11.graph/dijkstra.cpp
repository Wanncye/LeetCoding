#include<iostream>
#include<vector>
using namespace std;

vector<int> getDistMinValueAndIndex(vector<int>dist, vector<bool>visited){
    int min=__INT_MAX__;
    int minIndex;
    for(int i=0;i<dist.size();i++){
        if(visited[i]==false){
            if(dist[i]<min){
                min = dist[i];
                minIndex = i;
            }
        }
    }
    return {min, minIndex};
}

vector<int> dijkstra(vector<vector<int>> graph){
    int len = graph.size();
    vector<bool> visited(len, false);
    vector<int> dist(len, __INT_MAX__);
    dist[0]=0;
    while(len--){
        vector<int> valueAndIndex = getDistMinValueAndIndex(dist,visited);
        int curMinValue = valueAndIndex[0];
        int curMinValueIndex = valueAndIndex[1];
        visited[curMinValueIndex] = true;
        for(int i=0; i<graph[curMinValueIndex].size(); i++){
            if(graph[curMinValueIndex][i] != 0 && graph[curMinValueIndex][i] != -1){
                dist[i] = min(curMinValue+graph[curMinValueIndex][i], dist[i]);
            }
        }
        for(int i:dist) cout<<i<<" ";
        cout<<endl;
    }
    return dist;
}

int main(){
    vector<vector<int> > graph={
        {0,4,2,3,-1},
        {4,0,1,1,5},
        {2,1,0,2,-1},
        {3,1,2,0,7},
        {-1,5,-1,7,0}
    };
    dijkstra(graph);//计算0节点到所有节点的最短路径
}