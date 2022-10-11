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
	bool first;				//作为成员变量 
public:
    bool isValidBST(TreeNode* root)
	{
        if (!root) return true;
        if (!root->left && !root->right) return true;
		first=true;
        return JudgeBST(root);
	}
	bool JudgeBST(TreeNode* b)             	//判断是否为BST
	{
    	if (b==NULL)                       	//空树是一棵二叉排序树
        	return true;
    	else
        {	bool lflag=JudgeBST(b->left);   //判断左子树
        	if (!lflag)
            	return false;               //若左子树不是BST，则返回false
            if (first)
            	first=false;
        	else if (predt>=b->val)
				return false;               //若当前结点值小于等于中序前驱结点值，则返回false
        	predt=b->val;                   //保存当前结点的关键字
        	bool rflag=JudgeBST(b->right);   //判断右子树
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
