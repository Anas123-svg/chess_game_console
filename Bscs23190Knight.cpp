#include "Bscs23190Knight.h"

Knight::Knight(position p, color c) :pieces(p, c) {
    if (c == BLACK) {
        sym = 'h';
    }
    else {
        sym = 'H';
    }
}
/*
bool Knight::is_legal_move_by_knight(position start, position end){
	if (abs(start.x - end.x) == 2 && abs(start.y - end.y) == 1) {
		return true;
	}
	if (abs(start.x - end.x) == 1 && abs(start.y - end.y) == 2) {
		return true;
	}
	return false;
}*/