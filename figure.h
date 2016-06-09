#pragma once

const int SIZEARR = 4;//размер массива с координатами фигуры

class Figures
{
protected:
    int arrSize;//размер массива выделенного дл€ фигуры
public:
    Figures();
    int coord[SIZEARR][SIZEARR];//координаты фигуры
    int getArrSize() const;//получение размера массива выделенного дл€ фигуры
    virtual void rotate90();//переопредел€ю метод дл€ фигуры " уб" - его поворачивать не надо
    virtual ~Figures(){}
};

class TFigure : public Figures
{
public:
    TFigure();
};

class JFigure : public Figures
{
public:
    JFigure();
};

class LFigure : public Figures
{
public:
    LFigure();
};

class SFigure : public Figures
{
public:
    SFigure();
};

class ZFigure : public Figures
{
public:
    ZFigure();
};

class IFigure : public Figures
{
public:
    IFigure();
};

class CubeFigure : public Figures
{
public:
    CubeFigure();
    virtual void rotate90(){};//пуста€ функци€
};
