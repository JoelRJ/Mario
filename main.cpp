/*********************************************************************
** Program name: main.cpp
** Author: Joel Johnson
** Date: 3/4/19
** Description: The main() function.
** This is a text version of Mario, with items to help Mario on his way.
** The main function prints instructions, and accesses the board, which 
** is where most of the logic occurs. 
*********************************************************************/

#include "Menu.hpp"
#include "inputInteger.hpp"
#include "Board.hpp"

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	// Create menu prompts
	cout << endl;
	Menu mainMenu;
	
	int selection = -1;
	string input;
	
	// User selection and perform desired functions 
	while (mainMenu.continuePrompt("Mario: Text Edition"))
	{
		cout << "\nWelcome to Mario: Text Edition!" << endl;
		
		cout << "\n─▄████▄▄░\n▄▀█▀▐└─┐░░\n█▄▐▌▄█▄┘██\n└▄▄▄▄▄┘███\n██▒█▒███▀ \n" << endl;
		
		Board Mario;
		
		cout << "GOAL: Get Mario to the flag within 10 moves! \n\nSteps: \n1. Find the key\n"
		<< "2. Unlock the door \n3. Travel across spikes to the flag without getting hurt.\n";
		
		// Enter to continue
		cout << "\nPress ENTER to continue . . . \n";
		cin.ignore();	
		
		Mario.printLegend();
		
		int steps = 0;
		
		// Main game logic 
		while (!Mario.hasWon() && Mario.isAlive() && steps < 10)
		{
			Mario.printBoard();
			Mario.printItems();
			cout << "Steps left: " << 10 - steps++ << endl;
			Mario.move();
			Mario.checkSpace();
			
		}
		
		// Print ending depending on how game quit
		if (Mario.hasWon())
		{
			cout << "\nCongratulations! You reached the flag! Princess Peach was waiting for you!" << endl;
		}
		else if (!Mario.isAlive())
		{
			cout << "\nMama Mia! Mario died!" << endl;
		}
		else
		{
			cout << "\nYou ran out of steps! Mario couldn't save the Princess!" << endl;
		}
	}
	
	return 0;
}