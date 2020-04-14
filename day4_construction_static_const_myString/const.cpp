#include<iostream>
#include<string.h>

using namespace std;

class A{ 
public:
   A (int a, int  b):b(b){
    this-> a=a;  
   }

    void show() const{
        //a++;
        cout << "a=" << a <<endl;
        cout << "b=" << b << endl;
    }

private:
    int a;
    const int b;
};

int main(){
    
   const A obj(55,33) ;
    obj.show();

}
