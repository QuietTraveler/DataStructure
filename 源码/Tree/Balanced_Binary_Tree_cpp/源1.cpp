//#define _CRT_SECURE_NO_WARNINGS  1
//#include<stdio.h>
//#include<stdlib.h>
//
//#define HEIGHT(node) ((node == NULL)? 0 : (((avlnode*)(node))->height ))
//#define MAX(a,b) ((a > b) ? (a) : (b))
//typedef struct node {
//	int data;//�洢����ֵ
//	struct node* left;
//	struct node* right;
//	int height;//��ǰ�������
//}avlnode, * avltree;
//
//avlnode* creata_node(int key, avlnode* left, avlnode* right)
//{
//	avlnode* node = (avlnode*)malloc(sizeof(avlnode));
//	//�ж�һ���Ƿ񴴽��ɹ�
//	node->data = key;
//	node->left = left;
//	node->right = right;
//	node->height = 0;
//	return node;
//}
//
////��ȡ����
//int get_height(avlnode* node)
//{
//	return HEIGHT(node);
//}
///*���ӵ�������*/
//avltree left_left_rotation(avltree tree)
//{//�����treeΪ�������ڵ㣬ͬʱҲ��ʧ���� 
//	//k������������
//	avlnode* k = tree->left;
//	tree->left = k->right;
//	k->right = tree;
//	//�м�һ�� ������ת�����Ժ� ��Ҫ�������ĸ߶� 
//	//��������� һ����������� ��������������������ж��������
//	tree->height = MAX(get_height(tree->left), get_height(tree->right)) + 1;
//	k->height = MAX(get_height(k->left), get_height(k->right)) + 1;
//	return k;//��ʱkΪ���ڵ� 
//}
///*�Һ��ӵ�������*/
//avltree right_right_rotation(avltree tree)
//{//�����treeΪ�������ڵ㣬ͬʱҲ��ʧ���� 
//	avlnode* k = tree->right;
//	tree->right = k->left;
//	k->left = tree;
//	//�м�һ�� ������ת�����Ժ� ��Ҫ�������ĸ߶�
//	//��������� һ����������� ��������������������ж��������
//	tree->height = MAX(get_height(tree->left), get_height(tree->right)) + 1;
//	k->height = MAX(get_height(k->left), get_height(k->right)) + 1;
//	return k;//��ʱkΪ���ڵ� 
//
//}
///*���ӵ��������ĵ���*/
//avltree left_right_rotation(avltree tree)
//{
//	tree->left = right_right_rotation(tree->left);
//	tree = left_left_rotation(tree);
//	return tree;
//}
//
///*�Һ��ӵ������������*/
//avltree right_left_rotation(avltree tree)
//{
//	tree->right = left_left_rotation(tree->right);
//	tree = right_right_rotation(tree);
//	return tree;
//}
//
//
//avltree avltree_insertNode(avltree tree, int key)
//{
//	if (tree == NULL)
//	{
//		avlnode* node = creata_node(key, NULL, NULL);
//		tree = node;
//	}
//	else if (key < tree->data)//��tree������������ 
//	{
//		//�ݹ�Ѱ�Ҳ������λ��
//		tree->left = avltree_insertNode(tree->left, key);
//		if (get_height(tree->left) - get_height(tree->right) == 2)
//		{
//			//�������ж���LL����LR
//			if (key < tree->left->data)
//			{
//				tree = left_left_rotation(tree);
//			}
//			else
//			{
//				//LR��ת
//				tree = left_right_rotation(tree);
//			}
//		}
//	}
//	else if (key > tree->data) //��tree������������ 
//	{
//		tree->right = avltree_insertNode(tree->right, key);
//		if (get_height(tree->right) - get_height(tree->left) == 2)
//		{
//			//RR
//			if (key > tree->right->data)
//			{
//				tree = right_right_rotation(tree);
//			}
//			else
//			{
//				//RL
//				tree = right_left_rotation(tree);
//			}
//		}
//	}
//	else
//	{
//		//���������������ͬ��ֵ
//	}
//
//	//���µ��������������
//	tree->height = MAX(get_height(tree->left), get_height(tree->right)) + 1;
//
//	return tree;
//
//}
//
//avlnode* mininum_node(avltree tree)
//{
//	if (tree == NULL)
//	{
//		return NULL;
//	}
//	while (tree->left)
//	{
//		tree = tree->left;
//	}
//
//	return tree;
//}
//avltree avltree_deleteNode(avltree tree, int key)
//{
//
//	if (tree == NULL)
//	{
//		return tree;
//	}
//	if (key < tree->data)//Ҫɾ��������������
//	{
//		//�ȵݹ���Ҫɾ���Ľ��
//		tree->left = avltree_deleteNode(tree->left, key);
//		//ɾ���Ժ� Ҫ���ƽ����
//		if (get_height(tree->right) - get_height(tree->left) == 2)
//		{
//			//Ҫ����ж�RL,RR;
//			avlnode* tmp = tree->right;
//			if (get_height(tmp->left) - get_height(tmp->right) > 0)
//			{//RL
//				tree = right_left_rotation(tree);
//
//			}
//			else
//			{//RR
//				tree = right_right_rotation(tree);
//			}
//		}
//
//	}
//	else if (key > tree->data)//Ҫɾ������������
//	{
//		tree->right = avltree_deleteNode(tree->right, key);
//		//ɾ���Ժ� Ҫ���ƽ����
//		if (get_height(tree->left) - get_height(tree->right) == 2)
//		{
//			//Ҫ����ж�LL,LR
//			avlnode* tmp = tree->left;
//			if (get_height(tmp->left) - get_height(tmp->right) > 0)
//			{//LL
//				tree = left_left_rotation(tree);
//			}
//			else
//			{//LR
//				tree = left_right_rotation(tree);
//			}
//		}
//	}
//	else //�ҵ�Ҫɾ���Ľ�� �Ȱ��ն����������ķ�ʽ����ɾ��
//	{
//		if (tree->left && tree->right)
//		{
//			avlnode* min_node = mininum_node(tree->right);
//			tree->data = min_node->data;
//			//ɾ�� ��Сֵ���
//			tree->right = avltree_deleteNode(tree->right, min_node->data);
//		}
//		else
//		{
//			//���ӻ������ӵ�������
//			avlnode* node = tree;
//			tree = tree->left ? tree->left : tree->right;
//			if (tree == NULL)
//			{
//				free(tree);
//				return NULL;
//			}
//			else {
//				free(node);
//			}
//
//		}
//
//	}
//
//	//�����߶�
//	if (tree)
//	{
//		tree->height = MAX(get_height(tree->left), get_height(tree->right)) + 1;
//	}
//
//
//	return tree;
//}
//
//
//void pre_order(avltree tree)
//{//���������� 
//	if (tree)
//	{
//
//		pre_order(tree->left);
//		printf("%d   ", tree->data);
//		pre_order(tree->right);
//	}
//}
//
//
//int main()
//{
//	avltree tree = NULL;
//	int a[] = { 3,2,15,1 };
//	//int length = sizeof(a) / sizeof(a[0]);
//	for (int i = 0; i < 4; i++)
//	{
//		tree = avltree_insertNode(tree, a[i]);
//	}
//
//	pre_order(tree);
//	printf("\n");
//	//	in_order(tree);
//	printf("\n");
//	tree = avltree_deleteNode(tree, 15);
//	pre_order(tree);
//	printf("\n");
//	//in_order(tree);
//
//}
