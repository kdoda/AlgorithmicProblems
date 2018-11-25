/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
using namespace std;
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack <TreeNode*> s;
		vector <int> v;
		bool continueLeft = true;
		if (root)
			s.push(root);
		else return v; //if root = NULL

		while (!s.empty())
		{
			root = s.top();

			while (root->left && continueLeft) //while root->left!= Null and flag=true ,which means to contiue on the left
			{
				s.push(root->left);
				root = root->left;
			}

			s.pop(); //remove from stack
			v.push_back(root->val);

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