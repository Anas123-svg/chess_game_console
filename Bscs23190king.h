#pragma once
#ifndef KING_H
#define KING_H

#include "Bscs23190piece.h"

class king :
    public pieces
{
public:
    king(position p, color c);
};

#endif // !KING_H