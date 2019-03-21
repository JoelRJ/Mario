/*********************************************************************
** Program name: Space.hpp
** Author: Joel Johnson
** Date: 3/4/19
** Description: The header file for the class Space.
** Space is the base class for Spike, Questionblock, Flag, Door, and Block 
** classes. It holds virtual functions and member variables which all
** other classes inherit. 
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
using std::string;

// Declaring the Space class, with Space type enum 
enum SpaceType {BLOCK, QUESTIONBLOCK, SPIKE, DOOR, FLAG};

class Space
{
protected:
	SpaceType type;
	Space *top;
	Space *right;
	Space *left;
	Space *bottom;
	
	Space *next;
	Space *prev;
	
	bool hasMario;
	bool hasKey;
	bool hasStar;
	bool hasGoomba;
	bool hasMushroom;
public:
	Space();
	
	// Pure virtual functions 
	virtual SpaceType getType() = 0;
	virtual string getChar() = 0;
	
	void setMario();
	bool checkMario();
	void removeMario();
	
	void removeItems();
	
	void setMushroom();
	bool checkMushroom();
	
	void setKey();
	bool checkKey();
	
	void setStar();
	bool checkStar();
	
	void setGoomba();
	bool checkGoomba();
	
	void setTop(Space *);
	Space *getTop();
	void setBottom(Space *);
	Space *getBottom();
	void setRight(Space *);
	Space *getRight();
	void setLeft(Space *);
	Space *getLeft();
	
	void setNext(Space *);
	Space *getNext();
	void setPrev(Space *);
	Space *getPrev();
};

#endif