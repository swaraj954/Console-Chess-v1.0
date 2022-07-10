#pragma once
#include "Chess_Pieces.h"
//NTT --> Nothing to Test
 

class Player
{
public:

	//What does a player have? A set of 16 'Chess_pices' of a single 'Color'!
	Player(std::vector<Chess_Pieces*>, Color);//Implemented - Unused

	//We will need a default constructor as we cannot initilaize player object with parameter
	//in the Gameboard class
	Player();//Implemented - Nothing to Test

	//Give the player the pieces its needs
	void supply_pieces(std::vector<Chess_Pieces*>);//Implemented - Tested

	//The player has a certain color
	void assign_color(Color c);//Implemented - Tested

	//Obvious, return the color of the player
	Color get_color();

	//A function for testing purposes
	void test();//Showing expected results after gameboard constructor is just executed
	//Reminder: This function has been modified, test again

	//returns all the pieces player has still left in the game
	std::vector<Chess_Pieces*> get_alive_pieces();//Implemented -- Not Tested(NTT)

	//returns all the pieces the player has lost
	std::vector<Chess_Pieces*> get_dead_pieces();//Implemented -- Not Tested(NTT)

	//Removes the piece from alive pieces and adds it do dead pieces, in short it kills the piece at coordinates kill cord
	//also returns a pointer to the chess_piece that was killed, returns NULL if piece does not exist at kill_cord
	Chess_Pieces* kill(Coordinates kill_cord);// Lightly Tested -- Apparently Working

	//Revives the piece that was most recently killed, this function is exclusively written for
	//the Gameboard::incheck(Coordinates,Coordinates,Color) function
	void revive_last_killed();//Lightly Tested -- Seems to be working

	//Note:Remeber to add dead pieces as they are killed and to remove them for alive pieces

private:
	std::vector<Chess_Pieces*> alive;
	std::vector<Chess_Pieces*> dead;
	Color player_color;

};
