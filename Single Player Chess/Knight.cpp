#include <cmath>
#include <iostream>
#include "Chess_Pieces.h"


Knight::Knight(Coordinates cor, Color col)
	:Chess_Pieces(cor,col)
{
	tags.push_back("N");
	tags.push_back("Knight");
	tags.push_back("Ghoda");
	tags.push_back("Horse");
	tags.push_back("pony");
}

bool Knight::valid(Coordinates New)
{
	if (!New.isValid())
	{
		std::cout << "Error:Invalid coordinates supplied to bool Knight::valid(),returning false\n";
		return false;
	}
	bool one_horizontal_distance = ( abs(coordinates.get_x_coordinate() - New.get_x_coordinate()) == 1 );
	bool two_horizontal_distance = ( abs(coordinates.get_x_coordinate() - New.get_x_coordinate()) == 2 );
	bool one_vertical_distance   = ( abs(coordinates.get_y_coordinate() - New.get_y_coordinate()) == 1 );
	bool two_vertical_distance   = ( abs(coordinates.get_y_coordinate() - New.get_y_coordinate()) == 2 );
	if ((one_horizontal_distance && two_vertical_distance) || (two_horizontal_distance && one_vertical_distance))
	{
		return true;
	}
	return false;
}