#pragma once
#ifndef BISHOP_H
#define BISHOP_H



#include "Bscs23190piece.h"
class Bishop :
    public pieces
{
public:
    Bishop(position p, color c); 
  //  bool is_legal_move_by_bishop(position start, position end, board* broad[][8]);
};

#endif // !BISHOP_H