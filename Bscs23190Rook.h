#pragma once
#ifndef ROOK_H
#define ROOK_H


//#include "Header.h"

#include "Bscs23190piece.h"

class Rook :
    public pieces
{
public:
    Rook(position p, color c);

   // bool is_legal_move_by_rook(position new_position1, position new_position2, board* b1[][8]);
};

#endif // !ROOK_H