#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;


double diff = 1e-8;

bool isRightAngle(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
    double dist_1_2 =  sqrt(pow(abs(p1.first - p2.first), 2) + pow(abs(p1.second - p2.second), 2));
    double dist_1_3 =  sqrt(pow(abs(p1.first - p3.first), 2) + pow(abs(p1.second - p3.second), 2));
    double dist_2_3 =  sqrt(pow(abs(p2.first - p3.first), 2) + pow(abs(p2.second - p3.second), 2));
    
    if(abs(pow(dist_1_2, 2) + pow(dist_1_3, 2) - pow(dist_2_3, 2)) < diff || 
        abs(abs(pow(dist_1_2, 2) - pow(dist_1_3, 2)) - pow(dist_2_3, 2)) < diff) 
        return true;
    else return false;
}

int main(){
    int N;
    cin >> N;
    vector<pair<int, int> > coord(N, {0, 0});
    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        coord[i] = {x, y};
    }
    int count = 0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            for(int k=j+1; k<N; k++){
                if(isRightAngle(coord[i], coord[j], coord[k])) count++;
            }
        }
    }
    cout << count << endl;
}