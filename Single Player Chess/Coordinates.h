#pragma once
#include <string>
#include <vector>
//#include "Chess_Pieces.h";

enum Letter_Coordinate
{
	A=1,B,C,D,E,F,G,H
};

class Coordinates
{
public:

	/*Sets the x and y Accordingly
	*Since in arrays starting index is 0 ,not 1, we must subtract 1
	*to the user it will appear as if coordinates are from 1 to 8
	*when in reality it will be from 0 to 7
	*/
	Coordinates(int, int);
	Coordinates(Letter_Coordinate, int);

	  
	/* User can enter their move in two forms:
	* 1) [Coordinate_old (space) Coordinate_new]
	* 2) [Chess_piece (Space) Coordinate_new] 
	* 
	* This  input will be handled in the main source file where
	* this Constructor will take a string like "A8" or "18".
	* Input checking will be done in driver code, constructor will always
	* recieve correct input of length 2
	*/
	Coordinates(std::string S);//Tested -- Working


	/*When you are using the function "find_piece" and you are certain
	* that only one such piece exists in the game therefore the size
	* of the vector will anyway be one
	*/
	Coordinates(std::vector<Coordinates>);//Tested -- Working


	//returns the x and y coordinates
	int get_x_coordinate();
	int get_y_coordinate();

	// 100,100 is not a Valid Coordinate on a chess board!
	bool isValid();//Tested -- Working

	// returns true if 'New' and this Square share an edge or a corner
	bool isAdjacentwith(Coordinates New);//Tested -- Working

	//returns True is the 'New' Square is Diagnol to this Square
	bool isDiagnolwith(Coordinates New);//Tested -- Working

	//returns True is this and the New square lie in the same Column in ChessBoard
	bool isVerticalwith(Coordinates New);//Tested -- Working

	//returns True is this and the New square lie in the same Row in ChessBoard
	bool isHorizontalwith(Coordinates New);//Tested -- Working

	//checks if two coordinates are equal or not
	bool operator ==(Coordinates New);//Implemented - Tested
private:
	int x;
	int y;
};



