#include <iostream>

using namespace std;

template <typename KT ,typename VT>
class Hashnode
{
public:
	KT key;
	VT value;
	Hashnode* next;

	Hashnode(const KT& key, const VT& value)
	{
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};

template <typename KT, typename VT>
class Hashtable
{
private:
	int size;
	Hashnode<KT, VT>** table;

	int hash(const KT& key) const
	{
		int hashkey = key % size;
		if (hashkey < 0)
		{
			hashkey += size;
		}
		return hashkey;
	}

public:
	Hashtable(int size = 1000);
	~Hashtable();
	void insert(const KT& key, const VT& value);
	void remove(const KT& key);
	bool find(const KT& key, VT& value) const;

};

template <typename KT, typename VT>
Hashtable<KT ,VT>::Hashtable (int size )
{
	this->size = size;
	this->table = new Hashnode<KT, VT>* [size];
	for (int i = 0; i < size; i++)
	{
		table[i] = NULL;
	}
}

template <typename KT, typename VT>
Hashtable<KT, VT>::~Hashtable()
{
	for (int i = 0; i < size; i++)
	{
		if (table[i])
		{
			Hashnode<KT, VT>* current = table[i];
			while (current)
			{
				Hashnode<KT, VT>* next = current->next;
				delete current;
				current = next;
			}
			table[i] = NULL;
		}
	}
	delete[] table;
	table = NULL;
}

template <typename KT, typename VT>
void Hashtable<KT, VT>::insert(const KT& key, const VT& value)
{
	int index = hash(key);
	Hashnode<KT, VT>* now = new Hashnode<KT, VT>(key,value);
	if (table[index]==NULL)
	{
		table[index] = now;

	}
	else
	{
		now->next = table[index];
		table[index] = now;
	}
}

template <typename KT, typename VT>
void Hashtable<KT, VT>::remove(const KT& key)
{
	int index = hash(key);
	if (table[index])
	{
		if (table[index]->key == key)
		{
			Hashnode<KT, VT>* next = table[index]->next;
			delete table[index];
			table[index] = next;

		}
		else
		{
			Hashnode<KT, VT>* current = table[index];
			while (current->next && current->next != key)
			{
				current = current->next;
			}
			if (current->next)
			{
				Hashnode<KT, VT>* next = current->next->next;
				delete current->next;
				current->next = next;
			}
		}
	}

}

template <typename KT, typename VT>
bool Hashtable<KT, VT>::find(const KT& key, VT& value) const
{
	int index = hash(key);
	if (table[index])
	{
		if (table[index]->key == key)
		{
			value = table[index]->value;
			return true;
		}
		else
		{
			Hashnode<KT, VT>* current = table[index];
			while (current->next && current->next->key != key)
			{
				current = current->next;
			}
			if (current->next)
			{
				value = current->next->value;
				return true;
			}
		}
	}
		return false;
}



//int main()
//{
//	Hashtable<int, char> h(1000);
//	h.insert(1, 'a');
//	h.insert(2, 'b');
//	h.insert(3, 'v');
//	h.insert(41012012, 'd');
//
//	char val;
//	if (!h.find(43, val))
//	{
//		cout << "43 not found" << endl;
//	}
//
//	if (h.find(41012012, val))
//	{
//		cout << val << endl;
//	}
//
//	return 0;
//}


//¹þÏ£¼ÆÊýÆ÷
template<typename KT>
class Hashcounter
{
private:
	int* counter;
	int counterindex;
	int countersize;
	Hashtable<KT, int>* hash;

public:
	Hashcounter(int size = 256);
	~Hashcounter();
	void reset();
	int add(const KT& key);
	int sub(const KT& key);
	int get(const KT& key);

};

template<typename KT>
Hashcounter<KT>::Hashcounter(int size)
{
	countersize = size;
	counterindex = 0;
	counter = new int[countersize];
	hash = NULL;
	reset();
}

template<typename KT>
Hashcounter<KT>::~Hashcounter()
{
	delete[] counter;
	if (hash)
	{
		delete hash;
		hash = NULL;
	}
}

template<typename KT>
void Hashcounter<KT>::reset()
{
	if (hash)
	{
		delete hash;
		hash = NULL;
	}
	hash = new Hashtable<KT, int>(countersize);
	counterindex = 0;
	for (int i = 0; i < countersize; i++)
	{
		counter[i] = 0;
	}
}

template<typename KT>
int Hashcounter<KT>::add(const KT& key)
{
	int idx;
	if (!hash->find(key, idx))
	{
		idx = counterindex++;
		hash->insert(key, idx);
	}

	return ++counter[idx];
}

template<typename KT>
int Hashcounter<KT>::sub(const KT& key)
{
	int idx;
	if (hash->find(key, idx))
	{
		return --counter[idx];
	}
	return 0;
}

template<typename KT>
int Hashcounter<KT>::get(const KT& key)
{
	int idx;
	if (hash->find(key, idx))
	{
		return counter[idx];
	}
	return 0;
}

int main()
{
	Hashcounter<long long > hc(1000);
	hc.add(13);
	hc.add(13);
	hc.add(13);
	hc.add(13);
	hc.sub(13);
	cout << hc.get(13) << endl;

	return 0;
}