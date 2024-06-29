#include "Bscs23190king.h"

king::king(position p, color c) :pieces(p, c) {
    if (c == BLACK) {
        sym = 'k'; 
    }
    else {
        sym = 'K'; 
    }
}