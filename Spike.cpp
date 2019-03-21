/*********************************************************************
** Program name: Spike.cpp
** Author: Joel Johnson
** Date: 3/11/19
** Description: The implementation file for the class Spike.
** Spike class, inherits Space member variables and functions.
*********************************************************************/

#include "Spike.hpp"

/**********************************
** Returns type SPIKE
**********************************/
SpaceType Spike::getType()
{
	return SPIKE;
}

/*********************************
** Returns string to print to map.
** If Mario occupies Space, returns
** M to indicate such.
*********************************/
string Spike::getChar()
{
	if (hasMario)
	{
		return "M ";
	}
	else
	{
		return "* ";
	}
}