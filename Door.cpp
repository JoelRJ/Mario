/*********************************************************************
** Program name: Door.cpp
** Author: Joel Johnson
** Date: 3/11/19
** Description: The implementation file for the class Door.
** Door class (is locked, may become unlocked with key) which allows 
** Mario to travel to the matching door on the map.
*********************************************************************/

#include "Door.hpp"


/**********************************
** Returns type DOOR
**********************************/
SpaceType Door::getType()
{
	return DOOR;
}

/*********************************
** Returns string to print to map.
** If Mario occupies Space, returns
** M to indicate such.
*********************************/
string Door::getChar()
{
	if (hasMario)
	{
		return "M ";
	}
	else
	{
		return "[]";
	}
}