#include<iostream>
#include<vector>

using namespace std;


int BNum = 0;
int oneAreaBqi = 0;
int ansB = 0;
int ansW = 0;

void dfs(vector<vector<char> >& go, int r, int c, char target, vector<vector<bool> >& visited){
    int nr = go.size();
    int nc = go[0].size();

    visited[r][c] = true;

    BNum++;

    if (r - 1 >= 0 && go[r-1][c] == target && visited[r-1][c] == false){
        dfs(go, r - 1, c, target, visited);
    }else if(r - 1 >= 0 && go[r-1][c] == 'N'){
        oneAreaBqi++;
    }//上
    if (r + 1 < nr && go[r+1][c] == target && visited[r+1][c] == false){
        dfs(go, r + 1, c, target, visited);
    }else if(r + 1 < nr && go[r+1][c] == 'N'){
        oneAreaBqi++;
    }//下
    if (c - 1 >= 0 && go[r][c-1] == target && visited[r][c-1] == false){
        dfs(go, r, c - 1, target, visited);
    }else if(c - 1 >= 0 && go[r][c-1] == 'N'){
        oneAreaBqi++;
    }//左
    if (c + 1 < nc && go[r][c+1] == target && visited[r][c+1] == false){
        dfs(go, r, c + 1, target, visited);
    }else if(c + 1 < nc && go[r][c+1] == 'N'){
        oneAreaBqi++;
    }//右

    

}



int main(){

    int n;
    // cin >> n;
    n=3;
    vector<vector<bool> > visitedB(n, vector<bool>(n, false));
    vector<vector<bool> > visitedW(n, vector<bool>(n, false));
    vector<vector<char> > go(n, vector<char>(n));
    for(int i=0; i < n ; i++){
        for(int j=0; j < n; j++){
            cin >> go[i][j];
            cout << go[i][j];
        }
    }
    go = {
        {'W', 'W', 'W'},
        {'N', 'B', 'B'},
        {'B', 'N', 'N'}
    };
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            if(go[i][j] == 'B' && visitedB[i][j] == false){
                BNum = 0;
                oneAreaBqi = 0;
                dfs(go, i, j, 'B', visitedB);
                if(oneAreaBqi >= 2){
                    ansB += BNum;
                }
            }else if(go[i][j] == 'W' && visitedW[i][j] == false){
                BNum = 0;
                oneAreaBqi = 0;
                dfs(go, i, j, 'W', visitedW);
                if(oneAreaBqi >= 2){
                    ansW += BNum;
                }
            }
        }
    }
    cout << "B " << ansB << " W " << ansW << endl;
}



// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;
// // we have defined the necessary header files here FOR this problem.
// unordered_map<int, int> path;
// void getvec(vector<int>& ref, int l, int r){
//     if(l >= r) return;
//     int mid = l + (r - l) / 2;
//     getvec(ref, l, mid);
//     getvec(ref, mid + 1, r);
//     vector<int> temp(ref.size());
//     for(int i = 0; i < ref.size(); ++i){
//         temp[i] = ref[i];
//     }
//     int i = l, j = mid + 1, n = 0;
//     for(int k = l; k <= r; ++k){
//         if(i == mid + 1){
//             ref[k] = temp[j++];
//         }else if(j == r + 1){
//             ref[k] = temp[i];
//             path[temp[i++]] += n;
//         }else{
//             if(temp[i] > temp[j]){
//                 ref[k] = temp[j++];
//                 ++n;
//             }else{
//                 ref[k] = temp[i];
//                 path[temp[i++]] += n;
//             }
//         }
//     }
    
// }
// // IF additional header files are needed IN your program, please IMPORT here.
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> ref(n);
    
//     for(int i = 0; i < n; ++i){
//         cin >> ref[i];
//         path[ref[i]] = 0;
//     }
//     vector<int> res(ref);
//     getvec(ref, 0, n - 1);
    
//     for(int i = 0; i < n - 1; ++i){
//      cout << path[res[i]] << ' ';
//     }
//     cout << path[res[n - 1]];
    
    
//     return 0;
// }