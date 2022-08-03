#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
using namespace std;


int my_atoi(char *s){
    int i=0, res = 0;
    bool is_negative = false;
    size_t len = strlen(s); 
    cout << len << endl;
    // cout << len << endl;
    // while((i<len) && *(s+i) != '\0'){ //中括号，判断条件，一个等于
    // while((i<len)){ //中括号，判断条件，一个等于
    //     // i++;
    //     if(i == len) return 0;
    //     if(*(s+i) == '-'){
    //         is_negative = true;
    //         i++;
    //         continue;
    //     }else if(*(s+i) == '+'){
    //         i++;
    //         continue;
    //     }
    //     int number = 0;
    //     while((i<len) && (isdigit(*(s+i)))){//while该改成if
    //         number = *(s+i) - '0';//单引号，且number是局部变量
    //         if((res*10 + number) > __INT_MAX__){
    //             return is_negative ? -__INT_MAX__ : __INT_MAX__;
    //         }
    //         res = res * 10 + number;
    //         i++;
    //     }
    // }
    // return is_negative ? res : -res;
}

int main ()
{
    int res=0;
    char myStr[300] = "-267ewdwe+hd";
    res = my_atoi(myStr);
    // cout << res << endl;
    return 0;
}