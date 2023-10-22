#define _CRT_SECURE_NO_WARNINGS  1
#include"BSTree.h"

int main()
{
    BSTree* root = BSTreeInit(35);
    BSTreeInsert(root, 16);
    BSTreeInsert(root, 19);
    BSTreeInsert(root, 21);
    BSTreeInsert(root, 27);
    BSTreeInsert(root, 90);
    BSTreeInsert(root, 87);
    BSTreeInsert(root, 5);
    OrderPrint(root);
    BSTreeDelete(root, 90);
    BSTreeDelete(root, 21);
    BSTreeDelete(root, 19);
    BSTreeDelete(root, 5);
    cout << endl;
    OrderPrint(root);
    return 0;
}