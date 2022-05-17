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

class A{
public:
    void m_print(){
        cout << "class A" << endl;
    }
};


int main(){
    A *a = new A();
    a->m_print();
}