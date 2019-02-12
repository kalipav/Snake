#include "Map.h"

// конструктор
// [in] const unsigned int& - длина карты
// [in] const unsigned int& - ширина карты
Map::Map(const unsigned int& r_DLINA_KARTI, const unsigned int& r_SHIRINA_KARTI):
Granica(),
// чтобы змейка поместилась в своб. пространстве
m_dlina_karti(r_DLINA_KARTI < MIN_DLINA_KARTI ? MIN_DLINA_KARTI : r_DLINA_KARTI),
m_shirina_karti(r_SHIRINA_KARTI < MIN_SHIRINA_KARTI ? MIN_SHIRINA_KARTI : r_SHIRINA_KARTI)
{
	// создаем карту
	// сначала создается массив указателей на char, а потом массивы типа char
	m_p_map = new char* [m_shirina_karti];
	for (unsigned int i = 0; i < m_shirina_karti; i++)
	{
		m_p_map[i] = new char [m_dlina_karti];
	};
    std::cout << "Videlena pamjt' dlj karti.\n";

    // заносим символы свободного пространства
    for (unsigned int i = 0; i < m_shirina_karti; i++)
    {
    	for (unsigned int j = 0; j < m_dlina_karti; j++)
    	{
    		m_p_map[i][j] = SYMBOL_PROSTRANSTVA;
    	}
    };

    // заносим символы границы (первые и последние строки и столбцы)
	for (unsigned int i = 0; i < m_dlina_karti; i++)
	{
		m_p_map[0][i] = SYMBOL_GRANICA;
		m_p_map[m_shirina_karti - 1][i] = SYMBOL_GRANICA;
	};
	for (unsigned int i = 0; i < m_shirina_karti; i++)
	{
		m_p_map[i][0] = SYMBOL_GRANICA;
		m_p_map[i][m_dlina_karti - 1] = SYMBOL_GRANICA;
	};
    std::cout << "Karta sozdana.\n";

    // удалить  или закомментировать
    std::cout << "Otrisovka:\n";
    for (unsigned int i = 0; i < m_shirina_karti; i++)
    {
    	for (unsigned int j = 0; j < m_dlina_karti; j++)
    	{
    		std::cout << m_p_map[i][j];
    	};
    	std::cout << "\n";
    };
}

// деструктор
Map::~Map()
{
	// сначала освобождаем каждый массив символов, а потом массив указателей на массивы символов
	for (unsigned int i = 0; i < m_shirina_karti; i++)
	{
		delete [] m_p_map[i];
	}
	delete [] m_p_map;

	std::cout << "Karta osvobogdena.\n";
}
