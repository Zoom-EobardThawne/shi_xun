#ifndef _STRING_HEAD_H
#define _STRING_HEAD_H
#include <stdio.h>

class String{
public:
   String(const char *str = NULL,int len = 0); //初始化成员变量
  ~String();
   void show(void) const;//输出每个字符对应的字符和ASCII码 'A':65
   static void showObjects(void);
private:
    char *m_data;   //记录字符串存放的地址,需要在堆区分配内存存放字符串
    const int maxLen;//记录字符串的最大长度
    static int  n;  //记录产生的String对象个数
};

#endif