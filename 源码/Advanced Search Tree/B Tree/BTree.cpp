#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

constexpr auto level = 5;
#define m (level+1)/2-1
typedef int type;

typedef struct BTnode {
	int keycount;
	type* data;
	struct BTnode** child;
	struct BTnode* parent;
}BTnode, * BTree;

typedef struct {
	BTnode* ptr;
	int index;
	bool flag;
}result;

void mergeNode(BTree& root, BTnode* left, BTnode* right, BTnode* parent, int j);
void Merge(BTree& root, BTnode* parent, BTnode* cur, BTnode* left, BTnode* right, int j);
void Adjust(BTree& root, BTnode*& cur);

int find(BTnode* node, type key)
{
	int i = 1;
	for ( ; i <= node->keycount; i++ )
	{
		if ( key <= node->data[i] )
		{
			return i;
		}
	}
	return i;
}

result SearchBTree(BTree& root, type key)
{
	result ret{};
	if ( !root )
	{
		ret.flag = 1;
		ret.index = 1;
		ret.ptr = root;
		return ret;
	}
	else
	{
		BTnode* cur = root;
		BTnode* prev = nullptr;
		int index;
		int flag = 1;
		while ( cur )
		{
			index = find(cur, key);
			if ( index <= cur->keycount && cur->data[index] == key )
			{
				flag = 0;
				break;
			}
			else
			{
				prev = cur;
				cur = cur->child[index - 1];
			}
		}
		ret.index = index;
		if ( flag )
		{
			ret.flag = flag;
			ret.ptr = prev;
		}
		else
		{
			ret.flag = flag;
			ret.ptr = cur;
		}
		return ret;
	}
}

void NewNode(BTnode*& node)
{
	node = new BTnode;
	node->child = new BTnode * [level + 1];
	for ( int i = 0; i < level + 1; i++ )
		node->child[i] = nullptr;
	node->data = new type[level + 1];
	node->keycount = 0;
	node->parent = nullptr;
}

void NewNodeRoot(BTree& root, type key, BTnode* left, BTnode* right)
{
	NewNode(root);
	root->data[1] = key;
	root->child[0] = left;
	if ( left )
	{
		left->parent = root;
	}
	root->child[1] = right;
	if ( right )
	{
		right->parent = root;
	}
	root->keycount = 1;
}

void Insert(BTnode* cur, type key, int index, BTnode* child)
{
	for ( int j = cur->keycount; j >= index; j-- )
	{
		cur->data[j + 1] = cur->data[j];
		cur->child[j + 1] = cur->child[j];
	}
	cur->data[index] = key;
	if ( child )
	{
		child->parent = cur;
	}
	cur->child[index] = child;
	cur->keycount++;
}

void Divide(BTnode* cur, int pos, BTnode*& Newnode)
{
	NewNode(Newnode);
	Newnode->child[0] = cur->child[pos];
	for ( int i = pos + 1,j = 1; i <= cur->keycount; i++, j++ )
	{
		Newnode->data[j] = cur->data[i];
		Newnode->child[j] = cur->child[i];
	}

	Newnode->keycount = cur->keycount - pos;
	Newnode->parent = cur->parent;
	cur->keycount = pos - 1;

	for ( int i = 0; i <= Newnode->keycount; i++ )
	{
		if(Newnode->child[i] )
		Newnode->child[i]->parent = Newnode;
	}
}

void BTreeInsert(BTree& root, type key, result ret)
{
	if ( !root )
	{
		NewNodeRoot(root, key, nullptr, nullptr);
	}
	else
	{
		BTnode* cur = ret.ptr;
		BTnode* Newnode = nullptr;
		BTnode* child = nullptr;
		int index = ret.index;
		bool finished = 1, arrived = 1;
		while ( finished && arrived )
		{
			Insert(cur, key, index, child);
			if ( cur->keycount <= level - 1 )
			{
				finished = 0;
			}
			else
			{
				int pos = ( level + 1 ) / 2;
				Divide(cur, pos, Newnode);
				child = Newnode;
				key = cur->data[pos];
				if ( !cur->parent )
				{
					arrived = 0;
				}
				else
				{
					cur = cur->parent;
					index = find(cur, key);
				}
			}
		}
		if ( !arrived )
		{
			NewNodeRoot(root, key, cur, Newnode);
		}
	}
}

void PrintBTree(BTree root, int tab)
{
	if ( !root )
	{
		return;
	}
	BTnode* Node = root;
	for ( int i = 0; i < tab; i++ )
	{
		cout << "    ";
	}       
	for ( int i = 1; i <= Node->keycount; i++ )
	{
		cout << Node->data[i] << " ";
	}
	cout << endl;
	for ( int i = 0; i <= Node->keycount; i++ )
	{
		PrintBTree(Node->child[i], tab + 1);
	}
}

void CreateBTree(BTree& root)
{
	type key;
	result ret;
	char n;
	while ( 1 )
	{
		cout << "请输入要插入的数据：" << endl;
		cin >> key;
		ret = SearchBTree(root, key);
		if ( ret.flag )
		{
			BTreeInsert(root, key, ret);
			cout << "当前的数据结构为：" << endl;
			cout << "---------------------------------" << endl;
			PrintBTree(root, 1);
			cout << "---------------------------------" << endl;

		}
		else
		{
			cout << key << "已存在" << endl;
		}
		cout << "是否继续插入数据：y/n" << endl;
		getchar();
		cin >> n;
		if ( n != 'y' )
			break;
	}
}

void convert(BTnode*& cur,int i)
{
	BTnode* node = cur->child[i];
	while ( node->child[0] )
	{
		node = node->child[0];
	}
	
	cur->data[i] = node->data[1];
	cur = node;
}

void Remove(BTnode* &cur, int i)
{
	for ( int j = i; j < cur->keycount; j++ )
	{
		cur->data[j] = cur->data[j + 1];
		cur->child[j] = cur->child[j + 1];
	}

	cur->keycount--;
}

void Borrow(BTnode* parent, BTnode* cur,BTnode* left, BTnode* right,int j)
{
	if ( left && left->keycount > m )
	{
		for ( int i = cur->keycount + 1; i > 0; i-- )
		{
			cur->data[i] = cur->data[i - 1];
			cur->child[i] = cur->child[i - 1];
		}
		cur->child[0] = left->child[left->keycount];
		if ( cur->child[0] )
		{
			cur->child[0]->parent = cur;
		}
		cur->data[1] = parent->data[j];
		parent->data[j] = left->data[left->keycount];
		left->keycount--;
		cur->keycount++;
	}
	else
	{
		cur->data[cur->keycount + 1] = parent->data[j + 1];
		cur->child[cur->keycount + 1] = right->child[0];
		if ( cur->child[cur->keycount + 1] )
		{
			cur->child[cur->keycount + 1]->parent = cur;
		}
		cur->keycount++;
		parent->data[j + 1] = right->data[1];


		for ( int i = 0; i < right->keycount; i++ )
		{
			right->data[i] = right->data[i + 1];
			right->child[i] = right->child[i + 1];
		}
		right->keycount--;
	}
}

void mergeNode(BTree& root,BTnode*left,BTnode*right,BTnode* parent,int j)
{
	left->data[left->keycount + 1] = parent->data[j];
	if ( parent->keycount == 1 )
	{
		left->parent = parent->parent;
	}
	left->child[left->keycount + 1] = right->child[0];
	if ( left->child[left->keycount + 1] )
	{
		left->child[left->keycount + 1]->parent = left->child[left->keycount + 1];
	}
	left->keycount++;
	for ( int i = 1; i <= right->keycount; i++ )
	{
		left->keycount++;
		left->data[left->keycount] = right->data[i];
		left->child[left->keycount] = right->child[i];

		if ( left->child[left->keycount] )
		{
			left->child[left->keycount]->parent = left->child[left->keycount];
		}
	}
	delete right;
	Remove(parent, j);

	if (parent->parent &&  parent->keycount < m )
	{
		Adjust(root,parent);
	}
	if(parent && parent->keycount < 1 )
	{
		root = left;
	}
}

void Merge(BTree& root,BTnode* parent, BTnode* cur, BTnode* left, BTnode* right,int j)
{
	if (left)
	{
		mergeNode(root,left,cur,parent,j);
	}
	else if(right)
	{
		j++;
		mergeNode(root,cur,right,parent,j);
	}
}

void Adjust(BTree & root,BTnode*& cur)
{
	BTnode* parent = cur->parent;
	BTnode* right = nullptr;
	BTnode* left = nullptr;
	int j;
	for ( j = 0; j <= parent->keycount; j++ )
	{
		if ( parent->child[j] == cur )
			break;
	}

	if ( j > 0 )
	{
		left = parent->child[j - 1];
	}
	if ( j < parent->keycount )
	{
		right = parent->child[j + 1];
	}

	if ( ( left && left->keycount > m ) || ( right && right->keycount > m ) )
	{
		Borrow(parent,cur,left,right,j);
	}
	else
	{
		Merge(root, parent, cur, left, right, j);
	}
}

void Delete(BTree& root, result ret)
{
	BTnode* cur = ret.ptr;
	int i = ret.index;
	if ( cur->child[i] )
	{
		convert(cur,i);
		i = 1;
	}

	Remove(cur, i);

	if ( !cur->parent && cur->keycount < 1 ) 
	{
		root = nullptr;
		return;
	}
	if ( cur->parent && cur->keycount < m )
	{
		Adjust(root,cur);
		return;
	}
}

void DeleteTree(BTree& root)
{
	type key;
	result ret;
	while ( 1 )
	{
		cout << "请输入你想要删除的元素：" << endl;
		cin >> key;
		ret = SearchBTree(root, key);
		if ( !ret.flag )
		{
			Delete(root,ret);
			cout << "当前的数据结构为：" << endl;
			cout << "---------------------------------" << endl;
			PrintBTree(root, 1);
			cout << "---------------------------------" << endl;
		}
		else
		{
			cout << "该元素不存在！" << endl;
		}
	}
}

int main()
{
	BTree root = nullptr;
	CreateBTree(root);
	DeleteTree(root);
	return 0;
}