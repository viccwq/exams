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
#include <iostream>
using namespace std;




//c��C++����Ա�����ؼ�

//chapter6 26th
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

int test_626()
{  
    MyString a;  
    MyString b("abc");  
    MyString c = b;  
    a.PrintStr();
    b.PrintStr();
    c.PrintStr();
    cout<<"test for iostream"<<endl;

    return 0;
} 

//chapter6 28th
class B628
{
public:
    B628()
    {
        cout<<"default constructor"<<endl;
    }
    B628(const B628 &b)
    {
        cout<<"copy constructor"<<endl;
        data = b.data;
    }
    /*
    */
    B628(int i):data(i)
    {
        cout<<"constructed by parameter"<<data<<endl;
    }
    ~B628()
    {
        cout<<"destructed"<<endl;
    }
private:
    int data;
};

B628 Play(B628 b)
{
    return b;
}

int test_628()
{
    B628 t1 = Play(5);
    B628 t2 = Play(t1);
    return 0;
}




//chapter7 6th
//����ʱ�Ķ�̬--����ʵ��
//����ʱ�Ķ�̬--���Աʵ��
//
class Person706
{
public:
    virtual void print()
    {
        cout<<"I'm a Person"<<endl;
    }
};
class Chinese706:public Person706
{
public:
    virtual void print()
    {
        cout<<"I'm a Chinese Person"<<endl;
    }
};
class American706:public Person706
{
public:
    virtual void print()
    {
        cout<<"I'm a American Person"<<endl;
    }
};

void printPerson(Person706 &per)
{
    per.print();
}

int test_706()
{
    Person706 p;
    Chinese706 c;
    American706 a;
    printPerson(p);
    printPerson(c);
    printPerson(a);
    return 0;
}





//��������
//

//ϴ��
//
//static and const


//ʲô�ǹ������

//���̵߳�ʵ��
//����structʵ��class�Ĺ���
//����
//�����㷨(Ŀ��׷��)
//����λ(˾��������)
//
//
int main()
{
//    test_626();
//    test_628();
    test_706();
}
