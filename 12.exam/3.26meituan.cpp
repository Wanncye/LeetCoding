// #include<iostream>
// #include<string>
// using namespace std;

// int main(){
//     string myStr;
//     cin>>myStr;
//     int count[26]={0};
//     for(int i=0; i<myStr.size(); i++) count[myStr[i]-'a']++;
//     cout<<count[0]<<" "<<count[1]<<" "<<count[2]<<endl;
//     int subCount[3]={2,1,3};
//     int aNum = (count[0]+1)/subCount[0];
//     int bNum = count[1]/subCount[1];
//     int cNum = count[2]/subCount[2];
//     int minOut = min(aNum, min(bNum, cNum));
//     cout<<minOut<<endl;
    
// }


#include<iostream>
#include<vector>
using namespace std;

vector<int> path;
int maxSumTime7=0;

void backtracing(vector<int> cardNum, int index){
    int sum=0;
    for(int i:path) sum+=i;
    if(sum%7==0){
        maxSumTime7 = max(maxSumTime7, sum);
    }
    for(int i=index; i<cardNum.size(); i++){
        path.push_back(cardNum[i]);
        backtracing(cardNum, i+1);
        path.pop_back();
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> cardNum;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        cardNum.push_back(tmp);
    }
    backtracing(cardNum, 0);
    cout<<maxSumTime7<<endl;
}


// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// vector<int> path;
// int medianSum=0;

// int getmedianSum(vector<int> num){
//     sort(num.begin(), num.end());
//     int len = num.size();
//     return num[len/2];
// }

// void backtracing(vector<int> num, int index){
//     if(path.size()%2==1){
//         medianSum += getmedianSum(path);
//         for(int i:path) cout<<i<<" ";
//         cout<<endl;
//     }
//     for(int i=index; i<num.size(); i++){
//         path.push_back(num[i]);
//         backtracing(num, i+1);
//         path.pop_back();
//     }
// }

// int main(){
//     // int n;
//     // cin>>n;
//     // vector<int> num;
//     // for(int i=0; i<n; i++){
//     //     int tmp;
//     //     cin>>tmp;
//     //     num.push_back(tmp);
//     // }
//     vector<int> num = {2,3,1,4};
//     backtracing(num, 0);
//     cout<<medianSum<<endl;
// }



// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// vector<int> path;
// int medianSum=0;

// int getmedianSum(vector<int> num){
//     sort(num.begin(), num.end());
//     int len = num.size();
//     return num[len/2];
// }

// void backtracing(vector<int> num, int index){
//     if(path.size()%2==1){
        
//         medianSum += getmedianSum(path);
//     }
//     for(int i=index; i<num.size(); i++){
//         path.push_back(num[i]);
//         backtracing(num, i+1);
//         path.pop_back();
//     }
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<int> num;
//     for(int i=0; i<n; i++){
//         int tmp;
//         cin>>tmp;
//         num.push_back(tmp);
//     }
//     //backtracing(num, 0);
//     for(int i=0; i<num.size(); i++){
//         vector<int> subNum;
//         for(int j=i; j>=0; j--){
//             subNum.push_back(num[j]);
//             if(subNum.size()%2==1){
//                 for(int i:subNum) cout<<i<<" ";
//                 cout<<endl;
//                 medianSum += getmedianSum(subNum);
//             }
//         }
//     }
//     cout<<medianSum<<endl;
// }