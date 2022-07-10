#pragma once
#include <vector>
#include "Chess_Pieces.h"
#include "Coordinates.h"
#include "Player.h"

class GameBoard
{
public:

	//Returns true if the square at coordinate 'New' is empty, false otherwise
	bool empty(Coordinates);// Tested -- Working

	//prints the gameboard according to the color chosen by the player
	//the color of the player must face the player
	void print(Color player_color);//Implemented -- Tested

	//Prepares board for a new game,sets NULL for empty squares 
	//white always occupies 1st and 2nd row, black occupies last 2 rows
	GameBoard();//Implemented -- Tested

	//Update the Coordinates of the chess piece at 'Old', and place it at 'New',will also take care of pawn promotion and castling
	void move(Coordinates Old, Coordinates New);// In - Progress

	//Is there any piece (of the same color) blocking the move from 'Old' to 'New' 
	//Note:This method will be used in the 'legal; function defined in the public section 
	bool Obstruction_exists(Coordinates Old, Coordinates New);//Tested -- Working

	//Is the Coordinate at New already occupied, does this move result in check for the mover?
	bool legal(Coordinates Old, Coordinates New,Player Current_Player);//In - Progress

    //Checks whether the current position of the board results in check for a specific player
	bool inCheck(Player Current_Player);//Implemented - Lightly Tested -- Seems to Work

	//Checks Whether the next move results in a check or not for a specific player
	bool inCheck(Coordinates Old, Coordinates New,Player Current_Player);//Lightly Tested -- apparently working

	//Checks whether a stalemate situation has occured for any player
	bool stalemate();

	//Checks whether any player is in checkmate  Note: inCheck() && stalemate() == checkmate() ?
	bool checkmate();

	//finds the Coordinates of a certain chess piece(there can be multiple queens,bishop etc in a game)
	std::vector<Coordinates> findPiece(std::string chess_piece_name,Color color);//Implemented -- Tested

	//returns the opposite player of the current player
	Player& get_opposite_player(Player Current_Player);//Implemented -- Not Tested

	//Returns the player playing that color
	Player& get_player(Color c);//Implemented -- Not Tested

	
private:
	//Double dimensional vector representing the 8X8 chessboard
	//Empty Squares are represented by NULL pointers 
	std::vector<std::vector<Chess_Pieces*>> board;

	//Two players sit across a chess gameboard
	Player white_player;
	Player black_player;
	
	
	
};
