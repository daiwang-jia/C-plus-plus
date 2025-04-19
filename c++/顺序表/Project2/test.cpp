#include <iostream>
#include <vector>
using namespace std;

struct Sequnetlist {
	int size;
	int capacity;
	int* elements;
};

void initalizelist(Sequnetlist* list, int capacity)
{
	list->size = 0;
	list->capacity = capacity;
	list->elements = new int[capacity];
}

void insert(Sequnetlist* list, int index, int element)
{
	if (index<0 || index>list->size)
	{
		throw std::invalid_argument("Invalid index");
	}
	if (list->size == list->capacity)
	{
		int newcapacity = list->capacity * 2;
		int* newelements = new int[newcapacity];
		for (int i = 0; i < list->size; i++)
		{
			newelements[i] = list->elements[i];
		}
		delete[] list->elements;
		list->elements = newelements;
		list->capacity = newcapacity;
	}
	for (int i = list->size; i > index; i--)
	{
		list->elements[i] = list->elements[i - 1];
	}
	list->elements[index] = element;
	list->size++;
}
int getelement(Sequnetlist* list, int index)
{
	return list->elements[index];
}

int main()
{
	int n;
	while (cin >> n)
	{
		Sequnetlist s;
		initalizelist(&s, 1);
		for(int i=0;i<n;i++)
		{
			int x;
			cin >> x;
			insert(&s, i, x);
		}
		int prod = 1;
		for (int i = 0; i < s.size; i++)
		{
			int val = getelement(&s, i);
			if (val & 1)
			{
				prod = prod * val;
			}
			
		}
		cout << prod << endl;
	}
	return 0;
}