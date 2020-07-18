// Main function file for Stack Project.

#include <iostream>
#include <string>
#include "DynamicStack.h"
#include "StackProj_functions.h"
using namespace std;

int main()
{
	DynamicStack noun;  	// The noun stack.
	DynamicStack verb;  	// The verb stack.

	int choice;		 // Variable that holds the menu choice.
	string nounSp = "Noun",	 // Variable that is used for noun print message specification.
	       verbSp = "Verb";  // Variable that is used for verb print message specification.

	// While the choice is not EXIT_PROGRAM, continue printing the menu.
	do
	{
		// Print the menu, get the user's choice.
		menu(choice);

		// Perform the user's choice.
		switch (choice)
		{
		case PUSH_NOUN:
			pushValue(noun, nounSp);
			break;
		case POP_NOUN:
			popValue(noun, nounSp);
			break;
		case PUSH_VERB:
			pushValue(verb, verbSp);
			break;
		case POP_VERB:
			popValue(verb, verbSp);
			break;
		case CONCATENATE:
			concateValues(noun, nounSp);
			break;
		case ADD_S:
			addSVal(noun, nounSp);
			break;
		case DISPLAY_BOTH:
			displayStacks(noun, verb, nounSp, verbSp);
			break;
		case MAKE_STORY:
			printStory(noun, verb);
			break;
		case EXIT_PROGRAM:
			goodbyeMessage();
			break;
		default:
			menuChoiceError(choice);
			break;
		}

	} while (choice != EXIT_PROGRAM);

	return 0;
}
