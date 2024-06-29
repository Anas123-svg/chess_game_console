#pragma once
#pragma once
#ifndef PIECE_H
#define PIECE_H
#include<iostream>
#include "Bscs23190Header.h"
using namespace std;

class pieces {
protected:
	position Pos;
	color Col;
	char sym;
	int f = 0;
public:

	pieces(position p, color c) {
		Pos = p;
		Col = c;
	}
	void Draw() {
		position pf;
		pf.x = Pos.x + 4;
		pf.y = Pos.y + 30;
		gotoRowCol(Pos.x, Pos.y);
		if(Pos.x%2==0 && Pos.y%2==0)
			SetClr(0, 15);
		else if(Pos.x % 2 == 1 && Pos.y % 2 == 0)
			SetClr(15, 0);
		else if (Pos.x % 2 == 0 && Pos.y % 2 == 1)
			SetClr(15, 0);
		else {
			SetClr(0, 15);
		}
		cout <<sym;
	}

	void unDraw() {
		gotoRowCol(Pos.x, Pos.y);
		cout << " ";
	}

	void Move(position p) {
		Pos = p;
	}

	void update(position p) {
		unDraw();
		Move(p);
		Draw();
	}
	char getSym() {
		return sym;
	}
	void setSym(char s) {
		sym = s;
	}
};

#endif // PIECE_H