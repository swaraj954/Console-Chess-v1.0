#pragma once
#include <vector>
#include <string>
#include "Coordinates.h"

enum Color
{
	White,
	Black
};

class Chess_Pieces
{
public:
	//Updates the coordinates of the particular chess piece
	void move(Coordinates New);//Implemented -- Not Tested

	//Cheks if that chess piece is capable of moving to the New Coordinate
	virtual bool valid(Coordinates New) = 0;

	//Informs us whether the chess piece is a king,queen,rook..etc
	std::vector<std::string> get_tags();// Implemented -- Not Tested(Nothing to Test)

	// is this a king,queen,rook etc?
	bool is(std::string);//Tested -- Working

	//Every Chess piece has a Coordinate and color
	Chess_Pieces(Coordinates,Color);//Implemented -- Not Tested

	//Return the color of a particular chess piece
	Color getcolor();

	//Returns the coordinates of the chess piece
	Coordinates get_coordinates();
    
protected:
	Coordinates coordinates;
	Color color;
	//Reminder: tags[0] must always be a single Letter denoting the chess piece accorinng to chess notation
	std::vector<std::string> tags;
};

//Purpose of derived class constructors is to add tags for that particular chess piece,

class King :public Chess_Pieces
{
public:
	King(Coordinates C, Color col);
	bool valid(Coordinates New);//Tested -- Working
};

class Queen :public Chess_Pieces
{
public:
	Queen(Coordinates C, Color col);
	bool valid(Coordinates New);//Implemented -- Not Tested
};

class Knight :public Chess_Pieces
{
public:
	Knight(Coordinates C, Color col);
	bool valid(Coordinates New);//Tested -- Working
};

class Pawn :public Chess_Pieces
{
public:
	Pawn(Coordinates C, Color col);
	bool valid(Coordinates New);//Tested -- Partially incorrect(does not take into consideration that a pawn can move 2 squares at start of the game
};

class Rook :public Chess_Pieces
{
public:
	Rook(Coordinates C, Color Col);
	bool valid(Coordinates New);//Implemented -- Not tested
	//Casteling not considered as of now for rook
};

class Bishop :public Chess_Pieces
{
public:
	Bishop(Coordinates C, Color Col);
	bool valid(Coordinates New);//Implemented -- Not tested
};
