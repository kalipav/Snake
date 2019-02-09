#ifndef _KOROBKA_H_
#define _KOROBKA_H_

#include "Prostranstvo.h"
#include "Prostranstvo.cpp"
#include "Map.h"
#include "Map.cpp"
#include "Snake.h"
#include "Snake.cpp"
#include "Food.h"



// отрисовка слоёв: пространство -> карта -> змея -> еда

// конструктор коробки: карта -> пространство -> змея -> еда
// карта перед пространством, т.к. по карте будут определяться габариты пространства


class Korobka
{
protected:
	// карта
	Map* m_p_map;


	//Prostranstvo m_prostranstvo;


	//Snake m_snake;


	//Food m_food;

public:
	// конструктор
	Korobka(const unsigned int&, const unsigned int&);

	// деструктор
	~Korobka();
};


#endif
