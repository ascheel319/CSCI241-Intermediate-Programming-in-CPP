#ifndef COMPLEX_H
   #define COMPLEX_H


	//*****************************************************************
   // FILE:      Stack.h
   // AUTHOR:    Andrew Scheel
   // LOGON ID:  z1790270
   // DUE DATE:  10/31/17
   //
   // PURPOSE:   Declaration for the Stack class.
   //*****************************************************************
   #include <iostream>
   #include <cstdlib>
   using namespace std;

	class Stack
	{
	private:
		//data members
		int* stack_array;
		size_t stack_capacity;
		size_t stack_size;

	public:
		//methods
		Stack();//default constructor
		~Stack();//de-constructor
		Stack(const Stack&);//alternative constructor
		Stack& operator=(const Stack&);
		void clear();
		size_t size() const;
		size_t capacity() const;
		bool empty() const;
		int top() const;
		void push(int val);
		void pop();
		void reserve(size_t);
		int operator[](size_t) const;//read the subscript
		int& operator[](size_t);//write the subscript
		bool operator==(const Stack&) const;

		//friend
		friend ostream& operator<<(ostream&, const Stack&);

	};
#endif
