#include <iostream>
#include <cctype>
#include <iomanip>
#include "Coordinates.h"
#include "Chess_Pieces.h"
#include "GameBoard.h"
#include "All_Coordinates.h"


//Console_Chess v1.0
//Created by Swaraj

int number_of_turns_played = 0;

void remove_spaces(std::string& s)
{
	std::string build;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			build = build + s[i];
		}
	}
	s = build;
}

void remove_leading_spaces(std::string& S)
{
	bool encountered_non_space = false;
	std::string build;
	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] != ' ')
		{
			encountered_non_space = true;
		}
		if (encountered_non_space)
		{
			build = build + S[i];
		}
		
	}
	S = build;
}

bool valid_chess_piece_name(std::string S)
{
	Pawn p(A1, Black);
	Bishop b(A1, Black);
	Rook r(A1, Black);
	King k(A1, Black);
	Queen q(A1, Black);
	Knight n(A1, Black);
	if (p.is(S))
	{
		return true;
	}
	else if (b.is(S))
	{
		return true;
	}
	else if (r.is(S))
	{
		return true;
	}
	else if (k.is(S))
	{
		return true;
	}
	else if (q.is(S))
	{
		return true;
	}
	else if (n.is(S))
	{
		return true;
	}
	else
	{
		return false;
	}
}



bool valid_number_coordinate(char letter)
{
	int ascii_value = int(letter);
	if (ascii_value <= 56 && ascii_value >= 49)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool valid_letter_coordinate(char letter)
{
	int ascii_code = int(toupper(letter));
	if (ascii_code >= 65 && ascii_code <= 72)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Ensrues this function will recieve 4 valid coordinates
bool final_input_check(std::string user_input)
{
	int letter_counter=0;
	int number_counter=0;
	int tracker = 0;
	for (int i = 0; i < user_input.length(); i++)
	{
		if (isalpha(user_input[i]) && valid_letter_coordinate(user_input[i]))
		{
			tracker = tracker + 1;
			if (tracker == 2 || tracker == 4)
			{
				return false;
			}
			
		}
		if (isdigit(user_input[i]))
		{
			if (valid_number_coordinate(user_input[i]))
			{
				tracker = tracker + 1;
			}
		}
	}
	return true;
}



//Completed, This function return a vector of coordinates,the last coordinate
//is the destination coordinates, while the rest are source coordinates
std::vector<Coordinates> get_users_move(GameBoard g,Player p)
{
	
	std::vector<Coordinates> move;
	std::string build;
	
	bool Correct_input = false;
	
	while (!Correct_input)
	{
		int lettercord_counter = 0;
		int numbercord_counter = 0;
		bool encountered_junk_alphanum = false;
		bool start_again = false;
		std::string user_input;
		build = "";
		//std::cout << user_input;
		if (number_of_turns_played == 0)
		{
			std::cout << "Enter Your move here:";
			std::getline(std::cin, user_input);
		}
		else
		{
			std::cout << "Your next move:";
			std::getline(std::cin, user_input);
		}
		for (int i = 0; i < user_input.length(); i++)
		{
			if (isalpha(user_input[i]) && valid_letter_coordinate(user_input[i]))
			{
				lettercord_counter = lettercord_counter + 1;
				build = build + user_input[i];
			}
			else if (isdigit(user_input[i]) && valid_number_coordinate(user_input[i]))
			{
				numbercord_counter = numbercord_counter + 1;
				build = build + user_input[i];
			}
			else if (isalnum(user_input[i]))
			{
				encountered_junk_alphanum = true;
			}
			if ((numbercord_counter == 2 && lettercord_counter == 2) || (numbercord_counter == 3 && lettercord_counter == 1) || numbercord_counter == 4)
			{
				if (final_input_check(build))
				{
					char temp=' ';
					if (encountered_junk_alphanum)
					{
						std::cout << "Did you mean " << build.substr(0, 2) << " " << build.substr(2, 2) << "?\n";
						std::cout << "Enter N if you want to change the move,otherwise just press enter:\n";
						std::cin.get(temp);
					}
					if (temp == 'N')
					{
						std::string waste_in_buffer;
						std::getline(std::cin, waste_in_buffer);
						start_again = true;
						break;
					}
					else
					{
						Coordinates source(build.substr(0, 2));
						Coordinates destination(build.substr(2, 2));
						move.push_back(source);
						move.push_back(destination);
						return move;
					}
				}
				//std::cout << "numbercord:" << numbercord_counter << "\n";
				//std::cout << "lettercord:" << lettercord_counter << "\n";
				//std::cout << "build:" << build << "\n";

			}
		}

		if (start_again)
		{
			continue;
		}




		//std::cout << "A diff type of input?\n";
		lettercord_counter = 0;
		numbercord_counter = 0;
		std::string build2;
		encountered_junk_alphanum = false;






		std::string piece_name;
		remove_leading_spaces(user_input);
		for (int i = 0; i < user_input.length(); i++)
		{
			if (user_input[i] == ' ')
			{
				break;
			}
			piece_name = piece_name + user_input[i];
		}
		if (valid_chess_piece_name(piece_name))
		{
			std::cout << "CORRECT PIECE NAME HOORAY!!!!\n";
			std::string coordinates;
			coordinates = user_input.substr(piece_name.length());
			remove_leading_spaces(coordinates);
			bool coordinates_correct = false;
			for (int i = 0; i < coordinates.length(); i++)
			{
				if (isalpha(coordinates[i]) && valid_letter_coordinate(coordinates[i]))
				{
					lettercord_counter = lettercord_counter + 1;
					build2 = build2 + coordinates[i];
				}
				else if (isdigit(coordinates[i]) && valid_number_coordinate(coordinates[i]))
				{
					numbercord_counter = numbercord_counter + 1;
					build2 = build2 + coordinates[i];
				}
				else if (isalnum(coordinates[i]))
				{
					encountered_junk_alphanum = true;
				}

				if ((numbercord_counter == 1 && lettercord_counter == 1) || (numbercord_counter == 2 && lettercord_counter == 0))
				{
					if (final_input_check(build2))
					{
						if (encountered_junk_alphanum)
						{
							std::cout << "Did you mean " << piece_name << " " << build2 << "?\n";
						}
						std::cout << "Correct2\n";
						coordinates_correct = true;
					}
					break;
				}
			}
			if (!coordinates_correct)
			{
				std::cout << "Wrong coordinates entered,enter input again\n";
				build2 = "";
				continue;
			}

			std::vector<Coordinates> Piece_locations = g.findPiece(piece_name, p.get_color());
			Coordinates dest(build2);
			for (int i =0; i<Piece_locations.size(); i++)
			{
				if (!g.legal(Piece_locations[i], dest, p))
				{
					Piece_locations[i] = Piece_locations[Piece_locations.size() - 1];
					Piece_locations.pop_back();
					i = i - 1;
				}
			}

			for (int i = 0; i < Piece_locations.size(); i++)
			{
				move.push_back(Piece_locations[i]);
			}
			move.push_back(dest);
			return move;

		}
		else
		{
			std::cout << "Cant make sense of this input,try again\n";
		}
	}
	return move;
}

int main()
{
	GameBoard g;
	g.print(White);
	
	while (true)
	{
		std::vector<Coordinates> lol = get_users_move(g, g.get_player(White));
		if (lol.size() > 2)
		{
			std::cout << "Multiple moves possible on this one\n";
		}
		std::cout << "\n\n\n\n";
		g.move(lol[0], lol[lol.size() - 1]);
		g.print(White);
	}

}