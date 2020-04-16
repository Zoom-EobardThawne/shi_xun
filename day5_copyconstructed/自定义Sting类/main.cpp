#include <iostream>
#include "String.h"

using namespace std;

int main(void)
{
	String str1;
	str1.show();
	String::showObjects();
	cout << "======================" << endl;
	String str2("Hello World",30);
	str2.show();
	String::showObjects();
	cout << "======================" << endl;
	String str3("12345",3);
	str3.show();
	String::showObjects();
	
	return 0;
}

