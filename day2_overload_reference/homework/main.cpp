#include<iostream>
//先声明再使用
using namespace std;

namespace new1_space{
	extern void fun();
}

namespace new2_space{
	extern void fun();
}

int main()
{
	new1_space::fun();
	new2_space::fun();
	return 0;
}

