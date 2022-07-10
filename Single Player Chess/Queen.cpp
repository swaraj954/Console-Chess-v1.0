#include <iostream>
#include "Chess_Pieces.h"

Queen::Queen(Coordinates cor,Color col)
	:Chess_Pieces(cor,col)
{
	tags.push_back("Q");
	tags.push_back("Queen");
	tags.push_back("Rani");
	tags.push_back("Rajakibibi");//lol :)
}

bool Queen::valid(Coordinates New)
{
	if (!New.isValid())
	{
		std::cout << "Error:Invalid coordinates supplied to bool Queen::valid(),returning false\n";
		return false;
	}
	if (this->coordinates.isDiagnolwith(New) || this->coordinates.isVerticalwith(New) || this->coordinates.isHorizontalwith(New))
	{
		return true;
	}
	return false;
}