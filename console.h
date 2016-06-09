#pragma once
#include <windows.h>

class Console
{
private:
    HANDLE hStdOut;
    COORD coord;
public:
    Console();
    void setChar(int x, int y, char c);
    char getChar(int x, int y);
};
