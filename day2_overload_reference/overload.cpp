#include<iostream>
using namespace std;

int add (int a){
		return a;
}

int add (int a,int b){
		
	return (a+b);
}
double  add (double a,double b,double c){
		
	return (a+b+c);
}
int add (int a,int b,int c){
		
	return (a+b+c);
}
int main(){
	cout << add (100) << endl;
	cout << add (100,200) << endl;
	cout << add (100,200,300) << endl;
	cout << add (12.1,25.2,30.3) << endl;
	return 0;
}