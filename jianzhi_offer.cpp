/*************************************************************************
 * Copyright(c) 2016-2020 VX-Lab. All rights reserved.
 * File Name:    jianzhi_offer.cpp
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


#include "jianzhi_offer.h"
#include <iostream>
using namespace std;

//��ά�����в���
//��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int col = array[0].size() - 1;
        int row = array.size() - 1;
        int i = 0, j = col;
        while (i <= row && j >= 0)
        {
            if (array[i][j] == target)
                return true;
            else if (array[i][j] > target)
                j--;
            else
                i++;
        }
        return false;
        
    }
};


//
//�滻�ո�
//��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
class Solution {
public:
	void replaceSpace(char *str,int length) {

        
        int count = 0;
        int i = length - 1;
        while (i>=0)
        {
            if (str[i--] == ' ')
                count++;
        }

        if (!count)
            return;

        i = length - 1;
        str[length + 2 * count] = '\0';
        while (i>=0)
        {
            if (str[i] == ' ')
            {
                str[i + 2 * count] = '0';
                str[i + 2 * count - 1] = '2';
                str[i + 2 * count - 2] = '%';
                count--;
            }
            else
                str[i + 2 * count] = str[i];
            i--;
        }


	}
};



//��δ��ͷ��ӡ����
//����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vect;
        ListNode *next = head;
        while (next != NULL)
        {
            vect.push_back(next->val);
            next = next->next;
        }

        int i = 0, j = vect.size() - 1;
        int temp;
        while (i < j)
        {
            temp = vect[i]; 
            vect[i] = vect[j]; 
            vect[j] = temp; 
            i++;
            j--;
        }
        return vect;

    }
};





//������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
//
class Solution
{
public:
    void push(int node) {
       stack1.push(node); 
    }

    int pop() {
        int val;
        if (stack2.empty()) 
        {
            while (!stack1.empty())
            {
                int temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
        }
 
        val = stack2.top();
        stack2.pop();
        return val;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
//����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
//��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
//NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int size = rotateArray.size();
        if (!size)
            return 0;
        if (rotateArray[0] < rotateArray[size - 1])
            return rotateArray[0];

        size--;
        while (size)
        {
            if(rotateArray[size] < rotateArray[size - 1])
                break;
            size--;
        }
        return rotateArray[size];

    }
};

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
       sort(rotateArray.begin(),rotateArray.end());
         
        return rotateArray[0];
         
    }
};


//��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�
//n<=39

class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0)
            return 0;
        
       	if (n <= 2)
            return 1;
        else
        	return (Fibonacci(n - 1) + Fibonacci(n - 2)); 
    }
};

//һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������
class Solution {
public:
    int jumpFloor(int number) {
        vector<int> count(number+1);
        count[0] = 0;
        count[1] = 1;
        count[2] = 2;
        count[3] = 3;
        count[4] = 5;
        if (number >= 5)
        {
            for (int i = 5; i <= number; i++)
                count[i] = count[i - 1] + count[i - 2];
        }
        return count[number];
        
    }
};

//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�������
class Solution {
public:
    int jumpFloorII(int number) {
        if(number <= 2) 
            return number;
        else
            return 2 * jumpFloorII(number - 1);
    }
};


//����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
class Solution {
public:
     int  NumberOf1(int n) {
                 
        unsigned int temp;
        int i = 0;
        memcpy(&temp, &n, sizeof(int));
        while (temp)
        {
            temp &= (temp - 1);
                i++;
        }
        return i;
        
         
     }
};














