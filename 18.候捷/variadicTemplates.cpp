#include<iostream>

using namespace std;

void printX(){

}

template <typename T, typename... Types>
void printX(const T& firstArg, const Types&... args){
	cout << sizeof...(args) << " " << firstArg << endl;
	printX(args...);
}

int main(){
    int a = 2;
    int b = 2;
    int c = 2;
    double d = 2;
    printX(a, b, c, d);
}