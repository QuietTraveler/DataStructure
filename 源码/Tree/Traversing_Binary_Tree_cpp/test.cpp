#define _CRT_SECURE_NO_WARNINGS  1
#include"BiTree.h"

int main()
{
    BiTree T;
    BiTree* Tp = &T;
    InitBiTree(Tp);
    CreateBiTree(Tp);
    int returnSize = 0;
    int* arr = NULL;
    arr=preorderTraversal(Tp, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", arr[i]);
    }
   // TraverBiTree(Tp);
    /*BiTree newT;
    BiTree* newTp = &newT;
    CopyBiTree(Tp, newTp);
    TraverBiTree(newTp);
    int ret=DepthBiTree(Tp);
    int ret1=DepthBiTree(newTp);
    printf("Depth T=%d,Depth newT=%d\n", ret, ret1);
    int ret2 = LeafBiTree(Tp);
    int ret3 = LeafBiTree(newTp);
    printf("Leaf T=%d,Leaf newT=%d\n", ret2, ret3);
    int ret4 = NodeBiTree(Tp);
    int ret5 = NodeBiTree(newTp);
    printf("Node T=%d,Node newT=%d\n", ret4, ret5);*/

    return 0;
}
