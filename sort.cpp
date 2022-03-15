#include <iostream>
#include <vector>
using namespace std;

class mySort{
public:
    vector<int> array;
    mySort(vector<int> arr):array(arr){};

    void myPrint(){
        for(int i:array) cout<<i<<" ";
        cout<<endl;
    }
    
    vector<int>& insertSort(){
        int len = array.size();
        int preIndex,cur;
        for(int i=1; i<len; i++){
            preIndex = i-1;
            cur = array[i];
            while(preIndex>=0 && array[preIndex]>cur){
                array[preIndex+1] = array[preIndex];
                preIndex--;
            }
            array[preIndex+1] = cur;
        }
        myPrint();
        return array;
    };

    vector<int>& bubbleSort(){
        int len = array.size();
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                while(array[j] > array[j+1]){
                    int tmp = array[j+1];
                    array[j+1] = array[j];
                    array[j] = tmp;
                }
            }
        }
        myPrint();
        return array;
    };

    vector<int>& selectSort(){
        int len = array.size();
        for(int i=0; i<len-1; i++){
            int minIndex = i;
            for(int j=i+1; j<len; j++){
                if(array[j] < array[minIndex]){
                    minIndex = j;
                }
            }
            int tmp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = tmp;
        }
        myPrint();
        return array;
    };

    vector<int>& shellSort(){
        int len = array.size();
        int shell = len >> 1;
        while(shell != 0){
            for(int i=shell; i<len; i++){
                int pre = i-shell;
                int cur = array[i];
                while(pre>=0 && array[pre]>cur){
                    int tmp = array[pre + shell];
                    array[pre + shell] = array[pre];
                    array[pre] = tmp;
                    pre = pre - shell;
                }
            }
            shell = shell >> 1;
        }
        myPrint();
        return array;
    };

    void merge(int l,int mid,int r){
        int i=l,j=mid+1;
        int t=l;
        vector<int> b(r-l, 0);
        while(i<=mid&&j<=r){
            if(array[i]<=array[j]) b[t++]=array[i++];
            else b[t++]=array[j++];
        }
        while(i<=mid) b[t++]=array[i++];
        while(j<=r) b[t++]=array[j++];
        for(int i=l;i<=r;i++) array[i]=b[i];
    }
    void subMergeSort(int left, int right){
        if(left<right){
            int mid = (left+right)/2;
            subMergeSort(left, mid);
            subMergeSort(mid+1, right);
            merge(left, mid, right);
        }
    };
    vector<int>& mergeSort(){
        int len = array.size();
        int left = 0; 
        int right = len-1;
        subMergeSort(left, right);
        myPrint();
        return array;
    };

    void subQuickSort(int l,int r){
        int i,j,mid;
        i=l;j=r;
        mid=array[(i+j)/2];
        while(i<=j){
            while(array[i]<mid)i++;
            while(array[j]>mid)j--;
            if(i<=j){
                swap(array[i],array[j]);
                i++;
                j--;
            }
        }
        if(l<j) subQuickSort(l,j);
        if(i<r) subQuickSort(i,r);
    }
    vector<int>& quickSort(){
        int len = array.size();
        int left = 0; 
        int right = len-1;
        subQuickSort(left, right);
        myPrint();
        return array;
    };

    void coutSort(){
        int length = array.size();
        //确定数列最大值
        int max = array[0];
        for (int i = 1; i < length; ++i){
            if (array[i] > max)
                max = array[i];
        }

        // 确定统计数组长度并进行初始化
        int* coutData = new int[max + 1];
        for (int i = 0; i <= max; ++i)
            coutData[i] = 0;
        // 遍历数组，统计每个数出现的次数
        for (int i = 0; i < length; ++i)
            ++coutData[array[i]];
        // 排序数组，某个数出现了几次，便在data里累计输出几次
        int index = 0;
        for (int i = 0; i <= max; ++i){
            for (int j = 0; j < coutData[i]; ++j){
                array[index++] = i;
            }
        }
        myPrint();
    }

    void buckSort() {
        int len = array.size();
        int bucket[5001] = {0};
        for (int num:array) {
            bucket[num]++;
        }
        int big, small;
        if (len&1){
            big = len-2;
            small = len-1;
        }else{
            big = len-1;
            small = len-2;
        }
        int j = 5000;
        // insert big
        for (int i = 1; i <= big; i+=2) {
            while (bucket[j] == 0) j--;
            array[i]=j;
            bucket[j]--;
        }
        // insert small
        for (int i = 0; i <= small; i+=2) {
            while (bucket[j]==0)j--;
            array[i]=j;
            bucket[j]--;
        }
        myPrint();
    }
};

int main() {
    vector<int> array = {5,1,14,3,6,8,2,15,7};
    mySort mySortObj(array);
    // mySortObj.quickSort();
    // mySortObj.insertSort();
    // mySortObj.bubbleSort();
    // mySortObj.selectSort();
    // mySortObj.shellSort();
    // mySortObj.coutSort();
    mySortObj.buckSort();
}