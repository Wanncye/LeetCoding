#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<forward_list>
#include<algorithm>

using namespace std;

class A{
public:
 int a;
};

int main(){
    // class A test[3];
    // list<int> a = {3,2,6,4,9,2,7};
    // a.sort();

    // forward_list<int> c;
    // c.push_front(1);
    // c.push_front(2);
    // c.push_front(3);
    // for(auto i : c) cout << i << endl;
    // cout << c.back() <<endl;

    // deque<int> c;
    // c.push_front(1);

    // unordered_map<int, int> c = {{1,2},{3,7},{8,2}};
    // cout << sizeof(c) << endl;
    // cout << c.bucket_count() << endl;
    // for(auto i : c) cout << i << endl;

    // set<int> c = {1,8,7,0};
    // sort(c.begin(), c.end());
    vector<int> a = {1,2,3};
    vector<int> b(move(a));
    cout << b[1] << endl;;
}