/*************************************************************************
 * Copyright(c) 2016-2020 VX-Lab. All rights reserved.
 * File Name:    interview.c
 * Author:       Vic Chen
 * Mail:         vic_cwq@163.com 
 * Version:      v0.00 
 * Created Time: 2017/02/17
 * Description:  
 * 
 * Others:       
 * 
 * History:
 1.Version:
   Author:
   Modified Time:
   Modification:
 ************************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//链表排序


//洗牌


//string的构造 析构 赋值说明几点
//http://www.cnblogs.com/kaituorensheng/p/3245522.html
//http://blog.csdn.net/zhuimengzh/article/details/6708882
//1. 赋值函数中，上来比较 this == &other 是很必要的，因为防止自复制，这是很危险的，
//因为下面有delete []m_data，如果提前把m_data给释放了，指针已成野指针，再赋值就错了
//2. 赋值函数中，接着要释放掉m_data,否则就没机会了（下边又有新指向了）
//3. 拷贝构造函数是对象被创建时调用，赋值函数只能被已经存在了的对象调用
//    注意：String a("hello"); String b("world");  调用自定义构造函数
//    String c=a；调用拷贝构造函数，因为c一开始不存在，最好写成String c(a);

class MyString  
{  
public:  
    MyString(const char *str=NULL);//普通构造函数  
    MyString(const MyString &str);//拷贝构造函数  
    MyString & operator =(const MyString &str);//赋值函数  
    ~MyString();//析构函数  
    void PrintStr(void);
protected:  
private:  
    char* m_data;//用于保存字符串  
};  

void MyString::PrintStr(void)
{
//    coun<<m_data<<endl;
    printf("the string is %s\n", m_data);
}
//普通构造函数  
MyString::MyString(const char *str)
{  
    if (str==NULL)
    {  
        m_data = new char[1]; //对空字符串自动申请存放结束标志'\0'的空间  
        m_data[0] = '\0';  
    }  
    else
    {  
        int length = strlen(str);  
        m_data = new char[length + 1];  
        memcpy(m_data, str, length);
        m_data[length] = '\0';  
    }  
}  

MyString::MyString(const MyString &str)
{
    int length = strlen(str.m_data);
    m_data = new char[length + 1];  
    memcpy(m_data, str.m_data, length);
    m_data[length] = '\0'; 
}

//赋值函数  
MyString& MyString::operator =(const MyString &str)
{
    if (this == &str) //检查自赋值  
        return *this;  
    int length = strlen(str.m_data);  
    delete [] m_data;//释放原来的内存资源  
    m_data= new char[length + 1];  
    memcpy(m_data, str.m_data, length);
    m_data[length] = '\0'; 
    return *this;//返回本对象的引用  
}  

MyString::~MyString()
{
    delete [] m_data;
}

int main()
{  
    MyString a;  
    MyString b("abc");  
    MyString c = b;  
    a.PrintStr();
    b.PrintStr();
    c.PrintStr();
    return 0;
} 

//static and const


//什么是过度拟合

//单线程的实现
