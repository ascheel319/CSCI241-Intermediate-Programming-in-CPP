/*********************************************************************
 PROGRAM:    CSCI 241 Assignment 5
 PROGRAMMER: Andrew Scheel
 LOGON ID:   z1790270
 DUE DATE:   10/31/17

 FUNCTION:   Defines the methods for the program
**********************************************************************/

#include "Stack.h"

using namespace std;

//default constructor
Stack::Stack()
{
	stack_size = 0;
	stack_capacity = 0;
	stack_array = nullptr;
}

//copy constructor
Stack::Stack(const Stack& other)
{
	stack_capacity = other.stack_capacity;
	stack_size = other.stack_size;

	if(stack_capacity == 0)
	{
		stack_array = nullptr;
	}
	else
	{
		stack_array = new int[stack_capacity];
	}
	for(size_t i = 0; i < stack_size; ++i)
	{
		stack_array[i] = other.stack_array[i];
	}
}

//de-constructor
Stack::~Stack()
{
	delete[] stack_array;
}

//output operator
ostream& operator<<(ostream& lhs, const Stack& rhs)
{
	for(size_t i = 0; i < rhs.stack_size; i++)
	{
		lhs << rhs.stack_array[i] << " ";
	}
	return lhs;
}

/***************************************************************
	Function: size

	Use: returns the size of the stack

	Arguments: none

	Returns: stack_size

	Note:
	***************************************************************/
size_t Stack::size() const
{
	return stack_size;
}

/***************************************************************
        Function: capacity

        Use: returns the capacity of the stack

        Arguments: none

        Returns: stack_capacity

        Note:
        ***************************************************************/

size_t Stack::capacity() const
{
	return stack_capacity;
}

/***************************************************************
        Function: empty

        Use: returns if the stack is empty or not

        Arguments: none

        Returns: true if it is empty and false if it is not empty

        Note:
        ***************************************************************/
bool Stack::empty() const
{
	if(stack_size == 0)
	{
	return true;
	}
	else
	{
	return false;
	}
}

/***************************************************************
        Function: push

        Use: pushes a new value into the array

        Arguments: none

        Returns: none

        Note:
        ***************************************************************/
void Stack::push(int val)
{
	//if stack is full, allocate additional storage
	if(stack_size == stack_capacity)
	{
		if(stack_capacity == 0)
			reserve(1);
		else
			reserve(stack_capacity * 2);
	}

	stack_array[stack_size] = val;
	++stack_size;
}

/***************************************************************
        Function: reserve

        Use: allocates more space into the array

        Arguments: none

        Returns: none

        Note:
        ***************************************************************/
void Stack::reserve(size_t n)
{
	if(n < stack_size || n == stack_capacity)
		return;
	int* tempArray = new int[n];

	for(size_t i = 0; i < stack_size; i++)
	{
		tempArray[i] = stack_array[i];
	}

	stack_capacity = n;
	delete[] stack_array;
	stack_array = tempArray;
}

/***************************************************************
        Function: top

        Use: returns the element at the top of the array

        Arguments: none

        Returns: stack_size

        Note:
        ***************************************************************/
int Stack::top() const
{
	return stack_array[stack_size - 1];
}

/***************************************************************
        Function: pop

        Use: removes 1 from the size of the stack

        Arguments: none

        Returns: none

        Note:
        ***************************************************************/
void Stack::pop()
{
	--stack_size;
}

/***************************************************************
        Function: operator=

        Use: makes the orginal stack the same as the other stack

        Arguments: another stack

        Returns: a pointer to the this array

        Note:
        ***************************************************************/
Stack& Stack::operator=(const Stack& other)
{
	if(stack_array != other.stack_array){
	stack_capacity = other.stack_capacity;
        stack_size = other.stack_size;

	delete[] stack_array;

        if(stack_capacity == 0)
		stack_array = nullptr;
        else
		stack_array = new int[stack_capacity];

	for(size_t i = 0; i < stack_size; ++i)
	{
		stack_array[i] = other.stack_array[i];
	}}
return *this;
}

/***************************************************************
        Function: clear

        Use: sets the stack size to 0

        Arguments: none

        Returns: none

        Note:
        ***************************************************************/
void Stack::clear()
{
	stack_size = 0;
}

//write version of []
/***************************************************************
        Function: operator[]

        Use: writes to the array at n position

        Arguments: unsigned number n

        Returns: stack array at position n

        Note:
        ***************************************************************/
int& Stack::operator[](size_t n)
{
	return stack_array[n];
}

//read version of []
/***************************************************************
        Function: operator[]

        Use: returns the element at postion n

        Arguments: unsigned number n

        Returns: stack array at position n

        Note:
        ***************************************************************/
int Stack::operator[](size_t n) const
{
        return stack_array[n];
}

/***************************************************************
        Function: operator==

        Use: checks to see if 1 stack is the same as the other

        Arguments: another stack

        Returns: true if they are the same and fauls if they are not the same

        Note:
        ***************************************************************/
bool Stack::operator==(const Stack& rhs) const
{
	if(this->stack_size == rhs.size())
	{
		for(size_t i = 0; i < rhs.size(); i++)
		{
			if(stack_array[i] != rhs[i])
			{
				return false;
			}
		}
        return true;

	}
	else
	{
		return false;
	}
}
