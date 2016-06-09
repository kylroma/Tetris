#include "control.h"
#include <conio.h>
#include <ctime>

ControlTetris::ControlTetris() : SIZE(7), SPEED(0.5)
{
	step = 0.0;
	nextFigure = 0;
	xArea = 11;
	yArea = 21;

	coordinates();
	createPlayingArea();
	for(int i=0; i<SIZE; ++i)
		figures[i] = figuresFactory(i);
	newGame();
}

void ControlTetris::coordinates()
{
	x = 5;
	y = 0;
}

void ControlTetris::newGame()
{
	cleaningPlayingArea();
	coordinates();//задаю начало координат для новой фигуры
	genNextFigure();
}

void ControlTetris::createPlayingArea()
{
	for(int i=0; i<xArea; ++i)
		setChar(i, yArea-1, '*');

	for(int i=0; i<yArea; ++i)
	{
		setChar(0, i, '*');
		setChar(xArea, i, '*');
	}

}

void ControlTetris::cleaningPlayingArea()
{
	for(int j=0; j<yArea-1; ++j)
		for(int i=1; i<xArea; ++i)
			setChar(i, j, ' ');
}

Figures * ControlTetris::figuresFactory(int &number)
{
	switch(number)
	{
	case 0: return new IFigure;
		break;

	case 1: return new ZFigure;
		break;

	case 2: return new SFigure;
		break;

	case 3: return new CubeFigure;
		break;

	case 4: return new LFigure;
		break;

	case 5: return new JFigure;
		break;

	case 6: return new TFigure;
		break;

	default: return new CubeFigure;
	}
}

void ControlTetris::showNextFigure()
{
	//очищаю предыдущую фигуру
	for(int i=0; i<figures[nextFigure]->getArrSize()+1; ++i)
	{
		for(int j=0; j<figures[nextFigure]->getArrSize()+1; ++j)
			setChar(15+j, 3+i, ' ');
	}

	figures[nextFigure]->rotate90();
	//рисую фигуру
	for(int i=0; i<figures[nextFigure]->getArrSize(); ++i)
	{
		for(int j=0; j<figures[nextFigure]->getArrSize(); ++j)
		{
			if(figures[nextFigure]->coord[i][j] == 1)
				setChar(15+j, 3+i, 'X');
		}
	}

}

void ControlTetris::showFigure()
{
	for(int i=0; i<figure->getArrSize(); ++i)
	{
		for(int j=0; j<figure->getArrSize(); ++j)
		{
			if(figure->coord[i][j] == 1)
				setChar(j+x, i+y, 'X');
		}
	}
}

void ControlTetris::UpdateF(float deltaTime)
{
	step += deltaTime;

	if (kbhit())
        KeyPressed (getch());//считываю клавишу

	if(step >= SPEED)
	{
		step = 0.0;
		move();
		showFigure();

		if(ifObstracle())//проверяю, не наткнулся ли на препятствие снизу
		{
			Line();
			if(y<2)// если на поле больше нет места, то новая игра
				newGame();
			else
			{
				coordinates();//задаю начало координат для новой фигуры
				genNextFigure();
				step = SPEED;
			}
		}
	}
}

void ControlTetris::genNextFigure()
{
	figure = figures[nextFigure];
	srand(time(0)+nextFigure);
	nextFigure = 0 + rand() % (SIZE-1);
	showNextFigure();
}

ControlTetris::~ControlTetris()
{
	for(int i=0; i<SIZE; ++i)
		delete figures[i];
}

void ControlTetris::move()
{
	clearPrevious();//затираю фигуру на поле
	y += 1;//смещаю фигуру вниз
}

void ControlTetris::clearPrevious()
{
	for(int i=0; i<figure->getArrSize(); ++i)
		for(int j=0; j<figure->getArrSize(); ++j)
		{
			if(figure->coord[i][j] == 1)
				setChar(j+x, i+y, ' ');
		}
}

bool ControlTetris::ifObstracle()
{
	for(int i=0; i<figure->getArrSize(); ++i)
	{
		for(int j=0; j<figure->getArrSize(); ++j)
		{
			if((figure->coord[i][j] == 1) && (figure->coord[i+1][j] != 1))
			{
				if(getChar(x+j, y+i+1) != ' ')
					return true;
			}
		}
	}
	return false;
}

void ControlTetris::KeyPressed(int btnCode)
{
	if(btnCode == 75)//влево
	{
		if(!ifObstacleSide('L'))
		{
			clearPrevious();
			--x;
			showFigure();
		}
	}

	if(btnCode == 77)//вправо
	{
		if(!ifObstacleSide('R'))
		{clearPrevious();
		++x;
		showFigure();
		}
	}

	if(btnCode == 72)//поворот фигуры
	{
		if(ifRotate())
		{
			clearPrevious();
			figure->rotate90();
			showFigure();
		}
	}

	if(btnCode == 80)//быстро вниз
	{
		if(!ifObstracle())
			step = SPEED;
	}
}

bool ControlTetris::ifObstacleSide(char side)
{
	if(side == 'L')//препятствие слева
	{
		for(int i=0; i<figure->getArrSize(); ++i)
		{
			for(int j=0; j<figure->getArrSize(); ++j)
			{
				if((figure->coord[j][i] == 1) && (figure->coord[j][i-1] != 1))
				{
					if(getChar(x+i-1, y+j) != ' ')
						return true;
				}
			}
		}
	}

	if(side == 'R')//препятствие справа
	{
		for(int j=figure->getArrSize()-1; j>=0; --j)
		{
			for(int i=0; i<figure->getArrSize(); ++i)
			{
				if((figure->coord[i][j] == 1) && (figure->coord[i][j+1] != 1))
				{
					if(getChar(x+j+1, y+i) != ' ')
						return true;
				}
			}
		}
	}
	return false;
}

bool ControlTetris::ifRotate()
{
	int k=0;
	int tempX=0;
	int tempY=0;
	for(int i=0; i<figure->getArrSize(); ++i)
	{
		for(int j=0; j<figure->getArrSize(); ++j)
		{
			if(figure->coord[i][j] == 1)
			{
				tempY = j;
				tempX = figure->getArrSize()-1-i;
				if(getChar(tempX+x, tempY+y) == ' ' || figure->coord[tempY][tempX] == 1)
					++k;
			}
		}
	}

	if(k==4)
		return true;
	else
		return false;
}

void ControlTetris::Line()
{
	for(int j=y+3; j>=0; --j)
	{
		int line = 0;

		for(int i=1; i<xArea; ++i)
			if(getChar(i, j) == 'X')
				++line;
		if(line == 10)
		{
			for(int n=1; n<xArea; ++n)
				setChar(n, j, ' ');

			for(int k = 0; k<xArea; ++k)
				for(int z = j; z>=0; --z)
					if(getChar(k, z) == 'X')
					{
						setChar(k, z+1, 'X');
						setChar(k, z, ' ');
					}
					++j;
					if(line == 0)
						j = 0;
		}
	}
}
