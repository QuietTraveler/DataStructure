#pragma once
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<assert.h>

using namespace std;

typedef int BStype;

typedef struct Binary_Search_Tree {
    BStype data = 0;
    struct Binary_Search_Tree* left = NULL;
    struct Binary_Search_Tree* right = NULL;
}BSTree;

BSTree* CreateNode(BStype key);

BSTree* BSTreeInit(BStype key);

void OrderPrint(BSTree* root);

BSTree* BSTreeFind(BSTree* root, BStype key, BSTree*& prev);

void BSTreeInsert(BSTree* root, BStype key);

void BSTreeDelete(BSTree* root, BStype key);