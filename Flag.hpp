/*********************************************************************
** Program name: Flag.hpp
** Author: Joel Johnson
** Date: 3/11/19
** Description: The header file for the class Flag.
** Flag class (final destination for Mario, inherits Space 
** member variables and functions.
*********************************************************************/

#ifndef FLAG_HPP
#define FLAG_HPP

#include "Space.hpp"

class Flag : public Space
{
protected:

public:
	SpaceType getType();
	string getChar();
};

#endif