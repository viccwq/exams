/*************************************************************************
 * Copyright(c) 2016-2020 VX-Lab. All rights reserved.
 * File Name:    test.c
 * Author:       
 * Mail:         
 * Version:      v0.00 
 * Created Time: 2017/02/06
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
#include <stdlib.h>
#include <string.h>
#include <vector>

/*
#define ADD(a, b) {\
    int c;\
    c += ((a) + (b));\
    c;\
}
*/


#define ADD(a, b) ({\
    int c;\
    ((a) + (b));\
})

int test_1()
{
    int a = 3;
    int b = 2;
    int c = 5;
    int d = 4;
    int f = a<b ? a:c < d ? a:d;
    printf("--------test_1--------\n");
    printf("test_1:%d\n", f);
    return 0;
}

int test_2()
{
    printf("--------test_2--------\n");
	printf("sizeof(char) = %d\n", sizeof(char));
	printf("sizeof(int) = %d\n", sizeof(int));
	printf("sizeof(short) = %d\n", sizeof(short));
	printf("sizeof(long) = %d\n", sizeof(long));
    return 0;
}

int test_3()
{

	struct _a1 {
		long aa;
		char bb;
		char b2;
		int cc;
//		short c4;
	} a1;

	struct _a2 {
		long aa;
		char bb;
		char b2;
        short b3;
		int cc;
//		short c4;
	} a2;

	struct _a3 {
		long aa;
		char bb;
        short b3;
		char b2;
		int cc;
//		short c4;
	} a3;

	struct _ab {
		long aa;
		char bb;
		char b2;
		int cc;
//		short c4;
	} __attribute__ ((__packed__)) ab;

	printf("--------test_3--------\n");
	printf("%d\n", sizeof(a1));
	printf("%d\n", sizeof(a2));
	printf("%d\n", sizeof(a3));
	printf("%d\n", sizeof(ab));
    return 0;
}


int test_4()
{
	char *a1 = "\\\0";
	char *a2[10][10];
	int *b2[10][10];
	long *c2[10][10];
	
	char a3[10][10];
	int b3[10][10];
	long c3[10][10];
	printf("--------test_4--------\n");
	printf("%d\n", sizeof(a1));
	printf("%d\n", strlen(a1));
	
	printf("sizeof(a2) = %d\n", sizeof(a2));
	printf("sizeof(b2) = %d\n", sizeof(b2));
	printf("sizeof(c2) = %d\n", sizeof(c2));

	printf("sizeof(a3) = %d\n", sizeof(a3));
	printf("sizeof(b3) = %d\n", sizeof(b3));
	printf("sizeof(c3) = %d\n", sizeof(c3));
	
	printf("sizeof(\"abcd\") = %d\n", sizeof("abcd"));
	printf("strlen(\"abcd\") = %d\n", strlen("abcd"));
	return 0;
}

int test_5()
{
	printf("--------test_5--------\n");
    unsigned int a = 6;
    int b = -20;
    printf("%x\n", (a + b));
    printf("%d\n", (a + b));
    printf("%u\n", (a + b));
	return 0;
}

int test_6()
{
	printf("--------test_6--------\n");
    char s[] = "123456789";
    char d[] = "abc";
    strcpy(d, s);
    printf("%s, %s\n", s, d);
	return 0;
}

int test_7()
{
	printf("--------test_7--------\n");
    int a[2][2] = {{1},{2,3}};
    printf("a[0][1] = %d\n", a[0][1]);
	return 0;
}

int test_8()
{
	printf("--------test_8--------\n");
    int i, j = 2;
    int *p = &i;
    *p = (*&j + 1) ^ j;
    printf("i = %d\n", i);
    printf("strlen(\"\\\"1234\"\\\") = %d\n", strlen("\\\"1234\"\\"));
	return 0;
}

class Base
{
public:
    void f1()
    {
        printf("Base:f1()\n");
    }
    virtual void f2()
    {
        printf("Base:f2()\n");
    }
};

class Derived:public Base
{
public:
    void f1()
    {
        printf("Derived:f1()\n");
    }
    void f2()
    {
        printf("Derived:f2()\n");
    }    
};

int test_9()
{
	printf("--------test_9--------\n");
    Base *b1 = new Base();
    Base *b2 = new Derived();
    Derived *d3 = new Derived();
    b1->f1();
    b1->f2();
    b2->f1();
    b2->f2();
    d3->f1();
    d3->f2();
	return 0;
}

int test_10()
{
	printf("--------test_10--------\n");
    int a;  
    char c=10;  
    float f=100.0;  
    double x;  
    a=f/=c*=(x=6.5);  
    printf("%d %d %3.1f %3.1f\n",a,c,f,x);  
    return 0;  
}  

int test_11()
{
	printf("--------test_11--------\n");
    int a = 0;
    a = ADD(11, 12);
    printf("%d\n", a);  
    return 0;  
} 

int test_12()
{
	printf("--------test_12--------\n");
    int i = 0, j = -1, k = 1;

    printf("(i) = 0x%0x, %d\n", (i),(i));
    printf("((i)>>8) = 0x%0x, %d\n", ((i)>>8),((i)>>8));
    printf("((i)>>8) = 0x%0x, %d\n", ((i)<<8),((i)<<8));
    
    printf("(j) = 0x%0x, %d\n", (j),(j));
    printf("((j)>>8) = 0x%0x, %d\n", ((j)>>8),((j)>>8));
    printf("((j)>>8) = 0x%0x, %d\n", ((j)<<8),((j)<<8)); 
    
    printf("(k) = 0x%0x, %d\n", (k),(k));
    printf("((k)>>8) = 0x%0x, %d\n", ((k)>>8),((k)>>8));
    printf("((k)>>8) = 0x%0x, %d\n", ((k)<<8),((k)<<8)); 
    
    printf("(~i) = 0x%0x, %d\n", (~i),(~i));
    printf("((~i)>>8) = 0x%0x, %d\n", ((~i)>>8),((~i)>>8));
    printf("((~i)>>8) = 0x%0x, %d\n", ((~i)<<8),((~i)<<8));
	return 0;
}

/*
int test_13()
{
	printf("--------test_13--------\n");
    vector<int> vect1;
    for (int i = 0; i < 10; i++)
        vect1.push_back(i);

    vector<int> vect2(vect1.begin()+1, vect1.begin+9);
    for (int i = 0; i < vect2.size(); i++)
        count<<vect2[i]<<endl;

    return 0;
}
*/

int test_14(int n, int m, int j, int i)
{
	printf("--------test_14--------\n");
    int mask = (1 << (i - j + 1)) - 1;
    //将多m中余的位置0
    int temp = m & mask;
	printf("temp = %d, mask= 0x%x\n", temp, mask);
    temp = (temp << j);
    mask = (mask << j);
	printf("temp = %d, mask= 0x%x, ret = %d\n", temp, mask, ((n & ~mask) | temp));
    return ((n & ~mask) | temp);
}

int test_15()
{
	printf("--------test_15--------\n");
    int temp = 0;
    for (int i = 1584012; i > 0; i--)
    {
        temp = 1584012 % i;
        if (temp == 0)
            printf("%d * %d\n", i, (1584012/i));
    }

    return 0;
}


int main()
{
/*    
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    test_7();
    test_8();
    test_9();
    test_10();
    test_11();
    */
    test_12();
//    test_13();
    test_14(28679,205, 3,11);
    test_15();
    return 0;
}
