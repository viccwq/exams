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




//在一个字符串(1<=字符串长度<=10000，全部由大写字母组成)
//中找到第一个只出现一次的字符,并返回它的位置

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		int count[256] = {0};

		for (int i = 0; i < str.size(); i++)
			count[(str[i])]++;

		for (int i = 0; i < str.size(); i++)
		{
			if (1 == count[(str[i])])
				return i;
		}
		return -1;       
	}
};


//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
//输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 
//即输出P%1000000007 
/*
输入描述:
题目保证输入的数组中没有的相同的数字
	数据范围：
	对于%50的数据,size<=10^4
	对于%75的数据,size<=10^5
	对于%100的数据,size<=2*10^5


输入例子:
1,2,3,4,5,6,7,0

输出例子:
7
*/

class Solution {
public:
	int InversePairs(vector<int> data) {
		int size = data.size();

		if (size <= 1)
			return 0;

		int count = 0;
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (data[i] > data[j])
					count++;
			}
		}
		return (count % 1000000007);

	}
};


class Solution {
public:
	//http://blog.csdn.net/derrantcm/article/details/46761051
	int InversePairsCore( vector<int> &data, vector<int> &copy, int start, int end)
	{
		if (start == end)
		{
			copy[start]=data[start];
			return 0;
		}

		int mid = (start + end)/ 2 ;
		int left = InversePairsCore(copy, data, start, mid);
		int right = InversePairsCore(copy, data, mid + 1, end);
		long crossCount = 0;
		int i = mid, j = end, temp = end;

		while(i >= start && j >= (mid + 1)) 
		{  
			if (data[i] > data[j]) 
			{ 
				copy[temp--] = data[i--];
				crossCount += j - mid;
			} 
			else 
			{
				copy[temp--] = data[j--]; 
			}
		}
		while(i >= start) 
		{
			copy[temp--] = data[i--];
		}
		while(j >= (mid + 1)) 
		{
			copy[temp--] = data[j--];
		}

		long ret = (left + right + crossCount);
		if (ret > 1000000007)
			return (ret % 1000000007);
		else
			return ret;
	}
	int InversePairs(vector<int> data) {
		if (data. size() <= 1) 
			return 0;
		else if (data. size() == 2) 
			return (data[0] > data[1] ? 1 : 0);
		else 
		{
			vector<int> copy(data);
			return InversePairsCore(data, copy, 0 , data.size()- 1);
		}
	}
};


//输入两个链表，找出它们的第一个公共结点。
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
	ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
		if (!pHead1 || !pHead2)
			return NULL;

		if (pHead1 == pHead2)
			return pHead1;

		ListNode *p_1 = pHead1;
		ListNode *p_2 = pHead2;
		while (NULL != p_1 && NULL != p_2)
		{
			p_1 = p_1->next;
			p_2 = p_2->next;
		}

		if (NULL != p_1)
		{
			ListNode *p = pHead1;
			while (NULL != p_1)
			{
				p = p->next;
				p_1 = p_1->next;
			}
			p_1 = p;
			p_2 = pHead2;
		}
		else if (NULL != p_2)
		{
			ListNode *p = pHead2;
			while (NULL != p_2)
			{
				p = p->next;
				p_2 = p_2->next;
			}
			p_2 = p;
			p_1 = pHead1;
		}
		else
		{
			p_1 = pHead1;
			p_2 = pHead2;
		}

		while (p_1 != p_2)
		{
			p_2 = p_2->next;
			p_1 = p_1->next;
		}
		return p_1;        
	}
};


class Solution {
public:
	ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
		if (!pHead1 || !pHead2)
			return NULL;

		if (pHead1 == pHead2)
			return pHead1;

		ListNode *p_1 = pHead1;
		ListNode *p_2 = pHead2;
		ListNode *p = NULL;
		while (NULL != p_1 && NULL != p_2)
		{
			p_1 = p_1->next;
			p_2 = p_2->next;
		}

		int flag = 0;
		if (NULL != p_1)
		{
			flag = 1;
			p = pHead1;
		}
		else
		{
			flag = 0;
			p = pHead2;
		}

		while (NULL != p_2)
		{
			p_2 = p_2->next;
			p = p->next;
		}

		while (NULL != p_1)
		{
			p_1 = p_1->next;
			p = p->next;
		}

		if (flag == 1)
		{
			p_1 = p;
			p_2 = pHead2;
		}
		else
		{
			p_1 = pHead1;
			p_2 = p;
		}


		while (p_1 != p_2)
		{
			p_2 = p_2->next;
			p_1 = p_1->next;
		}
		return p_1;


	}
};



//统计一个数字在排序数组中出现的次数。
class Solution {
public:
	int GetNumberOfK(vector<int> data ,int k) {
		int ret = 0;
		int size = data.size();
        if (!size) 
			return 0;
        for(int i = (size - 1); i >= 0; i--)
		{
            if (data[i] == k)
                ret++;
        }
        return ret;
	}
};


//输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）
//形成树的一条路径，最长路径的长度为树的深度。
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
	int max_lay = 0;

    int TreeDepth(TreeNode* pRoot)
    {
		if (NULL == pRoot)
			return 0;

		getDepth(pRoot);
		return max_lay;
    }


	void getDepth(TreeNode* pRoot)
	{
		static int lay = 0;
		if (NULL == pRoot)
			return;

		lay++;
		if (lay > max_lay)
			max_lay = lay;

		if (pRoot->left)
			getDepth(pRoot->left);
		if (pRoot->right)
			getDepth(pRoot->right);
		lay--;
		return;
	}

};

class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if(pRoot == NULL)
			return 0;
		int left,right;
		left = TreeDepth(pRoot->left);
		right = TreeDepth(pRoot->right);
		return 1 + (left > right ? left : right);
	}
};



//输入一棵二叉树，判断该二叉树是否是平衡二叉树。
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if(pRoot == NULL)
			return 0;
		int left,right;
		left = TreeDepth(pRoot->left);
		right = TreeDepth(pRoot->right);
		return 1 + (left > right ? left : right);
	}

	bool IsBalanced_Solution(TreeNode* pRoot) {
		if(!pRoot) 
			return true;

		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		int dif = left - right;

		if(dif < -1 || dif > 1)
			return false;
		else
			return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
	}

};


//一个整型数组里除了两个数字之外，其他的数字都出现了两次。
//请写程序找出这两个只出现一次的数字。
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		int size = data.size();
		int n_xor_1 = 0, n_xor_2 = 0;
		int flag = 1;
		for (int i = 0; i < size; i++)
		{
			n_xor_1 ^= data[i];
		}

		while ((n_xor_1 & flag) == 0)
		{
			flag = (flag << 1);
		}

		n_xor_2 = n_xor_1;
		for (int i = 0; i < size; i++)
		{
			if ((data[i] & flag) == 0)
				n_xor_1 ^= data[i];
			else
				n_xor_2 ^= data[i];
		}
		*num1 = n_xor_1;
		*num2 = n_xor_2;

	}
};

//小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,
//他马上就写出了正确答案是100。但是他并不满足于此,他在想究
//竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,
//他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把
//问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck! 
//输出描述:
//输出所有和为S的连续正数序列。序列内按照从小至大的顺序，
//序列间按照开始数字从小到大的顺序

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		//2 * an = x + y - 1
		//2 * a1 = x - y + 1
		//x * y = 2 * sum
		//x > y

		//(x - y)为大于0的奇数
		//(x + y)为大于1的奇数
		//x * y = 2 * sum,其中（1<=y<=sqrt(2 * sum)）
		vector<vector<int> > data;
		if(sum < 3)
			 return data;

		int s = (2 * sum);
		int x = 0;
		int y = sqrt(s);
		for (; y > 1; y--)
		{
			x = 0;
			if (0 == s % y)
			{
				x = s / y;
				if (((x + y) & 0x1) == 0 || ((x - y) & 0x1) == 0)
					continue;
			}
			else
				continue;

			int a1 = (x - y + 1) / 2;
			int an = (x + y - 1) / 2;
			vector<int> v;
			for (int i = a1; i <= an; i++)
				v.push_back(i);
			data.push_back(v);
		}
		return data;

	}
};


//输入一个递增排序的数组和一个数字S，在数组中查找两个数，
//是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。 
//输出描述:
//对应每个测试案例，输出两个数，小的先输出。
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array,int sum) {
		vector<int> res;
		int size = array.size();
		if (size < 2)
			return res;

		int i = 0;
		int j = size - 1;
		while(i < j)
		{
			int s = array[i] + array[j];
			if (s > sum)
				j--;
			else if (s < sum)
				i++;
			else
			{
				res.push_back(array[i]);
				res.push_back(array[j]);
				break;
			}
		}
		return res;

	}
};


//汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
//就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，
//请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,
//要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
class Solution {
public:
	string LeftRotateString(string str, int n) {
		int len = str.length();
		if (len <= 1)
			return str;

		int m = n % len;
		if (0 == m)
			return str;
		else
		{
			str += str;
			return (str.substr(m, len));
		}

	}
};


//牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，
//写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，
//有一天他向Fish借来翻看，但却读不懂它的意思。例如，
//“student. a am I”。后来才意识到，这家伙原来把句子单词的
//顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一
//的翻转这些单词顺序可不在行，你能帮助他么？
class Solution {
public:
	string ReverseSentence(string str) {
		int size = str.length();
		if (size <= 1)
			return str;

		string rev = "";
		str += " ";
		int j = size;
		for (int i = size - 1; i >= 0; i--)
		{
			if (str[i] == ' ')
			{
				rev += str.substr(i + 1, j - i);
				j = i;
			}
		}
		rev += str.substr(0, j);
		return rev;

	}
};


//LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个
//小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,想测测自己的手
//气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
//“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高
//兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,
//K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),
//“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上
//面的过程,然后告诉我们LL的运气如何。为了方便起见,你可以认为大小王是0。

class Solution {
public:
	bool IsContinuous( vector<int> numbers ) {

		if (numbers.size() != 5)
			return false;
		sort(numbers.begin(), numbers.end());

		int cnt0 = 0;
		int gap = 0;
		for(int i = 0; i < 4; i++) 
		{
			if (numbers[i] == 0) 
				++cnt0;
			else if (numbers[i + 1] == numbers[i])
				return false;
			else
				gap += (numbers[i + 1] - numbers[i] - 1);
		}

		if (cnt0 >= gap)
			return true;
		else
			return false;

	}
};


//求1+2+3+...+n，要求不能使用乘除法、for、while、
//if、else、switch、case等关键字及条件判断语句（A?B:C）。
class Solution {
public:
	int Sum_Solution(int n) {
		int sum = 0;
		n && (sum = (Sum_Solution(n - 1) + n));
		return sum;
	}

};


//写一个函数，求两个整数之和，要求在函数
//体内不得使用+、-、*、/四则运算符号。
class Solution {
public:
	int Add(int num1, int num2)
	{
		int bits = sizeof(int) * 4;
		int flag = 0;
		int shift = 1;
		int ret = 0;
		while (shift)
		{
			int temp1 = (num1 & shift);
			int temp2 = (num2 & shift);
			ret = ((temp1 ^ temp2) ^ flag) ^ ret;

			shift = (shift << 1);
			if ((temp1 && temp2) || (temp1 && flag) || (temp2 && flag) )
				flag = shift;
			else
				flag = 0;
		}
		return ret;
	}
};


class Solution {
public:
	//第一遍我是移位运算的，看了一下人家的，确实这样的效率会高些。。。
	int Add(int num1, int num2){
		int sum = 0;
		do
		{
			sum = num1 ^ num2;
			num2 = (num1 & num2)<<1;
			num1 = sum;
		} while(num2);
		return sum;
	}
};


// 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
// 数值为0或者字符串不是一个合法的数值则返回0 
// 输入描述:
// 输入一个字符串,包括数字字母符号,可以为空
// 
// 
// 输出描述:
// 如果是合法的数值表达则返回该数字，否则返回0
// 
// 输入例子:
// +2147483647
// 	1a33
// 
// 输出例子:
// 2147483647
// 	0

class Solution {
public:
	int StrToInt(string str) {
		int len = str.length();
		if (0 == len || str.empty())
			return 0;

		int ret = 0;
		int flag = 1;
		int i;
		for (i = len - 1; i >= 0; i--)
		{
			if (str[i] >= '0' && str[i] <= '9')
				ret += ((str[i] - '0') * flag);
			else if (str[i] == ' ' || str[i] == '+' || str[i] == '-')
				break;
			else
				return 0;
			flag *= 10;
		}

		if(str[i] == '-')
			return ret * (-1);
		else
			return ret;

	}
};



//在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
//数组中某些数字是重复的，但不知道有几个数字是重复的。
//也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
//例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应
//的输出是重复的数字2或者3。

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (length <= 1)
			return false;
		
		bool ret = true;
		int idx = -1;

		int *cnt = new int[length];
		memset(cnt, 0x0, sizeof(int) * length);
	
		for (int i = 0; i < length; i++)
		{			
			if (numbers[i] >= 0 && numbers[i] < length)
			{
				if ((++cnt[numbers[i]]) >= 2)
					idx = i;
			}
			else
			{
				ret = false;
				break;
			}
		}
		if (ret && (idx >= 0))
			*duplication = numbers[idx];
		else
			ret = false;

		delete []cnt;
		return ret;


	}
};


//给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
//其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
//不能使用除法。
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		vector<int> B;
		int size = A.size();
		if (size <= 1)
			return A;

		int temp = 1;
		B.push_back(1);
		for (int i = 1; i < size; i++)
		{
			temp *= A[i - 1];
			B.push_back(temp);
		}

		temp = 1;
		for (int i = size - 2; i >= 0; i--)
		{
			temp *= A[i + 1];
			B[i] *= temp;
		}
		return B;
	}
};


//请实现一个函数用来匹配包括'.'和'*'的正则表达式。
//模式中的字符'.'表示任意一个字符，而'*'表示它前
//面的字符可以出现任意次（包含0次）。 在本题中，匹
//配是指字符串的所有字符匹配整个模式。例如，字符串
//"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和
//"ab*a"均不匹配
class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (NULL == str || NULL == pattern)
			return false;
		return ismatch(str, pattern);
	}


	bool ismatch(char* str, char* pattern)
    {
        if(str[0] == '\0' && pattern[0] == '\0')
            return true;
		if (str[0] != '\0' && pattern[0] == '\0')
			return false;

		if (pattern[1] == '*')
		{
			if (str[0] == pattern[0] || (pattern[0] == '.' && str[0] != '\0'))
				return ismatch(str + 1, pattern) || ismatch(str, pattern + 2);
			else
				return ismatch(str, pattern + 2);
		}

		if (str[0] == pattern[0] || (pattern[0] == '.' && str[0] != '\0'))
			return ismatch(str + 1, pattern + 1);
		else
			return false;
    }

};

//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
//例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
//但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
class Solution {
public:
	bool isNumeric(char* string)
	{
		if (string[0] == '\0')
			return false;

		int index = check_e(string);
		if (index < 0)
			return false;
		else if (index > 0)
		{
			string[index] = '\0';
			return check(string, 2) && check(string + index + 1, 1);
		}
		else
			return check(string, 2);
	}

	bool check(char* string, int flag)
	{
		int count = 0;
		if (!(string[0] >= '0' && string[0] <= '9') && (string[0] != '+') && (string[0] != '-'))
			return false;

		for (int i = 1; string[i] != '\0'; i++)
		{
			if (string[i] < '0' || string[i] > '9')
			{
				if (string[i] == '.')
					count++;
				else
					return false;
			}
			if (count >= flag)
				return false;
		}
		return true;
	}

	//返回唯一的字母e所在的位置
	int check_e(char* string)
	{
		if (string[0] == 'e' || string[0] == 'E')
			return -1;

		int index = 0;
		int count = 0;
		for (int i = 1; string[i] != '\0'; i++)
		{
			if (string[i] >= 'a' && string[i] <= 'z' )
			{
				if (string[i] == 'e')
				{
					index = i;
					count++;
				}
				else
					return -1;
			}

			if (string[i] >= 'A' && string[i] <= 'Z' )
			{
				if (string[i] == 'E')
				{
					index = i;
					count++;
				}
				else
					return -1;
			}
		}
		//如果有多e
		if (count > 1)
			return -1;
		else
			return index;
	}

};


//请实现一个函数用来找出字符流中第一个只出现一次的字符。
//例如，当从字符流中只读出前两个字符"go"时，第一个只出
//现一次的字符是"g"。当从该字符流中读出前六个字符“google"
//时，第一个只出现一次的字符是"l"。 
//输出描述:
//如果当前字符流没有存在出现一次的字符，返回#字符。
class Solution
{
public:
	//Insert one char from stringstream
	vector<char> buff;
	int count[256] = {0};
	void Insert(char ch)
	{
		buff.push_back(ch);
		count[ch]++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		int size = buff.size();
		for (int i = 0; i < size; i++)
		{
			char ch = buff[i];
			if (count[ch] == 1)
				return ch;
		}
		return '#';
	}

};


//一个链表中包含环，请找出该链表的环的入口结点。
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
	vector<ListNode *> p;
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
		if (!pHead->next)
			return NULL;

		ListNode* front = pHead;
		ListNode* temp = NULL;
		while (NULL != front->next)
		{
			temp = front->next;
			front->next = NULL;

			front = temp;
			p.push_back(temp);
		}

		temp = pHead;
		int i = 0;
		while (NULL == temp->next)
		{
			temp->next = p[i++];
			temp = temp->next;
		}
		return front;

    }

};

//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
//重复的结点不保留，返回链表头指针。 例如，
//链表1->2->3->3->4->4->5 处理后为 1->2->5
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
		if (NULL == pHead)
			return NULL;

		ListNode h(-1);
		ListNode* ph = &h;
		ph->next = pHead;

		ListNode* p1 = NULL;
		ListNode* p2 = NULL;
		int data = -1;
		while ((p1 = ph->next) && (p2 = p1->next))
		{
			if (p1->val == p2->val)
			{
				ph->next = p2->next;
				data = p1->val;
				delete p1;
				delete p2;
				continue;
			}

			if (data == p1->val)
			{
				ph->next = p2;
				delete p1;
			}
			else
				ph = p1;

		}

		if (p1 && (data == p1->val))
		{
			ph->next = NULL;
			delete p1;
		}
		return h.next;

    }
};

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


//给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
//注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (NULL == pNode)
			return NULL;
		
		TreeLinkNode* p = NULL;

		//1、有右子树的
		if (pNode->right != NULL)
		{
			p = pNode->right;
			while (p->left != NULL)
				p = p->left;
			return p;
		}

		//2、没有右子树的
		p = pNode->next;
		while (p != NULL)
		{
			TreeLinkNode *proot = p->next;
			if (proot->left == p)
				return proot;
			p = p->next;
		}
		return NULL;

	}
};








































