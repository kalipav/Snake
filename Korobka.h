#ifndef _KOROBKA_H_
#define _KOROBKA_H_

#include "Map.h"
#include "Map.cpp"
#include "Snake.h"
#include "Snake.cpp"
#include "Food.h"
#include "Food.cpp"

class Korobka
{
protected:
	// карта
	Map* m_p_map;

	// змейка
	Snake* m_p_snake;

	// еда
	Food* m_p_food;

public:
	// конструктор
	Korobka(const unsigned int&, const unsigned int&);

	// деструктор
	~Korobka();

	// поместить еду в коробку
	void Generate_food();

	// возвращает длину коробки
	unsigned int Get_dlina_box() const;

	// возвращает ширину коробки
	unsigned int Get_shirina_box() const;

	// создает комплексный слой, содержащий все объекты
	void Get_complex_layer(char**) const;
};


#endif
