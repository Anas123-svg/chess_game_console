#pragma once
#ifndef CHESS_H
#define CHESS_H


#include "Bscs23190Header.h"
#include "Bscs23190chess_board.h"
#include "Bscs23190Player.h"
struct moves {
	position p;
};

class chess_game {
private:
	board board;
	plaYer player1;
	plaYer player2;
	position p,f;
	int i = 0;
	int counter = 0;
	vector<moves> Moves_undo;
public:
	chess_game() : player1(1, BLACK), player2(2, BLACK) {
		board.init();
	}
	bool is_LEGAL_MOvEE(position p1, position p2, plaYer pla) {
		
		bool r = board.is_legal_move(p1, p2,pla);
		return r;
	}
	bool is_valid_loc1(position p) {
		bool r = board.is_valid_loc(p);
		return r;
	}

	bool is_legal_move_by_BLACK(position p1, plaYer p) {
		if (p.getColor() == color::BLACK) {
			bool r = board.is_legal_move_by_black(p1);
			return r;
		}
		else {
			return false;
		}
	}
	void select_row_col(position& p) {
		getRowColbyLeftClick_Cord(p.x, p.y);
	}

	void player_turn(plaYer& player) {
		//getRowColbyLeftClick_Cord(p.x, p.y);
		//getRowColbyLeftClick_Cord(f.x, f.y);
	}
	void turn_change(plaYer& current_turn) {
		if (current_turn.getColor() == color::White) {
			current_turn.setColor(BLACK);
		}
		else {
			current_turn.setColor(White);
		}
	}
	void turn(plaYer current_turn) {
		if (current_turn.getColor() == color::White) {
			gotoRowCol(12, 12);
			std::cout << "White's turn" << std::endl;
		}
		else {
			gotoRowCol(12, 12);
			std::cout << "Black's turn" << std::endl;
		}
	}
	
	void undo_last_move() {
		if (!Moves_undo.empty()) {
			auto last_move = Moves_undo.back();
			Moves_undo.pop_back(); 

			board.update_board(last_move.p, last_move.p);
		}
	}

	void start() {
		board.is_legal_move_by_King(p, f);
		while (true) {
			board.draw();
			turn(player1);

			do {

				do{
					//
					if (player1.getColor() == color::BLACK) {
						do {
							getRowColbyLeftClick_Cord(p.x, p.y);
							Moves_undo.push_back({p});

							if (p.x == 15 && p.y == 15)
								undo_last_move();
						} while (!board.is_legal_move_by_black(p));  //(!is_valid_loc1(p)) && !is_legal_move_by_BLACK(p,player1)
					}
					else {
						do {
							getRowColbyLeftClick_Cord(p.x, p.y);
							Moves_undo.push_back({ p });
						} while (board.is_legal_move_by_black(p));
					}
					//
					bool** h = board.highlight(p, player1);
					board.printHighlight(h);

					getRowColbyLeftClick_Cord(f.x, f.y);
					Moves_undo.push_back({ f });

				} while (!is_valid_loc1(f));

				bool** h = board.unhighlight(p, player1);
				board.printHighlight(h);


			} while (!is_LEGAL_MOvEE(p,f, player1));
			if (board.castling(p, f, player1)) {
				board.update_board_for_castling(p, f);
			}
			else {

			    board.update_board(p, f);
			}


			if (player1.getColor() == color::BLACK) {
				bool r = board.check__by_black('K', player1);
				if (r)
				{
					gotoRowCol(14, 14);
					cout << "Check white !";
				}
				else {
					gotoRowCol(14, 14);
					cout << "             ";
				}

			}
			else {
				bool r = board.check__by_white('k', player1);
				if (r)
				{
					gotoRowCol(14, 14);
					cout << "Check black !";
				}
			}
			if (player1.getColor() == color::White) {
				bool r = board.is_checkmate_by_white_on_black('k', player1);
				if (r)
				{
					gotoRowCol(16, 16);
					cout << "Checkmate black !";
					break;
				}
			}
			else {
				bool r = board.is_checkmate_by_black_on_white('K', player1);
				if (r)
				{
					gotoRowCol(16, 16);
					cout << "Checkmate white !";
					break;
				}
			}
			turn_change(player1);
		}

	}
};

#endif // !CHESS_H