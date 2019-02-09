#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "Snake_head.h"
#include "Snake_body.h"

class Snake
{
protected:
	// голова змейки
	Snake_head* m_p_head;

	// тельце змейки
	std::deque <Snake_body> m_body;

public:
	// конструктор
	Snake();

	// деструктор
	~Snake();
};

#endif
