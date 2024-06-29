#include "Bscs23190Rook.h"
#include "Bscs23190chess_board.h"


Rook::Rook(position p, color c) : pieces(p, c)
{
    if (c == BLACK) {
        sym = 'r';
    }
    else {
        sym = 'R';
    }
}
/*
bool Rook::is_legal_move_by_rook(position p1, position p2, board* b1[][8]) {
    return (is_horizontal_move(p1,p2) && b1.is_horizontal_path_clear(p1,p2,b1) || (is_vertical_move(p1, p2) && is_vertical_path_clear(p1, p2, b1)));
}*/