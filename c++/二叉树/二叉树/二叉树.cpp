#include <iostream>
using namespace std;

template <typename T>
struct Treenode
{
	T val;
	Treenode* right;
	Treenode* left;
	Treenode() :val(0), left(NULL), right(NULL) {}
	Treenode(T x) :val(x), left(NULL), right(NULL) {}
};

template <typename T>
class Tree
{
private:
	Treenode<T>* nodes;
	Treenode <T>* root;
	size_t nodesize;

	Treenode<T>* Create(T a[], int size, int nodeid, T nullnode);
	void vist(Treenode<T>* node);
	void preorder(Treenode<T>* node);
	void inorder(Treenode<T>* node);
	void postorder(Treenode<T>* node);
	void leveorder(Treenode<T>* node);

public:
	Tree();
	Tree(int maxnodes);
	~Tree(); 
	Treenode<T>* Gettreenode(int id);
	void CreateTree(T a[], int size, T nullNode);
	void preordertraversal();
	void inordertraversal();
	void postordertraversal( );
};

template <typename T>
Tree <T> ::Tree()
{
	nodesize = 100001;
	root=NULL:
	nodes = new Treenode<T>[nodesize];
}

template <typename T>
Tree <T> ::Tree(int maxnodes)
{
	nodesize = maxnodes;
	root=NULL:
	nodes = new Treenode<T>[nodesize];

}

template <typename T>
Tree <T> ::~Tree()
{
	delete[] nodes;
}

template <typename T>
Treenode <T>* Tree<T>::Gettreenode(int  id)
{
	return &nodes[id];
}

template <typename T>
void Tree <T> ::vist(Treenode<T>* node)
{
	cout << node->val;
}

template <typename T>
void Tree <T> ::preorder(Treenode <T>* node)
{
	if (node)
	{
		vist(node);
		preorder(node->left);
		preorder(node->right);
	}
}

template <typename T>
void Tree <T> ::inorder(Treenode <T>* node)
{
	if (node)
	{

		inorder(node->left);
		vist(node);
		inorder(node->right);
	}
}

template <typename T>
void Tree <T> ::postorder(Treenode <T>* node)
{
	if (node)
	{

		postorder(node->left);
		
		postorder(node->right);

		vist(node);
	}
}

template<typename T>
Treenode<T>* Tree<T>::Create(T a[], int size, int nodeid, T nullnode) {
	if (nodeid >= size || a[nodeid] == nullnode) {
		return NULL;
	}
	Treenode<T>* nownode = Gettreenode(nodeid);
	nownode->val = a[nodeid];
	nownode->left = Create(a, size, nodeid * 2, nullnode);
	nownode->right = Create(a, size, nodeid * 2 + 1, nullnode);
	return nownode;
}

template <typename T>
void Tree<T>::CreateTree(T a[], int size, T nullnode)
{
	root = Create(a, size, 1, nullnode);
}

template <typename T>
void Tree<T> ::preordertraversal()
{
	preorder(root);
}

template <typename T>
void Tree<T> ::inordertraversal()
{
	inorder(root);
}

template <typename T>
void Tree<T> ::postordertraversal()
{
	postorder(root);
}




int main()
{
	const char nullnode = '-';
	char a[15] = {
		nullnode,'a','b','c','d',
		nullnode,'e','f','g','h',
		nullnode,nullnode,nullnode,nullnode,'i'
	};

	Tree<char> T(15);
	T.CreateTree(a, 15, nullnode);
	T.preordertraversal(); cout << endl;
	T.inordertraversal(); cout << endl;
	T.postordertraversal(); cout << endl;

	return 0; 
}