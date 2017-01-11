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

//��ֵ�������η�
//����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
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



//��������˳��ʹ����λ��ż��ǰ��
//����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
//���е�ż��λ��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
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



//�����е�����k���ڵ�
//����һ����������������е�����k����㡣
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
        for(int i=0;i<k;i++)      //list_r ����k-1����
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



//��ת����
//����һ��������ת�����������������Ԫ�ء�
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





//�ϲ��������������
//���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
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


//�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
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

//���������Ķ�����������任ΪԴ�������ľ��� 
//��������:
//�������ľ����壺Դ������ 
//    	    8
//    	   /  \
//    	  6   10
//    	 / \  / \
//    	5  7 9 11
//    	���������
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


//˳ʱ���ӡ����
//����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣����磬����������¾��� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 �����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
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

//����min������ջ
//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������
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

//ջ��ѹ�� ��������
//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4��5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�


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

//�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
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

//����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No���������������������������ֶ�������ͬ��
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
        //�����е������������ж�
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



//����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
//·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
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



//����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩��
//���ؽ��Ϊ���ƺ��������head����ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
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


//����һ�ö��������������ö���������ת����һ�������˫������
//Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
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


//����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С�
//���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba�� 
//��������:
//����һ���ַ���,���Ȳ�����9(�������ַ��ظ�),�ַ�ֻ������Сд��ĸ��
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


//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
//��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0
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


//����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,
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

//HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ����������鿪����,���ַ�����:
//�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý����
//����,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�
//����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)��
//��᲻�ᱻ������ס��(�������ĳ���������1)

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
�㷨ʱ�临�Ӷ�O��n��
��total��¼�ۼ�ֵ��maxSum��¼�����
����˼�룺����һ����A������A������ۼ����Ǹ�����ô����A��ʹ��ֵ��С��A����Ϊ�ۼ�ֵ��
          ��������й��׵ġ����ǰ�����ۼ�ֵ����������Ϊ�к����ܺͣ�total��¼��ǰֵ��
��ʱ ���ʹ���maxSum ����maxSum��¼����
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


//������1���ֵĴ�������1��n������1���ֵĴ�����
//���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����
//Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,
//���Ƕ��ں�����������û���ˡ�ACMerϣ�����ǰ����,������������ձ黯,
//���Ժܿ���������Ǹ�����������1���ֵĴ�����

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



//����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
//������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
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


//��ֻ��������2��3��5��������������Ugly Number����
//����6��8���ǳ�������14���ǣ���Ϊ����������7�� 
//ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������
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


















































//ɾ���������ظ��Ľ��
//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5

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








