#include"a.h"
using namespace std;

A::~A(){
    if (_name !=null){
        delete[] _name;
    }
    cout << "~A()"  << endl;
}

A :: A (string nm, int ag , int sc){
        name = nm;
        age =  ag;
        score = sc;
        int len = strlen(nm.c_str()); //返回字符串首地址
        _name = new char[len+1];
        strcpy (_name,nm.c_str());
    }

void A::Show(){
        cout << "name :" << name <<endl;
        cout << "age :" << age << endl;
        cout << "score :" << score << endl;
        cout << "_name:" << _name << endl;
    }
    
