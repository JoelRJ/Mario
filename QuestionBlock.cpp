/*********************************************************************
** Program name: QuestionBlock.cpp
** Author: Joel Johnson
** Date: 3/1/19
** Description: The header file for the class QuestionBlock.
** QuestionBlock class, inherits Space member variables and functions.
*********************************************************************/

#include "QuestionBlock.hpp"

/**********************************
** Returns type QUESTIONBLOCK
**********************************/
SpaceType QuestionBlock::getType()
{
	return QUESTIONBLOCK;
}

/*********************************
** Returns string to print to map.
** If Mario occupies Space, returns
** M to indicate such.
*********************************/
string QuestionBlock::getChar()
{
	if (hasMario)
	{
		return "M ";
	}
	else if (!hasMushroom && !hasStar)
	{
		return "■ ";
	}
	else
	{
		return "? ";
	}
}