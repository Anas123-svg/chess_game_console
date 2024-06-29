#include "Bscs23190Queen.h"


Queen::Queen(position p, color c):pieces(p,c) {
	sym = ((c == BLACK) ? 'Q' : 'q');
    if (c == BLACK) {
        sym = 'q';
    }
    else {
        sym = 'Q';
    }
}
/*
bool Queen::is_legal_move_by_queen(position p1, position p2, board *b1 [][8]) {
    return (is_horizontal_move(p1, p2) && is_horizontal_path_clear(p1, p2, b1) || (is_vertical_move(p1, p2) && is_vertical_path_clear(p1, p2, b1))  || (is_diagonal_move(p1, p1) && is_diagonal_path_clear(p1, p2, b1)));
}**/
