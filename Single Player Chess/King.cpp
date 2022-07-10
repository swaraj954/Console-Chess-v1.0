#include <iostream>
#include "Chess_Pieces.h"
#include "Coordinates.h"

King::King(Coordinates cor,Color col)
	:Chess_Pieces(cor,col)
{
	tags.push_back("K");
	tags.push_back("Raja");
	tags.push_back("King");
	
}

bool King::valid(Coordinates New)
{
	if (!New.isValid())
	{
		std::cout << "Error:Invalid coordinates supplied to bool King::valid(),returning false\n";
		return false;
	}
	if (coordinates.isAdjacentwith(New))
	{
		return true;
	}
	else
	{
		return false;
	}
}