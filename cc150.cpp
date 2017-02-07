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

























































