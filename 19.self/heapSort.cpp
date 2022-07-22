#include<iostream>
#include<vector>

using namespace std;

void adjust(vector<int>& nums, int len, int index){
    int left = 2*index + 1;
    int right = 2*index + 2;
    int maxIndx = index;
    if(left < len && nums[left] > nums[maxIndx]) maxIndx = left;
    if(right < len && nums[right] > nums[maxIndx]) maxIndx = right;

    if(maxIndx != index){
        swap(nums[index], nums[maxIndx]);
        adjust(nums, len, maxIndx);
    }
}


void buildHeap(vector<int>& nums){
    for(int i=nums.size()/2-1; i>=0; i--){
        adjust(nums, nums.size(), i);
    }
}


void heapSort(vector<int>& nums){
    buildHeap(nums);
    for(int i : nums){
        cout << i << " ";
    }
    cout << endl;
    for(int i=nums.size()-1; i>0; i--){
        swap(nums[i], nums[0]);
        adjust(nums, i, 0);
        for(int i : nums){
            cout << i << " ";
        }
        cout << endl;
    }
}



int main(){
    vector<int> nums = {1,6,9,3,7,2};
    heapSort(nums);
}