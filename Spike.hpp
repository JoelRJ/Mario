/*********************************************************************
** Program name: Spike.hpp
** Author: Joel Johnson
** Date: 3/11/19
** Description: The header file for the class Spike.
** Spike class, inherits Space member variables and functions.
*********************************************************************/

#ifndef SPIKE_HPP
#define SPIKE_HPP

#include "Space.hpp"

class Spike : public Space
{
protected:

public:
	SpaceType getType();
	string getChar();
};

#endif