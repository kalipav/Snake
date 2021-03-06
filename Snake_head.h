﻿#ifndef _SNAKE_HEAD_H_
#define _SNAKE_HEAD_H_

class Map;

class Snake_head
{
protected:
	// координаты головы змейки {коорд. по длине; коорд. по ширине}
	int m_head_coord[2];

public:
	// конструктор
	Snake_head(const Map*);
	
	// деструктор
	~Snake_head();

	// помещает во входной массив координаты головы
	void Get_head_coord(int*) const;

	// устанавливает новые координаты головы
	void Set_head_coord(const int*);
};

#endif
