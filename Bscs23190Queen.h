#pragma once
#ifndef QUEEN_H
#define QUEEN_H
//#include "Header.h"
#include "Bscs23190piece.h"

class Queen :
    public pieces
{
public:
    Queen(position p, color c);
   // bool is_legal_move_by_queen(position start, position end, board *b1[][8]);
};

#endif // !QUEEN_H