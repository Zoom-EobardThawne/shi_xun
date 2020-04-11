#include<iostream>
using namespace std;
//通过引用实现交换
void swap(int &c ,int &d){
	int t;
	t=c;
	c=d;
	d=t;
	//cout << "before c:"<<c << "d:"<< d <<endl ;	
}

int main(){
	int a = 100;
	int b = 200;
	
	cout << "before a:"<< a <<endl ;
	cout << "before b:"<< b <<endl ;
	
	swap (a,b);
	
	cout <<" after a:" << a <<endl	;
	cout <<" after b: "<< b << endl	;
	
	
	
	
	return 0;
	


}