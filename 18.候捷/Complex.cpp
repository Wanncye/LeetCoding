#include<iostream>
using namespace std;

class Complex{
public:
    Complex(int real=0, int img=0)
    :_real(real), _img(img){

    }

    int getReal() const {return _real;}
    int getImg() const {return _img;}

private:
    int _real;
    int _img;
};


int main(){
    const Complex c1;
    cout << c1.getImg() << endl;
}