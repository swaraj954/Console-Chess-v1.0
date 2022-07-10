#include <iostream>
#include <cctype>
#include "GameBoard.h"
#include "Coordinates.h"
#include "Chess_Pieces.h"

bool GameBoard::empty(Coordinates C)
{
	if (!C.isValid())
	{
		std::cout << "Error: Invalid coordinates supplied to GameBoard::empty(Coordinates)\n";
		std::cout << "Returning False\n";
		return false;
	}
	else if (board[C.get_y_coordinate()][C.get_x_coordinate()] == NULL)
	{
		return true;
	}
	return false;
}

GameBoard::GameBoard()
{
	std::vector<Chess_Pieces*> white_pieces;
	std::vector<Chess_Pieces*> black_pieces;

	for (int i = 0; i < 8; i++)
	{
		std::vector<Chess_Pieces*> temp;
		for (int j = 0; j < 8; j++)
		{
			temp.push_back(NULL);
		}
		board.push_back(temp);
	}

	for (int i = 0; i < 8; i++)
	{
		std::vector<Chess_Pieces*> temp;
		for (int j = 0; j < 8; j++)
		{
			Coordinates temp_cord(j + 1, i + 1);
			if (i == 0)
			{
				switch (j)
				{
				case 0:
				case 7:
				{
					Rook* r = new Rook(temp_cord, White);
					white_pieces.push_back(r);
					board[i][j] = r;
				}
					break;
				
				case 1:
				case 6:
				{
					Knight* n = new Knight(temp_cord, White);
					white_pieces.push_back(n);
					board[i][j] = n;
				}
					break;
				case 2:
				case 5:
				{
					Bishop* p = new Bishop(temp_cord, White);
					white_pieces.push_back(p);
					board[i][j] = p;
				}
					break;
				case 3:
				{
					Queen* q = new Queen(temp_cord, White);
					white_pieces.push_back(q);
					board[i][j] = q;
				}
					break;
				case 4:
				{
					King* k = new King(temp_cord, White);
					white_pieces.push_back(k);
					board[i][j] = k;
				}
					break;
				default:
					std::cout << "Error in Gameboard Constructor\n";
					break;
				}
			}
			if (i == 1)
			{
				
				Pawn* p = new Pawn(temp_cord, White);
				white_pieces.push_back(p);
				board[i][j] = p;
			}
			if (i == 6)
			{
				Pawn* p = new Pawn(temp_cord, Black);
				black_pieces.push_back(p);
				board[i][j] = p;
			}
			if (i == 7)
			{
				switch (j)
				{
				case 0:
				case 7:
				{
					Rook* r = new Rook(temp_cord, Black);
					black_pieces.push_back(r);
					board[i][j] = r;
				}
					break;
				case 1:
				case 6:
				{
					Knight* n = new Knight(temp_cord, Black);
					black_pieces.push_back(n);
					board[i][j] = n;
				}
					break;
				case 2:
				case 5:
				{
					Bishop* p = new Bishop(temp_cord, Black);
					black_pieces.push_back(p);
					board[i][j] = p;
				}
					break;
				case 3:
				{
					Queen* q = new Queen(temp_cord, Black);
					black_pieces.push_back(q);
					board[i][j] = q;
				}
					break;
				case 4:
				{
					King* k = new King(temp_cord, Black);
					black_pieces.push_back(k);
					board[i][j] = k;
				}
					break;
				default:
					std::cout << "Error in Gameboard Constructor\n";
					break;
				}
			}
		}
		board.push_back(temp);
	}
	white_player.supply_pieces(white_pieces);
	white_player.assign_color(White);
	black_player.supply_pieces(black_pieces);
	black_player.assign_color(Black);
}

void GameBoard::print(Color player_color)
{
	if (player_color == Black)
	{
		for (int i = 0; i < 8; i++)
		{
			std::cout << i+1 << " ";
			for (int j = 0; j < 8; j++)
			{

				std::cout << "|  ";
				Coordinates temp(j + 1, i + 1);
				if (!empty(temp))
				{
					Chess_Pieces* cp = board[i][j];
					if (cp->getcolor() == Black)
					{
						std::cout << char(tolower((cp->get_tags()[0])[0]));
					}
					else
					{
						std::cout << char(toupper((cp->get_tags()[0][0])));
					}
					std::cout << "  ";
				}
				else
				{
					std::cout << "   ";
				}

			}
			std::cout << "|\n  -------------------------------------------------\n";
		}
	}
	else
	{
		for (int i = 7; i > -1; i--)
		{
			std::cout << i + 1 << " ";
			for (int j = 0; j < 8; j++)
			{

				std::cout << "|  ";
				Coordinates temp(j + 1, i + 1);
				if (!empty(temp))
				{
					Chess_Pieces* cp = board[i][j];
					if (cp->getcolor() == Black)
					{
						std::cout << char(tolower((cp->get_tags()[0])[0]));
					}
					else
					{
						std::cout << char(toupper((cp->get_tags()[0][0])));
					}
					std::cout << "  ";
				}
				else
				{
					std::cout << "   ";
				}

			}
			std::cout << "|\n  -------------------------------------------------\n";
		}
	}
	std::cout << "     ";
	for (int i = 65; i < 73; i++)
	{
		std::cout << static_cast<char>(i) << "     ";
	}
	std::cout << "\n";
}

bool GameBoard::Obstruction_exists(Coordinates Old, Coordinates New)
{
	Coordinates destination_square(New.get_x_coordinate()+1, New.get_y_coordinate()+1);
	if (New.isVerticalwith(Old))
	{
		int Upper = Old.get_y_coordinate() > New.get_y_coordinate() ? Old.get_y_coordinate() : New.get_y_coordinate();
		int Lower = Old.get_y_coordinate() > New.get_y_coordinate() ? New.get_y_coordinate() : Old.get_y_coordinate();
		for (int i = Lower+1; i < Upper; i++)
		{
			Coordinates temp(Old.get_x_coordinate()+1, i+1);
			if (!empty(temp))
			{
				return true;
			}
		}
		
		if (!empty(destination_square))
		{
			if (board[New.get_y_coordinate()][New.get_x_coordinate()]->getcolor() == board[Old.get_y_coordinate()][Old.get_x_coordinate()]->getcolor())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}

	}
	else if (New.isHorizontalwith(Old))
	{
		int lower = New.get_x_coordinate() < Old.get_x_coordinate() ? New.get_x_coordinate() : Old.get_x_coordinate();
		int upper = New.get_x_coordinate() < Old.get_x_coordinate() ? Old.get_x_coordinate() : New.get_x_coordinate();
		for (int i = lower + 1; i < upper; i++)
		{
			Coordinates temp(i+1, Old.get_y_coordinate()+1);
			if (!empty(temp))
			{
				return true;
			}
		}
		if (!empty(destination_square))
		{
			if (board[New.get_x_coordinate()][New.get_y_coordinate()]->getcolor() == board[Old.get_x_coordinate()][Old.get_y_coordinate()]->getcolor())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}

	}
	else if (New.isDiagnolwith(Old))
	{
		bool new_is_left  = New.get_x_coordinate() < Old.get_x_coordinate() ? true : false ;
		bool new_is_right = New.get_x_coordinate() > Old.get_x_coordinate() ? true : false ;
		bool new_is_up    = New.get_y_coordinate() > Old.get_y_coordinate() ? true : false ;
		bool new_is_down  = New.get_y_coordinate() < Old.get_y_coordinate() ? true : false ;

		int tracer_x = Old.get_x_coordinate();
		int tracer_y = Old.get_y_coordinate();
		if (new_is_up && new_is_right)
		{
			tracer_x = tracer_x + 1;
			tracer_y = tracer_y + 1;
			while (tracer_x != New.get_x_coordinate() && tracer_y != New.get_y_coordinate())
			{
				Coordinates temp(tracer_x+1, tracer_y+1);
				if (!empty(temp))
				{
					return true;
				}
				tracer_x = tracer_x + 1;
				tracer_y = tracer_y + 1;
			}
			if (!empty(destination_square))
			{
				if (board[New.get_y_coordinate()][New.get_x_coordinate()]->getcolor() == board[Old.get_y_coordinate()][Old.get_x_coordinate()]->getcolor())
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else if (new_is_up && new_is_left)
		{
			tracer_x = tracer_x - 1;
			tracer_y = tracer_y + 1;
			while (tracer_x != New.get_x_coordinate() && tracer_y != New.get_y_coordinate())
			{
				Coordinates temp(tracer_x+1, tracer_y+1);
				if (!empty(temp))
				{
					return true;
				}
				tracer_x = tracer_x - 1;
				tracer_y = tracer_y + 1;
			}
			if (!empty(destination_square))
			{
				if (board[New.get_y_coordinate()][New.get_x_coordinate()]->getcolor() == board[Old.get_y_coordinate()][Old.get_x_coordinate()]->getcolor())
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else if (new_is_down && new_is_right)
		{
			tracer_x = tracer_x + 1;
			tracer_y = tracer_y - 1;
			while (tracer_x != New.get_x_coordinate() && tracer_y != New.get_y_coordinate())
			{
				Coordinates temp(tracer_x+1, tracer_y+1);
				if (!empty(temp))
				{
					return true;
				}
				tracer_x = tracer_x + 1;
				tracer_y = tracer_y - 1;
			}
			if (!empty(destination_square))
			{
				if (board[New.get_y_coordinate()][New.get_x_coordinate()]->getcolor() == board[Old.get_y_coordinate()][Old.get_x_coordinate()]->getcolor())
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else if (new_is_down && new_is_left)
		{
			tracer_x = tracer_x - 1;
			tracer_y = tracer_y - 1;
			while (tracer_x != New.get_x_coordinate() && tracer_y != New.get_y_coordinate())
			{
				Coordinates temp(tracer_x+1, tracer_y+1);
				if (!empty(temp))
				{
					return true;
				}
				tracer_x = tracer_x - 1;
				tracer_y = tracer_y - 1;
			}
			if (!empty(destination_square))
			{
				if (board[New.get_y_coordinate()][New.get_x_coordinate()]->getcolor() == board[Old.get_y_coordinate()][Old.get_x_coordinate()]->getcolor())
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}

		}
	}
	else
	{
		std::cout << "Error: 'bool Obstruction_exists(cor,cor)' can not process the coordinates supplied,returning true\n";
	}
	return true;
}

void GameBoard::move(Coordinates Old, Coordinates New)
{
	if (true)
	{
		int Old_x = Old.get_x_coordinate();
		int Old_y = Old.get_y_coordinate();
		int New_x = New.get_x_coordinate();
		int New_y = New.get_y_coordinate();
		Chess_Pieces* temp = board[Old_y][Old_x];
		temp->move(New);
		board[Old_y][Old_x] = NULL;
		board[New_y][New_x] = temp;
	}
	else
	{
		std::cout << "Illegeal move!\n";
	}
}

bool GameBoard::legal(Coordinates Old,Coordinates New,Player Current_Player)
{
	Color Current_Player_Color = Current_Player.get_color();
	if (New.isValid())
	{
		//Coordinates temp = Coordinates(Old.get_x_coordinate(),Old.get_y_coordinate());//Use of this statement?
		if (!empty(Old))
		{
			Chess_Pieces* piece_to_be_moved = board[Old.get_y_coordinate()][Old.get_x_coordinate()];
			if (piece_to_be_moved->getcolor() != Current_Player_Color)
			{
				return false;
			}
			if (Old == New)
			{
				return false;
			}
			if (!piece_to_be_moved->is("Knight") && !piece_to_be_moved->is("Pawn"))
			{
				if (!piece_to_be_moved->valid(New))
				{
					return false;
				}
				else if (Obstruction_exists(Old, New))
				{
					return false;
				}
				else if (inCheck(Old, New,Current_Player))
				{
					return false;
				}
				else
				{
					return true;
				}				
			}
			else if (piece_to_be_moved->is("Knight"))
			{
				if (!piece_to_be_moved->valid(New))
				{
					return false;
				}
				if (!empty(New))
				{
					if (board[New.get_y_coordinate()][New.get_x_coordinate()]->getcolor() == Current_Player_Color)
					{
						return false;
					}
				}
				if (inCheck(Old, New, Current_Player))
				{
					return false;
				}
				
				return true;
			}
			else if (piece_to_be_moved->is("pawn"))
			{

			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool GameBoard::inCheck(Player Current_Player)
{
	Coordinates king_position = findPiece("King", Current_Player.get_color());
	Player opposite_player = get_opposite_player(Current_Player);
	std::vector<Chess_Pieces*> opposite_player_pieces = opposite_player.get_alive_pieces();
	for (int i = 0; i < opposite_player_pieces.size(); i++)
	{
		
		if (opposite_player_pieces[i]->is("Knight"))
		{
			if (opposite_player_pieces[i]->valid(king_position))
			{
				return true;
			}
			
		}
		else if (opposite_player_pieces[i]->is("Pawn"))
		{
			Coordinates temp = opposite_player_pieces[i]->get_coordinates();
			bool king_is_ahead = king_position.get_y_coordinate() > temp.get_y_coordinate();
			bool king_is_behind = king_position.get_y_coordinate() < temp.get_y_coordinate();
			bool king_in_front_of_pawn = (opposite_player.get_color() == Black ? king_is_behind : king_is_ahead);
			if (temp.isAdjacentwith(king_position) && temp.isDiagnolwith(king_position) && king_in_front_of_pawn)
			{
				return true;
			}
			
		}
		else
		{
			if (opposite_player_pieces[i]->valid(king_position)&&!Obstruction_exists(opposite_player_pieces[i]->get_coordinates(), king_position))
			{
				return true;
			}
		}
	}
	return false;
}

bool GameBoard::inCheck(Coordinates Old, Coordinates New,Player Current_Player)
{
	Chess_Pieces* chess_piece_at_new = board[New.get_y_coordinate()][New.get_x_coordinate()];
	bool killed = false;
	if (!empty(New))
	{
		killed = true;
		get_opposite_player(Current_Player).kill(New);
	}
	board[New.get_y_coordinate()][New.get_x_coordinate()] = board[Old.get_y_coordinate()][Old.get_x_coordinate()];
	board[Old.get_y_coordinate()][Old.get_x_coordinate()]->move(New);
	board[Old.get_y_coordinate()][Old.get_x_coordinate()] = NULL;
	bool check;
	if (inCheck(Current_Player))
	{
		check = true;
	}
	else
	{
		check = false;
	}
	board[Old.get_y_coordinate()][Old.get_x_coordinate()] = board[New.get_y_coordinate()][New.get_x_coordinate()];
	board[New.get_y_coordinate()][New.get_x_coordinate()] = chess_piece_at_new;
	board[Old.get_y_coordinate()][Old.get_x_coordinate()]->move(Old);
	if (killed)
	{
		get_opposite_player(Current_Player).revive_last_killed();
	}
	
	return check;
}

bool GameBoard::stalemate()
{
	return true;
}

bool GameBoard::checkmate()
{
	return true;
}

std::vector<Coordinates> GameBoard::findPiece(std::string chess_piece_name, Color c)
{
	std::vector<Coordinates> piece_positions;
	Player player_of_concern = get_player(c);
	std::vector<Chess_Pieces*> player_of_concern_alive_pieces = player_of_concern.get_alive_pieces();
	for (int i = 0; i < player_of_concern_alive_pieces.size(); i++)
	{
		if (player_of_concern_alive_pieces[i]->is(chess_piece_name))
		{
			piece_positions.push_back(player_of_concern_alive_pieces[i]->get_coordinates());
		}
	}
	return piece_positions;;
}

Player& GameBoard::get_opposite_player(Player Current_Player)
{
	return Current_Player.get_color() == White ? black_player : white_player;
}

Player& GameBoard::get_player(Color c)
{
	return c == White ? white_player : black_player;
}



