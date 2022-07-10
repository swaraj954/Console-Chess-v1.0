#include <vector>
#include <iostream>
#include "Player.h"
#include "Chess_Pieces.h"


Player::Player(std::vector<Chess_Pieces*> p, Color c)
{
	alive = p;
	player_color = c;
}

Player::Player()
{
	//do nothing, everything else will be taken care of in the Gamboard constructor
}

void Player::supply_pieces(std::vector<Chess_Pieces*> p)
{
	alive = p;
}

void Player::assign_color(Color c)
{
	player_color = c;
}

Color Player::get_color()
{
	return player_color;
}

void Player::test()
{
	std::cout << "Pieces that are alive:\n";
	for (int i = 0; i < alive.size(); i++)
	{
		std::cout <<"Color: "<< alive[i]->getcolor()<<"\n";
		std::cout <<"Name of piece: "<< alive[i]->get_tags()[1]<<"\n";
		std::cout << "Coordinates:(" << alive[i]->get_coordinates().get_x_coordinate() << ","
			                         << alive[i]->get_coordinates().get_y_coordinate() << ")\n";
		std::cout << "----------------------------------------\n";
	}
	std::cout << "Pieces that are dead:\n";
	for (int i = 0; i < dead.size(); i++)
	{
		std::cout << "Color: " << dead[i]->getcolor() << "\n";
		std::cout << "Name of piece: " << dead[i]->get_tags()[1] << "\n";
		std::cout << "Coordinates:(" << dead[i]->get_coordinates().get_x_coordinate() << ","
			<< dead[i]->get_coordinates().get_y_coordinate() << ")\n";
		std::cout << "----------------------------------------\n";
	}
}

std::vector<Chess_Pieces*> Player::get_alive_pieces()
{
	return alive;
}

std::vector<Chess_Pieces*> Player::get_dead_pieces()
{
	return dead;
}

Chess_Pieces* Player::kill(Coordinates kill_cord)
{
	for (int i = 0; i < alive.size(); i = i + 1)
	{
		if (alive[i]->get_coordinates() == kill_cord)
		{
			Chess_Pieces* killed = alive[i];
			alive[i] = alive[alive.size() - 1];
			alive.pop_back();
			dead.push_back(killed);
			return killed;
		}
	}
	std::cout << "Warning: Player::kill(Coordinates) recieved questionable coordinates\n";
	return NULL;
}

void Player::revive_last_killed()
{
	if (dead.size() == 0)
	{
		std::cout << "Player::revive_last_killed() : There are no dead pieces!!\n";
		return;
	}
	alive.push_back(dead[dead.size() - 1]);
	dead.pop_back();
}