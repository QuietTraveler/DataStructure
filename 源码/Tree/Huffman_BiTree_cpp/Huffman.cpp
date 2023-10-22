#define _CRT_SECURE_NO_WARNINGS  1
#include"HuffmanTree.h"
//哈夫曼树
void CreateHMTree(HMTree* T,int node)
{
    assert(T);
    int m = node * 2;
    for (int i = 1; i < m; i++)
    {
        T[i].lchild = 0;
        T[i].rchild = 0;
        T[i].parent = 0;
    }
    for (int i = 1; i <= node; i++)
    {
        printf("请输入该结点权重:\n");
        scanf("%d", &T[i].weight);
        getchar();
        printf("请输入该结点的数值:\n");
        scanf("%c", &T[i].val);
        getchar();
    }
    int j=0;
    for (j = node+1; j < m; j++)
    {
        int min1, min2;
        int num = j;
        Minimal(T, num, min1, min2);
        if (min1 > min2)
        {
            min1 ^= min2;
            min2 = min1 ^ min2;
            min1 = min1 ^ min2;
        }
        T[j].lchild = min1;
        T[j].rchild = min2;
        T[j].weight = T[min1].weight + T[min2].weight;
        T[min1].parent =T[min2].parent = j;
    }

}

void Minimal(HMTree* T, int num, int& min1, int& min2)
{
    assert(T);
    int min = 1;
    int flag = 0;
    for (int i = 1; i < num; i++)
    {
        if (T[i].parent != 0)
        {
            continue;
        }
        else
        {
            if (!flag)
            {
                min = i;
                flag = 1;
            }
            else if(T[i].weight < T[min].weight)
            {
                min = i;
            }
        }
    }
    min1 = min;
    for (int i = 1; i < num; i++)
    {
        if (T[i].parent != 0 || i==min1)
        {
            continue;
        }
        else
        {
            if (flag)
            {
                min = i;
                flag = 0;
            }
            else if(T[i].weight < T[min].weight)
            {
                min = i;
            }
        }
    }
    min2 = min;
}

void HMTreePirnt(HMTree* T)
{
    assert(T);
    for (int i = 1; i <NUM; i++)
    {
     printf("权重:%d, 双亲:%d, 左孩子:%d, 右孩子:%d\n", T[i].weight,T[i].parent, T[i].lchild, T[i].rchild);
    }
}

char** AcquireCode(HMTree* T,int node)
{
    assert(T);
    char** codes= (char**)malloc(sizeof(char*)*(node+1));
    if (codes == NULL)
    {
        perror("malloc");
        exit(-1);
    }
    char* cd = (char*)malloc(sizeof(char) * node);
    if (cd == NULL)
    {
        perror("malloc");
        exit(-1);
    }
    int j = 0;
    for (int i = 1; i <= node; i++)
    {
        int temp = i;
        int n = node;
        int num = 0;
        cd[n - 1] = '\0';
        while (T[i].parent)
        {
            j = T[i].parent;
            if (T[j].lchild == i)
                cd[n - 2] = '0';
            else
                cd[n - 2] = '1';
            i = j;
            num = n - 2;
            n--;
        }
        i = temp;
        codes[i] = (char*)malloc(sizeof(char)*node);
        strcpy(codes[i], &cd[num]);
    }
        free(cd);
        return codes;
}

void CodesPrint(char** codes,int node)
{
    for (int i = 1; i <=node; i++)
    {
        printf("编码%d: %s\n", i, codes[i]);
    }
}

char* Decode(HMTree* T, char* codes, int node, int codesSize,int* returnSize)
{
    int j = 0;
    int n = 0;
    int t = 0;
    char* arr = (char*)malloc(sizeof(char) * codesSize);
    if (arr == NULL)
    {
        perror("malloc");
        exit(-1);
    }
    while (n<codesSize)
    {
        int i = node * 2 - 1;
        while (T[i].lchild && T[i].rchild)
        {
            if (codes[n] == '0')
                j = T[i].lchild;
            else
                j = T[i].rchild;
            i = j;
            n++;
        }
        arr[t] = T[i].val;
        t++;
    }
    *returnSize = t;
    return arr;
}