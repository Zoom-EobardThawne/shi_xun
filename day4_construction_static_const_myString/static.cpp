#include<iostream>
#include<string.h>

using namespace std;

class A{ 
public:
    int a=25;
    static int b;
    static void fun();
    void _fun();

};
int A::b=100;
 void A:: fun(){
    
    cout << "b:  " << b << endl;
}
void A:: _fun(){
    cout << "a:  " << a << endl;
    cout << "b:  " << b << endl;
}

int main(){
    A obj1;

    cout << "static " << endl;
    A::fun();

    cout << "non_static " << endl;
    obj1. _fun();


}
