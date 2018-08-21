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

#include<list>
class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        // write your code here
        using namespace std;
       list<TreeNode *> to_travel;

        vector<int> rv;
        if (root == nullptr)
            return rv;

        to_travel.push_front(root);

        while (!to_travel.empty()) {

            auto cur = to_travel.front();
            to_travel.pop_front();

            rv.push_back(cur->val);
            if (cur->right != nullptr) {
                to_travel.push_front(cur->right);
            }
            if (cur->left != nullptr) {
                to_travel.push_front(cur->left);
            }
        }
        return rv;
    }
    
};