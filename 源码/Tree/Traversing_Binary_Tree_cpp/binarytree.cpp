#define _CRT_SECURE_NO_WARNINGS  1
#include"BiTree.h"
#include"Stack.h"
#include"Queue.h"

void InitBiTree(BiTree* T)
{
    T->data = 0;
    T->lchild = NULL;
    T->rchild = NULL;
}

void Visit(BiTree* T)
{
    printf("BiTree* T->data=%d\n",T->data);
}

void CreateBiTree(BiTree*& T)
{
    int a;
    scanf("%d", &a);
    if (a == 0)
    {
        T = NULL;
        return;
    }
    BiTree* cur = (BiTree*)malloc(sizeof(BiTree));
    if (cur == NULL)
    {
        perror("malloc");
        exit(-1);
    }
    cur->data = a;
    T = cur;
    CreateBiTree(T->lchild);
    CreateBiTree(T->rchild);
    return;
}

//ÏÈÐòµÝ¹é±éÀú
//void TraverBiTree(BiTree* T)
//{
//    if (T != NULL)
//    {
//        Visit(T);
//        TraverBiTree(T->lchild);
//        TraverBiTree(T->rchild);
//    }
//}

//ÖÐÐòµÝ¹é±éÀú
//void TraverBiTree(BiTree* T)
//{
//    if (T != NULL)
//    {
//        TraverBiTree(T->lchild);
//        Visit(T);
//        TraverBiTree(T->rchild);
//    }
//}

//ºóÐòµÝ¹é±éÀú
//void TraverBiTree(BiTree* T)
//{
//    if (T != NULL)
//    {
//        TraverBiTree(T->lchild);
//        TraverBiTree(T->rchild);
//        Visit(T);
//    }
//}

//void TraverBiTree(BiTree* T)
//{
//    assert(T);
//    Stack K;
//    InitStack(&K);
//    BiTree* q = T; BiTree* p = q;
//    while (p || !EmptyStack(&K))
//    {
//        if (p != NULL)
//        {
//            EnterStack(&K,p);
//            p=p->lchild;
//        }
//        else
//        {
//            PopStack(&K, &q);
//            Visit(q);
//            p=q->rchild;
//        }
//    }
//}

void TraverBiTree(BiTree* T)
{
    Q q;
    InitQueue(&q);
    QueuePush(&q, T);
    BiTree* qt = T;
    while (!QueueEmpty(&q))
    {
        QueuePop(&q, qt);
        Visit(qt);
        if (qt->lchild != NULL)
            QueuePush(&q, qt->lchild);
        if (qt->rchild != NULL)
            QueuePush(&q, qt->rchild);
    }
}

void CopyBiTree(BiTree* T, BiTree*& newT)
{
    if (T == NULL)
    {
        newT = T;
        return;
    }
    BiTree* news = (BiTree*)malloc(sizeof(BiTree));
    if (news == NULL)
    {
        perror("malloc");
        exit(-1);
    }
    news->data = T->data;
    newT = news;
    CopyBiTree(T->lchild, newT->lchild);
    CopyBiTree(T->rchild, newT->rchild);
    return;
}

int DepthBiTree(BiTree* T)
{
    if (T==NULL)
    {
        return 0;
    }
    int m = DepthBiTree(T->lchild);
    int n = DepthBiTree(T->rchild);
    if (m > n)
        return m + 1;
    else
        return n + 1;
}

int NodeBiTree(BiTree* T)
{
    if (T == NULL)
    {
        return 0;
    }
    return NodeBiTree(T->lchild) + NodeBiTree(T->rchild) + 1;
}

int LeafBiTree(BiTree* T)
{
    if (T->lchild == NULL && T->rchild == NULL)
    {
        return 1;
    }
    if (T == NULL)
        return 0;
    return LeafBiTree(T->lchild) + LeafBiTree(T->rchild);
}

int TraversalBiTree(BiTree* T, int* arr)
{
    if (T == NULL)
        return 0;
    static int i = 0;
    arr[i++] = T->data;
    TraversalBiTree(T->lchild, arr);
    TraversalBiTree(T->rchild, arr);
    return i;
}

int* preorderTraversal(BiTree* T, int* returnSize) {

    int* arr = (int*)malloc(sizeof(int) * 100);
    if (arr == NULL)
    {
        perror("malloc");
        exit(-1);
    }
    *returnSize = TraversalBiTree(T, arr);
    return arr;
}