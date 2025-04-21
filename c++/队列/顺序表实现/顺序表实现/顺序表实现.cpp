#include<iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Queue
{
private:
	T* data;
	int front;
	int rear;
	int capacity;
	void resize();

public:
	Queue() : data(new T[10]),front(0),rear(0),capacity(10) {}
	~Queue();
	void enqueue(T element);
	T dequeue();
	T getfront() const;
	int getsize() const;
};

template <typename  T>
void Queue<T>::resize()
{
	T* newdata = new T[capacity * 2];
	for (int i = 0; i < rear; i++)
	{
		newdata[i] = data[i];
	}
	delete[] data;
	data = newdata;
	capacity *= 2;
}

template<typename T>
Queue<T>:: ~Queue()
{
	delete[] data;
}

template<typename T>
void Queue<T>::enqueue(T element)
{
	if (rear == capacity)
	{
		resize();
	}
	data[rear++] = element;
}

template<typename T>
T Queue<T>::dequeue()
{
	if (rear == front)
	{
		throw std::underflow_error("Queue is empty");
	}
	T element = data[front++];
	return element;
}

template<typename T>
T Queue<T>::getfront() const
{
	if (rear == front)
	{
		throw std::underflow_error("Queue is empty");
	}
	return data[front];
}

template<typename T>
int Queue<T>::getsize() const
{
	return rear - front;
}



int main()
{
	Queue <int> q;
	q.enqueue(3);
	q.enqueue(4);
	cout << q.getfront() << endl;
	q.enqueue(5);
	cout << q.getfront() << endl;
	q.dequeue();
	cout << q.getfront() << endl;
	return 0;
}