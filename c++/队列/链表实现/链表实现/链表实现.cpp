#include<iostream>
#include<stdexcept>

using namespace std;

template<typename T>
class Queue
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node(T d) : data(d),next(NULL) {}

	};

	Node* front;
	Node* rear;
	int size;

public:
	Queue() : front(NULL), rear(NULL), size(0) {}
	~Queue();
	void enqueue(T element);
	T dequeue();
	T getfront() const;
	int geisize() const;

};

template<typename T>
Queue<T>::~Queue()
{
	while (front)
	{
		Node* temp = front;
		front = front->next;
		delete temp;
	}
	
}
template<typename T>
void Queue<T>::enqueue(T element)
{
	if (rear == NULL)
	{
		rear = new Node(element);
		front = rear;
	}
	else
	{
		rear->next = new Node(element);
		rear = rear->next;
	}
	size++;
}
template<typename T>
T Queue<T>::dequeue()
{
	if (rear == front)
	{
		throw std::underflow_error("Queue is empty");
	}
	T element = front->data;
	Node* temp = front;
	front = front->next;
	delete temp;
	size--;
	return element;
}
template<typename T>
T Queue<T>::getfront() const
{
	if (rear == front)
	{
		throw std::underflow_error("Queue is empty");
	}
	return front->data;
}
template<typename T>
int Queue<T>::geisize() const
{
	return size;;
}




int main()
{
	Queue <int> q;
	q.enqueue(3);
	q.enqueue(4);
	cout << q.getfront() << endl;

	return 0;
}