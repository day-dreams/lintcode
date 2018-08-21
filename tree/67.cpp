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
#include <list>
#include <vector>

class TreeNode {
  public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

using namespace std;

class Solution {
  public:
    /**
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here

        vector<int> rv;

        if (root == nullptr)
            return rv;

        list<TreeNode *> to_travel;

        while (!to_travel.empty() || root != nullptr) {

            if (root == nullptr) {
                root = to_travel.front();
                to_travel.pop_front();
                rv.push_back(root->val);
                root=root->right;
            } else {
                to_travel.push_front(root);
                root=root->left;

            }
        }

        return rv;
    }
};