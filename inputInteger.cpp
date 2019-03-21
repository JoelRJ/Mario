/*********************************************************************
** Program name: inputInteger.cpp
** Author: Joel Johnson
** Date: 1/11/19
** Description: Implementation file for the function inputInteger().
** This function validates the user input until they return an integer.
*********************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <sstream>
using std::stringstream;

#include <string>
using std::string;

#include "inputInteger.hpp"

// Function inputInteger returns an integer value
int inputInteger()
{
	// Declare variables for return value and input string
	int finalInteger;
	string input;

	// Run while loop until if loop runs, ending inputInteger function
	while(true)
	{
		// Get line from user input and convert to int
		getline(cin, input);
		stringstream convert(input);
		
		// True if input is integer
		if(convert >> finalInteger && !(convert >> input))
		{
		    return finalInteger;
		}
		
		// Clear cin in case of input error, reprompt user for actual integer
		cin.clear();
	    cout << "Please enter an integer: " << endl;
	}
}
