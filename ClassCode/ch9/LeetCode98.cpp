#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct TreeNode
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
	int predt;
	bool first;				//��Ϊ��Ա���� 
public:
    bool isValidBST(TreeNode* root)
	{
        if (!root) return true;
        if (!root->left && !root->right) return true;
		first=true;
        return JudgeBST(root);
	}
	bool JudgeBST(TreeNode* b)             	//�ж��Ƿ�ΪBST
	{
    	if (b==NULL)                       	//������һ�ö���������
        	return true;
    	else
        {	bool lflag=JudgeBST(b->left);   //�ж�������
        	if (!lflag)
            	return false;               //������������BST���򷵻�false
            if (first)
            	first=false;
        	else if (predt>=b->val)
				return false;               //����ǰ���ֵС�ڵ�������ǰ�����ֵ���򷵻�false
        	predt=b->val;                   //���浱ǰ���Ĺؼ���
        	bool rflag=JudgeBST(b->right);   //�ж�������
        	return rflag;
    	}
	}
};

int main()
{
	TreeNode* root=new TreeNode(2);
	TreeNode* l=new TreeNode(1);
	TreeNode* r=new TreeNode(3);
	root->left=l;
	root->right=r;
	Solution obj;
	cout << obj.isValidBST(root) << endl;
	return 0;
}
