/*********************************************************************
** Program name: Menu.cpp
** Author: Joel Johnson
** Date: 1/25/19
** Description: Implementation file for the Class Menu.
** The menu class allows the user to add an initial prompt, add options for 
** the user to select, allow the user to choose a number between two numbers,
** and tell the program if the user will continue or quit (T/F). 
*********************************************************************/

#include "Menu.hpp"
#include "inputInteger.hpp"

#include <iostream>
using std::cout;
using std::endl;

// Constructor setting the number of options for the user without having a prompt
Menu::Menu()
{
}

// Constructor setting the prompt and the number of options for the user 
Menu::Menu(int numberOptionsIn, string promptIn)
{
	prompt = promptIn;
	numberOptions = numberOptionsIn;
}

// Destrutor to deallocate memory for options
Menu::~Menu()
{

}

// Let user choose number between min and max 
int Menu::chooseNumber(int min, int max, string promptIn)
{
	cout << endl <<  promptIn << endl;
	
	int choice = min - 1;
	
	while (choice < min || choice > max)
	{
		choice = inputInteger();
		if (choice < min || choice > max)
		{
			cout << "Enter a number between " << min << " and " << max << "." << endl;
		}
	}
	
	return choice;
}

// Set the prompt for the menu 
void Menu::setPrompt(string promptIn)
{ 
	prompt = promptIn;
}

// Set the size of the menu
void Menu::setNumberOptions(int numberOptionsIn)
{ 
	numberOptions = numberOptionsIn;
}

// Include the desired option into the options string array
void Menu::addOption(string optionIn)
{
	options.push_back(optionIn);
}

// Print the menu (prompt and options for user )
void Menu::printMenu()
{
	if (prompt != "")
	{
		cout << endl << prompt << endl;
	}
		
	for (int count = 0; count < options.size(); count++)
	{
		cout << count + 1 << ". ";
		cout << options.at(count) << endl;	
	}
}

// Return true or false to continue playing
bool Menu::continuePrompt(string promptIn)
{
	// Initialize variable to -1 to prevent garbage values; create counter variable
	int selection = -1;
	static int counter = 0;

	// Initial start program menu screen, validating input to only receive 1 or 2
	while (selection != 1 && selection != 2)
	{
		if (counter == 0)
		{
			cout << endl << "1. Play " << promptIn << endl;
			cout << "2. Exit " << promptIn << endl;
			selection = inputInteger();
			counter++;
		}
		else
		{
			cout << endl << "1. Play " << promptIn << " again!" << endl;
			cout << "2. End " << promptIn << endl;
			selection = inputInteger();			
		}
	}
	
	switch (selection)
	{
		case 1: return true;
			break;
		case 2: return false;
			break;
	}
}

