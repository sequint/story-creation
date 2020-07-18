// Steven Quintana
// Ch.19 Assignment - Stack Project
// July 16, 2020

// Implementation file for the DynIntStack class.

#include <iostream>
#include <string>
#include "DynamicStack.h"
using namespace std;

//******************************************************************************************
// Destructor Function									   *
//											   *
// This function deletes every node from the stack.					   *
//******************************************************************************************

DynamicStack::~DynamicStack()
{
	StackNode* nodePtr = nullptr;   // To travse the stack.
	StackNode* nextNode = nullptr;  // To point to the next node.

// Point to the top of the stack.
	nodePtr = top;

	// Traverse through the stack and delete each node.
	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

//******************************************************************************************
// push Function									   *
//											   *
// This function pushes the passed value onto the stack.				   *
//******************************************************************************************

void DynamicStack::push(string value)
{
	// If the value passed is blank or is longer than 10 letters, print error message and exit fail.
	if (value.empty() || value.length() > 10)
	{
		cout << "\nInvalid entry.\n";
		exit(EXIT_FAILURE);
	}

	StackNode* newNode = nullptr;  // Points to a new node.

	// Allocate a new node and store the value there.
	newNode = new StackNode;
	newNode->value = value;

	// If the stack is empty, make newNode the first (top) node.
	if (isEmpty())
	{
		top = newNode;
		newNode->next = nullptr;
	}
	// Otherwise, insert newNode before top.
	else
	{
		newNode->next = top;
		top = newNode;
	}
}

//******************************************************************************************
// pop Function										   *
//											   *
// This function pops out the top value of the stack, then makes a copy of the variable.   *
//******************************************************************************************

void DynamicStack::pop(string& value)
{
	StackNode* nextNode = nullptr;  // To point to the next node in the stack.

	// If the stack is empty, return a message that it is empty and do nothing.
	if (isEmpty())
	{
		cout << "\nThe stack is empty.\n";
		exit(EXIT_FAILURE);
	}
	// Otherwise, pop the value off the stack and save a copy of it.
	else
	{
		// Save a copy of the value.
		value = top->value;

		// Have nextNode point to the next node from the top.
		nextNode = top->next;

		// Delete the top node.
		delete top;

		// Make the new top the nextNode in the stack.
		top = nextNode;

	}
}

//******************************************************************************************
// concatenate Function									   *
//											   *
// This function checks if there are two at least two nodes in a stack, then combines the  *
// two values and makes that value the new top node.					   *
//******************************************************************************************

void DynamicStack::concatenate(string& value)
{
	StackNode* nextNode = top->next;  // To traverse the stack.
	StackNode* newNode = nullptr;     // Points to a new node.
	string newValue = "";		  // To hold the new concatenated value.
	string tempValue;		  // To hold a temporary value if newValue is longer than 10 characters.

	// Allocate a new node and store the value there.
	newNode = new StackNode;
	newNode->value = newValue;

	// If the stack is empty or there is only one node in the stack, print error message and exit fail.
	if (!twoValues())
	{
		cout << "\nError, there is not enough values in the stack to concatenate.\n";
		exit(EXIT_FAILURE);
	}
	// Otherwise, pop the top two values from the stack and push the combined values to the top.
	else
	{
		// Combine the top two nodes of the stack.
		newValue = top->value + nextNode->value;

		// If tempValue is greater than 10, truncate the new string to 10 characters.
		if (newValue.length() > 10)
		{
			// Make the first 10 characters of tempValue, the first 10 of newValue and stop.
			for (int count = 0; count < 10; count++)
			{
				tempValue += newValue[count];
			}

			// Make newValue equal to tempValue as a new 10 letter word.
			newValue = tempValue;
		}

		// Pop the top two values of the stack.
		for (int count = 0; count < 2; count++)
		{
			// Have nextNode point to the next node from the top.
			nextNode = top->next;

			// Delete the top node.
			delete top;

			// Make the new top the nextNode in the stack.
			top = nextNode;
		}
		
		// Store newValue into the newNodes value and push the newNode to the top of the stack.
		newNode->value = newValue;
		newNode->next = top;
		top = newNode;

		// Store the concatenated value into newValue.
		value = newValue;
	}
}

//******************************************************************************************
// addS Function									   *
//											   *
// This function adds an 's' character to the end of the string value in the top node.	   *
// If the value is already 10 characters long, the string is truncated to accomidate the   *
// new 's' character.									   *
//******************************************************************************************

void DynamicStack::addS(bool& isTen)
{
	StackNode* nodePtr = top;   // To point to the top node.

	// If the stack is empty, return a message that it is empty and exit the program.
	if (isEmpty())
	{
		cout << "\nThe stack is empty.\n";
		exit(EXIT_FAILURE);
	}
	// Else, if the value of the top node in the stack is 10 characters long delete the last character and replace it with 's'.
	else if (nodePtr->value.length() == 10)
	{
		// Loop through the length of the value.
		for (int count = 0; count < nodePtr->value.length(); count++)
		{
			if (count == nodePtr->value.length() - 1)
			{
				nodePtr->value[count] = 's';
			}
		}

		// Set the isTen bool to true to indicate to the calling function that the last character was changed.
		isTen = true;
	}
	// Otherwise, add an 's' character to the end of the value.
	else
	{
		nodePtr->value = nodePtr->value + 's';
	}
}

//******************************************************************************************
// displayStack Function								   *
//											   *
// This function traverses through a stack and displays each node in the stack.		   *
//******************************************************************************************

void DynamicStack::displayStack()
{
	StackNode* nodePtr = top;  // To traverse the list starting at the top of the stack.

	// While the pointer points to a node, display the node and traverse the stack.
	while (nodePtr)
	{
		// Display the number stored in the node.
		cout << nodePtr->value << "\n";

		// Point to the next node.
		nodePtr = nodePtr->next;
	}
}

//******************************************************************************************
// printNextValue Function								   *
//											   *
// This function prints the top node in the stack, then pops it out and assigned the next  *
// node as the top of the stack.							   *
//******************************************************************************************

string DynamicStack::printNextValue()
{
	StackNode* nextNode = nullptr;  // To point to the next node in the stack.
	string tempValue;		// Variable to temporarily hold the top nodes value.

	// Store the top nodes value into tempValue.
	tempValue = top->value;

	// Have nextNode point to the next node from the top.
	nextNode = top->next;

	// Delete the top node.
	delete top;

	// Make the new top the nextNode in the stack.
	top = nextNode;

	return tempValue;
}

//******************************************************************************************
// isEmpty Function									   *
//											   *
// This function returns true if the top node of a stack is null, and false if it is not.  *
//******************************************************************************************

bool DynamicStack::isEmpty()
{
	if (!top)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//******************************************************************************************
// twoValues Function									   *
//											   *
// This function returns true if there are two values in a stack, and false if not.	   *
//******************************************************************************************

bool DynamicStack::twoValues()
{
	if (!isEmpty() && top->next != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//******************************************************************************************
// stackSize Function									   *
//											   *
// This function traverses through a stack and returns the number of nodes in the stack.   *
//******************************************************************************************

int DynamicStack::stackSize()
{
	StackNode* nodePtr = top;   // To point to the top node.
	int size = 0;		    // Variable to hold the size of the stack.

	// If the stack is empty, return the size at '0'.
	if (isEmpty())
	{
		return size;
	}
	// Otherwise traverse the stack, adding 1 to the stack size with each iteration.
	else
	{
		// While nodePtr is not null, increment the size and traverse the list.
		while (nodePtr)
		{
			size++;
			nodePtr = nodePtr->next;
		}
	}

	return size;
}
