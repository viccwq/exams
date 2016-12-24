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
