// Steven Quintana
// Ch.19 Assignment - Stack Project
// July 16, 2020

// Specification file for the DynIntStack class.

#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H
#include <string>
using namespace std;


class DynamicStack
{
private:
	struct StackNode
	{
		string value;     // Value in the node.
		StackNode* next;  // Pointer to the next stack node.
	};

	StackNode* top;		  // Points to the first node in the stack.

public:
	// Constructor
	DynamicStack()
	{
		top = nullptr;
	}

	// Destructor
	~DynamicStack();

	// Stack operations
	void push(string);
	void pop(string&);
	void concatenate(string&);
	void addS(bool&);
	void displayStack();
	string printNextValue();
	bool isEmpty();
	bool twoValues();
	int stackSize();
};
#endif