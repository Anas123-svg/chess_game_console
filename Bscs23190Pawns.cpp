#include "Bscs23190Pawns.h"


Pawns::Pawns(position p, color c) : pieces(p, c) {
    if (c == BLACK) {
        sym = 'p';
    }
    else {
        sym = 'P';
    }
}
