#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "Snake_head.h"
#include "Snake_head.cpp"
#include "Snake_body_segment.h"
#include "Snake_body_segment.cpp"

class Snake
{
protected:
	// голова змейки
	Snake_head* m_p_head;

	// тельце змейки
	std::deque <Snake_body_segment> m_body;

	// положение змейки на карте                   <-------------------
	//char** m_pp_snake_on_map;

public:
	// конструктор
	Snake(const Map*);

	// деструктор
	~Snake();
};

#endif
