//#define _CRT_SECURE_NO_WARNINGS  1
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct AVLNode
//{
//	int data;
//	int height;
//	struct AVLNode* left;
//	struct AVLNode* right;
//}Node;
//#define HEIGHT(node) ((node == NULL)? 0 : (((Node*)(node))->height ))
//#define MAX(a,b) ((a > b) ? (a) : (b))
//
//int get_height(Node* node)
//{
//	return HEIGHT(node);
//}
//
///*�������ӵ�������-����*/
////�������Ϊ��Сʧ����tree����tree��������
//Node* left_left(Node* tree)
//{
//	//������
//	Node* k = tree->left;//����tree�����ӣ�k�������յĸ��ڵ�
//	tree->left = k->right;//��k���Һ��ӽӵ�tree��������
//	k->right = tree;//tree��Ϊk��������
//
//	//�߶ȵ���������ָ��ȣ��������������жϣ�
//	tree->height = MAX(get_height(tree->left), get_height(tree->right)) + 1;
//	k->height = MAX(get_height(k->left), get_height(k->right)) + 1;
//	return k;
//}
//
///*�����Һ��ӵ�������-����*/
////�������Ϊ��Сʧ����tree����tree��������
//Node* right_right(Node* tree)
//{
//	//������
//	Node* k = tree->right;
//	tree->right = k->left;
//	k->left = tree;
//
//	//�߶ȵ���
//	tree->height = MAX(get_height(tree->left), get_height(tree->right)) + 1;
//	k->height = MAX(get_height(k->left), get_height(k->right)) + 1;
//	return k;
//}
//
///*�������ӵ�������-������������*/
////��tree->left����(left_left)����tree����(right_right)
//Node* left_right(Node* tree)
//{
//	tree->left = right_right(tree->left);
//	tree = left_left(tree);
//	return tree;
//}
//
///*�����Һ��ӵ�������-������������*/
////��tree->right����(left_left),��tree����
//Node* right_left(Node* tree)
//{
//	tree->right = left_left(tree->right);
//	tree = right_right(tree);
//	return tree;
//}
//
///*����һ�����������Ϊnode*/
//Node* create(int key)
//{
//	Node* node = (Node*)malloc(sizeof(Node));
//	//�˴����ж��Ƿ񴴽��ɹ�����ʡ����
//	node->data = key;
//	node->left = NULL;
//	node->right = NULL;
//	node->height = 0;
//	return node;
//}
//
///*�����ڵ�Ϊtree�����в���һ��ֵkey*/
////����λ��ͬ�������������߼�������������λ�ã�С��������λ��
//Node* Insert(Node* tree, int key)
//{
//	//���Ϊ�գ��ʹ���һ����
//	if (tree == NULL)
//	{
//		Node* node = create(key);
//		tree = node;
//	}
//	//������������
//	else if (key < tree->data)
//	{
//		//�ݹ�Ѱ�Ҳ���λ��
//		tree->left = Insert(tree->left, key);
//		//�ж��Ƿ�ʧ��
//		if (get_height(tree->left) - get_height(tree->right) == 2)
//		{
//			//�жϲ���λ�������ӵ�����������������
//			if (key < tree->left->data)
//				tree = left_left(tree);
//			else
//				tree = left_right(tree);
//		}
//	}
//	//������������
//	else if (key > tree->data)
//	{
//		tree->right = Insert(tree->right, key);
//		if (get_height(tree->right) - get_height(tree->left) == 2)
//		{
//			if (key > tree->right->data)
//				tree = right_right(tree);
//			else
//				tree = right_left(tree);
//		}
//	}
//	else
//		printf("����������ظ���ֵ\n");
//	//���µ������������
//	tree->height = MAX(get_height(tree->left), get_height(tree->right)) + 1;
//	return tree;
//}
//
///*���ҽ��*/
//Node* search(Node* tree, int key)
//{
//	if (tree == NULL || tree->data == key)
//		return tree;
//	else if (key < tree->data)
//		return search(tree->left, key);
//	else
//		return search(tree->right, key);
//}
///*�ҵ��滻���-�����������ұ�*/
//Node* mininum(Node* tree)
//{
//	if (tree == NULL)
//		return NULL;
//	while (tree->right)
//		tree = tree->right;
//	return tree;
//}
///*ɾ�����*/
//Node* del(Node* tree, int key)
//{
//	//��λ��Ҫɾ�����
//	Node* node = search(tree, key);
//	if (tree == NULL || node == NULL)
//	{
//		printf("ɾ��ʧ��\n");
//		return tree;
//	}
//	//��ɾ�������������
//	if (key < tree->data)
//	{
//		//�ݹ��ҵ�Ҫɾ�����
//		tree->left = del(tree->left, key);
//		//ɾ����Ҫ���ƽ��
//		if (get_height(tree->right) - get_height(tree->left) == 2)
//		{
//			if (key < tree->right->data)
//				tree = right_left(tree);
//			else
//				tree = right_right(tree);
//		}
//	}
//	//��ɾ�������������
//	else if (key > tree->data)
//	{
//		tree->right = del(tree->right, key);
//		if (get_height(tree->left) - get_height(tree->right) == 2)
//		{
//			if (key < tree->left->data)
//				tree = left_left(tree);
//			else
//				tree = left_right(tree);
//		}
//	}
//	//��ʱ����Ҫɾ�����,//��ɾ����������Һ���-ͬ����������
//	else if (tree->left != NULL && tree->right != NULL)
//	{
//		Node* min_node = mininum(tree->left);
//		tree->data = min_node->data;
//		tree->left = del(tree->left, min_node->data);
//	}
//	//ֻ��һ�����ӻ���û�к���
//	else
//		tree = tree->left ? tree->left : tree->right;
//
//	if (tree)
//		tree->height = MAX(get_height(tree->left), get_height(tree->right)) + 1;
//	return tree;
//}
//
///*ǰ�����*/
//void pre_order(Node* tree)
//{
//	if (tree)
//	{
//		printf("%d ", tree->data);
//		pre_order(tree->left);
//		pre_order(tree->right);
//	}
//}
//
///*�������*/
//void in_order(Node* tree)
//{
//	if (tree)
//	{
//		in_order(tree->left);
//		printf("%d ", tree->data);
//		in_order(tree->right);
//	}
//}
//
//int main()
//{
//	//��һ�����-���ӵ�������
//	Node* tree1 = NULL;
//	int a1[] = { 13, 8, 15, 3, 10 };
//	int l1 = sizeof(a1) / sizeof(int);
//	for (int i = 0; i < l1; i++)
//	{
//		tree1 = Insert(tree1, a1[i]);
//	}
//	printf("��һ�����-���ӵ�������\n");
//	printf("ǰ�����:");
//	pre_order(tree1);
//	printf("\n");
//	printf("�������:");
//	in_order(tree1);
//	printf("\n");
//	printf("�����Ϊ%d,���Ϊ:%d\n\n", tree1->data, tree1->height);
//
//	printf("����1\n");
//	tree1 = Insert(tree1, 1);
//	printf("ǰ�����:");
//	pre_order(tree1);
//	printf("\n");
//	printf("�������:");
//	in_order(tree1);
//	printf("\n");
//	printf("�����Ϊ%d,���Ϊ:%d\n\n", tree1->data, tree1->height);
//
//	printf("ɾ�����8\n");
//	tree1 = del(tree1, 8);
//	printf("ǰ�����:");
//	pre_order(tree1);
//	printf("\n");
//	printf("�������:");
//	in_order(tree1);
//	printf("\n");
//	printf("�����Ϊ%d,���Ϊ:%d\n\n", tree1->data, tree1->height);
//
//	printf("ɾ�����13\n");
//	tree1 = del(tree1, 13);
//	printf("ǰ�����:");
//	pre_order(tree1);
//	printf("\n");
//	printf("�������:");
//	in_order(tree1);
//	printf("\n");
//	printf("�����Ϊ%d,���Ϊ:%d\n\n", tree1->data, tree1->height);
//
//	printf("ɾ�����1\n");
//	tree1 = del(tree1, 1);
//	printf("ǰ�����:");
//	pre_order(tree1);
//	printf("\n");
//	printf("�������:");
//	in_order(tree1);
//	printf("\n");
//	printf("�����Ϊ%d,���Ϊ:%d\n\n", tree1->data, tree1->height);
//	//�ڶ������-�Һ��ӵ�������
//	Node* tree2 = NULL;
//	int a2[] = { 13, 8, 15, 14, 16 };
//	int l2 = sizeof(a2) / sizeof(int);
//	for (int i = 0; i < l2; i++)
//	{
//		tree2 = Insert(tree2, a2[i]);
//	}
//	printf("�ڶ������-�Һ��ӵ�������\n");
//	printf("ǰ�����:");
//	pre_order(tree2);
//	printf("\n");
//	printf("�������:");
//	in_order(tree2);
//	printf("\n");
//	printf("���������Ϊ:%d\n\n", tree2->height);
//
//	tree2 = Insert(tree2, 20);
//	printf("����20\n");
//	printf("ǰ�����:");
//	pre_order(tree2);
//	printf("\n");
//	printf("�������:");
//	in_order(tree2);
//	printf("\n");
//	printf("���������Ϊ:%d\n\n", tree2->height);
//
//	//���������-���ӵ�������
//	Node* tree3 = NULL;
//	int a3[] = { 13, 8, 15, 3, 10 };
//	int l3 = sizeof(a3) / sizeof(int);
//	for (int i = 0; i < l3; i++)
//	{
//		tree3 = Insert(tree3, a3[i]);
//	}
//	printf("���������-���ӵ�������\n");
//	printf("ǰ�����:");
//	pre_order(tree3);
//	printf("\n");
//	printf("�������:");
//	in_order(tree3);
//	printf("\n");
//	printf("���������Ϊ:%d\n\n", tree3->height);
//
//	tree3 = Insert(tree3, 9);
//	printf("����9\n");
//	printf("ǰ�����:");
//	pre_order(tree3);
//	printf("\n");
//	printf("�������:");
//	in_order(tree3);
//	printf("\n");
//	printf("���������Ϊ:%d\n\n", tree3->height);
//
//
//	//��������� - �Һ��ӵ�������
//	Node* tree4 = NULL;
//	int a4[] = { 13, 8, 18, 15, 20 };
//	int l4 = sizeof(a4) / sizeof(int);
//	for (int i = 0; i < l4; i++)
//	{
//		tree4 = Insert(tree4, a4[i]);
//	}
//	printf("���������-�Һ��ӵ�������\n");
//	printf("ǰ�����:");
//	pre_order(tree4);
//	printf("\n");
//	printf("�������:");
//	in_order(tree4);
//	printf("\n");
//	printf("���������Ϊ:%d\n\n", tree4->height);
//
//	tree4 = Insert(tree4, 14);
//	printf("����14\n");
//	printf("ǰ�����:");
//	pre_order(tree4);
//	printf("\n");
//	printf("�������:");
//	in_order(tree4);
//	printf("\n");
//	printf("���������Ϊ:%d\n\n", tree4->height);
//
//
//
//}