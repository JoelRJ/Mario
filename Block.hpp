/*********************************************************************
** Program name: Block.hpp
** Author: Joel Johnson
** Date: 3/4/19
** Description: The header file for the class Block.
** Block is the normal ground. It inherits Spaces member variables and 
** member functions.
*********************************************************************/

#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Space.hpp"

class Block : public Space
{
protected:

public:
	SpaceType getType();
	string getChar();
};

#endif