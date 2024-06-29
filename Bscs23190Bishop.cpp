#include "Bscs23190Bishop.h"

Bishop::Bishop(position p, color c) :pieces(p, c) {
    if (c == BLACK) {
        sym = 'b';
    }
    else {
        sym = 'B';
    }
}
/*
bool Bishop::is_legal_move_by_bishop(position p1, position p2, board* board1[][8]) {
    return(is_diagonal_move(p1, p1) && is_diagonal_path_clear(p1, p2, board1));
}*/