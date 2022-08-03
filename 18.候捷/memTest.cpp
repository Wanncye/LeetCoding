
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;
    for(auto i = 0; i < n; i++){
        cout << a[i] << endl;
    }
}