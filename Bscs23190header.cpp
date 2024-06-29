#include "Bscs23190Header.h"

void gotoRowCol(int rpos, int cpos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = cpos;
    scrn.Y = rpos;
    SetConsoleCursorPosition(hOuput, scrn);
}

void SetClr(int tcl, int bcl)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (tcl + (bcl * 16)));
}

bool is_horizontal_move(position p1, position p2) {
    return p1.x == p2.x;
}

bool is_vertical_move(position p1, position p2) {
    return p1.y == p2.y;
}

bool is_diagonal_move(position p1, position p2) {
    return abs(p1.x - p2.x) == abs(p1.y - p2.y);
}



bool getRowColbyClick_CORDSS(int& rpos, int& cpos) {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD Events;
    INPUT_RECORD InputRecord;
    SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
    do {
        ReadConsoleInput(hInput, &InputRecord, 1, &Events);
        if (InputRecord.EventType == MOUSE_EVENT) {
            if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
                cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
                rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
                return true; // Left click
            }
            else if (InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
                cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
                rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
                return false; // Right click
            }
        }
    } while (true);
}


void getRowColbyLeftClick_Cord(int& rpos, int& cpos)
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD Events;
    INPUT_RECORD InputRecord;
    SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
    do
    {
        ReadConsoleInput(hInput, &InputRecord, 1, &Events);
        if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
        {
            cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
            rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            break;
        }
    } while (true);
}