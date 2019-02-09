#ifndef _MAP_H_
#define _MAP_H_

#include "Granica.h"  // содержит описание границы

class Map : public Granica
{
protected:
	// длина карты
	unsigned int m_dlina_karti;

	// ширина карты
	unsigned int m_shirina_karti;

	// карта
	char* m_p_map;

public:
	// конструктор
	Map(const unsigned int&, const unsigned int&);

	// деструктор
	~Map();
};

#endif
