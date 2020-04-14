#include<iostream>
#include<string.h>
using namespace std;

class String{
	public:
		String(const char *str = NULL);
		~String();
		void show(void) const;
	private:
		char *m_data;										//开辟的内存的空间地址
		const int maxLen;									//最大长度	
		static int n;										//对象个数
};

int String :: n =0;											//类外初始化static修饰的静态变量

String::String(const char *str):maxLen(10){
	
	if(str == NULL){
		m_data = new char [1];
		m_data = '\0';
	}
	else if(strlen(str) > maxLen){
		int i ;
		m_data = new char [maxLen+1];
		for( i=0; i < maxLen; i++){
			m_data[i] = str[i];
		}
		m_data[i] = '\0';
		cout << "string length overflow" << endl;
	}
	else{
		m_data = new char [strlen(str)+1];
		strcpy(m_data,str);
	}


	n++;
	cout << "obj_number:"<< n << endl;
	

}

String::~String()
{
	if (m_data != NULL)
    {
        delete[] m_data;
        m_data = NULL;
    }
}

void String::show(void) const{
	for(int i = 0;i < strlen(m_data);i++){
		cout << m_data[i] << ':' << (int)m_data[i] << "____";
	}
	cout << endl;
	cout << "-------------------------------------------------------"<<endl;

}

int main(void){

	String a("ABCDE");
	String b("abhssj");
	String c("sddasddasddasdads");
	
	a.show();
	b.show();
	c.show();
}