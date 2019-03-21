/*********************************************************************
** Program name: Menu.hpp
** Author: Joel Johnson
** Date: 1/25/19
** Description: Header file for the Class Menu.
** The menu class allows the user to add an initial prompt, add options for 
** the user to select, allow the user to choose a number between two numbers,
** and tell the program if the user will continue or quit (T/F). 
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
using std::string;
#include <vector>
using std::vector;

// The class Menu defined member variables and methods
class Menu
{
private:
	string prompt;
	int numberOptions;
	vector<string> options;

public:
	Menu();
	Menu(int numberOptionsIn, string promptIn);
	~Menu();
	int chooseNumber(int min, int max, string promptIn);
	void setPrompt(string promptIn);
	void setNumberOptions(int numberOptionsIn);
	void addOption(string optionIn);
	void printMenu();
	
	bool continuePrompt(string promptIn);
};

#endif

