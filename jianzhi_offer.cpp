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

//二维数组中查找
//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
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
//替换空格
//请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
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



//从未到头打印链表
//输入一个链表，从尾到头打印链表每个节点的值。
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





//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
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


//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
//例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
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


//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
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

//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
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

//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳
class Solution {
public:
    int jumpFloorII(int number) {
        if(number <= 2) 
            return number;
        else
            return 2 * jumpFloorII(number - 1);
    }
};


//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
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

//数值的整数次方
//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
class Solution {
public:
    double Power(double base, int exponent) {
    
        if (!exponent)
            return 1;
        unsigned int exp = (exponent > 0) ? exponent : (exponent * -1);
        double result = base;
        while (--exp)
        {
            result *= base;
        }
        return (double)((exponent > 0) ? result : (1 / result)); 

    }
};



//调整数组顺序使奇数位于偶数前面
//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
//所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> even_a; 
        int size = array.size();
        int odd_idx = 0;
        for(int i = 0; i < size; i++)
        {
            if (array[i] & 0x1)
            {
                if (odd_idx < i)
                    array[odd_idx] = array[i];
                odd_idx++;
            }
            else
                even_a.push_back(array[i]);
        }
        for(int i = odd_idx; i < size; i++)
        {
            array[i] = even_a[i - odd_idx];
        }

    }
};



//链表中倒数第k个节点
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



//反转链表
//输入一个链表，反转链表后，输出链表的所有元素。
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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* p_temp = pHead;
        if (NULL == p_temp)
            return NULL;

        ListNode* p_temp_n = pHead->next;
        if (NULL == p_temp_n)
            return pHead;

        pHead->next = NULL;
        while(NULL != p_temp_n)
        {
            ListNode* p = p_temp_n->next; 
            p_temp_n->next = p_temp;
            p_temp = p_temp_n;
            p_temp_n = p;
        }

        return p_temp;


    }
};





//合并两个排序的链表
//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        
        if (!pHead1)
            return pHead2;
        if (!pHead2)
            return pHead1;
        ListNode* p_temp= NULL, *ph1 = pHead1, *ph2 = pHead2;
        ListNode* p_head= NULL;

        if (ph1->val < ph2->val)
        {
            p_head= ph1;
            ph1 = ph1->next;
        }
        else
        {
            p_head= ph2;
            ph2 = ph2->next;
        }

        p_temp = p_head;
        while (ph1 && ph2)
        {
            if (ph1->val < ph2->val)
            {
                p_temp->next = ph1;
                ph1 = ph1->next;
            }
            else
            {
                p_temp->next = ph2;
                ph2 = ph2->next;
            }
            p_temp = p_temp->next;
        }

        if (ph1)
            p_temp->next = ph1;
        else if (ph2) 
            p_temp->next = ph2;
        else
            p_temp->next = NULL;

        return p_head;

    }
};


//删除链表中重复的结点
//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        int val;
        if (NULL == pHead)
            return NULL;
        if (NULL == pHead->next)
            return pHead;

        ListNode head(-1);
        head.next = pHead;

        ListNode* p_pre = &head;
        ListNode* p_cur = head.next;
        ListNode* p_d = NULL;
        while (p_cur && p_cur->next)
        {
            if (p_cur->next->val == p_cur->val)
            {
                val = p_cur->val;
                p_d = p_cur;
                p_cur = p_cur->next->next;
                p_pre->next = p_cur;
                    
                delete p_d->next;
                delete p_d;
                continue;
            }

            if (p_cur->val == val)
            {
                p_d = p_cur;
                p_cur = p_cur->next;
                p_pre->next = p_cur;
                delete p_d;
            }
            else
            {
                p_pre = p_cur;
                p_cur = p_cur->next;
            }
        }

        if (p_cur && p_cur->val == val)
        {
            p_pre->next = NULL;
            delete p_cur;
        }
        return head.next;

    }
};








