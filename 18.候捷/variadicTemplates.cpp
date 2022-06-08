#include<iostream>
#include<set>

using namespace std;

void printX(){

}

template <typename T, typename... Types>
void printX(const T& firstArg, const Types&... args){
	cout << sizeof...(args) << " " << firstArg << endl;
	printX(args...);
}

void wcy(int, int){
    cout << "in wcy(int, int), no para obj" << endl;
}


class cmp{
public:
    bool operator()(const int& a, int b) const {
        return a>b;
    }
};


int main(){
    // int a = 2;
    // int b = 2;
    // int c = 2;
    // double d = 2;
    // printX(a, b, c, d);
    // wcy(1, 2);

    // string *a = "wcy";
    // cout << sizeof(nullptr) <<endl;


    // int id = 0;
    // auto f = [id] () {
    //     cout << "id:" << id <<endl;
    //     ++id;
    // };
    // id = 42;
    // f();
    // f();
    // f();
    // cout << "id:" << id <<endl;
    auto f = [] (int a, int b) {
        return a>b;
    };
    set<int, decltype(f)> mySet(f);
}