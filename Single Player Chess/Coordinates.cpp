#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include <cctype>
#include "Coordinates.h"

Coordinates::Coordinates(int X, int Y)
{
	x = X-1;
	y = Y-1;
	if (X > 8 || Y > 8|| X<1 || Y<1)
	{
		std::cout << "Error,invalid coordinates supplied to Coordinates class\n";
	}
}

Coordinates::Coordinates(Letter_Coordinate X, int Y)
{
	x = X-1;
	y = Y-1;
	if (X > 8 || Y > 8 || X<1 || Y<1)
	{
		std::cout << "Error,invalid coordinates supplied to Coordinates class\n";
	}
}

bool Coordinates::isValid()
{
	if (x < 8 && y < 8 && x>-1 && y>-1)
	{
		return true;
	}
	return false;
}

bool Coordinates::isAdjacentwith(Coordinates New)
{
	if ( isValid() && New.isValid() )
	{
		if (std::abs(x - New.x) <= 1 && std::abs(y - New.y) <= 1 )
		{
			return true;
		}
	}
	else
	{
		std::cout << "ERROR:Invalid coordinates supplied to isAdjacentwith()\n";
	}
	return false;
}

bool Coordinates::isDiagnolwith(Coordinates New)
{
	if (isValid() && New.isValid())
	{
		if (std::abs(x - New.x) == std::abs(y - New.y))
		{
			return true;
		}
	}
	else
	{
		std::cout << "ERROR:Invalid supplied coordinates supplied to isDiagnolwith()\n";
	}
	return false;
}

bool Coordinates::isVerticalwith(Coordinates New)
{
	if (isValid() && New.isValid())
	{
		if (x == New.x)
		{
			return true;
		}
	}
	else
	{
		std::cout << "ERROR:Invalid Coordinates supplied to isVerticalwith()\n";
	}
	return false;
}

bool Coordinates::isHorizontalwith(Coordinates New)
{
	if (isValid() && New.isValid())
	{
		if (y == New.y)
		{
			return true;
		}
	}
	else
	{
		std::cout << "ERROR:Invalid Supplied to isHorizontalwith()\n";
	}
	return false;
}

int Coordinates::get_x_coordinate()
{
	return x;
}

int Coordinates::get_y_coordinate()
{
	return y;
}

bool Coordinates::operator ==(Coordinates New)
{
	return (this->get_x_coordinate() == New.get_x_coordinate()) && (this->get_y_coordinate() == New.get_y_coordinate());
}

Coordinates::Coordinates(std::vector<Coordinates> vec)
{
	x = vec[0].get_x_coordinate();
	y = vec[0].get_y_coordinate();
}

Coordinates::Coordinates(std::string user_input)
{
	if (user_input.length() == 2)
	{
		int ascii_value = int(toupper(user_input[0]));
		if (isalpha(user_input[0]) && ascii_value<=72)
		{
			x = ascii_value - 65;
		}
		else if (isdigit(user_input[0]) && ascii_value<=56 && ascii_value>48)
		{
			x = ascii_value - 49;
		}
		else
		{
			std::cout << "Error: Coordinates(std::string user_intput) recieved incorrect input\n";
			//std::cout << "Setting x and y to 0\n";
			x = 0;
			y = 0;
		}
		ascii_value = int(user_input[1]);
		if (isdigit(user_input[1]) && ascii_value>48 && ascii_value<=56)
		{
			y = ascii_value - 49;
		}
		else
		{
			std::cout << "Error: Coordinates(std::string user_intput) recieved incorrect input\n";
			//std::cout << "Setting x and y to 0\n";
			x = 0;
			y = 0;
		}
	}
	else
	{
		std::cout << "Error: Coordinates(std::string user_intput) recieved incorrect input\n";
		std::cout << "Setting x and y to 0\n";
		x = 0;
		y = 0;
	}
}
