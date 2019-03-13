#include "interface.h"
#include "student.h"

void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord);
}

int getx()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(
            GetStdHandle(STD_OUTPUT_HANDLE),
            &csbi))
        return -1;
    return csbi.dwCursorPosition.X;
}

int gety()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(
            GetStdHandle(STD_OUTPUT_HANDLE),
            &csbi))
        return -1;
    return csbi.dwCursorPosition.Y;
}

COORD getXY()
{
    return {getx(), gety()};
};


string getLineHidden() {
    string input ;
    char c = _getch();
    while(c != '\r')
    {
        cout << "*";
        input += c;
        c = _getch();
    }
    cout << endl;
    return input;
};