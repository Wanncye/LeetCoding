#include<iostream>

using namespace std;
/*  
    字节序：字节在内存中存储的顺序。
    小端字节序：数据的高位字节存储在内存的高位地址，低位字节存储在内存的低位地址
    大端字节序：数据的低位字节存储在内存的高位地址，高位字节存储在内存的低位地址
*/
int main(){
    union {
        short value;
        char bytes[sizeof(short)];
    } test;
    test.value = 0x0102;
    if(test.bytes[0]==1 && test.bytes[1]==2){
        cout << "大端字节序" << endl;
    } else if((test.bytes[0]==2 && test.bytes[1]==1)){
        cout << "小端字节序" << endl;
    } else {
        cout << "未知" << endl;
    }
}