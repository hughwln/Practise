#ifndef MYSTACK_H
#define MYSTACK_H

#include <vector>
#include <iostream>
using namespace std;

template<class T>
class myStack
{
private:
	int m_size;
	int m_capacity;
	T * m_ptr;

public:
	myStack();
	myStack(const myStack& mystack);
	int size() const;
	int capacity() const;
	void push(T val);
	void pop();
	T top();
	myStack<T>& operator=(const myStack& mystack);
	~myStack();
};

template<class T>
myStack<T>::myStack():m_size(0),m_capacity(0),m_ptr(nullptr)
{}

template<class T>
myStack<T>::myStack(const myStack& mystack)
{
	m_size = mystack.size();
	m_capacity = mystack.capacity();
	m_ptr = new T[mystack.capacity()];
	memcpy(m_ptr, mystack.m_ptr, mystack.size()*sizeof(T));
}

template<class T>
int myStack<T>::size() const
{
	if(m_size < 0)
	{
		cout << "===========stack size error!!!================" << endl;
		return 0;
	}
	else
		return m_size;
}

template<class T>
int myStack<T>::capacity() const
{
	if(m_capacity < 0)
	{
		cout << "===========stack capacity error!!!================" << endl;
		return 0;
	}
	else
		return m_capacity;
}

template<class T>
void myStack<T>::push(T val)
{
	if(m_size > m_capacity)
		cout << "===========size can't bigger than capacity!!!=======" << endl;
	else if(m_size == m_capacity)
	{
		if(m_capacity == 0)
		{
			m_ptr = new T[2];
			m_ptr[0] = val;
			m_capacity = 2;
			m_size = 1;
		}
		else
		{
			T * temp_ptr = m_ptr;
			m_capacity = m_capacity * 2;
			m_ptr = new T[m_capacity];
			memcpy(m_ptr, temp_ptr, m_size*sizeof(T));
			delete []temp_ptr;
			m_ptr[m_size++] = val;
		}
	}
	else
		m_ptr[m_size++] = val;
	return;
}

template<class T>
void myStack<T>::pop()
{

	if(m_size > m_capacity)
		cout << "===========size can't bigger than capacity!!!=======" << endl;
	if(m_size <= 0)
		cout << "===========can't pop from an empty stack!!!=========" << endl;
	else
		m_size--;
}

template<class T>
T myStack<T>::top()
{
	if(m_size > m_capacity)
	{
		cout << "===========size can't bigger than capacity!!!=======" << endl;
		return T();
	}
	else if(m_size <= 0)
	{
		cout << "===========can't pop from an empty stack!!!=========" << endl;
		return T();
	}
	else
		return m_ptr[m_size-1];
}

template<class T>
myStack<T>& myStack<T>::operator=(const myStack& mystack)
{
	if(this == &mystack)
		return *this;
	delete []m_ptr;
	m_size = mystack.size();
	m_capacity = mystack.capacity();
	m_ptr = new T[mystack.capacity()];
	memcpy(m_ptr, mystack.m_ptr, mystack.size()*sizeof(T));
	return *this;
}

template<class T>
myStack<T>::~myStack()
{
	delete []m_ptr;
}

#endif