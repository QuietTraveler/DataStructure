#define _CRT_SECURE_NO_WARNINGS  1
#include"AVLTree.h"

AVLTree* AVLTreeInit(AVLtype key)
{
    AVLTree* root = new AVLTree;
    root->data = key;
    root->left = root->right = NULL;
    return root;
}

int GetMax(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}

AVLTree* CreateNode(AVLtype key)
{
    AVLTree* Node = new AVLTree;
    Node->data = key;
    return Node;
}

int GetHigh(AVLTree* node)
{
    if (!node)
        return 0;
    else
        return node->high;
}

//左旋
AVLTree* LL_Rotate(AVLTree* x)
{
    AVLTree* y = x->right;
    x->right = y->left;
    y->left = x;
    x->high = GetMax(GetHigh(x->left), GetHigh(x->right)) + 1;
    y->high = GetMax(GetHigh(y->left), GetHigh(y->right)) + 1;
    return y;
}

//右旋
AVLTree* RR_Rotate(AVLTree* x)
{
    AVLTree* y = x->left;
    x->left = y->right;
    y->right = x;
    x->high = GetMax(GetHigh(x->left), GetHigh(x->right)) + 1;
    y->high = GetMax(GetHigh(y->left), GetHigh(y->right)) + 1;
    return y;
}

//左右旋
AVLTree* LR_Rotate(AVLTree* x)
{
    x->left = LL_Rotate(x->left);
    x = RR_Rotate(x);
    //   x->high = GetMax(GetHigh(x->left), GetHigh(x->right)) + 1;
    return x;
}

//右左旋
AVLTree* RL_Rotate(AVLTree* x)
{
    x->right = RR_Rotate(x->right);
    x = LL_Rotate(x);
    //   x->high = GetMax(GetHigh(x->left), GetHigh(x->right)) + 1;
    return x;
}

//平衡二叉树
AVLTree* AVLTreeInsert(AVLTree* root, AVLtype key)
{
    if (!root)
    {
        root = CreateNode(key);
    }
    else if (root->data > key)
    {
        root->left = AVLTreeInsert(root->left, key);
        if (GetHigh(root->left) - GetHigh(root->right) > 1)
        {
            if (root->left->data > key)
            {
                root = LL_Rotate(root);
            }
            else
            {
                root = LR_Rotate(root);
            }
        }
    }
    else if (root->data < key)
    {
        root->right = AVLTreeInsert(root->right, key);
        if (GetHigh(root->right) - GetHigh(root->left) > 1)
        {
            if (root->right->data < key)
            {
                root = RR_Rotate(root);
            }
            else
            {
                root = RL_Rotate(root);
            }
        }
    }
    if (root)
        root->high = GetMax(GetHigh(root->left), GetHigh(root->right)) + 1;
    return root;
}

//右子树中的最小值
AVLTree* GetMinNode(AVLTree* root)
{
    AVLTree* node = root->right;
    if (!(node->left))
        return node;
    else
    {
        while (node->left)
        {
            node = node->left;
        }
        return node;
    }
}

//平衡二叉树的删除
AVLTree* AVLTreeDelete(AVLTree* root, AVLtype key)
{
    if (!root)
    {
        return NULL;
    }
    if (root->data == key)
    {
        if (root->left && root->right)
        {
            AVLTree* min = GetMinNode(root);
            root->data = min->data;
            root->right = AVLTreeDelete(root->right, min->data);
        }
        else
        {
            AVLTree* Node1 = root;
            if (root->left)
                root = root->left;
            else
                root = root->right;
            delete(Node1);
        }
    }
    else if (root->data > key)
    {
        root->left = AVLTreeDelete(root->left, key);
        if (GetHigh(root->right) - GetHigh(root->left) == 2)
        {
            AVLTree* Node = root->right;
            if (GetHigh(Node->right) - GetHigh(Node->left) >= 0)
            {
                root = LL_Rotate(root);
            }
            else
            {
                root = RL_Rotate(root);
            }
        }
    }
    else
    {
        root->right = AVLTreeDelete(root->right, key);
        if (GetHigh(root->left) - GetHigh(root->right) == 2)
        {
            AVLTree* Node = root->left;
            if (GetHigh(Node->left) - GetHigh(Node->right) >= 0)
            {
                root = RR_Rotate(root);
            }
            else
            {
                root = LR_Rotate(root);
            }
        }
    }
    if (root)
        root->high = GetMax(GetHigh(root->left), GetHigh(root->right)) + 1;
    return root;
}

void OrederPrint(AVLTree* root)
{
    if (!root)
        return;
    OrederPrint(root->left);
    cout << root->data << " ";
    OrederPrint(root->right);
    return;
}