#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Bscs23190Header.h"

class plaYer {
private:
		int player_id = 0;
		color player_color;
		position p;
public:
	plaYer() {
		player_id = 0;
		player_color=White;
	}
	plaYer(int id, color color1) {
		player_id = id;
		player_color = color1;
		p.x = 0;
		p.y = 0;
	}

	void update_position(int x, int y) {
		p.x = x;
		p.y = y;
	}

    position get_position() {
		return p;
	}

	void setColor(color c) {
		player_color = c;
	}


	int getid() {
		return player_id;
	}
	color getColor() {
		return player_color;
	}
};

#endif // !PLAYER_H