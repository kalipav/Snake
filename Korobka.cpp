#include "Korobka.h"

// конструктор
//[in] const unsigned int& - длина карты
//[in] const unsigned int& - ширина карты
Korobka::Korobka(const unsigned int& r_DLINA_MAP, const unsigned int& r_SHIRINA_MAP)
{
	// конструктор карты
	m_p_map = new Map(r_DLINA_MAP, r_SHIRINA_MAP);

	// конструктор змейки
	m_p_snake = new Snake(m_p_map);

    std::cout << "Korobka sozdana.\n";
}

// деструктор
Korobka::~Korobka()
{
	delete m_p_map;
	delete m_p_snake;

	std::cout << "Korobka osvobojdena.\n";
}
