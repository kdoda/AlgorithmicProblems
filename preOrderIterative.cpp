/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> v;
		if (!root) return v;

		stack <TreeNode*> s;
		s.push(root);

		bool continueLeft = true;
		while (!s.empty())
		{
			root = s.top();

			while (root->left && continueLeft)
			{
				v.push_back(root->val);
				s.push(root->left);
				root = root->left;
			}

			if (!root->left) 
				v.push_back(root->val);

			s.pop();

			if (root->right) //if there is a child on the right
			{
				s.push(root->right);
				continueLeft = true; //keep searching on the left,for the last child we added on the stack
			}
			else
			{
				continueLeft = false; //false to stop searching on the left in the nested while loop
			}
		}

		return v;
	}
};