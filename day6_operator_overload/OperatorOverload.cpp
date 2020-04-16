#include<iostream>
#include<string.h>
using namespace std;

class String{
public:
    String ();
    String (const char* str);
    String(const String & str);
   
    ~String();
    void show() const;
    String &operator=(const String &other);
    //非成员函数
   friend String operator+(const String &str1,const String &str2);
    //成员函数
    String  operator+ (const String &str);
    //前置++
    String &operator++();
    //后置++
    String operator++(int);
private:
    char* m_data ;
};

String::String (){
    m_data= NULL;
}


String::String(const char *str){
    cout << "String(char *)" <<endl;
    int len = strlen (str)+1;
    m_data =new char[len];
    strcpy(m_data,str);
}

String::String(const String & str){
    cout << "copy struction" <<endl;
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
//赋值运算符重载 =
String & String :: operator=(const String &other){
    cout << " operator = overload" << endl;
    if(this == &other){
        return *this;
    }
    if(this->m_data !=NULL){
        delete[] this->m_data;
    }
    if(other.m_data != NULL){
        int len =strlen(other.m_data)+1;
        this->m_data =new char[len];
        strcpy(this->m_data,other.m_data);   
    }else{
        this->m_data =NULL;
    }
    return *this;
}

//成员函数定义
 String String::operator+ (const String &str){
    cout << "operator + overload"<< endl;
    String newString;
    int len1=strlen(this->m_data);
    int len2=strlen(str.m_data);
    newString.m_data = new char [len1 +len2+2];//hello world \0
    strcpy(newString.m_data,this->m_data);
    strcat(newString.m_data," ");
    strcat(newString.m_data,str.m_data);

    return newString;
 }

//非成员函数定义
String operator+(const String &str1,String const &str2){
    cout << "operator + 3overload"<< endl;
    String newString;
    int len1=strlen(str1.m_data);
    int len2=strlen(str2.m_data);
    newString.m_data = new char [len1 +len2+2];//hello world \0
    strcpy(newString.m_data,str1.m_data);
    strcat(newString.m_data," ");
    strcat(newString.m_data,str2.m_data);

    return newString;
} 

//前置++
String& String::operator++(){
    cout << "operator ++a overload"<< endl;

    for (char *p = this-> m_data;p!= NULL&&*p!='\0';p++){
        *p = *p+1;
    }
    return *this;
}

//后置++
String String::operator++(int){
    cout << "operator a++ overload"<< endl;
    String tmp(*this);

    for(char *p =this-> m_data; *p; p++){
        (*p)++;
    }
    return tmp;
}

int main(){
   String str1("Hello");
   String str2("World");

   String str3 (str1+str2) ;
  
     str3.show();
    String str4 = str3++;
     str4.show();
    String str5 = ++str3;
    str5.show();
    str1=str2;
    str1.show();
    return 0;
}
