#include <iostream>
#include <stdexcept>
using namespace std;

#define eletype int 

struct Listnode
{
	eletype data;
	Listnode* next;

	Listnode(eletype x):data(x),next(NULL){}

};

class Linkedlist
{
private:
	Listnode* head;
	int size;

public:
	Linkedlist():head(NULL),size(0){}
	~Linkedlist();
	void insert(int i, eletype value);
	void remove(int i);
	Listnode* find(eletype value);
	Listnode* get(int i);
	void update(int i, eletype value);
	void print();


};

Linkedlist::~Linkedlist()
{
	Listnode* curr = head;
	while (curr != NULL)
	{
		Listnode* tmp = curr;
		curr = curr->next;
		delete tmp;
	}
}

void Linkedlist::insert(int i,  eletype value)
{
	if (i<0 || i>size)
	{
		throw std::out_of_range("Invalid position");
	 }
	Listnode* newnode = new Listnode(value);
	if (i == 0)
	{
		newnode->next = head;
		head = newnode;
	}
	else
	{
		Listnode* curr = head;
		for (int j = 0; j < i - 1; j++)
		{
			curr = curr->next;
		}
		newnode->next = curr->next;
		curr->next = newnode;
		
	}
	++size;
}

void Linkedlist::remove(int i)
{
	if(i<0 || i>size)
	{
		throw std::out_of_range("Invalid position");
	}
	if (i == 0)
	{
		Listnode* temp = head;
		head = head->next;
		delete temp;
	}
	else
	{
		Listnode* curr = head;
		for (int j = 0; i < i - 1; j++)
		{
			curr = curr->next;
		}
		Listnode* temp = curr->next;
		curr->next = temp->next;
		delete temp;
	}
	--size;
}

Listnode* Linkedlist::find(eletype value)
{
	Listnode* curr = head;
	while (curr && curr->data != value)
	{
		curr = curr->next;
	}
	return curr;
}

Listnode* Linkedlist::get(int i)
{
	if (i<0 || i>size)
	{
		throw std::out_of_range("Invalid position");
	}
	Listnode* curr = head;
	for (int j = 0; j < i; j++)
	{
		curr = curr->next;
	}
	return curr;
}

void Linkedlist::update(int i, eletype value)
{
	get(i)->data = value;
}

void Linkedlist::print()
{
	Listnode* curr = head;
	while (curr)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}

int main()
{
	Linkedlist list;
	list.insert(0, 10);
	list.insert(1, 20);
	list.insert(2, 30);
	list.insert(3, 40);
	list.insert(4, 50);
	list.print();
	list.remove(1);
	list.print();
	list.update(2, 60);
	list.print();
	Listnode* tmp = list.find(30);
	cout << tmp->data << endl;
	return 0;
}