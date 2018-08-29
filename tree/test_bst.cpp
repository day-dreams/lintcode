/**
 * @brief test for tree
 * 
 * @file test_bst.cpp
 * @author kakaxi
 * @date 2018-08-29
 */

#include <iostream>
#include <list>
using namespace std;

class TreeNode
{
  public:
    int value;
    TreeNode *left, *right;

    TreeNode(int value)
    {
        this->value = value;
        this->left = this->right = nullptr;
    }

    static TreeNode *giveMeATree()
    {
        TreeNode *rv = new TreeNode(1);

        rv->left = new TreeNode(2);
        rv->right = new TreeNode(3);

        rv->left->left = new TreeNode(4);
        rv->left->right = new TreeNode(5);

        rv->right->left = new TreeNode(6);
        rv->right->right = new TreeNode(7);

        rv->right->left->left = new TreeNode(8);

        rv->right->right->left = new TreeNode(9);
        rv->right->right->right = new TreeNode(10);

        return rv;
    }

    static void deleteTree(TreeNode *root)
    {
        if (root == nullptr)
            return;
        deleteTree(root->left);
        deleteTree(root->right);
        // std::cout << root->value << ' ';
        delete root;
    }
};

void re_inorder_travel(const TreeNode *const root)
{

    if (root == nullptr)
    {
        return;
    }

    re_inorder_travel(root->left);
    cout << root->value << ' ';
    re_inorder_travel(root->right);
}

void re_preorder_travel(const TreeNode *const root)
{

    if (root == nullptr)
    {
        return;
    }

    cout << root->value << ' ';
    re_preorder_travel(root->left);
    re_preorder_travel(root->right);
}

void re_postorder_travel(const TreeNode *const root)
{

    if (root == nullptr)
    {
        return;
    }

    re_postorder_travel(root->left);
    re_postorder_travel(root->right);
    cout << root->value << ' ';
}

void preorder_travel(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    list<TreeNode *> travel;

    travel.push_back(root);
    while (!travel.empty())
    {

        auto cur = travel.front();
        travel.pop_front();
        std::cout << cur->value << ' ';

        if (cur->right != nullptr)
        {
            travel.push_front(cur->right);
        }

        if (cur->left != nullptr)
        {
            travel.push_front(cur->left);
        }
    }
}

void inorder_travel(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    list<TreeNode *> travel;

    while (root != nullptr || !travel.empty())
    {

        if (root != nullptr)
        {
            travel.push_front(root);
            root = root->left;
        }
        else
        {
            root = travel.front();
            std::cout << root->value << ' ';
            travel.pop_front();
            root = root->right;
        }
    }
}

void postorder_travel(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    list<TreeNode *> travel;
    TreeNode *prv = nullptr;
    travel.push_back(root);

    while (!travel.empty())
    {
        root = travel.front();

        if (root->left == nullptr && root->right == nullptr)
        {
            travel.pop_front();
            std::cout << root->value << ' ';
            prv = root;
        }
        else if ((prv != nullptr) && (prv == root->left || prv == root->right))
        {
            prv = root;
            travel.pop_front();
            std::cout << root->value << ' ';
        }
        else
        {
            if (root->right != nullptr)
            {
                travel.push_front(root->right);
            }

            if (root->left != nullptr)
            {
                travel.push_front(root->left);
            }
        }
    }
}

int main(int argc, char **argv)
{
    TreeNode *root = TreeNode::giveMeATree();

    re_preorder_travel(root);
    std::cout << std::endl;
    preorder_travel(root);
    std::cout << std::endl;
    std::cout << std::endl;

    re_inorder_travel(root);
    std::cout << std::endl;
    inorder_travel(root);
    std::cout << std::endl;
    std::cout << std::endl;

    re_postorder_travel(root);
    std::cout << std::endl;
    postorder_travel(root);
    std::cout << std::endl;
    std::cout << std::endl;

    TreeNode::deleteTree(root);

    return 0;
}