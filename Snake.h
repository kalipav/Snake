#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <deque>

class Snake_head;
class Snake_body_segment;
class Map;

class Snake
{
protected:
	// голова змейки
	Snake_head* m_p_head;

	// тельце змейки
	std::deque <Snake_body_segment*> m_body;

	// положение змейки на карте
	char** m_pp_snake_on_map;

	// длина карты
	unsigned int m_dlina_karti;

	// ширина карты
	unsigned int m_shirina_karti;

	// перерисовать силуэт змейки
	void Redraw_siluet();

	// вычисляет координату, которая наиболее быстро приведёт к еде
	void Fast_move(const int*, const int*, int*) const;

public:
	// конструктор
	Snake(const Map*);

	// деструктор
	~Snake();

	// проверка на размещение объектов на карте, чтобы не попасть на змейку
	bool Can_it_place(const int*) const;

	// вернуть значение по координате
	char Get_znachenie_po_coord(const unsigned int&, const unsigned int&) const;

	// передвинуть змейку
	void Snake_move(const Map*, bool, const int*);

	// поместить во входной массив координаты последнего сегмента
	void Get_last_segm_coord(int*) const;

	// поместить во входной массив координаты головы
	void Get_head_coord(int*) const;
};

#endif
