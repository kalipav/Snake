#include "Snake.h"

// конструктор
// [in] const Map* - карта
Snake::Snake(const Map* p_MAP)
{
	// создает голову змейки
	m_p_head = new Snake_head(p_MAP);

	//    отсюда, зацикливается в "теле"

	// создает тело змейки
	m_body.clear();
	m_body.push_front(Snake_body_segment (m_p_head, p_MAP));

	// разместить змейку на кальке !!!

	std::cout << "Zmeika sozdana.\n";
}

// деструктор
Snake::~Snake()
{
	delete m_p_head;

	std::cout << "Zmeika osvobojdena.\n";
}
