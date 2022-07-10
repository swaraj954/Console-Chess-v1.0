#include <iostream>
#include <cmath>
#include "Chess_Pieces.h"

Pawn::Pawn(Coordinates cor, Color col)
	:Chess_Pieces(cor,col)
{
	tags.push_back("P");
	tags.push_back("Pawn");
	tags.push_back("Sipahi");
}

bool Pawn::valid(Coordinates New)
{
	if (!New.isValid())
	{
		std::cout << "Error:Invalid coordinates supplied to bool Pawn::valid(),returning false\n";
		return false;
	}

	bool vertical_distance_one   = (New.get_y_coordinate() - coordinates.get_y_coordinate() == 1);
	bool horizontal_distance_one = (New.get_x_coordinate() - coordinates.get_x_coordinate() == 1);
	bool horizonatal_distance_negative_one = (New.get_x_coordinate() - coordinates.get_x_coordinate() == -1);
	bool horizontal_distance_zero = (New.get_x_coordinate() == coordinates.get_x_coordinate());
	if (vertical_distance_one && (horizonatal_distance_negative_one ||horizontal_distance_zero || horizontal_distance_one))
	{
		return true;
	}
	return false;
}