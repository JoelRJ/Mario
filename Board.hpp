/*********************************************************************
** Program name: Board.hpp
** Author: Joel Johnson
** Date: 3/4/19
** Description: Header file for the class Board.
** Board holds the game logic, printing the board, checking spaces,
** printing Mario's health and inventory, and seeing if Mario has won.
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include "Space.hpp"
#include "Block.hpp"
#include "Door.hpp"
#include "QuestionBlock.hpp"
#include "Flag.hpp"
#include "Spike.hpp"

#include <vector>
using std::vector;
#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

enum POWERUPS {MUSHROOM, KEY, STAR};


// The class Board defined member variables and methods
class Board
{
private:
	Space * board;
	Space * head;
	Space * last;
	
	int marioHealth;
	bool won;
	vector<POWERUPS> items;
public:
	Board(); 
	~Board(); 
	
	void printLegend();
	
	void move(); 
	void printBoard();
	void printItems();
	void checkSpace();
	
	bool isAlive();
	bool hasWon();
};

#endif
