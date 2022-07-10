#include <iostream>
#include "Chess_Pieces.h"

Bishop::Bishop(Coordinates cor, Color col)
	:Chess_Pieces(cor,col)
{
	tags.push_back("B");
	tags.push_back("Bishop");
	tags.push_back("Camel");
	tags.push_back("Unt");
}

bool Bishop::valid(Coordinates New)
{
	if (!New.isValid())
	{
		std::cout << "Error:Invalid coordinates supplied to bool Bishop::valid(),returning false\n";
		return false;
	}
	if (coordinates.isDiagnolwith(New))
	{
		return true;
	}
	return false;
}

