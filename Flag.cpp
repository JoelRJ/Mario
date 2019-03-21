/*********************************************************************
** Program name: Flag.cpp
** Author: Joel Johnson
** Date: 3/11/19
** Description: The implementation file for the class Flag.
** Flag class (final destination for Mario, inherits Space 
** member variables and functions.
*********************************************************************/

#include "Flag.hpp"

/**********************************
** Returns type FLAG
**********************************/
SpaceType Flag::getType()
{
	return FLAG;
}

/*********************************
** Returns string to print to map.
** If Mario occupies Space, returns
** M to indicate such.
*********************************/
string Flag::getChar()
{
	if (hasMario)
	{
		return "M ";
	}
	else
	{
		return "⌠ ";
	}
}