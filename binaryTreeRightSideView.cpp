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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> v;
		rightsSideviewRek(root, 0, v);
		return v;
	}
	void rightsSideviewRek(TreeNode* root, int depth, vector<int> &v)
	{
		if (!root) return;

		if (depth == v.size()) v.push_back(root->val);
		rightsSideviewRek(root->right, depth + 1, v);
		rightsSideviewRek(root->left, depth + 1, v);
	}
};