#include "figure.h"

Figures::Figures()
{
    /*
    0 0 0 0
    0 0 0 0
    0 0 0 0
    0 0 0 0
    */
    for(int i=0; i<SIZEARR; ++i)
        for(int j=0; j<SIZEARR; ++j)
            coord[i][j] = 0;
    arrSize = 3;
}

void Figures::rotate90()
{
    int temp[SIZEARR][SIZEARR] = {0,0,0,0,
                                  0,0,0,0,
                                  0,0,0,0,
                                  0,0,0,0};

    for(int i=0; i<arrSize; ++i)
        for(int j=0; j<arrSize; ++j)
        {
            if(coord[i][j] == 1)
            temp[j][arrSize-1-i] = 1;
        }

    for(int i=0; i<arrSize; ++i)
        for(int j=0; j<arrSize; ++j)
            coord[i][j] = temp[i][j];
}

int Figures::getArrSize() const
{
    return arrSize;
}

TFigure::TFigure()
{
    /*
    0 0 0
    0 X 0
    X X X
    */
    coord[1][1] = 1;
    coord[2][0] = 1;
    coord[2][1] = 1;
    coord[2][2] = 1;
}

JFigure::JFigure()
{
    /*
    0 X 0
    0 X 0
    X X 0
    */

    coord[0][1] = 1;
    coord[1][1] = 1;
    coord[2][0] = 1;
    coord[2][1] = 1;
}

LFigure::LFigure()
{
    /*
    X 0 0
    X 0 0
    X X 0
    */
    coord[0][0] = 1;
    coord[1][0] = 1;
    coord[2][0] = 1;
    coord[2][1] = 1;
}

SFigure::SFigure()
{
    /*
    0 0 0
    0 X X
    X X 0
    */
    coord[1][1] = 1;
    coord[1][2] = 1;
    coord[2][0] = 1;
    coord[2][1] = 1;
}

ZFigure::ZFigure()
{
    /*
    0 0 0
    X X 0
    0 X X
    */
    coord[1][0] = 1;
    coord[1][1] = 1;
    coord[2][1] = 1;
    coord[2][2] = 1;
}

IFigure::IFigure()
{
    /*
    0 X 0 0
    0 X 0 0
    0 X 0 0
    0 X 0 0
    */
    coord[0][1] = 1;
    coord[1][1] = 1;
    coord[2][1] = 1;
    coord[3][1] = 1;

    arrSize = SIZEARR;
}

CubeFigure::CubeFigure()
{
    /*
    0 0 0
    X X 0
    X X 0
    */
    coord[1][0] = 1;
    coord[1][1] = 1;
    coord[2][0] = 1;
    coord[2][1] = 1;
}
