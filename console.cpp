#include "console.h"
#include <iostream>
using std::cout;

Console::Console()
{
   hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hStdOut, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(hStdOut, &cursorInfo);
}

void Console::setChar(int x, int y, char c)
{
    coord.X = x;
    coord.Y = y;
    if(!SetConsoleCursorPosition(hStdOut, coord))
    {
        std::cout << "Set cursor position failed: " << GetLastError();
    }
    cout << c;
}

char Console::getChar(int x, int y)
{
    CHAR lpBuffer[1];
    DWORD lpNumber;
    coord.X = x;
    coord.Y = y;
    if(!ReadConsoleOutputCharacter(hStdOut, lpBuffer, 1, coord, &lpNumber))
    {
        cout << "Read char failed: " << GetLastError();
    }
    return lpBuffer[0];
}
