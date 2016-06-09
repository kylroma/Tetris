#pragma once

#include "console.h"
#include "figure.h"

class ControlTetris : public Console
{
private:
	const int SIZE;// ������ ������� � ��������
	const float SPEED;// �������� ����

    int xArea;//������ ���� �� ������
    int yArea;//����� ����
    int x;//���������� ������
    int y;//���������� ������
    int nextFigure;//����� ��������� ������
	float step; // ����� ������� ��������

	Figures *figures[7];
	Figures *figure;
public:
    ControlTetris();
    void newGame();
	void coordinates();//����� ������ ��������� ��� ����� ������
    void createPlayingArea();//����� ������� �������� ����
    void cleaningPlayingArea();//������ ���� ��� ����� ����
	void showFigure();//��������� ������ �� ������� ����
    void showNextFigure();//���������� ������ ������, ������� ����� ���������
	void move();//�������� ������ ����
	void clearPrevious();//������� ���������� ������
	void Line();// �������� ������� �����
	void genNextFigure();// ��������� ��������� ������

	bool ifObstracle();// ���� ������ ������������ �� ����������� �����
	bool ifObstacleSide(char side);// �������� ��� ������������ ������ � ������� �� �����������
	bool ifRotate();// ��������, ����� �� ������ ������������, �� �������� �� �� �����������

    Figures * figuresFactory(int &number);//������� �����

	virtual void UpdateF(float deltaTime);
    virtual void KeyPressed(int btnCode);

    ~ControlTetris();
};

