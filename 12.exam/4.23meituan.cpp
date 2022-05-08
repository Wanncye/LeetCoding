// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;
//     string origin;
//     cin >> origin;
//     cout<<origin<<endl;
//     int C_count=0;
//     int J_count=0;
//     for(int i=0; i<origin.size(); i++){
//         if(origin[i]=='C') C_count++;
//         if(origin[i]=='J') J_count++;
//     }
//     if(abs(C_count-J_count) > 1){// 大于1，无法满足条件
//         cout<<-1<<endl;
//         return -1;
//     }
//     unordered_map<char, char> cjMap;
//     cjMap.insert(make_pair<char, char>('C', 'J'));
//     cjMap.insert(make_pair<char, char>('J', 'C'));

//     int res = 0;
//     if (C_count > J_count){ // 用C语言的人多，那么只可以CJCJ....这种排列
//         char target = 'C';
//         for (int i=0;i<n;i++){
//             if (origin[i]!=target){
//                 res += 1;
//             }
//             target = cjMap[target];
//         }
//     }else if (C_count < J_count){ // 用Java的人多，只可以JCJC....这种排列
//         char target = 'J';
//         for (int i=0;i<n;i++){
//             if (origin[i]!=target){
//                 res += 1;
//             }
//             target = cjMap[target];
//         }
//     }else { // 二者一样多，理论上可以随意排列，但是还得看看哪个改动次数多
//         int count_res1 = 0;
//         int count_res2 = 0;
//         char target1 = 'C';
//         for (int i=0;i<n;i++){
//             if (origin[i]!=target1){
//                 count_res1 += 1;
//             }else {
//                 count_res2 += 1;
//             }
//             target1 = cjMap[target1];
//         }
//         res = min(count_res1, count_res2);
//     }
//     cout<<res/2<<endl;
// }


#include<iostream>
#include<vector>
using namespace std;
bool isOrder(vector<int> arr){
    for(int i=1; i<arr.size(); i++){
        if(arr[i]<arr[i-1]) return false;
    }
    return true;
}

int main(){
    int group;
    cin>>group;
    while(group--){
        int n;
        cin>>n;
        vector<int> nums(n);
        vector<int> color(n);
        for(int i=0; i<n; i++){
            cin>>nums[i];
        }
        for(int i=0; i<n; i++){
            cin>>color[i];
        }
        int count=10000;
        while(count--){
            for(int i=1; i<n; i++){
                if(nums[i] < nums[i-1] && color[i] != color[i-1]){
                    swap(nums[i], nums[i-1]);
                    swap(color[i], color[i-1]);
                }
            }
            if(isOrder(nums)){
                cout<<"YES"<<endl;
                break;
            }
        }
        if(count == -1){
            cout<<"NO"<<endl;
        }
    }
}