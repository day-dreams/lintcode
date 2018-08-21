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
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here

        vector<int> rv;

        if (root == nullptr)
            return rv;

        list<TreeNode *> travel;
        travel.push_back(root);
        TreeNode *prv = nullptr;

        while (!travel.empty() ) {

            root=travel.front();

            if ((root->left == nullptr && root->right == nullptr) ||
                (prv!=nullptr && (prv == root->left || prv == root->right))) {

                rv.push_back(root->val);
                prv=root;
                travel.pop_front();

            } else {

                if(root->right!=nullptr){
                    travel.push_front(root->right);
                }
                if(root->left!=nullptr){
                    travel.push_front(root->left);
                }
            }
            
        }

        return rv;
    }
};