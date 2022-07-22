#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& nums, int left, int right, int mid){
    // vector<int> tmp(right - left + 1, 0);
    // int i = left, j = mid+1;
    // int index = 0;
    // while(i <= mid && j <= right){
    //     if(nums[i] <= nums[j]) 
    //         tmp[index++] = nums[i++];
    //     else 
    //         tmp[index++] = nums[j++];
    // }
    // while(i <= mid) 
    //     tmp[index++] = nums[i++];
    // while(j <= right) 
    //     tmp[index++] = nums[j++];
    // // for(int i=left; i <= right; i++){
    // //     nums[i] = tmp[i];
    // // }
    // for(int i=0; i < tmp.size(); i++){
    //     nums[i+left] = tmp[i];
    // }


    int i = left;
    int j = mid+1;
    int index = 0;
    vector<int> tmp(right-left+1, 0);
    while(i <= mid && j <= right){
        if(nums[i] <= nums[j]) tmp[index++] = nums[i++];
        else tmp[index++] = nums[j++];
    }
    while(i <= mid){
        tmp[index++] = nums[i++];
    }
    while(j <= right){
        tmp[index++] = nums[j++];
    }
    for(int i=0; i<tmp.size(); i++){
        nums[left+i] = tmp[i];
    }

}

void mergeSort(vector<int>& nums, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, right, mid);
        for(int i : nums){
            cout << i << " ";
        }
        cout << endl;
    }
    
}

int main(){
    vector<int> nums = {1,6,9,3,7,2};
    mergeSort(nums, 0, nums.size()-1);
    for(int i : nums){
        cout << i << " ";
    }
    cout << endl;

}