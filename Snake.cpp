#include "Snake.h"

// конструктор
Snake::Snake()
{
	m_p_head = new Snake_head();
	m_body.clear();

	std::cout << "Zmeika sozdana.\n";
}

// деструктор
Snake::~Snake()
{
	delete m_p_head;

	std::cout << "Zmeika osvobojdena.\n";
}
