#include<iostream>
#include<vector>
using namespace std;

int getMinDist(vector<int>& curDist, vector<bool>& visited){
    int tmpMin = __INT_MAX__;
    int index = -1;
    for(int i = 0; i < curDist.size(); i++){
        if(curDist[i] >= 0 &&  curDist[i] <= tmpMin && visited[i] == false){
            index = i;
            tmpMin = curDist[i];
        }
    }
    visited[index] = true;
    return index;
}


vector<int> dijkstra(vector<vector<int>> graph){
    int numNode = graph.size();
    vector<int> curDist(numNode, __INT_MAX__);
    vector<bool> visited(numNode, false);
    curDist[0] = 0;
    while(true){
        // 首先要获得0号节点与其他节点之间的最小距离，以及访问情况
        int index = getMinDist(curDist, visited);
        if(index == -1){
            break;
        }else{
            vector<int> curNode = graph[index];
            for(int i=0; i<curNode.size(); i++){
                if(curNode[i] > 0 && visited[i] == false) curDist[i] = min(curDist[index]+curNode[i], curDist[i]);
            }
        }
    }
    return curDist;
}

int main(){
    vector<vector<int> > graph={
        {0,4,2,3,-1},
        {4,0,1,1,5},
        {2,1,0,2,-1},
        {3,1,2,0,7},
        {-1,5,-1,7,0}
    };
    vector<int> dist =  dijkstra(graph);//计算0节点到所有节点的最短路径
    for(int i : dist){
        cout << i << " ";
    }
    cout << endl;
}