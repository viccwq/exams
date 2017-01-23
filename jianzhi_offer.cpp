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




//��һ���ַ���(1<=�ַ�������<=10000��ȫ���ɴ�д��ĸ���)
//���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��

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


//�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
//����һ������,�����������е�����Ե�����P������P��1000000007ȡģ�Ľ������� 
//�����P%1000000007 
/*
��������:
��Ŀ��֤�����������û�е���ͬ������
	���ݷ�Χ��
	����%50������,size<=10^4
	����%75������,size<=10^5
	����%100������,size<=2*10^5


��������:
1,2,3,4,5,6,7,0

�������:
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


//�������������ҳ����ǵĵ�һ��������㡣
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



//ͳ��һ�����������������г��ֵĴ�����
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


//����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩
//�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
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



//����һ�ö��������жϸö������Ƿ���ƽ���������
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


//һ�����������������������֮�⣬���������ֶ����������Ρ�
//��д�����ҳ�������ֻ����һ�ε����֡�
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

//С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,
//�����Ͼ�д������ȷ����100�����������������ڴ�,�����뾿
//���ж������������������еĺ�Ϊ100(���ٰ���������)��û���,
//���͵õ���һ������������Ϊ100������:18,19,20,21,22�����ڰ�
//���⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? Good Luck! 
//�������:
//������к�ΪS�������������С������ڰ��մ�С�����˳��
//���м䰴�տ�ʼ���ִ�С�����˳��

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		//2 * an = x + y - 1
		//2 * a1 = x - y + 1
		//x * y = 2 * sum
		//x > y

		//(x - y)Ϊ����0������
		//(x + y)Ϊ����1������
		//x * y = 2 * sum,���У�1<=y<=sqrt(2 * sum)��
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


//����һ����������������һ������S���������в�����������
//�ǵ����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ� 
//�������:
//��Ӧÿ�����԰����������������С���������
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


//�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵�����
//�������ַ���ģ�����ָ���������������һ���������ַ�����S��
//�������ѭ������Kλ���������������磬�ַ�����S=��abcXYZdef��,
//Ҫ�����ѭ������3λ��Ľ��������XYZdefabc�����ǲ��Ǻܼ򵥣�OK���㶨����
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


//ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��
//дЩ�����ڱ����ϡ�ͬ��Cat��Fishд�������ĸ���Ȥ��
//��һ������Fish������������ȴ������������˼�����磬
//��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�
//˳��ת�ˣ���ȷ�ľ���Ӧ���ǡ�I am a student.����Cat��һһ
//�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��
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


//LL���������ر��,��Ϊ��ȥ����һ���˿���,���������Ȼ��2������,2��
//С��(һ����ԭ����54��^_^)...��������г����5����,�����Լ�����
//��,�����ܲ��ܳ鵽˳��,����鵽�Ļ�,������ȥ��������Ʊ,�ٺ٣���
//������A,����3,С��,����,��Ƭ5��,��Oh My God!������˳��.....LL����
//����,��������,������\С �����Կ����κ�����,����A����1,JΪ11,QΪ12,
//KΪ13�������5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ���2��4),
//��So Lucky!����LL����ȥ��������Ʊ���� ����,Ҫ����ʹ�������ģ����
//��Ĺ���,Ȼ���������LL��������Ρ�Ϊ�˷������,�������Ϊ��С����0��

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


//��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��
//if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
class Solution {
public:
	int Sum_Solution(int n) {
		int sum = 0;
		n && (sum = (Sum_Solution(n - 1) + n));
		return sum;
	}

};


//дһ������������������֮�ͣ�Ҫ���ں���
//���ڲ���ʹ��+��-��*��/����������š�
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
	//��һ��������λ����ģ�����һ���˼ҵģ�ȷʵ������Ч�ʻ��Щ������
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


// ��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯����
// ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0 
// ��������:
// ����һ���ַ���,����������ĸ����,����Ϊ��
// 
// 
// �������:
// ����ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0
// 
// ��������:
// +2147483647
// 	1a33
// 
// �������:
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



//��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� 
//������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
//Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� 
//���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ
//��������ظ�������2����3��

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


//����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],
//����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]��
//����ʹ�ó�����
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


//��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��
//ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ
//����ַ����Գ�������Σ�����0�Σ��� �ڱ����У�ƥ
//����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���
//"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��
//"ab*a"����ƥ��
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

//��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������
//���磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ��
//����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�
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

	//����Ψһ����ĸe���ڵ�λ��
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
		//����ж�e
		if (count > 1)
			return -1;
		else
			return index;
	}

};


//��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ���
//���磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ��
//��һ�ε��ַ���"g"�����Ӹ��ַ����ж���ǰ�����ַ���google"
//ʱ����һ��ֻ����һ�ε��ַ���"l"�� 
//�������:
//�����ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���
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


//һ�������а����������ҳ�������Ļ�����ڽ�㡣
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

//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬
//�ظ��Ľ�㲻��������������ͷָ�롣 ���磬
//����1->2->3->3->4->4->5 �����Ϊ 1->2->5
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


//����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
//ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
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

		//1������������
		if (pNode->right != NULL)
		{
			p = pNode->right;
			while (p->left != NULL)
				p = p->left;
			return p;
		}

		//2��û����������
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








































