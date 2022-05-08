// #include<iostream>
// #include<vector>
// #include<list>
// #include<iomanip>
// using namespace std;
// double getAvg(vector<double> arr){
//     double avg=0;
//     double sum=0;
//     for(double i:arr){
//         sum+=i;
//     }
//     double len = arr.size();
//     avg = sum/len;
//     return avg;
// }
// int main(){
//     // int n;
//     // cin>>n;
//     // vector<double> arr;
//     // for(int i=0;i<n;i++){
//     //     int tmp;
//     //     cin>>tmp;
//     //     arr.push_back(tmp);
//     // }

//     vector<double> arr={1,2,3,4,5};
//     int ans=0;
//     while(true){
//         double curAvg = getAvg(arr);
//         // cout<<curAvg<<endl;
//         // int len = arr.size();
//         int delCount=0;
//         for(int i=0; i<arr.size(); i++){
//             if(arr[i]>curAvg){
//                 // int start=i-delCount;
//                 // int end=i-delCount+1;
//                 // cout<< start<<" "<<end<<endl;
//                 // arr.erase(arr.begin()+i-delCount, arr.begin()+i-delCount+1);
//                 arr.erase(arr.begin()+i, arr.begin()+i+1);
//                 delCount += 1;
//                 i -= 1;
//             }
//         }
        
//         if(delCount==0) break;
//         ans++;
//     }
//     cout<<ans<<endl;
    
    
// }
    




// #include<iostream>
// #include<vector>
// using namespace std;


// int indexOf(vector<long long> arr, int i){
//     for(int n=0;n<arr.size(); n++){
//         if(arr[n]==i) return n;
//     }
//     return -1;
// }

// int main(){
//     long long p,q;
//     cin>>p>>q;
// //     int p=1;
// //     int q=6;
//     vector<long long> myVec;
//     if(q==0){
//         cout<<-1<<endl;
//         return 0;
//     }
//     p = p % q;
//     while(true){
//         myVec.push_back(p);
//         p *= 10;
//         p = p % q;
//         if(p==0){
//             cout<<-1<<endl;
//             break;
//         }
//         if(indexOf(myVec, p)>=0){
//             int first=indexOf(myVec, p);
//             int second = myVec.size() - first;
//             cout<<first<<" "<<second<<endl;
//             break;
//         }
//     }
// }


