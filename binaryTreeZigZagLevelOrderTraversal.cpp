/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution
{
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> levels; //levels
		vector<int> level; //for each level
		if (root == NULL)
			return levels; //empty

		deque<TreeNode*> q;
		q.push_back(root);
		bool even = false;

		while (!q.empty())
		{
			int size = q.size(); //nodes in this level
								 //or you can have one while and check inside with if else
								 //but this is faster since we check if/else only once per level
			if (even)
			{
				while (size--)
				{
					TreeNode* p = q.back(); //get the last node in deque
					level.push_back(p->val);
					if (p->right) //if it has right child
						q.push_front(p->right); //push front
					if (p->left)
						q.push_front(p->left);

					q.pop_back(); //remove the last
				}
			}
			else
			{   //note the difference
				while (size--)
				{
					TreeNode* p = q.front(); //get the first node in deque
					level.push_back(p->val);
					if (p->left) //if it has left child
						q.push_back(p->left); //push back
					if (p->right)
						q.push_back(p->right);

					q.pop_front(); //remove the last
				}
			}
			levels.push_back(level);
			level.resize(0);
			even = !even;
		}
		return levels;
	}

};