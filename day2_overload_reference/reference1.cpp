#include<iostream>
using namespace std;

int main(){
	int data=100;
	cout << "data:"<<data<<endl;
	int &qoute_data = data;//这是一个引用变量，&标识作用。
	int &qoute_2 = data;
	
	qoute_2=200;
	
	cout << "qoute_2:"<<qoute_data<<endl;
	
	
	return 0;
	


}