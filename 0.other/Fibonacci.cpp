#include<iostream>
#include <chrono>
using namespace std;
using namespace chrono;

/*第一种递归斐波那契
时间复杂度为O(2^n) 《----- 因为存在重复计算，想象为递归二叉树中的节点个数为2^k-1
空间复杂度为O(n)   《----- 每一次函数调用的空间复杂度为1，但是会调用n次这个函数
*/
int fibonacii_1(int i)
{
    if( i == 0) return 0;
    if( i == 1 ) return 1;
    return fibonacii_1( i - 1) + fibonacii_1(i - 2);
}

/*第二种递归斐波那契
时间复杂度为O(n)    《----- 调用n次该函数，每次的时间复杂度为1
空间复杂度为O(n)    《----- 递归深度为n，每次的空间复杂度为1
*/
int fibonacii_2(int first, int second, int n)
{
    if(n == 0){
        return 0;
    }
    else if(n < 3){
        return 1;
    }
    else if(n == 3){
        return first + second;
    }
    else{
        return fibonacii_2(second, first + second, n-1);
    }
}

/*第三种斐波那契
非递归实现
时间复杂度为O(n)
空间复杂度为O(1)
*/
int fibonacii_3(int n)
{
    int a = 1;
	int b = 1;
	int c = a;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

void time_consumption()
{
    int n;
    while (cin >> n) {
        milliseconds start_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );

        // fibonacii_1(n);
        // fibonacii_2(1, 1, n);
        fibonacii_3(n);

        milliseconds end_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );
        cout << milliseconds(end_time).count() - milliseconds(start_time).count()
            <<" ms"<< endl;
    }
}

int main()
{
    time_consumption();
    return 0;
}