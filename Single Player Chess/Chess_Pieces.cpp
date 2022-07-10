#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include "Chess_Pieces.h"
#include "Coordinates.h"

void Chess_Pieces::move(Coordinates New)
{
	coordinates = New;
}


std::vector<std::string> Chess_Pieces::get_tags()
{
	return tags;
}

bool Chess_Pieces::is(std::string name)
{
	for (int i = 0; i < tags.size(); i++)
	{
		if (name.size() == tags[i].size())
		{
			bool match = true;
			for (int x = 0; x < name.size(); x++)
			{
				if (toupper(name[x]) != toupper(tags[i][x]))
				{
					match = false;
					break;
				}
			}
			if (match)
			{
				return true;
			}
		}
	}
	return false;
}


Chess_Pieces::Chess_Pieces(Coordinates c, Color col)
	:coordinates(c)
{
	color = col;
}

Color Chess_Pieces::getcolor()
{
	return color;
}

Coordinates Chess_Pieces::get_coordinates()
{
	return coordinates;
}