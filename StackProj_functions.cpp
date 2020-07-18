// Implementation file for the program functions.

#include <iostream>
#include <string>
#include <iomanip>
#include "StackProj_functions.h"
#include "DynamicStack.h"
using namespace std;


//*******************************************************
//		      INPUT FUNCTIONS			*
//*******************************************************


//*******************************************************************************************
// menu Function									    *
//											    *
// This function gives the user a list of numbered choices, gets the choice from the user,  *
// then validates that the choice is valid.						    *
//*******************************************************************************************

void menu(int& choice)
{
	// Display the menu and get the user's choice.
	cout << "\n\nMAIN MENU\n\n";
	cout << PUSH_NOUN << ") Push Noun (push a noun onto the Noun Stack)\n";
	cout << POP_NOUN << ") Pop Noun (pop a noun off of the Noun Stack)\n";
	cout << PUSH_VERB << ") Push Verb (push a verb onto the Verb Stack)\n";
	cout << POP_VERB << ") Pop Verb (pop a verb off of the Verb Stack)\n";
	cout << CONCATENATE << ") Concatenate (top two words of the Noun Stack)\n";
	cout << ADD_S << ") Add an 's'  (to the end of the top word on the Noun Stack)\n";
	cout << DISPLAY_BOTH << ") Display Both Stacks\n";
	cout << MAKE_STORY << ") Make a Story\n";
	cout << EXIT_PROGRAM << ") Exit the Program\n\n";
	cout << "Enter a number from the menu options: ";
	cin >> choice;

	// Check if the input is an integer.
	isInteger(choice);
}

//*******************************************************************************************
// pushValue Function									    *
//											    *
// This function takes a DynamicStack object as an argument an pushes a value from the	    *
// user onto that stack.								    *
//*******************************************************************************************

void pushValue(DynamicStack& stack, string& stackSpecifier)
{
	string value;  // Variable to store the user choice to be pushed onto the stack.

	// Get a value from the user.
	cin.clear();
	cin.ignore(10, '\n');
	cout << "\nEnter a " << stackSpecifier << " here: ";
	getline(cin, value);

	// While the input is empty or longer the ten character get a new value.
	while (value.empty() || value.length() > 10)
	{
		// If the input is empty print an empty error message and get a new value.
		if (value.empty())
		{
			cout << "\nError, input left empty.\n";
			cout << "Please enter a " << stackSpecifier << ": ";
			getline(cin, value);
		}
		// Otherwise, print a longer than 10 characters error message and get a new value.
		else
		{
			cout << "\nError, value cannot be longer than 10 characters.\n";
			cout << "Enter a new " << stackSpecifier << " that is 10 characters or less here: ";
			getline(cin, value);
		}
	}

	stack.push(value);

	// Print a confirmation message of the value pushed.
	cout << "\n'" << value << "' was pushed to the top of the " << stackSpecifier << " stack.\n";
}

//*******************************************************************************************
// popValue Function									    *
//											    *
// This function pops out the top value of a stack.					    *
//*******************************************************************************************

void popValue(DynamicStack& stack, string& stackSpecifier)
{
	string value = "";  // Variable that will hold a temporary copy of the popped value.

	// If the stack is empty, print an error message and exit the function.
	if (stack.isEmpty())
	{
		cout << "\nError, there were no values to pop because the " << stackSpecifier << " stack is empty.\n";
	}
	// Otherwise, pop the top value off the stack.
	else
	{
		stack.pop(value);

		// If value is no longer null, print a confirmation message of the value that was popped out.
		if (value != "")
		{
			cout << "\n'" << value << "' was popped from the " << stackSpecifier << " stack.\n";
		}
	}
}

//*******************************************************************************************
// concateValues Function								    *
//											    *
// This function performs a high level check of whether the stack has two nodes or not,	    *
// and prints an error message if not. If the stack has two, it then calls concatenate.	    *
//*******************************************************************************************

void concateValues(DynamicStack& stack, string& stackSpecifier)
{
	string newValue;  // To hold the new concenated value.

	// If there is not two values in the stack, prompt the user to return to the menu to enter more.
	if (!stack.twoValues())
	{
		cout << "\nError, there are not two or more values in the " << stackSpecifier << " stack to concatenate.\n";
		cout << "Please return to the main menu to enter more values onto the stack.\n";
	}
	// Otherwise, concatenate the top two values.
	else
	{
		stack.concatenate(newValue);

		//Print a confirmation message.
		cout << "\nThe top two words of the " << stackSpecifier << " stack have been combined into '" << newValue << "'.\n";
	}
}

//*******************************************************************************************
// addSVal Function									    *
//											    *
// This function check if the top node in a stack is empty, then add an 's' charater to	    *
// the end of it's value variable.							    *
//*******************************************************************************************

void addSVal(DynamicStack& stack, string& stackSpecifier)
{
	bool isTen = false;  // Boolean variable to indicate whether the value of a node was ten characters long or not.
	// If the stack is empty, print an error message and exit the function.
	if (stack.isEmpty())
	{
		cout << "\nError, the " << stackSpecifier << " stack is empty.\n";
		cout << "Please return to the main menu and add a value to the " << stackSpecifier << " stack to execute this choice.\n";
	}
	// Otherwise, add an 's' character to the end of the value.
	else
	{
		stack.addS(isTen);

		// If isTen was changed to true, print a message to the customer the the last variable in the value was changed.
		if (isTen)
		{
			cout << "\nThe value in the top node of the " << stackSpecifier << " stack is 10 characters long.\n";
			cout << "Therefore, the last character of that value was changed to 's'\n";
		}
		// Otherwise, print a confirmation that an 's' character was added to the end of the value.
		else
		{
			cout << "\nAn 's' was succussfully added to the end of the top node in the " << stackSpecifier << " stack.\n";
		}
	}
}



//*******************************************************
//		     OUTPUT FUNCTIONS			*
//*******************************************************


//*******************************************************************************************
// displayStacks Function								    *
//											    *
// This function display two stacks in colomns next to each other with the top value	    *
// display on the top.									    *
//*******************************************************************************************

void displayStacks(DynamicStack& stack1, DynamicStack& stack2, string& stackSpec1, string& stackSpec2)
{
	// Title for stack1.
	cout << "\n\n" << stackSpec1 << " Stack\n";
	cout << "***********\n\n";

	// If stack1 is empty print an empty message.
	if (stack1.isEmpty())
	{
		cout << "The " << stackSpec1 << " stack is empty.\n\n";
	}
	// Otherwise, print stack1.
	else
	{
		stack1.displayStack();
	}

	// Title for stack2.
	cout << "\n\n" << stackSpec2 << " Stack\n";
	cout << "***********\n\n";

	// If stack1 is empty print an empty message.
	if (stack2.isEmpty())
	{
		cout << "The " << stackSpec2 << " stack is empty.\n\n";
	}
	// Otherwise, print stack2.
	else
	{
		stack2.displayStack();
	}
}

//*******************************************************************************************
// printStory Function									    *
//											    *
// This function prints out a story using using the top nodes of the noun and verb stack    *
// and popping through them.								    *
//*******************************************************************************************

void printStory(DynamicStack& stack1, DynamicStack& stack2)
{
	int stack1Size = stack1.stackSize(),  // Variable to hold the size of the first stack.
		stack2Size = stack2.stackSize();  // Variable to hold the size of the second stack.

	// If there are 5 values in the noun stack, and 4 values in the verb stack, print the story.
	if (stack1Size >= 5 && stack2Size >= 4)
	{
		cout << "\n\n**You Customer Story**\n\n";

		cout << "A long time ago in a land they called " << stack1.printNextValue() << " there was a " << stack1.printNextValue() << " who liked to " << stack2.printNextValue() << ".\n";
		cout << "There was also a " << stack1.printNextValue() << " which was known to the people to " << stack2.printNextValue() << " often.\n";
		cout << "There was a mynth in the land that if you " << stack2.printNextValue() << " better than a " << stack1.printNextValue() << " you will get a " << stack1.printNextValue() << "!\n";
		cout << "In the end the people of this odd land just wanted to " << stack2.printNextValue() << " together.\n\n";
		cout << "The End.\n";
	}
	// Else, if there are not enough nouns but there are enough verbs print an error message.
	else if (stack1Size < 5 && stack2Size >= 4)
	{
		cout << "\nError, there is currently '" << stack1Size << "' values in the noun stack.\n";
		cout << "Please enter at least 5 nouns to complete the story.\n";
	}
	// Else, if there are not enough verbs but there are enough nouns print an error message.
	else if (stack1Size >= 5 && stack2Size < 4)
	{
		cout << "\nError, there is currently '" << stack2Size << "' values in the verb stack.\n";
		cout << "Please enter at least 4 verbs to complete the story.\n";
	}
	else
	{
		cout << "\nError, there is currently '" << stack1Size << "' values in the noun stack, and '" << stack2Size << "' values in the verb stack.\n";
		cout << "Please enter at least 5 nouns and 4 verbs to complete the story.\n";
	}
}

//*******************************************************************************************
// goodbyeMessage Function								    *
//											    *
// This function prints a goodbye message used at the exit of the program. 		    *
//*******************************************************************************************

void goodbyeMessage()
{
	cout << "\nHope the story was all you imagined it would be. Goodbye!\n";
}

//*******************************************************************************************
// menuChoiceError Function								    *
//											    *
// This function prints an error message to inform user that their selection is not valid.  *
//*******************************************************************************************

void menuChoiceError(int& choice)
{
	cout << "\nError, '" << choice << "' is not a menu option.\n";
}



//*******************************************************
//		INPUT VALIDATION FUNCTIONS		*
//*******************************************************


//*******************************************************************************************
// isInteger Function									    *
//											    *
// This functions takes checks if the input is an integer, and prompts for another input    *
// if it is not.									    *
//*******************************************************************************************

void isInteger(int& input)
{
	// While input is not an integer, prompt the user for another choice.
	while (cin.fail())
	{
		cout << "\nError, input must be a number.\n";
		cin.clear();
		cin.ignore(10, '\n');
		cout << "Please enter a number: ";
		cin >> input;
	}
}
