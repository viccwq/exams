/*************************************************************************
 * Copyright(c) 2016-2020 VX-Lab. All rights reserved.
 * File Name:    cc150.cpp
 * Author:       
 * Mail:         
 * Version:      v0.00 
 * Created Time: 2016/12/20
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


#include "cc150.h"
#include <iostream>
using namespace std;

//字符互异
class Different {
public:
    bool checkDifferent(string iniString) {
        // write code here
        int len = iniString.length();
        for (int i = 0; i < (len - 1); i++)
            for (int j = (i+1); j < len; j++)
            {
                if (iniString.at(i) == iniString.at(j)) 		
                    return false;
            }
           	return true;
        }
    }
};


class Different {
public:
    bool checkDifferent(string iniString) {
        // write code here
        char dict[256] = {0};
        int length = iniString.size();
        for(int i = 0; i < length; i++){
            int c = iniString[i];
            dict[c]++;
            if(dict[c] > 1) return false;
        }
        return true;
    }
};


//原串翻转
class Reverse {
public:
    string reverseString(string iniString) {
        // write code here
        int len = iniString.size();
        for (int i = 0; i < len - 1; i++)
        {
            int j = len - 1 - i;
            if (i < j)
                swap(iniString[i], iniString[j]);
            else
                break;
    	}
        return iniString;
    }
};


//给定两个字符串，请编写程序，确定其中一个字符串的字符重新
//排列后，能否变成另一个字符串。这里规定大小写为不同字符，
//且考虑字符串重点空格。
//给定一个string stringA和一个string stringB，请返回一个
//bool，代表两串是否重新排列后可相同。保证两串的长度都小于
//等于5000。
//测试样例：
//"This is nowcoder","is This nowcoder"
//返回：true
//"Here you are","Are you here"
//返回：false
class Same {
public:
    bool checkSam(string stringA, string stringB) {
		// write code here
		int len = stringA.size();
		if (len != stringB.size())
			return false;
		int A[256] = {0};
		int i = len;
		while (i--)
		{
			A[stringA[i]]++;
			A[stringB[i]]--;
		}

		i = 256;
		while (i--)
		{
			if (A[i])
				return false;
		}
		return true;
        
    }
};

//请编写一个方法，将字符串中的空格全部替换为“%20”。
//假定该字符串有足够的空间存放新增的字符，并且知道
//字符串的真实长度(小于等于1000)，同时保证字符串由
//大小写的英文字母组成。
//给定一个string iniString 为原始的串，以及串的长度
//int len, 返回替换后的string。
//测试样例：
//"Mr John Smith”,13
//返回："Mr%20John%20Smith"
//”Hello  World”,12
//返回：”Hello%20%20World”
class Replacement {
public:
    string replaceSpace(string iniString, int length) {
        // write code here
        if (length <= 0)
            return iniString;
        
        int count = 0;
        for (int i = 0; i < length; i++)
            if (iniString[i] == ' ')
                count++;
        
        count = length + count * 2;
        char *str = new char[count + 1];
        
        int j = 0;
        for (int i = 0; i < length; i++)
        {
            if (iniString[i] == ' ')
            {
                str[j++] = '%';
                str[j++] = '2';
                str[j++] = '0';
            }
            else
            {
                str[j++] = iniString[i];
            }
        }
        str[j] = '\0';
        
        string ret(str);
        return ret;
    }
};



//利用字符重复出现的次数，编写一个方法，实现基本的字符串压缩功能。
//比如，字符串“aabcccccaaa”经压缩会变成“a2b1c5a3”。若压缩后的
//字符串没有变短，则返回原先的字符串。
//给定一个string iniString为待压缩的串(长度小于等于10000)，保证串
//内字符均由大小写英文字母组成，返回一个string，为所求的压缩后或
//未变化的串。
//测试样例
//"aabcccccaaa"
//返回："a2b1c5a3"
//"welcometonowcoderrrrr"
//返回："welcometonowcoderrrrr"

class Zipper {
public:
	string zipString(string iniString) {
		// write code here
		int len = iniString.size();
		if (len <= 2)
		{
			return iniString;
		}

		string zip = "";
		char temp;
		for (int i = 0; i < len;)
		{
			temp = iniString.at(i);
			zip.append(1, temp);
			i++;
			int count = 1;
			while (i < len && temp == iniString.at(i))
			{
				i++;
				count++;
			}
			zip += to_string(count);
		}
		if (zip.size() >= len)
			return iniString;
		else
			return zip;

	}
};

//有一副由NxN矩阵表示的图像，这里每个像素用一个int表示，
//请编写一个算法，在不占用额外内存空间的情况下(即不使用
//缓存矩阵)，将图像顺时针旋转90度。
//给定一个NxN的矩阵，和矩阵的阶数N,请返回旋转后的NxN矩
//阵,保证N小于等于500，图像元素小于等于256。
//测试样例：
//[[1,2,3],[4,5,6],[7,8,9]],3
//返回：[[7,4,1],[8,5,2],[9,6,3]]
class Transform {
public:
	vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
		// write code here
		if (n <= 1)
			return mat;
		int range = n / 2;
//		if (n % 2)
//			range++;
		int i = 0, j = 0;
		for (i = 0; i < range; i++)
		{
			for (j = 0; j < range; j++)
			{
				int temp = mat[i][j];
				mat[i][j] = mat[n-1-j][i];
				mat[n-1-j][i] = mat[n-1-i][n-1-j];
				mat[n-1-i][n-1-j] = mat[j][n-1-i];
				mat[j][n-1-i] = temp;
			}
		}
		if (n % 2 == 1)
		{
			for (j = 0; j < range; j++)
			{
				int temp = mat[i][j];
				mat[i][j] = mat[n-1-j][i];
				mat[n-1-j][i] = mat[n-1-i][n-1-j];
				mat[n-1-i][n-1-j] = mat[j][n-1-i];
				mat[j][n-1-i] = temp;
			}
		}
		return mat;

	}
};


//请编写一个算法，若N阶方阵中某个元素为0，
//则将其所在的行与列清零。
//给定一个N阶方阵int[][](C++中为vector>)mat和矩阵的阶数n，
//请返回完成操作后的int[][]方阵(C++中为vector>)，保证n小于
//测试样例：
//[[1,2,3],[0,1,2],[0,0,1]]
//返回：[[0,0,3],[0,0,0],[0,0,0]]
class Clearer {
public:
	vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
		// write code here
		int *row = new int[n];
		int *col = new int[n];
		memset(row, 0, sizeof(int)*n);
		memset(col, 0, sizeof(int)*n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (mat[i][j] == 0)
				{
					row[i] = 1;
					col[j] = 1;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (row[i] || col[j])
					mat[i][j] = 0;
			}
		}
		delete []row;
		delete []col;
		return mat;

	}
};

//假定我们都知道非常高效的算法来检查一个单词是否为其他字符串的子串。
//请将这个算法编写成一个函数，给定两个字符串s1和s2，请编写代码检查
//s2是否为s1旋转而成，要求只能调用一次检查子串的函数。
//	给定两个字符串s1,s2,请返回bool值代表s2是否由s1旋转而成。字符串
//中字符为英文字母和空格，区分大小写，字符串长度小于等于1000。
//	测试样例：
//	"Hello world","worldhello "
//	返回：false
//	"waterbottle","erbottlewat"
//	返回：true
class ReverseEqual {
public:
	bool checkReverseEqual(string s1, string s2) {
		// write code here
		int len = s1.size();
		if (len != s2.size())
			return false;
		
		string test = s2 + s2;
		for (int j = 0; j < len; j++)
		{
			int i = 0;
			for (i = 0; i < len; i++)
			{
				if (s1[i] != test[j + i])
					break;
			}
			if (i == len)
				return true;
		}
		return false;

	}
};

//输入一个链表，输出该链表中倒数第k个结点。
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        int list_len = 0;
        ListNode * list_k =  pListHead;
        ListNode * list_r =  pListHead;
        for(int i=0;i<k;i++)      //list_r 先走k-1步；
        {
            if(list_r == NULL)
                return NULL;
            list_r = list_r->next;
        }
        while(list_r != NULL)
        {
            list_r = list_r->next;
            list_k = list_k->next;
        }
        return list_k;    
    }
};



//实现一个算法，删除单向链表中间的某个结点，假定你只能访问该结点。
//给定带删除的节点，请执行删除操作，若该节点为尾节点，返回false，否则返回true
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Remove {
public:
    bool removeNode(ListNode* pNode) {
        // write code here
        if (pNode == NULL)
            return false;
        if (pNode != NULL && pNode->next == NULL )
            return false;
        //删除next的内存
        ListNode *next = pNode->next;
        pNode->val = next->val;
        pNode->next = next->next;
        delete next;
        return true;
    }
};

//编写代码，以给定值x为基准将链表分割成两部分，
//所有小于x的结点排在大于或等于x的结点之前
//给定一个链表的头指针 ListNode* pHead，请返回
//重新排列后的链表的头指针。注意：分割以后保持
//原来的数据顺序不变。
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        if (NULL == pHead)
            return NULL;
        
        ListNode l(0);
        ListNode s(0);
        ListNode *pl = &l;
        ListNode *ps = &s;
        
        ListNode *p_tmp = pHead;
        while (p_tmp)
        {
            if (p_tmp->val >= x) {
                pl->next = p_tmp;
                pl = p_tmp;                
            }
            else {
                ps->next = p_tmp;
                ps = p_tmp;                    
            }
            p_tmp = p_tmp->next;                
        }
        
        ps->next = l.next;
        pl->next = NULL;
        return s.next;
        
    }
};

//有两个用链表表示的整数，每个结点包含一个数位。
//这些数位是反向存放的，也就是个位排在链表的首部。
//编写函数对这两个整数求和，并用链表形式返回结果。
//给定两个链表ListNode* A，ListNode* B，请返回A+B的结果(ListNode*)。
//测试样例：
//{1,2,3},{3,2,1}
//返回：{4,4,4}
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
        // write code here
        if (NULL == a && NULL != b)
            return b;
        if (NULL != a && NULL == b)
            return a;
        if (NULL == a && NULL == b)
            return NULL;

        ListNode *m = a;
        ListNode *n = b;
        ListNode node(0);
        ListNode *p = &node;
        int flag = 0;
        while (m && n)
        {
            int sum = flag + m->val + n->val;
            m = m->next;
            n = n->next;
            flag = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
        }
        while (m)
        {
            int sum = flag + m->val;
            m = m->next;
            flag = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
        }
        while (n)
        {
            int sum = flag + n->val;
            n = n->next;
            flag = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
        }

		if (flag)
        {    
            p->next = new ListNode(flag);
        	p->next->next = NULL;
        }
        else
	        p->next=NULL;
        return node.next;
    }
};


//请编写一个函数，检查链表是否为回文。
//给定一个链表ListNode* pHead，请返回一个bool，代表链表是否为回文。
//测试样例：
//{1,2,3,2,1}
//返回：true
//{1,2,3,2,3}
//返回：false
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        // write code here
        vector<int> vect;
        if (NULL == pHead)
            return false;
        ListNode *p = pHead;
        while (p)
        {
            vect.push_back(p->val);
            p = p->next;
        }
        for (int i = 0, j = vect.size() - 1; i <= j; i++, j--)
        {
           if (vect[i] != vect[j]) 
               return false;
        }
        return true;

    }
};

//请实现一种数据结构SetOfStacks，由多个栈组成，
//其中每个栈的大小为size，当前一个栈填满时，新建一个栈。
//该数据结构应支持与普通栈相同的push和pop操作。
//给定一个操作序列int[][2] ope(C++为vector<vector<int>>)，
//每个操作的第一个数代表操作类型，若为1，则为push操作，后
//一个数为应push的数字；若为2，则为pop操作，后一个数无意义。
//请返回一个int[][](C++为vector<vector<int>>)，为完成所有操
//作后的SetOfStacks，顺序应为从下到上，默认初始的SetOfStacks
//为空。保证数据合法。
class SetOfStacks {
public:
    vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
        // write code here
        vector<vector<int> > ret;
        int vol = ope.size();
        if (0 == vol || 0 == size)
            return ret;
        
        vector<int > data(vol, 0);
        int idx = 0;
        for (int i = 0; i < vol; i++)
        {
            if (ope[i][0] == 1)
            {
                data[idx] = ope[i][1];
                idx++;
            }
            else if (ope[i][0] == 2)
                idx--;
            else
                ;
        }
        if (0 == idx)
            return ret;
        for (int i = 0; i < (idx / size); i++)
        {
            //恍然大悟
            //迭代器(start)和迭代器(end) - 构造一个初始值为[start,end)区间元素的Vector(注:半开区间).
            //vector<int > vect(data.begin() + size * i, data.begin() + size * (i + 1) - 1);
            vector<int > vect(data.begin() + size * i, data.begin() + size * (i + 1));
            ret.push_back(vect);
        }
        
        if (0 != (idx % size))
        { 
            //vector<int > vect(data.begin() + size * (idx / size), data.end() - 1);
            vector<int > vect(data.begin() + size * (idx / size), data.begin() + size * (idx / size) + (idx % size));
            ret.push_back(vect);
        }
        return ret;
        
    }
};
































