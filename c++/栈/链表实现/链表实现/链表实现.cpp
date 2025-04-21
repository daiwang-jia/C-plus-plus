#include <iostream>
#include<stdexcept>

using namespace std;

template<typename T>
class Stack
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node(T d) : data(d),next(NULL){}
	};
	Node* head;
	int size;

public:
	Stack() :head(NULL), size(0) {}
	~Stack();
	void push(T element);
	T pop();
	T top() const;
	int getsize() const;
};

template<typename T>
Stack<T>::~Stack()
{
	while (head)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

template<typename T>
void Stack<T>::push(T element)
{
	Node* newnode = new Node(element);
	newnode->next = head;
	head = newnode;
	++size;
}

template<typename T>
T Stack<T>::pop()
{
	if (head == NULL)
	{
		throw std::underflow_error("stack is empty");
	}
	T result = head->data;
	Node* temp = head;
	head = head->next;
	delete temp;
	--size;
	return result;
}

template<typename T>
T Stack<T>::top() const
{
	if (head == NULL)
	{
		throw std::underflow_error("stack is empty");
	}
	return head->data;
}

template<typename T>
int Stack<T>::getsize() const
{
	return size;
}


int main()
{
	Stack<int> st;
	st.push(4);
	st.push(7);
	st.push(14);
	cout << st.top() << endl;
	return 0;
}