#pragma once
#ifndef KNIGHT_H
#define KNIGHT_H
#include "Bscs23190piece.h"
//#include "Header.h"
class Knight :
    public pieces
{
public:
    Knight(position p, color c);
  //  bool is_legal_move_by_knight(position start, position end);
};

#endif // !KNIGHT_H
