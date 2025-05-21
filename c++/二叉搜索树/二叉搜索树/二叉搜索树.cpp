#include <iostream>
using namespace std;

//Ê÷½Úµã
template<typename T>
struct Treenode
{
	T val;
	Treenode* left;
	Treenode* right;
	Treenode() : val(0), left(NULL), right(NULL) {}
	Treenode(T a) : val(a), left(NULL), right(NULL) {}
};

//¶þ²æËÑË÷Ê÷
template<typename T>
class Binarysearchtree
{
private:
	Treenode<T>* root;

	Treenode<T>* insertnode(Treenode<T>* node, T value);
	Treenode<T>* removenode(Treenode<T>* node, T value);
	bool searchnode(Treenode<T>* node, T value);
	void inorder(Treenode <T>* node);

public:
	Binarysearchtree() :root(NULL) {}
	~Binarysearchtree();

	void insert(T value)
	{
		root = insertnode(root, value);
	}

	void remove(T value)
	{
		root = removenode(root, value);
	}

	bool search(T value) {
		return searchnode(root, value);
	}

	void inordertraversal() {
		inorder(root);
		cout << endl;
	}
};

template<typename T>
Binarysearchtree<T>::~Binarysearchtree() {
	while (root) {
		remove(root->val);
	}

}

template<typename T>
Treenode<T>* Binarysearchtree<T>::insertnode(Treenode<T>* node, T value) {
	if (node == NULL) {
		return new Treenode<T>(value);
	}
	if (value < node->val) {
		node->left=insertnode(node->left, value);
	}
	else if (value > node->val) {
		node->right=insertnode(node->right, value);
	}
	return node;
}

template<typename T>
Treenode<T>* Binarysearchtree<T>::removenode(Treenode<T>* node, T value) {
	if (node == NULL) {
		return NULL;
	}
	if (value < node->val) {
		node->left = removenode(node->left, value);
	}
	else if (value > node->val) {
		node->right = removenode(node->right, value);
	}
	else {
		if (node->left == NULL && node->right == NULL) {
			delete node;
			node = NULL;
			return NULL;
		}
		if (node->left == NULL) {
			Treenode<T>* rightchild = node->right;
			delete node;
			return rightchild;
		}
		if (node->right == NULL) {
			Treenode<T>* leftchild = node->left;
			delete node;
			return leftchild;
		}
		else {
			Treenode<T>* replacement = node->right;
			while (replacement->left) {
				replacement = replacement->left;
			}
			node->val = replacement->val;
			node->right = removenode(node->right, replacement->val);
		}
	}
	return node;
}

template<typename T>
bool Binarysearchtree<T>::searchnode(Treenode<T>* node, T value) {
	if (node == NULL)
	{
		return false;
	}
	if (value < node->val) {
		return searchnode(node->left, value);
	}
	if (value > node->val) {
		return search(node->right, value);
	}
	return true;
}

template<typename T>
void Binarysearchtree<T>::inorder(Treenode <T>* node) {
	if (node) {
		inorder(node->left);
		cout << node->val << ',';
		inorder(node->right);
	}
}



int main()
{
	Binarysearchtree<int> bst;
	bst.insert(50);
	bst.insert(30);
	bst.insert(60);
	bst.insert(80);
	bst.insert(90);
	bst.insert(100);
	bst.inordertraversal();

	return 0;
}