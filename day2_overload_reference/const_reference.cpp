#include<iostream>
using namespace std;
//常引用
string fun(const int &a)
{
	cout << "a" <<a;//可以识别但不能修改
	//
}


int main(){
	int a = 100;
	fun(a);
	
	return 0;
	


}