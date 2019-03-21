/*********************************************************************
** Program name: Space.cpp
** Author: Joel Johnson
** Date: 3/4/19
** Description: The implementation file for the class Space.
** Space is the base class for Spike, Questionblock, Flag, Door, and Block 
** classes. It holds virtual functions and member variables which all
** other classes inherit. 
*********************************************************************/
	
#include "Space.hpp"

/*********************************************************************
** Constructor: sets all member variables to true or false.
*********************************************************************/
Space::Space()
{
	next = nullptr;
	prev = nullptr;
	top = nullptr;
	bottom = nullptr;
	left = nullptr;
	right = nullptr;
	
	hasMario = false;
	hasKey = false;
	hasGoomba = false;
	hasMushroom = false;
	hasStar = false;
}

/*********************************************************************
** Set Mario to this space on the board.
*********************************************************************/
void Space::setMario()
{
	hasMario = true;
}

/*********************************************************************
** Return true or false if Mario is on this space or not. 
*********************************************************************/
bool Space::checkMario()
{
	return hasMario;
}

/*********************************************************************
** Remove Mario from this space, set hasMario to false. 
*********************************************************************/
void Space::removeMario()
{
	hasMario = false;
}

/*********************************************************************
** Removes all items from the space on the board. Completed after Mario
** interacts with Space.
*********************************************************************/
void Space::removeItems()
{
	hasGoomba = false;
	hasStar = false;
	hasKey = false;
	hasMushroom = false;
}

/*********************************************************************
** Sets hasMushroom to true, setting mushroom on this space on board.
*********************************************************************/
void Space::setMushroom()
{
	hasMushroom = true;
}

/*********************************************************************
** Checks to see if the mushroom item is on the space of the board.
** Returns a bool.
*********************************************************************/
bool Space::checkMushroom()
{
	return hasMushroom;
}

/*********************************************************************
** Sets hasKey to true, setting key on this space on board.
*********************************************************************/
void Space::setKey()
{
	hasKey = true;
}

/*********************************************************************
** Checks to see if the key item is on the space of the board.
** Returns a bool.
*********************************************************************/
bool Space::checkKey()
{
	return hasKey;
}

/*********************************************************************
** Sets hasStar to true, setting star on this space on board.
*********************************************************************/
void Space::setStar()
{
	hasStar = true;
}

/*********************************************************************
** Checks to see if the star item is on the space of the board.
** Returns a bool.
*********************************************************************/
bool Space::checkStar()
{
	return hasStar;
}

/*********************************************************************
** Sets hasGoomba to true, setting Goomba on this space on board.
*********************************************************************/
void Space::setGoomba()
{
	hasGoomba = true;
	this->setKey();
}

/*********************************************************************
** Checks to see if the Goomba bad guy is on the space of the board.
** Returns a bool.
*********************************************************************/
bool Space::checkGoomba()
{
	return hasGoomba;
}

/*********************************************************************
** Sets the pointer for the Space above current location. Stored in top,
** which is a pointer to a Space object.
*********************************************************************/
void Space::setTop(Space *topIn)
{
	top = topIn;
}

/*********************************************************************
** Returns the pointer to the class for the space above current location.
*********************************************************************/
Space *Space::getTop()
{
	return top;
}

/*********************************************************************
** Sets the pointer for the Space below current location. Stored in bottom,
** which is a pointer to a Space object.
*********************************************************************/
void Space::setBottom(Space *bottomIn)
{
	bottom = bottomIn;
}

/*********************************************************************
** Returns the pointer to the class for the space below current location.
*********************************************************************/
Space *Space::getBottom()
{
	return bottom;
}

/*********************************************************************
** Sets the pointer for the Space right of current location. Stored in right,
** which is a pointer to a Space object.
*********************************************************************/
void Space::setRight(Space *rightIn)
{
	right = rightIn;
}

/*********************************************************************
** Returns the pointer to the class for the space right of current location.
*********************************************************************/
Space *Space::getRight()
{
	return right;
}

/*********************************************************************
** Sets the pointer for the Space left of current location. Stored in left,
** which is a pointer to a Space object.
*********************************************************************/
void Space::setLeft(Space *leftIn)
{
	left = leftIn;
}

/*********************************************************************
** Returns the pointer to the class for the space left of current location.
*********************************************************************/
Space *Space::getLeft()
{
	return left;
}

// Returns the Space pointer to the next Space in the list 
Space *Space::getNext()
{
	return next;
}

// Sets the next object location in the list
// Accepts a Space pointer, and sets "next"
void Space::setNext(Space *nextIn)
{
	next = nextIn;
}

// Returns the previous Space pointer in the linked list 
Space *Space::getPrev()
{
	return prev;
}

// Sets the previous object location in the list
// Accepts a Space pointer, and sets "prev"
void Space::setPrev(Space *prevIn)
{
	prev = prevIn;
}