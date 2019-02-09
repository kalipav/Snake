#include "Korobka.h"

// конструктор
//[in] const unsigned int& - длина коробки
//[in] const unsigned int& - ширина коробки
Korobka::Korobka(const unsigned int& r_DLINA, const unsigned int& r_SHIRINA)
{
	m_p_map = new Map(r_DLINA, r_SHIRINA); // конструктор карты



    std::cout << "Korobka sozdana.\n";
}

// деструктор
{
	delete m_p_map;

	std::cout << "Korobka osvobojdena.\n";
}
