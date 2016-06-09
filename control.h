#pragma once

#include "console.h"
#include "figure.h"

class ControlTetris : public Console
{
private:
	const int SIZE;// размер массива с фигурами
	const float SPEED;// скорость игры

    int xArea;//размер поля по ширине
    int yArea;//длина поля
    int x;//координаты фигуры
    int y;//координаты фигуры
    int nextFigure;//номер следующей фигуры
	float step; // сумма времени итераций

	Figures *figures[7];
	Figures *figure;
public:
    ControlTetris();
    void newGame();
	void coordinates();//задаю начало координат для новой фигуры
    void createPlayingArea();//рисую границы игрового поля
    void cleaningPlayingArea();//очищаю поле для новой игры
	void showFigure();//показываю фигуру на игровом поле
    void showNextFigure();//показывает справа фигуру, которая будет следующей
	void move();//движение фигуры вниз
	void clearPrevious();//очистка предыдущей фигуры
	void Line();// проверка собрана линия
	void genNextFigure();// генерирую следующую фигуру

	bool ifObstracle();// если фигура натолкнулась на препятствие снизу
	bool ifObstacleSide(char side);// проверка при передвижении фигуры в сторону на препятствия
	bool ifRotate();// проверка, можно ли фигуру поворачивать, не наткнётся ли на препятствия

    Figures * figuresFactory(int &number);//фабрика фигур

	virtual void UpdateF(float deltaTime);
    virtual void KeyPressed(int btnCode);

    ~ControlTetris();
};

