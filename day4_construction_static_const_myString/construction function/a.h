#ifndef _A_HEAD_H 
#define _A_HEAD_H

#include<iostream>
#include<string.h>

using namespace std;

class A{
private:
    string name;
    int age;
    int score;
    char *_name;

public:
    A (string nm = "", int ag = 0 , int sc = 0);
   ~A();
    void Show();

};
#endif