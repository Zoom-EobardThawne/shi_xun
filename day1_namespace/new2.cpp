#include<iostream>
using namespace std;

namespace new2_space{

	void fun(void){
		int i, sum=0;
		for(i=2;i<=100;i+=2)
		{
			sum=sum+i;
		}
		cout <<sum <<endl;
	}
}
