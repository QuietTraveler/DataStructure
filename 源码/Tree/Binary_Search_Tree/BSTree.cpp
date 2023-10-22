#define _CRT_SECURE_NO_WARNINGS  1
#include"BSTree.h"

BSTree* CreateNode(BStype key)
{
    BSTree* Node = new BSTree;
    Node->data = key;
    Node->left = Node->right = NULL;
    return Node;
}

BSTree* BSTreeInit(BStype key)
{
    BSTree* root = CreateNode(key);
    return root;
}

BSTree* BSTreeFind(BSTree* root, BStype key, BSTree*& prev)
{
    BSTree* cur = root;
    prev = NULL;
    while (cur && cur->data != key)
    {
        prev = cur;
        if (cur->data > key)
            cur = cur->left;
        else if (cur->data < key)
            cur = cur->right;
    }
    return cur;
}

void BSTreeInsert(BSTree* root, BStype key)
{
    BSTree* tprev = NULL;
    if (root && !BSTreeFind(root, key, tprev))
    {
        BSTree* Node = CreateNode(key);
        BSTree* cur = root, * prev = NULL;
        while (cur)
        {
            prev = cur;
            if (cur->data > key)
            {
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }
        if (prev->data>key)
        {
            prev->left = Node;
        }
        else
        {
            prev->right = Node;
        }
    }
}

void OrderPrint(BSTree* root)
{
    if (!root)
        return;
    OrderPrint(root->left);
    cout << root->data << " ";
    OrderPrint(root->right);
    return;
}

void BSTreeDelete(BSTree* root, BStype key)
{
    assert(root);
    BSTree* prev = NULL;
    BSTree* Node = BSTreeFind(root, key, prev);
    if (!(Node->left) && !(Node->right))
    {
        if (!prev)
        {
            delete(root);
            root = NULL;
        }
        else
        {
            if (prev->left == Node)
                prev->left = NULL;
            else
                prev->right = NULL;
            delete(Node);
        }
    }
    else if (Node->left && Node->right)
    {
        BSTree* temp = Node->left;
        BSTree* tparent = Node;
        while (temp->right)
        {
            tparent = temp;
            temp = temp->right;
        }
        Node->data = temp->data;
        if (tparent == Node)
            tparent->left = NULL;
        else
            tparent->right = NULL;
        delete(temp);
    }
    else
    {
            BSTree* temp = Node->left ? Node->left : Node->right;
            if(prev)
            {
                if (prev->left == Node)
                    prev->left = temp;
                else
                    prev->right = temp;
            }
            else
                root = temp;
        delete(Node);
    }
}