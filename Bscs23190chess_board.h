#pragma once
#ifndef Chess_BOARD_H
#define Chess_BOARD_H


#include<iostream>
#include<vector>
#include "Bscs23190Pawns.h"
#include "Bscs23190king.h"
#include "Bscs23190Rook.h"
#include "Bscs23190Header.h"
#include "Bscs23190Bishop.h"
#include "Bscs23190Knight.h"
#include "Bscs23190Queen.h"
#include "Bscs23190Player.h"
//#include"piece.h"
using namespace std;


class board {
private:
	int dem;
	pieces***Ps=nullptr;

public:
	board() {
		dem = 8;

	}

	void init() {
		Ps = new pieces ** [8];

		for (int i = 0; i < dem; i++) {
			Ps[i] = new pieces * [8] {};
			
			for (int j = 0; j < dem; j++) {
				if ((i == 0 && j == 0) || (i == 0 && j == 7) || (i==7 && j==7) || (i==7 && j==0) ) {
					Ps[i][j] = new Rook(position{ i,j }, BLACK);
					if ((i == 7 && j == 7) || (i == 7 && j == 0)) {
						Ps[i][j] = new Rook(position{ i,j }, White);
					}
				}
				else if ((i == 0 && j == 1) || (i == 0 && j == 6) || (i == 7 && j == 6) || (i == 7 && j == 1)) {
					Ps[i][j] = new Knight(position{ i,j }, BLACK);
					if ((i == 7 && j == 6) || (i == 7 && j == 1)) {
						Ps[i][j] = new Knight(position{ i,j }, White);
					}
				}
				else if ((i == 0 && j == 2) || (i == 0 && j == 5) || (i == 7 && j == 5) || (i == 7 && j == 2)) {
					Ps[i][j] = new Bishop(position{ i,j }, BLACK);
					if ((i == 7 && j == 5) || (i == 7 && j == 2)) {
						Ps[i][j] = new Bishop(position{ i,j }, White);
					}

				}
				else if ((i == 0 && j == 3) || (i == 7 && j == 3) ) {
					Ps[i][j] = new king(position{ i,j }, BLACK);
					if ((i == 7 && j == 3)) {
						Ps[i][j] = new king(position{ i,j }, White);
					}
				}
				else if ((i == 0 && j == 4) || (i == 7 && j == 4)) {
					Ps[i][j] = new Queen(position{ i,j }, BLACK);
					if ((i == 7 && j == 4)) {
						Ps[i][j] = new Queen(position{ i,j }, White);
					}
				}
				else if (i == 1) {
					Ps[i][j] = new Pawns(position{ i,j }, BLACK);

				}
				else if (i == 6) {
					Ps[i][j] = new Pawns(position{ i,j }, White);
				}
			}
		}
	}


	void init2() {
		Ps = new pieces **[8];

		for (int i = 0; i < dem; i++) {
			Ps[i] = new pieces * [8] {};

			for (int j = 0; j < dem; j++) {
				if ((i == 0 && j == 0) || (i == 0 && j == 7) || (i == 7 && j == 7) || (i == 7 && j == 0)) {
					Ps[i][j] = nullptr; //new Rook(position{ i,j }, BLACK);
					if ((i == 7 && j == 7) || (i == 7 && j == 0)) {
						Ps[i][j] = new Rook(position{ i,j }, White);
					}
				}
				else if ((i == 0 && j == 1) || (i == 0 && j == 6) || (i == 7 && j == 6) || (i == 7 && j == 1)) {
					Ps[i][j] = nullptr;//new Knight(position{ i,j }, BLACK);
					if ((i == 7 && j == 6) || (i == 7 && j == 1)) {
						Ps[i][j] = nullptr;//new Knight(position{ i,j }, White);
					}
				}
				else if ((i == 0 && j == 2) || (i == 0 && j == 5) || (i == 7 && j == 5) || (i == 7 && j == 2)) {
					Ps[i][j] = nullptr;//new Bishop(position{ i,j }, BLACK);
					if ((i == 7 && j == 5) || (i == 7 && j == 2)) {
						Ps[i][j] = nullptr;//new Bishop(position{ i,j }, White);
					}

				}
				else if ((i == 0 && j == 3) || (i == 7 && j == 3)) {
					Ps[i][j] = nullptr;//new king(position{ i,j }, BLACK);
					if ((i == 7 && j == 3)) {
						Ps[i][j] = new king(position{ i,j }, White);
					}
				}
				else if ((i == 0 && j == 4) || (i == 7 && j == 4)) {
					Ps[i][j] = nullptr;//new Queen(position{ i,j }, BLACK);
					if ((i == 7 && j == 4)) {
						Ps[i][j] = nullptr;//new Queen(position{ i,j }, White);
					}
				}
				else if (i == 1) {
					Ps[i][j] = nullptr;//new Pawns(position{ i,j }, BLACK);

				}
				else if (i == 6) {
					Ps[i][j] = nullptr;//new Pawns(position{ i,j }, White);
				}
			}
		}
	}

	int jj = 4;
	void draw() {
		for (int i = 0; i < dem; i++) {
			for (int j = 0; j < 8; j++) {
				/*if (i % 2 == 0)
					SetClr(0, 15);*/
				
				if (Ps[i][j] == nullptr) {
					if (i % 2 == 0 && j % 2 == 0)
						SetClr(0, 15);
					else if (i % 2 == 1 && j % 2 == 0)
						SetClr(15, 0);
					else if (i % 2 == 0 && j % 2 == 1)
						SetClr(15, 0);
					else {
						SetClr(0, 15);
					}
					//gotoRowCol(jj, 3*j+90);

					cout <<"-";
				}
				else {
					Ps[i][j]->Draw();
				}
			}
			//jj++;
			cout << endl;
		}
		SetClr(15, 0);
		gotoRowCol(15, 0);
		cout << "Y";
	}


	bool** highlight(position p, plaYer pla) {
        bool** h = new bool* [8];
		for (int i = 0; i < 8; i++) {
			h[i] = new bool[8];
			for (int j = 0; j < 8; j++) {
				h[i][j] = new bool[8];
			}
		}

		position d;
		for (int i = 0; i < 8; i++) {
			for(int j = 0; j < 8; j++) {
				d = { i,j };
				if (is_legal_move(p, d, pla)) {
					h[i][j] = true;
				}
				else
					h[i][j] = false;
			}
		}
		return h;
	}

	bool** unhighlight(position p, plaYer pla) {
		bool** h = new bool* [8];
		for (int i = 0; i < 8; i++) {
			h[i] = new bool[8];
			for (int j = 0; j < 8; j++) {
				h[i][j] = new bool[8];
			}
		}

		position d;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				d = { i,j };
				if (is_legal_move(p, d, pla)) {
					h[i][j] = false;
				}
				else
					h[i][j] = false;
			}
		}
		return h;
	}

	void printHighlight(bool** highlight) {
		for (int i = 0; i < dem; i++) {
			for (int j = 0; j < 8; j++) {
				if (highlight[i][j] && Ps[i][j] == nullptr) {
					cout << 'X';
				}
				else if (Ps[i][j] == nullptr) {
					if (i % 2 == 0 && j % 2 == 0)
						SetClr(0, 15);
					else if (i % 2 == 1 && j % 2 == 0)
						SetClr(15, 0);
					else if (i % 2 == 0 && j % 2 == 1)
						SetClr(15, 0);
					else {
						SetClr(0, 15);
					}
					cout << "-";
				}
				else {
					Ps[i][j]->Draw();
				}
			}
			cout << endl;
		}
		SetClr(15, 0);
	}

	bool is_horizontal_path_clear(position p1, position p2) {
		if (p1.y < p2.y) {
			for (int i = p1.y + 1; i < p2.y; i++) {
				if (Ps[p1.x][i] != nullptr)
					return false;
			}
		}
		else {
			for (int i = p2.y + 1; i < p1.y; i++) {
				if (Ps[p1.x][i] != nullptr)
					return false;
			}
		}
		return true;
	}


	bool is_legal_move_by_King(position p1, position p2) {
		int r = abs(p1.x - p2.x);
		int c = abs(p1.y - p2.y);
		return (r <= 1 && c <= 1);
	}
	bool is_legal_move_by_King_for_castling(position p1, position p2) {
		int r = abs(p1.x - p2.x);
		int c = abs(p1.y - p2.y);
		return (r == 0 && c == 2);
	}


	bool is_vertical_path_clear(position p1, position p2) {
		if (p1.x < p2.x) {
			for (int i = p1.x + 1; i < p2.x; i++) {
				if (Ps[i][p1.y] != nullptr)
					return false;
			}
		}
		else {
			for (int i = p2.x + 1; i < p1.x; i++) {
				if (Ps[i][p1.y] != nullptr)
					return false;
			}
		}
		return true;
	}

	bool is_diagonal_path_clear(position p1, position p2) {

		if (abs(p1.x - p2.x) != abs(p1.y - p2.y))
			return false;


		if (p1.x < p2.x) {
			if (p1.y < p2.y) {
				for (int i = p1.x + 1, j = p1.y + 1; i < p2.x; i++, j++) {
					if (Ps[i][j] != nullptr)
						return false;
				}
			}
			else {
				for (int i = p1.x + 1, j = p1.y - 1; i < p2.x; i++, j--) {
					if (Ps[i][j] != nullptr)
						return false;
				}
			}
		}

		else {
			if (p1.y < p2.y) {
				for (int i = p1.x - 1, j = p1.y + 1; i > p2.x; i--, j++) {
					if (Ps[i][j] != nullptr)
						return false;
				}
			}
			else {
				for (int i = p1.x - 1, j = p1.y - 1; i > p2.x; i--, j--) {
					if (Ps[i][j] != nullptr)
						return false;
				}
			}
		}
		return true;
	}
	
	void update_board(position p1, position p2) {
		if (p1.x >= 0 && p1.x < dem && p1.y >= 0 && p1.y < dem &&
			p2.x >= 0 && p2.x < dem && p2.y >= 0 && p2.y < dem) {
			char symbol = Ps[p1.x][p1.y]->getSym();
			if (Ps[p2.x][p2.y] == nullptr) {
				Ps[p2.x][p2.y] = new pieces(position{ p2.x,p2.y }, BLACK);
			}
			//Ps[p1.x][p1.y]->Move(p2);
			Ps[p2.x][p2.y]->setSym(symbol);
			Ps[p1.x][p1.y] = nullptr;
			draw();
		}
		else {
			cout << "Invalid position" << endl;
		}
	}
	/*
	void update_board(position p1, position p2, plaYer player1) {
		if (p1.x >= 0 && p1.x < dem && p1.y >= 0 && p1.y < dem &&
			p2.x >= 0 && p2.x < dem && p2.y >= 0 && p2.y < dem) {
			// Check if the move is a castling move
			if (p1.y == 3 && (p2.y == 1 || p2.y == 5)) {
				// Handle castling move
				if (castling(p1, p2, player1)) {
					// Castling successful, no need to update the board here
					return;
				}
				else {
					// Invalid castling move
					cout << "Invalid castling move" << endl;
					return;
				}
			}

			// Regular move
			char symbol = Ps[p1.x][p1.y]->getSym();
			if (Ps[p2.x][p2.y] == nullptr) {
				Ps[p2.x][p2.y] = new pieces(position{ p2.x,p2.y }, BLACK);
			}
			//Ps[p1.x][p1.y]->Move(p2);
			Ps[p2.x][p2.y]->setSym(symbol);
			Ps[p1.x][p1.y] = nullptr;
			draw();
		}
		else {
			cout << "Invalid position" << endl;
		}
	}
	*/

	bool is_legal_move_by_rook(position p1, position p2) {
		return (is_horizontal_move(p1, p2) && is_horizontal_path_clear(p1, p2)) || (is_vertical_move(p1, p2) && is_vertical_path_clear(p1, p2));
	}
	/**bool is_legal_move_by_rook(position p1, position p2) {
		return (is_horizontal_move(p1, p2) && is_horizontal_path_clear(p1, p2) || (is_vertical_move(p1, p2) && is_vertical_path_clear(p1, p2)));
	}*/
	bool is_legal_move_by_bishop(position p1, position p2) {
		return(is_diagonal_move(p1, p1) && is_diagonal_path_clear(p1, p2));
	}

	bool is_legal_move_by_Queen(position p1, position p2) {
		return (is_legal_move_by_rook(p1, p2) || is_legal_move_by_bishop(p1, p2));
	}
	bool is_legal_move_by_Knight(position p1, position p2) {
		int r = abs(p1.x - p2.x);
		int c = abs(p1.y - p2.y);
		return ((r == 2 && c == 1 ) || (c == 2 && r == 1));
	}
	
	bool is_legal_move_by_pawn(position p1, position p2, plaYer pla) {
		int r = p2.x - p1.x;
		int c = abs(p2.y - p1.y);


		bool is_white = (p1.x == 1);

		if (pla.getColor()==color::BLACK) {
			if (r == 1 && c == 0 && Ps[p2.x][p2.y] == nullptr) {
				return true;
			}
			else if (p1.x == 1 && r == 2 && c == 0 && Ps[p2.x][p2.y] == nullptr) {
				return true;
			}
			
			else if (r == 1 && c == 1 && Ps[p2.x][p2.y] != nullptr ) {
				if ((is_same_color(Ps[p1.x][p1.y]->getSym(), Ps[p2.x][p2.y]->getSym())))
					return false;
				return true;
			}
			else {
				return false;
			}
		}
		else {
			if (r == -1 && c == 0 && Ps[p2.x][p2.y] == nullptr) {
				return true;
			}
			else if (p1.x == 6 && r == -2 && c == 0 &&Ps[p2.x][p2.y] == nullptr) {
				return true;
			}
			
			else if (r == -1 && c == 1 && Ps[p2.x][p2.y] != nullptr ) {
				if ((is_same_color(Ps[p1.x][p1.y]->getSym(), Ps[p2.x][p2.y]->getSym())))
					return false;
				return true;
			}
			else {
				return false;
			}
		}
	}/*
	bool is_legal_move_by_pawn(position p1, position p2, plaYer pla) {
		int r = p2.x - p1.x;
		int c = abs(p2.y - p1.y);

		if (pla.getColor() == color::BLACK) {
			if (r == 1 && c == 0 && Ps[p2.x][p2.y] == nullptr && p2.x > p1.x) {
				return true; // Black pawn moving one step forward
			}
			else if (p1.x == 1 && r == 2 && c == 0 && Ps[p2.x][p2.y] == nullptr && Ps[p1.x + 1][p1.y] == nullptr && p2.x > p1.x) {
				return true; // Black pawn moving two steps forward from the starting position
			}
			else if (r == 1 && c == 1 && Ps[p2.x][p2.y] != nullptr && p2.x > p1.x) {
				if (!is_same_color(Ps[p1.x][p1.y]->getSym(), Ps[p2.x][p2.y]->getSym()))
					return true; // Black pawn capturing diagonally
			}
		}
		else {
			if (r == -1 && c == 0 && Ps[p2.x][p2.y] == nullptr && p2.x < p1.x) {
				return true; // White pawn moving one step forward
			}
			else if (p1.x == 6 && r == -2 && c == 0 && Ps[p2.x][p2.y] == nullptr && Ps[p1.x - 1][p1.y] == nullptr && p2.x < p1.x) {
				return true; // White pawn moving two steps forward from the starting position
			}
			else if (r == -1 && c == 1 && Ps[p2.x][p2.y] != nullptr && p2.x < p1.x) {
				if (!is_same_color(Ps[p1.x][p1.y]->getSym(), Ps[p2.x][p2.y]->getSym()))
					return true; // White pawn capturing diagonally
			}
		}
		return false; // Invalid move
	}
	*/


	bool check__by_white(char sym_king, plaYer pla) {
		position kingPos;
		kingPos.x = -1;
		kingPos.y = -1;
		for (int i = 0; i < dem; i++) {
			for (int j = 0; j < dem; j++) {
				if (Ps[i][j] != nullptr ) {
					if ( Ps[i][j]->getSym() == sym_king) {
						kingPos = { i, j };
						break;
					}
				}
			}
		}
		for (int i = 0; i < dem; i++) {
			for (int j = 0; j < dem; j++) {
				if (Ps[i][j] != nullptr && Ps[i][j]->getSym() != 'K' && Ps[i][j]->getSym() != 'k' && (Ps[i][j]->getSym()>=65 && Ps[i][j]->getSym() <=96)) {
					position piecePos = { i, j };
					if (is_legal_move(piecePos, kingPos, pla)) {
						return true;
					}
				}
			}
		}

		return false;
	}

	bool check__by_black(char sym_king, plaYer pla) {
		position kingPos;
		kingPos.x = -1;
		kingPos.y = -1;
		for (int i = 0; i < dem; i++) {
			for (int j = 0; j < dem; j++) {
				if (Ps[i][j] != nullptr && Ps[i][j]->getSym() == sym_king) {
					kingPos = { i, j };
					break;
				}
			}
		}
		for (int i = 0; i < dem; i++) {
			for (int j = 0; j < dem; j++) {
				if (Ps[i][j] != nullptr && Ps[i][j]->getSym() != 'K' && Ps[i][j]->getSym() != 'k' && (Ps[i][j]->getSym() >= 97 && Ps[i][j]->getSym() <= 120)) {
					position piecePos = { i, j };
					if (is_legal_move(piecePos, kingPos, pla)) {
						return true;
					}
				}
			}
		}

		return false;
	}


	bool is_same_color(char sym1, char sym2) {
		if (sym1 >= 'A' && sym1 <= 'Z' && sym2 >= 'A' && sym2 <= 'Z') {
			return true;
		}
		else if (sym1 >= 'a' && sym1 <= 'z' && sym2 >= 'a' && sym2 <= 'z') {
			return true;
		}
		else {
			return false;
		}
	}

	bool there_is_no_piece_except_rook_and_king_in_row(int row) {
		if (row == 0) {
			for (int i = 0; i < dem; i++) {
				if (Ps[row][i] != nullptr) {
					char sym = Ps[row][i]->getSym();
					if (sym != 'r' && sym != 'k') {
						return false;
					}
				}
			}
		}
		else if(row==7) {
			for (int i = 0; i < 8; i++) {
				if (Ps[row][i] != nullptr) {
					char sym = Ps[row][i]->getSym();
					if ( sym != 'R' && sym != 'K') {
						return false;
					}
				}
			}
		}
		return true;
	}

	bool is_legal_move_by_black(position p1) {
       if (Ps[p1.x][p1.y] == nullptr)
			return false;
		switch (Ps[p1.x][p1.y]->getSym())
		{
		case 'r':
			return true;
			break;
		case 'b':
			return true;
			break;
		case 'q':
			return true;
			break;
		case 'k':
	        return true;
			break;
		case 'h':
			return true;
			break;
		case 'p':
			return true;
			break;
		default:
			break;
		}
		return false;
	
	}
	bool is_valid_loc(position p) {
		if (p.x >= 0 && p.x < 8 && p.y >= 0 && p.y < 8)
			return true;
	}

	bool is_legal_move(position p1, position p2, plaYer pla) {
		if (!is_valid_loc(p1) || !is_valid_loc(p2)) 
			return false;
		if (Ps[p1.x][p1.y] == nullptr)
			return false;
		if (Ps[p2.x][p2.y] != nullptr) { 
			if (is_same_color(Ps[p1.x][p1.y]->getSym(), Ps[p2.x][p2.y]->getSym()))
				return false;
		}
		switch (Ps[p1.x][p1.y]->getSym())
		{
		case 'R':
		case 'r':
			/*
			if (Ps[p2.x][p2.y] != nullptr) {
				

				if (is_same_color(Ps[p1.x][p1.y]->getSym(), Ps[p2.x][p2.y]->getSym()))
					return false;
			}*/
			return is_legal_move_by_rook(p1, p2);
			break;
		case 'B':
		case 'b':
			/*
			if (Ps[p2.x][p2.y] != nullptr) {
				if (is_same_color(Ps[p1.x][p1.y]->getSym(), Ps[p2.x][p2.y]->getSym()))
					return false;
			}*/
			return is_legal_move_by_bishop(p1, p2);
			break;
		case 'Q':
		case 'q':
			/**
			if (Ps[p2.x][p2.y] != nullptr) {
				if (is_same_color(Ps[p1.x][p1.y]->getSym(), Ps[p2.x][p2.y]->getSym()))
					return false;
			}*/
			return is_legal_move_by_Queen(p1, p2);
			break;
		case 'k':
		case 'K':
			/*
			if (Ps[p2.x][p2.y] != nullptr) {
				if (is_same_color(Ps[p1.x][p1.y]->getSym(), Ps[p2.x][p2.y]->getSym()))
					return false;
			}*/
			if (p1.x == 0 && p1.y ==3) {
				
				if(there_is_no_piece_except_rook_and_king_in_row(0))
					return is_legal_move_by_King_for_castling(p1, p2);
			}
			else if (p1.x == 7 && p1.y==3) {
				if(there_is_no_piece_except_rook_and_king_in_row(7))
					return is_legal_move_by_King_for_castling(p1, p2);
			}
			return is_legal_move_by_King(p1, p2);
	       
			break;
		case 'H':
		case 'h':
			/*
			if (Ps[p2.x][p2.y] != nullptr) {
				if (is_same_color(Ps[p1.x][p1.y]->getSym(), Ps[p2.x][p2.y]->getSym()))
					return false;
			}*/
			return is_legal_move_by_Knight(p1, p2);
			break;
		case 'P':
		case 'p':
			/*
			if (Ps[p2.x][p2.y] != nullptr) {
				if (is_same_color(Ps[p1.x][p1.y]->getSym(), Ps[p2.x][p2.y]->getSym()))
					return false;
			}*/

			return is_legal_move_by_pawn(p1, p2, pla);
			break;
		default:
			break;
		}
		return false;
	}




	bool is_checkmate_by_white_on_black(char sym_king, plaYer pla) {
		position kingPos;
		kingPos.x = 0;
		kingPos.y = 3;
		for (int i = 0; i < dem; i++) {
			for (int j = 0; j < dem; j++) {
				if (Ps[i][j] != nullptr && Ps[i][j]->getSym() == sym_king) {
					kingPos = { i, j };
					break;
				}
			}
		}

		if (!check__by_white(sym_king, pla)) {
			return false;
		}

		for (int i = 0; i < dem; i++) {
			for (int j = 0; j < dem; j++) {
				if (Ps[i][j] != nullptr && Ps[i][j]->getSym() >= 'a' && Ps[i][j]->getSym() <= 'z'&& Ps[i][j]->getSym() != 'p' ) {
					position piecePos = { i, j };
					for (int x = 0; x < dem; x++) {
						for (int y = 0; y < dem; y++) {
							position newPos = { x, y };
							if ( is_legal_move(piecePos, newPos, pla )) {
							if (!(x == kingPos.x && y == kingPos.y)) {
									pieces* tempPiece = Ps[x][y];
									Ps[x][y] = Ps[i][j];
									Ps[i][j] = nullptr;
									if (!check__by_white('k', pla)) {
										Ps[i][j] = Ps[x][y];
										Ps[x][y] = tempPiece;
										return false;
									}
									Ps[i][j] = Ps[x][y];
									Ps[x][y] = tempPiece;
								}
							}
						}
					}
				}
			}
		}

		return true;
	}

	bool is_checkmate_by_black_on_white(char sym_king, plaYer pla) {
		position kingPos;
		kingPos.x = 0;
		kingPos.y = 3;
		for (int i = 0; i < dem; i++) {
			for (int j = 0; j < dem; j++) {
				if (Ps[i][j] != nullptr && Ps[i][j]->getSym() == sym_king) {
					kingPos = { i, j };
					break;
				}
			}
		}

		if (!check__by_black(sym_king, pla)) {
			return false;
		}

		for (int i = 0; i < dem; i++) {
			for (int j = 0; j < dem; j++) {
				if (Ps[i][j] != nullptr && Ps[i][j]->getSym() >= 'A' && Ps[i][j]->getSym() <= 'Z' && Ps[i][j]->getSym() != 'P') {
					position piecePos = { i, j };
					for (int x = 0; x < dem; x++) {
						for (int y = 0; y < dem; y++) {
							position newPos = { x, y };
							if (is_legal_move(piecePos, newPos, pla)) {
								if (!(x == kingPos.x && y == kingPos.y)) {
									pieces* tempPiece = Ps[x][y];
									Ps[x][y] = Ps[i][j];
									Ps[i][j] = nullptr;
									if (!check__by_black('K', pla)) {
										Ps[i][j] = Ps[x][y];
										Ps[x][y] = tempPiece;
										return false;
									}
									Ps[i][j] = Ps[x][y];
									Ps[x][y] = tempPiece;
								}
							}
						}
					}
				}
			}
		}

		return true;
	}

	bool is_square_under_attack(position p, plaYer pla) {

		if (pla.getColor() == color::White) {
			for (int i = 0; i < dem; i++) {
				for (int j = 0; j < dem; j++) {
					if (Ps[i][j] != nullptr ) {
						if (Ps[i][j]->getSym() >= 'a' && Ps[i][j]->getSym() <= 'z') {
							position piecePos = { i, j };
							if (is_legal_move(piecePos, p, pla)) {
								return true;
							}
						}
					}
				}
			}
		}
		else {
			for (int i = 0; i < dem; i++) {
				for (int j = 0; j < dem; j++) {
					if (Ps[i][j] != nullptr && Ps[i][j]->getSym() >= 'A' && Ps[i][j]->getSym() <= 'Z') {
						position piecePos = { i, j };
						if (is_legal_move(piecePos, p, pla)) {
							return true;
						}
					}
				}
			}
		}
		return false;
	} 


	bool castling(position p1, position p2, plaYer pla) {
		if ((p1.x == 0 && p1.y == 3 && p2.x==0 && p2.y==1) || (p1.x == 0 && p1.y == 3 && p2.x == 0 && p2.y == 5)) {
			for (int i = 0; i < 1; i++) {
				for (int j = 0; j < dem; j++) {
					position piecePos = { i, j };
					if (is_square_under_attack(piecePos,pla)) {
						return false;
					}
				}
			}
		}
		else if ((p1.x == 7 && p1.y == 3 && p2.x == 7 && p2.y == 1) || (p1.x == 7 && p1.y == 3 && p2.x == 7 && p2.y == 5)) {
			for (int i = 7; i < 8; i++) {
				for (int j = 0; j < dem; j++) {
					position piecePos = { i, j };
					if (is_square_under_attack(piecePos, pla)) {
						return false;
					}
				}
			}
		}
		if (p1.x == 0 && p1.y == 3 && p2.x == 0 && p2.y == 1) {
			if (Ps[0][0] != nullptr && Ps[0][0]->getSym() == 'r' ) {  //&& Ps[0][0]->getFirstMove() == false
				if (Ps[0][1] == nullptr && Ps[0][2] == nullptr ) {
					Ps[0][1] = Ps[0][3];
					Ps[0][3] = nullptr;
					Ps[0][2] = Ps[0][0];
					Ps[0][0] = nullptr;
					return true;
				}
			}
		}
		else if (p1.x == 0 && p1.y == 3 && p2.x == 0 && p2.y == 5) {
			if (Ps[0][7] != nullptr && Ps[0][7]->getSym() == 'r') {  // && Ps[0][7]->getFirstMove() == false
				if (Ps[0][5] == nullptr && Ps[0][6] == nullptr) {
					Ps[0][5] = Ps[0][3];
					Ps[0][3] = nullptr;
					Ps[0][4] = Ps[0][7];
					Ps[0][7] = nullptr;
					return true;
				}
			}
		}
		else if (p1.x == 7 && p1.y == 3 && p2.x == 7 && p2.y == 1) {
			if (Ps[7][0] != nullptr && Ps[7][0]->getSym() == 'R' ) { //&& Ps[7][0]->getFirstMove() == false
				if (Ps[7][1] == nullptr && Ps[7][2] == nullptr ) {
					Ps[7][1] = Ps[7][3];
					Ps[7][3] = nullptr;
					Ps[7][2] = Ps[7][0];
					Ps[7][0] = nullptr;
					return true;
				}
			}
		}
		else if(p1.x == 7 && p1.y == 3 && p2.x == 7 && p2.y == 5) {
			if (Ps[7][7] != nullptr ) { //&& Ps[7][7]->getFirstMove() == false
				if (Ps[7][7]->getSym() == 'R') {
					if (Ps[7][5] == nullptr && Ps[7][6] == nullptr) {
					    
						Ps[7][5] = new king{ position{ 7,5 }, BLACK };//Ps[7][3];//new king{ position{ 7,5 }, BLACK };
						p1.x = 7;
                        p1.y = 5;
						Ps[7][3] = nullptr;
						Ps[7][4] = new Rook{ position{ 7,4 }, BLACK };
						Ps[7][7] = nullptr;
						return true;
					}
				}
			}
		}

		return false;
	}

	void update_board_for_castling(position p1, position p2) {
		if (p1.x >= 0 && p1.x < dem && p1.y >= 0 && p1.y < dem &&
			p2.x >= 0 && p2.x < dem && p2.y >= 0 && p2.y < dem) {

			if ((p1.x == 0 && p1.y == 3 && p2.x == 0 && p2.y == 1) || (p1.x == 0 && p1.y == 3 && p2.x == 0 && p2.y == 5)) {
	
				if (p2.y == 1) {
				
					Ps[0][1] = new king{ position{ 0,1 }, BLACK };
					Ps[0][3] = nullptr;
				
					Ps[0][2] = new Rook{ position{ 0,2 }, BLACK };
					Ps[0][0] = nullptr;
				}
				else {
					
					Ps[0][5] = new king{ position{ 0,5 }, BLACK };
					Ps[0][3] = nullptr;
					
					Ps[0][4] = new Rook{ position{ 0,4 }, BLACK };
					Ps[0][7] = nullptr;
				}
				draw();
				return;
			}
			else if ((p1.x == 7 && p1.y == 3 && p2.x == 7 && p2.y == 1) || (p1.x == 7 && p1.y == 3 && p2.x == 7 && p2.y == 5)) {
				if (p2.y == 1) {
					Ps[7][1] = new king{ position{ 7,1 }, White };
					Ps[7][3] = nullptr;
					Ps[7][2] = new Rook{ position{ 7,2 }, White };
					Ps[7][0] = nullptr;
				}
				else {
					Ps[7][5] = new king{ position{ 7,5 }, White };
					Ps[7][3] = nullptr;
					Ps[7][4] = new Rook{ position{ 7,4 }, White };
					Ps[7][7] = nullptr;
				}
				draw();
				return;
			}
		}
		cout << "Invalid  castling " << endl;
	}


	void play() {

	}
};




#endif // !Chess_BOARD_H

