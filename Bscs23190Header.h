#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include<Windows.h>
#include<conio.h>
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<iomanip>
#include<fstream>
#include <chrono>
#define BLACK1 0
#define BROWN 6
#define WHITE 15
#define GREEN 2
#define RED 4
#define LBLUE 9
using namespace std;

struct position {
	int x, y;
};

enum color {
	BLACK,
	White
};

void gotoRowCol(int rpos, int cpos);
void SetClr(int tcl, int bcl);
void gotorow_col(int rpos, int cpos);
bool is_horizontal_move(position p1, position p2);
bool is_vertical_move(position p1, position p2);
bool is_diagonal_move(position p1, position p2);

bool getRowColbyClick_CORDSS(int& rpos, int& cpos);
void getRowColbyLeftClick_Cord(int& rpos, int& cpos);
//bool is_horizontal_path_clear(position p1, position p2, board board1[][8]);
//bool is_vertical_path_clear(position p1, position p2, board board1[][8]);
//bool is_diagonal_path_clear(position p1, position p2, board board1[][8]);

#endif // !HEADER_H