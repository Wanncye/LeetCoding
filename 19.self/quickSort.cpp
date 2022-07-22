#include<iostream>
#include<vector>

using namespace std;

void quickSort(vector<int>& nums, int left, int right){
    int mid = (left + right) / 2;
    int tmp = nums[mid];
    int i = left;
    int j = right;
    while(i <= j){
        while(nums[i] < tmp){
            i++;
        }
        while(nums[j] > tmp){
            j--;
        }
        if(i <= j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    if(j > left) quickSort(nums, left, j);
    if(right > i) quickSort(nums, i, right);

}



int main(){
    vector<int> nums = {1,6,3,9,2,7};
    quickSort(nums, 0, nums.size()-1);
    for(int i : nums){
        cout << i << " ";
    }
    cout << endl;
}