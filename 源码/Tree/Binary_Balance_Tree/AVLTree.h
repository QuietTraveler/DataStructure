#pragma once
#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

typedef int AVLtype;

typedef struct AVLTree {
    AVLtype data = 0;
    struct AVLTree* left = NULL;
    struct AVLTree* right = NULL;
    int high = 0;
}AVLTree;

AVLTree* AVLTreeInit(AVLtype key);

AVLTree* CreateNode(AVLtype key);

int GetHigh(AVLTree* node);

int GetMax(int a, int b);

AVLTree* LL_Rotate(AVLTree* x);

AVLTree* RR_Rotate(AVLTree* x);

AVLTree* LR_Rotate(AVLTree* x);

AVLTree* RL_Rotate(AVLTree* x);

AVLTree* AVLTreeInsert(AVLTree* root, AVLtype key);

AVLTree*  AVLTreeDelete(AVLTree*root,AVLtype key);

void OrederPrint(AVLTree* root);