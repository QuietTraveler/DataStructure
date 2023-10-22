#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

typedef int retype;

enum {
	RED,
	BLACK
};


//ºìºÚÊ÷
typedef struct rbTree {
	retype data;
	int color;
	struct rbTree* left;
	struct rbTree* right;
	struct rbTree* parent;
}rbTree;

rbTree* CreateRoot(int key)
{
	rbTree* root = new rbTree;
	root->data = key;
	root->color = BLACK;
	root->left = root->right = root->parent = NULL;

	return root;
}

rbTree* CreateNode(int key, rbTree* parent)
{
	rbTree* node = new rbTree;
	node->data = key;
	node->color = RED;
	node->left = node->right = NULL;
	node->parent = parent;

	return node;
}

void Right_Rotate(rbTree*& root, rbTree* node)
{
	rbTree* x = node->left;
	if ( x->right )
		x->right->parent = node;
	x->parent = node->parent;

	if ( node->parent && node->parent->left == node )
		node->parent->left = x;
	else if ( node->parent && node->parent->right == node )
		node->parent->right = x;
	else
		root = x;

	node->parent = x;
	node->left = x->right;
	x->right = node;
}

void Left_Rotate(rbTree*& root, rbTree* node)
{
	rbTree* x = node->right;
	if ( x->left )
		x->left->parent = node;
	x->parent = node->parent;

	if ( node->parent && node->parent->left == node )
		node->parent->left = x;
	else if ( node->parent && node->parent->right == node )
		node->parent->right = x;
	else
		root = x;

	node->parent = x;
	node->right = x->left;
	x->left = node;
}


void rbAdjust(rbTree*& root, rbTree* node)
{
	if ( node->parent->color == BLACK )
		return;
	else
	{
		rbTree* parent = node->parent;
		rbTree* grandpa = NULL;
		rbTree* uncle = NULL;

		while ( parent && parent->color == RED )
		{
			grandpa = parent->parent;

			if ( parent == grandpa->right )
			{
				uncle = grandpa->left;
				if ( uncle && uncle->color == RED )
				{
					parent->color = BLACK;
					grandpa->color = RED;
					uncle->color = BLACK;

					node = grandpa;
					parent = node->parent;
					continue;
				}
				else
				{
					if ( parent->left == node )
					{
						Right_Rotate(root, parent);
						rbTree* tmp;
						tmp = node;
						node = parent;
						parent = tmp;
					}

					parent->color = BLACK;
					grandpa->color = RED;

					Left_Rotate(root, grandpa);
					continue;
				}
			}
			if ( parent == grandpa->left )
			{
				uncle = grandpa->right;
				if ( uncle && uncle->color == RED )
				{
					parent->color = BLACK;
					grandpa->color = RED;
					uncle->color = BLACK;

					node = grandpa;
					parent = node->parent;
					continue;
				}
				else
				{
					if ( parent->right == node )
					{
						Left_Rotate(root, parent);
						rbTree* tmp;
						tmp = node;
						node = parent;
						parent = tmp;
					}

					parent->color = BLACK;
					grandpa->color = RED;

					Right_Rotate(root, grandpa);
				}

			}
		}

		root->color = BLACK;
		return;
	}
}

void rbTreeInsert(rbTree*& root, retype key)
{
	if ( !root )
	{
		root = CreateRoot(key);
		return;
	}
	else
	{
		rbTree* parent = NULL;
		rbTree* cur = root;
		while ( cur )
		{
			parent = cur;
			if ( cur->data > key )
			{
				cur = cur->left;
			}
			else if ( cur->data < key )
			{
				cur = cur->right;
			}
			else
			{
				return;
			}
		}

		rbTree* node = CreateNode(key, parent);

		if ( parent->data > key )
			parent->left = node;
		else
			parent->right = node;

		rbAdjust(root, node);
	}
}

void rbTreePrint(rbTree* root)
{
	if ( !root )
		return;
	rbTreePrint(root->left);
	cout << root->data << " ";
	if ( root->color == RED )
		cout << "ºìÉ«" << endl;
	else
		cout << "ºÚÉ«" << endl;

	rbTreePrint(root->right);

	return;
}

rbTree* findLocation(rbTree*& root, retype key)
{
	rbTree* node = root;
	while ( node && node->data != key )
	{
		if ( node->data > key )
			node = node->left;
		else if ( node->data < key )
			node = node->right;
		else
			break;
	}
	return node;
}

void DeleteAdjust(rbTree*& root, rbTree* child,rbTree* p)
{
	if ( child && child->color == RED )
	{
		child->color = BLACK;
	}
	else
	{
		rbTree* parent = p;
		rbTree* brother = NULL;
     
		 if (parent->right == child )
		 {
			brother = parent->left;
			 while(1)
			 {
				 if ( ( brother && brother->color == RED ) && ( ( !brother->left || brother->left->color != RED ) || ( !brother->right || brother->right->color != RED ) ) )
				 {
					 brother->color = BLACK;
					 parent->color = RED;
					 Right_Rotate(root, parent);

					 brother = parent->left;
				 }

				 if ( ( !brother->left || brother->left->color == BLACK ) && ( !brother->right || brother->right->color == BLACK ) )
				 {
					 brother->color = RED;
					 if ( parent->color == BLACK )
						 parent = child;
					 else
					 {
						 parent->color = BLACK;
						 break;
					 }

					 if ( !parent->parent )
					 {
						 parent->color = BLACK;
						 break;
					 }

					 continue;
				 }

				 if ( brother->color == BLACK && ( ( brother->left && brother->left->color == RED ) || ( brother->right && brother->right->color == RED ) ) )
				 {
					 rbTree* R = NULL;
					 if ( brother->left->color == BLACK )
						 R = brother->left;
					 else
						 R = brother->right;

					 if ( R == brother->right )
					 {
						 brother->color = RED;
						 R->color = BLACK;

						 Left_Rotate(root, brother);

						 brother = parent->left;
					 }

					 Right_Rotate(root, parent);
					 brother->color = parent->color;
					 R->color = BLACK;
					 parent->color = BLACK;

					 break;
				 }
			 }


		 }
		else
		{
			brother = parent->right;
			while ( 1 )
			{
				if ( ( brother && brother->color == RED ) && ( ( !brother->left || brother->left->color != RED ) || ( !brother->right || brother->right->color != RED ) ) )
				{
					brother->color = BLACK;
					parent->color = RED;
					Left_Rotate(root, parent);

					brother = parent->right;
				}

				if ( ( !brother->left || brother->left->color == BLACK ) && ( !brother->right || brother->right->color == BLACK ) )
				{
					brother->color = RED;
					if ( parent->color == BLACK )
						parent = child;
					else
					{
						parent->color = BLACK;
						break;
					}

					if ( !parent->parent )
					{
						parent->color = BLACK;
						break;
					}

					continue;
				}

				if ( brother->color == BLACK && ( ( brother->left && brother->left->color == RED ) || ( brother->right && brother->right->color == RED ) ) )
				{
					rbTree* R = NULL;
					if ( brother->left->color == BLACK )
						R = brother->left;
					else
						R = brother->right;

					if ( R == brother->left )
					{
						brother->color = RED;
						R->color = BLACK;

						Right_Rotate(root, brother);

						brother = parent->right;
					}

					Left_Rotate(root, parent);
					brother->color = parent->color;
					R->color = BLACK;
					parent->color = BLACK;

					break;
				}
			}


		}
	}
}

void rbTreeDelete(rbTree*& root, retype key)
{
	rbTree* node = findLocation(root, key);
	if ( node == root && !node->left && !node->right )
	{
		delete( node );
		root = NULL;
		return;
	}

	rbTree* parent = NULL;
	rbTree* child = NULL;
	int color = -1;
	if ( node )
	{
		rbTree* min = NULL;
		if ( node->left && node->right )
		{
			if ( node->right )
				min = node->right;
			else
				min = node;
				
			while ( min!=node && min->left )
			{
				min = min->left;
			}
			node->data = min->data;
			node = min;
		}

		parent = node->parent;
		child = NULL;
		if ( node->right )
			child=node->right;
		else
			child=node->left;

		if ( parent && parent->left == node )
			parent->left = child;
		else if(parent && parent->right == node )
			parent->right = child;

		if ( child )
			child->parent = parent;
		
		if ( node == root )
			root = child;

		color = node->color;

		delete( node );
		node = NULL;

		if ( color == BLACK )
		{
			DeleteAdjust(root,child,parent);
		}

	}
}

int main()
{
	retype arr[] = { 10,40,30,60,90,70,20,50,80 };
	int size = sizeof(arr) / sizeof(arr[0]);
	rbTree* root = NULL;
	for ( int i = 0; i < size; i++ )
	{
		rbTreeInsert(root, arr[i]);
	}
	rbTreePrint(root);
	cout << endl;
	rbTreeDelete(root,30);
	rbTreePrint(root);
	return 0;
}
