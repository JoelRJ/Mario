/*********************************************************************
** Program name: Door.hpp
** Author: Joel Johnson
** Date: 3/11/19
** Description: The header file for the class Door.
** Door class (is locked, may become unlocked with key) which allows 
** Mario to travel to the matching door on the map.
*********************************************************************/

#ifndef DOOR_HPP
#define DOOR_HPP

#include "Space.hpp"

class Door : public Space
{
protected:
public:
	SpaceType getType();
	string getChar();
};

#endif