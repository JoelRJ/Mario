/*********************************************************************
** Program name: Board.cpp
** Author: Joel Johnson
** Date: 3/4/19
** Description: Implementation file for the class Board.
** Board holds the game logic, printing the board, checking spaces,
** printing Mario's health and inventory, and seeing if Mario has won.
*********************************************************************/

#include "Board.hpp"
#include "Menu.hpp"
#include "inputInteger.hpp"

#include <iostream>
using std::cout;
using std::endl;

/*********************************************************************
DEFAULT CONSTRUCTOR
*********************************************************************/
Board::Board()
{
	won = false;
	marioHealth = 1;
	
	int spaceCount = 0;

	// 0, 0 (block)
	board = new Block;
	head = board;
	head->setNext(new QuestionBlock);
	Space *iter = head->getNext();
	head->setRight(iter);

	// 0, 1 (?-block)
	board = head->getNext();
	board->setMushroom();
	board->setPrev(head);
	board->setLeft(head);
	board->setNext(new Block);
	board->setRight(board->getNext());

	// 0, 2 (block)
	iter = board;
	board = board->getNext();
	board->setPrev(iter);
	board->setLeft(iter);
	
	// 0, 3 (spike)
	board->setNext(new Spike);
	board->setRight(board->getNext());
	iter = board;
	board = board->getNext();
	board->setPrev(iter);
	board->setLeft(iter);
	
	// 0, 4 (spike)
	board->setNext(new Spike);
	board->setRight(board->getNext());
	iter = board;
	board = board->getNext();
	board->setPrev(iter);
	board->setLeft(iter);
	
	// 0, 5 (?-block)
	board->setNext(new QuestionBlock);
	board->setRight(board->getNext());
	iter = board;
	board = board->getNext();
	board->setStar();
	board->setPrev(iter);
	board->setLeft(iter);
	
	// 0, 6 (spike)
	board->setNext(new Spike);
	board->setRight(board->getNext());
	iter = board;
	board = board->getNext();
	board->setPrev(iter);
	board->setLeft(iter);
	
	// 0, 7 (block)
	board->setNext(new Block);
	board->setRight(board->getNext());
	iter = board;
	board = board->getNext();
	board->setPrev(iter);
	board->setLeft(iter);
	
	// 1, 0 
	head->setBottom(new Block);
	board->setNext(head->getBottom());
	iter = board;
	board = head->getBottom();
	board->setPrev(iter);
	board->setNext(new Block);
	board->setTop(head);
	
	// 1, 1
	iter = board;
	board = iter->getNext();
	board->setGoomba();
	iter->setRight(board);
	(head->getNext())->setBottom(board);
	board->setTop(head->getNext());
	board->setPrev(iter);
	board->setLeft(iter);
	board->setNext(new Door);
	board->setRight(board->getNext());
	
	// 1, 2
	iter = board;
	board = board->getNext();
	((head->getNext())->getNext())->setBottom(board);
	board->setTop((head->getNext())->getNext());
	board->setPrev(iter);
	board->setLeft(iter);
	board->setNext(new Spike);
	board->setRight(board->getNext());
	
	// 1, 3
	iter = board;
	board = iter->getNext();
	iter->setRight(board);
	(((head->getNext())->getNext())->getNext())->setBottom(board);
	board->setTop(((head->getNext())->getNext())->getNext());
	board->setPrev(iter);
	board->setLeft(iter);
	board->setNext(new Spike);
	board->setRight(board->getNext());
	
	// 1, 4
	iter = board;
	board = iter->getNext();
	iter->setRight(board);
	((((head->getNext())->getNext())->getNext())->getNext())->setBottom(board);
	board->setTop(((((head->getNext())->getNext())->getNext())->getNext()));
	board->setPrev(iter);
	board->setLeft(iter);
	board->setNext(new Door);
	board->setRight(board->getNext());
	
	// 1, 5
	iter = board;
	board = iter->getNext();
	iter->setRight(board);
	(((((head->getNext())->getNext())->getNext())->getNext())->getNext())->setBottom(board);
	board->setTop(((((head->getNext())->getNext())->getNext())->getNext())->getNext());
	board->setPrev(iter);
	board->setLeft(iter);
	board->setNext(new Spike);
	board->setRight(board->getNext());
	
	// 1, 6
	iter = board;
	board = iter->getNext();
	iter->setRight(board);
	(((head->getBottom())->getPrev())->getPrev())->setBottom(board);
	board->setTop(((head->getBottom())->getPrev())->getPrev());
	board->setPrev(iter);
	board->setLeft(iter);
	board->setNext(new Flag);
	board->setRight(board->getNext());
	
	// 1, 7
	iter = board;
	board = iter->getNext();
	iter->setRight(board);
	((head->getBottom())->getPrev())->setBottom(board);
	board->setTop(((head->getBottom())->getPrev()));
	board->setPrev(iter);
	board->setLeft(iter);
	board->setNext(head);

	// Put Mario on the board
	(head->getBottom())->setMario();
}

/*********************************************************************
** DESTRUCTOR - This will delete the board from memory
*********************************************************************/
Board::~Board()
{
	board = head->getNext();
	while (board->getNext() != head)
	{
		Space *garbage = board;
		board = board->getNext();
		delete garbage;
	}
	delete board;
	delete head;
}

/*********************************************************************
** printLegend() prints the map legend, hard-coded.
*********************************************************************/
void Board::printLegend()
{
	cout << "Map Legend:" << endl;
	cout << "M = Mario\n■ = Ground\n? = Question Block\n[] = Door\n* = Spike Block\n⌠ = Flag" << endl;
}


/*********************************************************************
** Move checks each linked pointer to a space around it to see the 
** possible options for moving Mario, and adds those options to the 
** menu, which is printed out. 
*********************************************************************/
void Board::move()
{	
	while (!board->checkMario())
	{
		board = board->getNext();
	}
	
	Menu mario(0, "Select a direction to move Mario.");
	int count = 0;
	
	// Add options for Mario to move
	if (board->getTop() != nullptr)
	{
		mario.addOption("Move up.");
		count++;
	}
	if (board->getLeft() != nullptr)
	{
		mario.addOption("Move left.");
		count++;
	}
	if (board->getRight() != nullptr)
	{
		mario.addOption("Move right.");
		count++;
	}
	if (board->getBottom() != nullptr)
	{
		mario.addOption("Move bottom.");
		count++;
	}
	
	// Print menu and capture user input 
	mario.printMenu();
	int selection = -1;
	while (selection < 1 || selection > count)
	{
		selection = inputInteger();
	}	
	
	// Move Mario to selected direction 
	count = 0;
	Space *iter = board;
	if (board->getTop() != nullptr && ++count == selection)
	{
		board->removeMario();
		board = iter->getTop();
	}
	if (board->getLeft() != nullptr && ++count == selection)
	{
		board->removeMario();
		board = iter->getLeft();
	}
	if (board->getRight() != nullptr && ++count == selection)
	{
		board->removeMario();
		board = iter->getRight();
	}
	if (board->getBottom() != nullptr && ++count == selection)
	{
		board->removeMario();
		board = iter->getBottom();
	}
	
	board->setMario();
}

/*********************************************************************
** Checks the landed on space for items, or for Goombas. Adds items to 
** Mario's inventory, or hurts Mario if Goomba. 
*********************************************************************/
void Board::checkSpace()
{
	if (board->getType() == QUESTIONBLOCK)
	{
		
		Menu qBlock(2, "You landed on a Question Block!");
		qBlock.addOption("Hit it!");
		qBlock.addOption("Do nothing.");

		qBlock.printMenu();
		
		int selection = 0;
		while (selection < 1 || selection > 2)
		{
			selection = inputInteger();
		}
		
		if (selection == 1)
		{
			if (board->checkMushroom())
			{
				items.push_back(MUSHROOM);
				cout << "\nYou found a mushroom! It will be stored in your inventory until you get hurt." << endl;
				marioHealth = 2;
				board->removeItems();
			}
			else if (board->checkStar())
			{
				items.push_back(STAR);
				cout << "\nYou found a star! It will protect you next time you touch something that will hurt you! (like spikes)." << endl;
				board->removeItems();
			}
		}
	}
	else if (board->checkGoomba())
	{
		Menu qBlock(2, "You come across a Goomba. What would you like to do?");
		qBlock.addOption("Attack!");
		qBlock.addOption("Run away!");

		qBlock.printMenu();
		
		int selection = 0;
		while (selection < 1 || selection > 2)
		{
			selection = inputInteger();
		}
		
		if (selection == 1)
		{
			if (!items.empty())
			{
				if (items.at(0) == MUSHROOM)
				{
					items.erase(items.begin());
					
				}
				else if (items.at(1) == MUSHROOM)
				{
					items.erase(items.begin() + 1);
				}
				
				cout << "\nThe Goomba fought back! Mario is now little." << endl;
				cout << "As the Goomba was running away, it dropped a key. \nIt will be stored in your inventory until you find a locked door." << endl;
				items.push_back(KEY);
				marioHealth = 1;
			}
			else
			{
				marioHealth = 0;
				cout << "\nThe Goomba fought back, and you don't have a MUSHROOM!" << endl;
			}
		}
	}
	else if (board->getType() == DOOR)
	{
		static int count = 0;
		Menu qBlock(2, "You found a door. What would you like to do?");
		qBlock.addOption("Open it.");
		qBlock.addOption("Do nothing.");

		qBlock.printMenu();
		
		int selection = 0;
		while (selection < 1 || selection > 2)
		{
			selection = inputInteger();
		}
		
		if (selection == 1)
		{
			if (count == 0 && !items.empty() && items.at(0) == KEY)
			{
				cout << "\nYou unlocked the door with your key!" << endl;
				items.pop_back();
				
				board->removeMario();
				
				board = board->getNext();
				
				while (board->getType() != DOOR)
				{
					board = board->getNext();
				}
				
				board->setMario();
				count++;
			}
			else if (count == 0)
			{
				cout << "\nYou need a key to get through the door! There may be a Goomba walking around who has it..." << endl;
			}
			else
			{
				board->removeMario();
				
				board = board->getNext();
				
				while (board->getType() != DOOR)
				{
					board = board->getNext();
				}
				
				board->setMario();
			}
		}
	}
	else if (board->getType() == FLAG)
	{
		won = true;
	}
	else if (board->getType() == SPIKE)
	{
		if (items.empty())
		{
			cout << "\nMario touched the spikes without protection!" << endl;
			marioHealth = 0;	
		}
		else
		{
			vector<string> itemNames = {"Mushroom", "Key", "Star"};
			cout << "\nMario used his " << itemNames.at(items.at(0)) << " item!" << endl;
			items.pop_back();
			marioHealth = 1;
		}
	}
}

/*********************************************************************
** Prints the contents of the board each turn as well as Mario's status.
*********************************************************************/
void Board::printBoard()
{
	// Set upper boundary line
	cout << endl << ' ';
	for(int column = 0; column < 8 * 2; column++)
	{
		cout << '-';
	}
	cout << endl;
	
	board = head;
	
	for(int i = 0; i < 2; i ++)
	{
		cout << "|";
		
		for(int j = 0; j < 8; j++)
		{
			cout << board->getChar();
			board = board->getNext();
		}
		cout << "|" << endl;
	}

	// Set lower boundary line
	cout << ' ';
	for(int column = 0; column < 8 * 2; column++)
	{
		cout << '-';
	}
	
	// Print the health of Mario (large or small)
	cout << "\nMario's status: ";
	if (marioHealth == 2)
	{
		cout << "Large";
	}
	else 
	{
		cout << "Small";
	}
}

/*********************************************************************
** Prints the contents Mario's inventory, using a vector of strings
** to get the name of the item. 
*********************************************************************/
void Board::printItems()
{
	vector<string> itemNames = {"Mushroom", "Key", "Star"};
	cout << endl << "Available items: ";
	if (items.empty())
	{
		cout << "NONE";
	}
	else 
	{
		for (int count = 0; count < items.size(); count++)
		{
			cout << itemNames.at(items.at(count)) << "\t";
		}
	}
	cout << endl;
}

/*********************************************************************
** Checks Mario's health, and returns the bool if greater than 0 (alive).
*********************************************************************/
bool Board::isAlive()
{
	if (marioHealth > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*********************************************************************
** Won is set to false at the beginning of the game, and is set to true
** after the user gets to the flag. 
*********************************************************************/
bool Board::hasWon()
{
	return won;
}