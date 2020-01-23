#ifndef STACK_H
#define STACK_H

//*****************************************************************
   // FILE:      Stack.h
   // AUTHOR:    Andrew Scheel
   // LOGON ID:  z1790270
   // DUE DATE:  11/16/17
   //
   // PURPOSE:   Declaration for the Stack class
   //*****************************************************************
#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

//template
template <class T>
class Stack;

template <class T>
ostream& operator<<(ostream&, const Stack<T>&);

//struct
template <class T>
struct Node
{
	T data;
	Node<T>* next;

	Node(const T& = T(), Node<T>* next = nullptr);
};

template <class T>
Node<T>::Node(const T& newData, Node<T>* newNext)
{
	data = newData;
	next = newNext;
}

template <class T>
class Stack
{
	private:
		Node<T>* stkTop;
		size_t stkSize;
		void copyList(const Stack<T>&);

	public:
		//constructors
		Stack();
		~Stack();
		Stack(const Stack<T>&);

		//methods and such
		Stack<T>& operator=(const Stack<T>&);
		void clear();
		size_t size() const;
		bool empty() const;
		T& top() const;
		void push(const T&);
		void pop();

		//friends
		friend ostream& operator<< <>(ostream&, const Stack<T>&);
};

//methods and such
template <class T>
Stack<T>::Stack()
{
	stkTop = nullptr;
	stkSize = 0;
}

template <class T>
Stack<T>::Stack(const Stack<T>& other)
{
	stkTop = nullptr;
	copyList(other);
	stkSize = other.stkSize;
}

template <class T>
Stack<T>::~Stack()
{
	delete [] stkTop;
}

//Name:		operator=
//Use:		overloading the = operator
//Parameters:	the stack that is being copied
//Returns:	*this
template <class T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
	if (this != &other)
	{
		clear();
		copyList(other);
		stkSize = other.stkSize;
	}
	return *this;
}

//Name:		clear
//Use:		clears out the stack and resets it to empty
//Parameters:	none
//Returns:	none
template <class T>
void Stack<T>::clear()
{
	stkTop = nullptr;
	stkSize = 0;
}

//Name:		size
//Use:		returns the size of the stack
//Parameters:	none
//Returns:	return stack Size
template <class T>
size_t Stack<T>::size() const
{
	return stkSize;
}

//Name:		empty
//Use:		tests to see if the stack is empty or not
//Parameters:	none
//Returns:	true if empty and false if not empty
template <class T>
bool Stack<T>::empty() const
{
	if(stkSize == 0 )
		return true;
	else
		return false;
}

//Name:		top
//Use:		returns the top of the stack
//Parameters:	none
//Returns:	stkTop-> data
template <class T>
T& Stack<T>::top() const
{
	if (stkSize == 0 )
		throw underflow_error("Stack underflow on call to top()");

	return stkTop-> data;
}

//Name:		push
//Use:		pushes a new item into the stack
//Parameters:	a constant reference of T type
//Returns:	none
template <class T>
void Stack<T>::push(const T& item)
{
	Node<T>* newNode = new Node<T>(item, stkTop);
	stkTop = newNode;
	stkSize++;
}

//Name:		pop
//Use:		delete an item from the stack
//Parameters:	none
//Returns:	none
template <class T>
void Stack<T>::pop()
{
	if (stkSize == 0)
		throw underflow_error("Stack underflow on call to pop()");
	Node<T>* delNode = stkTop;
	stkTop = stkTop->next;
	delete delNode;
	stkSize--;
}

//friend function

//Name:		operator<<
//Use:		outputs the stack
//Parameters:	a reference to an ostream object and a constant stack object
//Returns:	returns the ostream object
template <class T>
ostream& operator<<(ostream& lhs, const Stack<T> &rhs)
{
	Node<T>* ptr;

	for(ptr = rhs.stkTop; ptr != nullptr; ptr = ptr->next)
		lhs << ptr->data << " ";
	return lhs;
}

//private method

//Name:		copyList
//Use:		copies a stack into another stack
//Parameters:	a constant reference to a stack object
//Returns:	none
template <class T>
void Stack<T>::copyList(const Stack<T>& other)
{
	Node<T>* ptr, * newNode, * last = nullptr;
	for (ptr = other.stkTop; ptr != nullptr; ptr = ptr->next)
	{
		newNode = new Node<T>(ptr->data);
		if (last == nullptr)
			stkTop = newNode;
		else
			last->next = newNode;

		last = newNode;
	}
}

#endif
