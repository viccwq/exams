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




















































