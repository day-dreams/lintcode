#include <algorithm>
#include <iostream>
#include <vector>
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
class TreeNode {
  public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
};

class Solution {
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here

        if (preorder.size() == 0) {
            return nullptr;
        }

        TreeNode *rv = nullptr;

        return rv;
    }

    TreeNode *_buildTree(int *prebegin, int *preend, int *inbegin, int *inend) {
        TreeNode *rv = nullptr;

        if (prebegin == preend) {
            return nullptr;
        } else if (prebegin + 1 == preend) {
            rv = new TreeNode(*prebegin);
        }else{
            int root=*prebegin;
            int *root_in_inorder=find(inbegin,inend,root);            
            


            rv=new TreeNode(root);




        }
        return rv;
    }
};