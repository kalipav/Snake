#ifndef _KOROBKA_H_
#define _KOROBKA_H_

#include "Map.h"
#include "Map.cpp"
#include "Snake.h"
#include "Snake.cpp"
#include "Food.h"

class Korobka
{
protected:
	// карта
	Map* m_p_map;

	// змейка
	Snake* m_p_snake;


	//Food m_food;

public:
	// конструктор
	Korobka(const unsigned int&, const unsigned int&);

	// деструктор
	~Korobka();
};


#endif
