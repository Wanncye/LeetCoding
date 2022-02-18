#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

struct node{
   int num;
   char cha;
}st;
int main() {
    int a[100];
    char b[100];
    cout << sizeof(int) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(st) << endl;
}