#pragma once

const int SIZEARR = 4;//������ ������� � ������������ ������

class Figures
{
protected:
    int arrSize;//������ ������� ����������� ��� ������
public:
    Figures();
    int coord[SIZEARR][SIZEARR];//���������� ������
    int getArrSize() const;//��������� ������� ������� ����������� ��� ������
    virtual void rotate90();//������������� ����� ��� ������ "���" - ��� ������������ �� ����
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
    virtual void rotate90(){};//������ �������
};
