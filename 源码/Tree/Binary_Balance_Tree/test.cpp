#include"AVLTree.h"

int main()
{
    AVLTree* root=AVLTreeInit(7);
    root=AVLTreeInsert(root,8);
    root=AVLTreeInsert(root,9);
    root=AVLTreeInsert(root,10);
    root=AVLTreeDelete(root,8);
    OrederPrint(root);
    return 0;
}