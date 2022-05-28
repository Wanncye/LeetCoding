#include<iostream>
#include<string>
#include<iomanip>

using namespace std;


class A {
    
public:
    A(){
        
    };
    A(A &a){

    };
};


int main(){
    A a;
    A b(a);
    // int val[] = {123,45,78,546};
    // char *name[] = {"hello", "how", "C++"};
    // cout<<setiosflags(ios::left) << setw(6) << name[2] << resetiosflags(ios::left)<<val[1]<<endl;
}


// class D{
//     int a;
//     public:
//     D(int i=0):a(i){
//         cout<<"*";
//     }
//     D(D & p){
//         a=p.a;
//         cout<<"#";
//     }
//     ~D(){cout<<"@";}
//     void show(){cout<<a<<endl;}
// };

// D f(D p){
//     D d1(p);
//     return d1;
// }



// int main(){
//     D o1,o2(2);
//     o2=f(o1);
//     return 0;

// }