/*********************************************************************
** Program name: Block.cpp
** Author: Joel Johnson
** Date: 3/1/19
** Description: The header file for the class Block.
** Block is the normal ground. It inherits Spaces member variables and 
** member functions.
*********************************************************************/

#include "Block.hpp"

/**********************************
** Returns type BLOCK
**********************************/
SpaceType Block::getType()
{
	return BLOCK;
}

/*********************************
** Returns string to print to map.
** If Mario occupies Space, returns
** M to indicate such.
*********************************/
string Block::getChar()
{
	if (hasMario)
	{
		return "M ";
	}
	else
	{
		return "■ ";
	}
}