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
//��������


//ϴ��


//string�Ĺ��� ���� ��ֵ˵������
//http://www.cnblogs.com/kaituorensheng/p/3245522.html
//http://blog.csdn.net/zhuimengzh/article/details/6708882
//1. ��ֵ�����У������Ƚ� this == &other �Ǻܱ�Ҫ�ģ���Ϊ��ֹ�Ը��ƣ����Ǻ�Σ�յģ�
//��Ϊ������delete []m_data�������ǰ��m_data���ͷ��ˣ�ָ���ѳ�Ұָ�룬�ٸ�ֵ�ʹ���
//2. ��ֵ�����У�����Ҫ�ͷŵ�m_data,�����û�����ˣ��±�������ָ���ˣ�
//3. �������캯���Ƕ��󱻴���ʱ���ã���ֵ����ֻ�ܱ��Ѿ������˵Ķ������
//    ע�⣺String a("hello"); String b("world");  �����Զ��幹�캯��
//    String c=a�����ÿ������캯������Ϊcһ��ʼ�����ڣ����д��String c(a);

class MyString  
{  
public:  
    MyString(const char *str=NULL);//��ͨ���캯��  
    MyString(const MyString &str);//�������캯��  
    MyString & operator =(const MyString &str);//��ֵ����  
    ~MyString();//��������  
    void PrintStr(void);
protected:  
private:  
    char* m_data;//���ڱ����ַ���  
};  

void MyString::PrintStr(void)
{
//    coun<<m_data<<endl;
    printf("the string is %s\n", m_data);
}
//��ͨ���캯��  
MyString::MyString(const char *str)
{  
    if (str==NULL)
    {  
        m_data = new char[1]; //�Կ��ַ����Զ������Ž�����־'\0'�Ŀռ�  
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

//��ֵ����  
MyString& MyString::operator =(const MyString &str)
{
    if (this == &str) //����Ը�ֵ  
        return *this;  
    int length = strlen(str.m_data);  
    delete [] m_data;//�ͷ�ԭ�����ڴ���Դ  
    m_data= new char[length + 1];  
    memcpy(m_data, str.m_data, length);
    m_data[length] = '\0'; 
    return *this;//���ر����������  
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


//ʲô�ǹ������

//���̵߳�ʵ��
