#ifndef _KOROBKA_H_
#define _KOROBKA_H_

#include "Map.h"
#include "Snake.h"
#include "Food.h"
#include "Map.cpp"
#include "Snake.cpp"
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

	// поместить еду в коробку
	void Generate_food();

	// проверка на совпадение координат последнего сегмента змейки и координат еды
	bool Can_increase_snake();

public:
	// конструктор
	Korobka(const unsigned int&, const unsigned int&);

	// деструктор
	~Korobka();

	// возвращает длину коробки
	unsigned int Get_dlina_box() const;

	// возвращает ширину коробки
	unsigned int Get_shirina_box() const;

	// создает комплексный слой, содержащий все объекты
	void Get_complex_layer(char**) const;

	// отрисовка кадра
	void Draw_frame() const;

	// игровая механика
	void Game_mechanic();
};


#endif
