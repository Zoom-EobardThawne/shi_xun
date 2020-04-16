#include<iostream>
#include<string.h>
using namespace std;

class Test{
    private:
    int a ;
    public:
    Test(){
        a=100;
    }
    friend void function(void);
    void show()const {
        cout << "a:" << a << endl;
    }
};

void function(void){
    Tese obj;
    obj.a=200;
    obj.show;
}

int main(){
    funtion();
    return 0;
}