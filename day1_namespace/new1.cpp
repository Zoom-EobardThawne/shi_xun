#include<iostream>
using namespace std;
namespace new1_space{

	void fun(void) {
		int i,sum=0;
		for(i=1;i<=100;i++)
		{
			sum=sum+i;
		}
		cout<< sum <<endl;
	}
}