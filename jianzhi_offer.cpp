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


//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;

        if (pRoot1 && pRoot2)
        {
            if (pRoot1->val == pRoot2->val)
            {
                result = DoesTree1HasTree2(pRoot1, pRoot2);
            }
            if (!result)
            {
                result = HasSubtree(pRoot1->left, pRoot2);
            }
            if (!result)
            {
                result = HasSubtree(pRoot1->right, pRoot2);
            }
        }

        return result;
    }

    bool DoesTree1HasTree2(TreeNode* root1, TreeNode* root2)
    {
        if (!root2)
        {
            return true;
        }

        if (!root1)
        {
            return false;
        }

        if (root1->val != root2->val)
        {
            return false;
        }
        return DoesTree1HasTree2(root1->left, root2->left) \
            && DoesTree1HasTree2(root1->right, root2->right);
        
    }


};

//操作给定的二叉树，将其变换为源二叉树的镜像。 
//输入描述:
//二叉树的镜像定义：源二叉树 
//    	    8
//    	   /  \
//    	  6   10
//    	 / \  / \
//    	5  7 9 11
//    	镜像二叉树
//    	    8
//    	   /  \
//    	  10   6
//    	 / \  / \
//    	11 9 7  5


/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {

        if (pRoot)
        {
           TreeNode *temp = pRoot->left;
           pRoot->left = pRoot->right;
           pRoot->right = temp;
        }
        else
           return;
        Mirror(pRoot->left);
        Mirror(pRoot->right);

    }
};


//顺时针打印矩阵
//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int h = matrix.size();
        int w = matrix[0].size();
        vector<int> res;
        if (h == 0)
            return res;
        else if (h == 1)
            return matrix[0];
        else if (h > 1 && w == 1)
        {
            for(int i = 0; i < h; i++)
                res.push_back(matrix[i][0]);
            return res;
        }
        else
        {
            int top = 0, bottom = h - 1, left = 0, right = w - 1;
            while (top <= bottom && left <= right)
            {
                
                
                for(int i = left; i <= right; i++)
                    res.push_back(matrix[top][i]);          
                for(int j = top + 1; j <= bottom - 1; j++)
                    res.push_back(matrix[j][right]);

                if (top != bottom)
                {
                    for(int k = right; k >= left; k--)
                        res.push_back(matrix[bottom][k]);
                }

                if (right != left)
                {
                    for(int m = bottom - 1; m >= top + 1; m--)
                        res.push_back(matrix[m][left]);
                }
                top++;
                bottom--;
                left++;
                right--;
            }
            return res;
        }



    }
};

//包含min函数的栈
//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
class Solution {
public:


    stack<int> data, min_data;
    void push(int value) {
        
        data.push(value);
        if (min_data.empty())
            min_data.push(value);
        else
        {
            int last_min = min_data.top();
            min_data.push((last_min < value)?last_min:value);
        }
    }
    void pop() {
        data.pop();
        min_data.pop();
       
    }
    int top() {
        if (!data.empty())
            return data.top();
        else
            return -1;
        
    }
    int min() {
        if (!min_data.empty())
            return min_data.top();
        else
            return -1;
    }

};

//栈的压入 弹出序列
//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）


class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
  		int size = popV.size();
		if (0 == size) 
			return false;

		stack<int> data;
		for(int i = 0, j = 0; i < size; i++)
		{
			data.push(pushV[i]);
			while(j < size && data.top() == popV[j])
			{
				data.pop();
				j++;
			}    
		}
		return data.empty();        
    }
};

//从上往下打印出二叉树的每个节点，同层节点从左至右打印。
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> result;
		if(root==NULL)
			return result;

		queue<TreeNode *> Q;
		Q.push(root);
		while(!Q.empty())
		{
			TreeNode* p = Q.front();
			result.push_back(p->val);
			Q.pop();
			if(p->left != NULL)
				Q.push(p->left);
			if(p->right != NULL)
				Q.push(p->right);
		}
		return result;
    }
};

//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		int size = sequence.size();
		if (!size)
			return false;

		return isPostBST(sequence, 0, size - 1);
    }
    
    bool isPostBST(vector<int>& sequence, int start, int end)
    {
        if (end <= start)
            return true;

        int i = start;
        int data = sequence[end];
        for (; i < end; i++)
        {
            if (sequence[i] > data)
                break;
        }
        //对序列的右子树进行判断
        int j = i;
        for (; j < end; j++)
        {
            if (sequence[j] < data)
                return false;
        }
        return isPostBST(sequence, start, i - 1) \
            && isPostBST(sequence, i, end - 1);
    }   
    
    
};



//输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
//路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {

public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		if (NULL == root)
			return allRes;
		Find(root, expectNumber);
		return allRes;
    }

	vector<vector<int> >allRes;
	vector<int> tmp;

	void Find(TreeNode * node , int val)
	{
		tmp.push_back(node->val);
		int val_tmp = val - node->val;

		if(val_tmp == 0 && !node->left && !node->right)
			allRes.push_back(tmp);
		else 
		{
			if(node->left) 
				Find(node->left, val_tmp);
			if(node->right) 
				Find(node->right, val_tmp);
		}
		tmp.pop_back(); 
	}
};



//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
//返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
		if (NULL == pHead)
			return NULL;
		RandomListNode* p_tmp_1 = pHead;
		RandomListNode* p_tmp_2 = NULL;

		while (p_tmp_1)
		{
			RandomListNode* p_new = new RandomListNode(p_tmp_1->label);
			p_tmp_2 = p_tmp_1->next;

			p_tmp_1->next = p_new;
			p_new->next = p_tmp_2;
			
			p_tmp_1 = p_tmp_2;
		} 
		
		p_tmp_1 = pHead;
		while (p_tmp_1)
		{			
			if (p_tmp_1->random != NULL)
				p_tmp_1->next->random = p_tmp_1->random->next;

			p_tmp_1 = p_tmp_1->next->next;
		} 

		p_tmp_1 = pHead;
		RandomListNode* p_new = pHead->next;
		p_tmp_2 = p_new;
		while (1)
		{

			p_tmp_1->next = p_tmp_2->next;
			p_tmp_1 = p_tmp_2->next;
			if (p_tmp_1)
			{
				p_tmp_2->next = p_tmp_1->next;
				p_tmp_2 = p_tmp_1->next;
			}
			else
			{
				p_tmp_2->next = NULL;
				break;
			}
		}
		return p_new;

    }
};


//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
//要求不能创建任何新的结点，只能调整树中结点指针的指向。
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	bool first_flag = true;
	TreeNode *p_n = NULL;
	TreeNode *p_head = NULL;

    TreeNode* Convert(TreeNode* pRootOfTree)
    {
		if (!pRootOfTree)
			return NULL;
        first_flag = true;
		add_node(pRootOfTree);
		p_n->right = NULL;
		return p_head;       
    }

	void add_node(TreeNode* p_node)
	{
		if (NULL == p_node)
			return;

		TreeNode *p_left = p_node->left;
		TreeNode *p_right = p_node->right;
		add_node(p_left);

		if (first_flag)
		{
			p_head = p_node;
			p_n = p_node;
			first_flag = false;
		}
		else
		{
			p_n->right = p_node;
			p_node->left = p_n;
			p_n = p_node;
		}
		add_node(p_right);
	}
};


//输入一个字符串,按字典序打印出该字符串中字符的所有排列。
//例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。 
//输入描述:
//输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
class Solution {
public:
	void Help(vector<string> &ans, int k, string str)
	{
		if(k == str.size() - 1)
			ans.push_back(str);
		for(int i = k; i < str.size(); i++)
		{
			if(i != k && str[k] == str[i])
				continue;
			swap(str[i], str[k]);
			Help(ans, k + 1, str);
		}
	}

	vector<string> Permutation(string str) {
		sort(str.begin(), str.end());
		vector<string> vect;
		Help(vect, 0, str);
		return vect;
	}

};


//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int size = numbers.size();
		int size_half = size / 2;
		int idx = -1;
		if (0 == size)
			return 0;
		if (1 == size)
			return numbers[0];

		int *p_cal = new int [size];
		for (int i = 0; i < size; i++)
			p_cal[i] = 1;

		for (int i = 0; i < (size - 1); i++)
		{
			if (0 == p_cal[i])
				continue;
			for (int j = (i + 1); j < size; j++)
			{
				if (0 == p_cal[j])
					continue;
				if (numbers[i] == numbers[j])
				{
					p_cal[i]++;
					p_cal[j] = 0;
				}
			}

			if (p_cal[i] > size_half)
			{
				idx = i;
				break;
			}
		}
		delete [] p_cal;
		if (idx > -1)
			return numbers[idx];
		else
			return 0;  
	}
};


//输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> min;
		vector<int> temp(input);		
		vector<int>::iterator it;
		if (0 == k || k > input.size())
			return min;

		int min_a = 0;
		int min_b = 0x7fffffff;
		for (it = temp.begin(); it != temp.end(); it++)
		{
			if (min_b > (*it))
				min_b = (*it);
		}

		min.push_back(min_b);
		if (1 == k)		
			return min;

		while(min.size() < k)
		{
			min_a = min_b;
			min_b = 0x7fffffff;
			for (it = temp.begin(); it != temp.end(); )
			{
				if (min_a == (*it))
				{
					temp.erase(it);
					continue;
				}
				if (min_b > (*it))
					min_b = (*it);
				it++;
			}
			min.push_back(min_b);
		}

		return min;
	}
};


class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> vec;
        if(input.size() < k)
            return vec;
        if(input.size() == k)
            return input;
        sort(input.begin(), input.end());
        for(int i = 0; i < k; ++i)
            vec.push_back(input[i]);
        return vec;
    }
};

//HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:
//在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
//但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
//例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
//你会不会被他忽悠住？(子向量的长度至少是1)

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int size = array.size();
		if (0 == size)
			return 0;
		if (1 == size)
			return array[0];
		if (2 == size)
			return (array[0] > array[1])?array[0]:array[1];

		int max = array[0];
		int temp = 0;
		for (int i = 0; i < size; i++)
		{
			temp = 0;
			for (int j = i; j < size; j++)
			{
				temp += array[j];
				if (temp > max)
					max = temp;
			}
		}
		return max;


	}
};
/*
算法时间复杂度O（n）
用total记录累计值，maxSum记录和最大
基于思想：对于一个数A，若是A的左边累计数非负，那么加上A能使得值不小于A，认为累计值对
          整体和是有贡献的。如果前几项累计值负数，则认为有害于总和，total记录当前值。
此时 若和大于maxSum 则用maxSum记录下来
*/
public class Solution {
    public int FindGreatestSumOfSubArray(int[] array) {
        if(array.length==0)
            return 0;
        else{
            int total=array[0],maxSum=array[0];
            for(int i=1;i<array.length;i++){
                if(total>=0)
                    total+=array[i];
                else
                    total=array[i];
                if(total>maxSum)
                    maxSum=total;
            }
            return maxSum;
        }
         
    }
}


//整数中1出现的次数（从1到n整数中1出现的次数）
//求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
//为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
//但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,
//可以很快的求出任意非负整数区间中1出现的次数。

class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int count = 0;
		if (0 == n)
			return 0;

		for (int i = 0; i <= n; i++)
			count += NumberOf1(i);
		return count;
	}

	int NumberOf1(int n)
	{
		int number = 0;
		while(n != 0)
		{
			if(n % 10 == 1)
				number++;

			n = n / 10;
		}
		return number;
	}
};



//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		string str = "";
		int size = numbers.size();
		if (0 == size)
			return str;
		if (1 == size)
		{
			return to_string(numbers[0]);
		}

		vector<string> vec_str;
		for (int j = 0; j < size; j++)
		{
			vec_str.push_back(to_string(numbers[j]));
		}


		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i; j < size; j++)
			{
				string s1 = vec_str[i] + vec_str[j];
				string s2 = vec_str[j] + vec_str[i];
				if (s1 > s2)
					swap(vec_str[i], vec_str[j]);
			}
			str += vec_str[i];
		}
		str += vec_str[size - 1];
		return str;
		
	}
};


//把只包含因子2、3和5的数称作丑数（Ugly Number）。
//例如6、8都是丑数，但14不是，因为它包含因子7。 
//习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
		if (index <= 0)
			return 0;
		if (index >= 1 && index <=6)
			return index;

		int i2 = 0, i3 = 0, i5 = 0;
		vector<int> ugly;
		ugly.push_back(1);
		while (ugly.size() < index)
		{
			int v2 = ugly[i2] * 2;
			int v3 = ugly[i3] * 3;
			int v5 = ugly[i5] * 5;
			int v_min = min(min(v2, v3), v5);
			ugly.push_back(v_min);
			if (v_min == v2)
				i2++;
			if (v_min == v3)
				i3++;
			if (v_min == v5)
				i5++;
		}
		return ugly[index - 1];

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








