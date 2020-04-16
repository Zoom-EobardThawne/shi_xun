#include<iostream>
#include<string.h>
using namespace std;

class String{
public:
    String (const char* str);
    String(const String & str);
    ~String();
    void show() const;
    void change();
private:
    char* m_data ;
};


String::String(const char *str){
    cout << "String(char *)" <<endl;
    int len = strlen (str)+1;
    m_data =new char[len];
    strcpy(m_data,str);
}

String::String(const String & str){
    int len = strlen(str.m_data) +1;
    this->m_data=new char[len];
    strcpy(this->m_data,str.m_data);
}

String::~String()
{
	cout <<"~String " <<endl;
	
	if(m_data != NULL){
		delete[] m_data;
	}
}

void String::show() const{
    cout << m_data << endl;
}

void String:: change(){
    *m_data ='x';
}

int main(){
   String obj1("ABD");
   obj1.show();

   cout << "------------------------" <<endl;
    String obj2(obj1);
   //String obj2= obj1;     //两种写法等价                 
   obj2.show();

   cout << "------------------------" <<endl;
    obj1.change();
    obj2.show();

    return 0;
}