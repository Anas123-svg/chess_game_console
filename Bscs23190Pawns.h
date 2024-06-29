#pragma once
#ifndef PAWNS_H
#define PAWNS_H

#include "Bscs23190piece.h"
//#include "Header.h"



class Pawns :
    public pieces
{
public:
    Pawns(position p, color c);
    //bool is_legal_move_by_pawn(position p1, position p2);
};

#endif 