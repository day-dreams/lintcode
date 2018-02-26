#include <iostream>
#include <vector>
#include <queue>
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
		this->left = this->right = NULL;
	}
};

class Solution
{
  public:
	/*
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
	vector<int> searchRange(TreeNode *root, int k1, int k2)
	{
		// write your code here

		vector<int> rv;

		if (root != nullptr)
		{
			queue<TreeNode *> to_travel;
			to_travel.push(root);

			while (!to_travel.empty())
			{
				auto node = to_travel.front();
				to_travel.pop();
				if (node->val < k1)
				{
					if (node->right != nullptr)
						to_travel.push(node->right);
				}
				else if (node->val > k2)
				{
					if (node->left != nullptr)
						to_travel.push(node->left);
				}
				else
				{
					rv.push_back(node->val);

					if (node->left != nullptr)
						to_travel.push(node->left);
					if (node->right != nullptr)
						to_travel.push(node->right);
				}
			}
		}

		sort(rv.begin(), rv.end());

		return rv;
	}
};

int main(int argc, char **argv)
{

	return 0;
}