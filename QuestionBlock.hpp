/*********************************************************************
** Program name: QuestionBlock.hpp
** Author: Joel Johnson
** Date: 3/11/19
** Description: The header file for the class QuestionBlock.
** QuestionBlock class, inherits Space member variables and functions.
*********************************************************************/

#ifndef QUESTIONBLOCK_HPP
#define QUESTIONBLOCK_HPP

#include "Space.hpp"

class QuestionBlock : public Space
{
protected:

public:
	SpaceType getType();
	string getChar();
};

#endif