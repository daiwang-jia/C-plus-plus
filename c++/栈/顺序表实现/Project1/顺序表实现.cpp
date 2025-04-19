#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Stack {
private:
    T* data;
    int size;
    int capacity;
    void resize() {
        int newcapacity = capacity * 2;
        T* newdata = new T[newcapacity];
        for (int i = 0; i < size; i++) {
            newdata[i] = data[i];
        }
        delete[] data;
        data = newdata;
        capacity = newcapacity;
    }

public:
    Stack() : size(0), capacity(10), data(new T[capacity]) {}
    ~Stack() { delete[] data; }

    // 深拷贝支持
    Stack(const Stack& other) : size(other.size), capacity(other.capacity), data(new T[capacity]) {
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    void push(T element) {
        if (size == capacity) resize();
        data[size++] = element;
    }

    T pop() {
        if (size == 0) throw std::underflow_error("Stack is empty");
        return data[--size];
    }

    T top() const {
        if (size == 0) throw std::underflow_error("Stack is empty");
        return data[size - 1];
    }

    int getSize() const { return size; }
};

int main() {
    Stack<int> st;
    st.push(1);
    st.push(2);
    Stack<int> st2 = st; // 测试拷贝构造函数
    st2.push(3);
    while (st2.getSize() > 0) {
        cout << st2.pop() << endl; // 应输出 3, 2, 1
    }
    return 0;
}