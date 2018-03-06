#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class TreeNode
{
  public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val)
	{
		this->val = val;
		this->left = this->right = nullptr;
	}
};

class Solution
{
	/**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
  public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		// write your code here

		if (preorder.size() == 0)
		{
			return nullptr;
		}

		TreeNode *rv = new TreeNode(preorder[0]);

		auto mid = find(inorder.begin(), inorder.end(), preorder[0]);

		auto l_inorder = vector<int>(inorder.begin(), mid);
		auto r_inorder = vector<int>(mid + 1, inorder.end());

		
		// auto right = buildTree();
		// auto left = buildTree(lv);

		rv->left = left;
		rv->right = right;

		return rv;
	}
};