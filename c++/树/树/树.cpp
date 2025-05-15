#include <iostream>
using namespace std;

template <typename T>
struct Listnode
{
	T data;
	Listnode* next;
	Listnode(T d) :data(d), next(NULL) {}

};

template <typename T>
struct Treenode
{
	T data;
	Listnode <Treenode <T>*>* childrenhead;

	Treenode()
	{
		data = T();
		childrenhead = NULL;
	}

	void Addchild(Treenode <T>* node)
	{
		Listnode< Treenode <T>*>* childnode = new Listnode<Treenode<T>*>(node);
			if (childrenhead == NULL)
			{
				childrenhead = childnode;
			}
			else
			{
				childnode->next = childrenhead;
				childrenhead = childnode;
			}
	}
};

//¶¨ÒåÊ÷
template <typename T>
class Tree
{
private:
	Treenode<T>* nodes;
	Treenode<T>* root;

public:
	Tree();
	Tree(int maxnodes);
	~Tree();
	Treenode<T>* Gettreenode(int id);
	void Setroot(int rootid);
	void Addchild(int parentid, int sonid);
	void Assigndata(int nodeid, T data);
	void Print(Treenode<T>* node = NULL);

};

template <typename T>
Tree<T>::Tree()
{
	nodes = new Treenode<T>[10001];
	root = NULL;
}

template <typename T>
Tree<T>::Tree(int maxnodes)
{
	nodes = new Treenode<T>[maxnodes];
	root = NULL;
}

template <typename T>
Tree<T>::~Tree()
{
	delete[] nodes;
}

template <typename T>
Treenode<T>* Tree<T>::Gettreenode(int id)
{
	return &nodes[id];
}

template <typename T>
void Tree<T>:: Setroot(int id)
{
	root = Gettreenode(id);
}

template <typename T>
void Tree<T>::Addchild(int parentid, int sonid)
{
	Treenode<T>* parentnode = Gettreenode(parentid);
	Treenode<T>* sonnode = Gettreenode(sonid);
	parentnode->Addchild(sonnode);

}

template <typename T>
void Tree<T>::Assigndata(int nodeid, T data)
{
	Gettreenode(nodeid)->data = data;
}

template <typename T>
void Tree<T>::Print(Treenode<T>* node)
{
	if (node == NULL)
	{
		node = root;
	}
	cout << node->data;

	Listnode <Treenode <char>*>* tmp = node->childrenhead;
	while (tmp)
	{
		Print(tmp->data);
		tmp = tmp->next;
	}

}


int main()
{
	Tree<char> T(9);
	T.Setroot(0);
	T.Assigndata(0, 'a');
	T.Assigndata(1, 'b');
	T.Assigndata(2, 'c');
	T.Assigndata(3, 'd');
	T.Assigndata(4, 'e');
	T.Assigndata(5, 'f');
	T.Assigndata(6, 'g');
	T.Assigndata(7, 'h');
	T.Assigndata(8, 'i');

	T.Addchild(0, 2);
	T.Addchild(0, 1);
	T.Addchild(1, 3);
	T.Addchild(2, 5);
	T.Addchild(2, 4);
	T.Addchild(3,8);	
	T.Addchild(3, 7);
	T.Addchild(3, 6);

	T.Print();

	return 0;
}