#include "String.h"
#include <string.h>
#include <iostream>

using namespace std;

int String::n = 0;

String::String(const char *str,int len):maxLen(len)
{
	n ++;
	
	if(str != NULL){
		int len = strlen(str) + 1;
		if(len > maxLen){
			cout << "Error,The string len gt maxLen: " << maxLen << endl;
			m_data = NULL;
		}else{
			m_data  = new char[len];
			strcpy(m_data,str);
		}
	}else{
		m_data = NULL;
	}
}

String::~String()
{
	n --;
	
	if(m_data != NULL){
		delete[] m_data;
	}
}

void String::show(void) const
{
	cout << "---------------------------" << endl;
	//ABCD\0
	//p
	for(char *p = m_data; p != NULL && *p != '\0';p ++){
		cout << *p << ":" << (int)*p << endl;
	}
	
}

void String::showObjects(void)
{
	cout << "current objects : " << n << endl;
}