#include <iostream>
#include "Chess_Pieces.h"

Rook::Rook(Coordinates cor, Color col)
	:Chess_Pieces(cor, col)
{
	tags.push_back("R");
	tags.push_back("Rook");
	tags.push_back("Hathi");
	tags.push_back("HathimeraSathi");
	tags.push_back("Castle");
	tags.push_back("Tower");
}

bool Rook::valid(Coordinates New)
{
	if (!New.isValid())
	{
		std::cout << "Error:Invalid coordinates supplied to bool Rook::valid(),returning false\n";
		return false;
	}
	if (coordinates.isHorizontalwith(New) || coordinates.isVerticalwith(New))
	{
		return true;
	}
	return false;
}

