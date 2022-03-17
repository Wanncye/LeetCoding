#include <iostream>
/*
chrono是一个头文件的名字，但是也是一个std下的一个子命名空间的名字：
在这个头文件下的所有元素(除了(不包含)common_type 类 特殊化)不是
直接定义在std命名空间下的(就像大多数标准库一样)而是定义在std::chrono
命名空间里。
*/
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

// O(n)
void function1(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        k++;
    }
}

// O(n^2)
void function2(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        for (long j = 0; j < n; j++) {
            k++;
        }
    }

}

// O(nlogn)
void function3(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 1; j < n; j = j*2) { // 注意这里j=1
            k++;
        }
    }
}

int main() {
    long long n; // 数据规模
    while (1) {
        cout << "输入n：";
        cin >> n;
        //system_clock 提供访问当前的time_point,是一个全系统实时时钟。
        milliseconds start_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );
        function1(n);
        // function2(n);
        // function3(n);
        milliseconds end_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );
        cout << "耗时:" << milliseconds(end_time).count() - milliseconds(start_time).count()
            <<" ms"<< endl;
    }
}
/*
结论：
O(nlogn)算法1s时间内能够计算的量级为10^7
O(n)算法1s时间内能够计算的量级为10^8
O(n^2)算法1s时间内能够计算的量级为10^4
*/