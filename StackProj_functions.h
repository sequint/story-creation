// Specification file for the program functions.

#pragma once

#include <string>
#include "DynamicStack.h"
using namespace std;

// Global Variables - constant menu choices
const int PUSH_NOUN = 1,
	  POP_NOUN = 2,
	  PUSH_VERB = 3,
	  POP_VERB = 4,
	  CONCATENATE = 5,
	  ADD_S = 6,
	  DISPLAY_BOTH = 7,
	  MAKE_STORY = 8,
	  EXIT_PROGRAM = 9;

// Input Functions
void menu(int&);
void pushValue(DynamicStack&, string&);
void popValue(DynamicStack&, string&);
void concateValues(DynamicStack&, string&);
void addSVal(DynamicStack&, string&);

// Output Functions
void displayStacks(DynamicStack&, DynamicStack&, string&, string&);
void printStory(DynamicStack&, DynamicStack&);
void goodbyeMessage();
void menuChoiceError(int&);

// Input Validation Functions
void isInteger(int&);
