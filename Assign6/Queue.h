#ifndef QUEUE_H
#define QUEUE_H

//*****************************************************************
   // FILE:      Queue.h
   // AUTHOR:    Andrew Scheel
   // LOGON ID:  z1790270
   // DUE DATE:  11/9/17
   //
   // PURPOSE:   Declaration for the queue class
   //*****************************************************************
#include <iostream>
//#include <cstdlib>
#include <stdexcept>
using namespace std;

template <class T>
class Queue;

template <class T>
ostream& operator<<(ostream&, const Queue<T>&);

template <class T>
class Queue
{
	private:
		size_t qCapacity;
		size_t qSize;
		T* qArray;
		int qFront;
		int qBack;

	public:
		//constructors
		Queue();
		~Queue();
		Queue(const Queue<T>&);

		//methods
		void clear();
		size_t size() const;
		size_t capacity() const;
		bool empty() const;
		T& front() const;
		T& back() const;
		void push(const T&);
		void pop();
		void reserve(size_t);
		Queue<T>& operator=(const Queue<T>&);

		//friend
		friend ostream& operator<< <>(ostream&, const Queue<T>&);
};

//methods
template <class T>
Queue<T>::Queue()
{
	qCapacity = 0;
	qSize = 0;
	qArray = nullptr;
	qFront = 0;
	qBack = qCapacity -1;
}

template <class T>
Queue<T>::Queue(const Queue& other)
{
	qCapacity = other.qCapacity;
	qSize = other.qSize;
	qArray = new int[qCapacity];

	for (size_t i = 0; i < qCapacity; ++i)
		qArray[i] = other.qArray[i];

	qFront = other.qFront;
	qBack = other.qBack;
}

template <class T>
Queue<T>::~Queue()
{
	delete[] qArray;
}

//Name:		operator=
//Use:		to copy one queue into another
//Parameters:	a constant reference to a queue variable
//Returns:	the pointer to this
template <class T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
	if(qArray != other.qArray)
	{
		qCapacity = other.qCapacity;
		qSize = other.qSize;

		delete[] qArray;

		if(qCapacity == 0)
			qArray = nullptr;
		else
			qArray = new int[qCapacity];

		for(size_t i = 0; i < qSize; ++i)
		{
			qArray[i] = other.qArray[i];
		}
	}
	return *this;
}

//Name:		operator<<
//Use:		outputing the queue
//Parameters:	the ostream variable(cout) and the queue that is to be printed out
//Returns:	the ostream variable
template <class T>
ostream& operator<<(ostream& lhs, const Queue<T> &rhs)
{
	size_t current, i;

	for (current = rhs.qFront, i = 0; i < rhs.qSize; ++i)
	{
		// Print queue element at subscript i
		lhs << rhs.qArray[current] << ' ';

		// Increment i, wrapping around to front of queue array if necessary
		current = (current + 1) % rhs.qCapacity;
	}
	return lhs;
}

//Name:		clear
//Use:		to clear the data out of the queue
//Parameters:	none
//Returns	none
template <class T>
void Queue<T>::clear()
{
	qSize = 0;
	qFront = 0;
	qBack = qCapacity -1;
}

//Name:		size
//Use:		returns the size of the queue
//Parameters:	none
//Returns	qSize
template <class T>
size_t Queue<T>::size() const
{
	return qSize;
}

//Name:		capacity
//Use:		returns the capacity of the queue
//Parameters:	none
//Returns	qCapacity
template <class T>
size_t Queue<T>::capacity() const
{
	return qCapacity;
}

//Name:		empty
//Use:		check to see if it is empty
//Parameters:	none
//Returns	true if empty and false if not empty
template <class T>
bool Queue<T>::empty() const
{
	if(qSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Name:		front
//Use:		returns the first item in the queue
//Parameters:	none
//Returns	qArray[qFront]
template <class T>
T& Queue<T>::front() const
{
	// Optional
	if (empty())
		throw underflow_error("Stack underflow on call to top()");
	return qArray[qFront];
}

//Name:		back
//Use:		returns the last item in the queue
//Parameters:	none
//Returns	qArray[qBack]
template <class T>
T& Queue<T>::back() const
{
	// Optional
        if (empty())
                throw underflow_error("Stack underflow on call to back()");

	return qArray[qBack];
}

//Name:		push
//Use:		to put a new value into the queue
//Parameters:	the new value
//Returns	none
template <class T>
void Queue<T>::push(const T& val)
{
	// If queue is full, allocate additional storage
	if (qSize == qCapacity)
	{
		if (qCapacity == 0)
			reserve(1);
		else
			reserve(qCapacity * 2);
	}

	qBack = (qBack + 1) % qCapacity;
	qArray[qBack] = val;
	++qSize;
}

//Name:		pop
//Use:		takes the first value out of the queue
//Parameters:	none
//Returns	none
template <class T>
void Queue<T>::pop()
{
	// Optional
        if (empty())
                throw underflow_error("Stack underflow on call to pop()");

	qFront = (qFront + 1) % qCapacity;
	--qSize;
}

//Name:		reserve
//Use:		makes more space in the queue
//Parameters:	a number that is passed from push
//Returns	none
template <class T>
void Queue<T>::reserve(size_t n)
{
	if (n < qSize || n == qCapacity)
		return;

	T* tempArray = new T[n];

	int current = qFront;
	for (size_t i = 0; i < qSize; i++)
	{
		tempArray[i] = qArray[current];
		current = (current + 1) % qCapacity;
	}

	qCapacity = n;
	qFront = 0;
	qBack = qSize - 1;
	delete[] qArray;
	qArray = tempArray;
}


#endif
