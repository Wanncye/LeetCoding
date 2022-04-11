#include<iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber > 0) {
            int a0 = (columnNumber - 1) % 26 + 1;
            ans += a0 - 1 + 'A';
            columnNumber = (columnNumber - a0) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    string a;
    // string类只能使用+=操作符来进行int型和char型的操作
    // a = a + 1 + 'A'; 就会报错
    a += 1 + 'A';
    cout << a << endl;
    Solution stl;
    stl.convertToTitle(12341234);
}