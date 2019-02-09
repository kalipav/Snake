#include "Map.h"

// конструктор
// [in] const unsigned int& - длина карты
// [in] const unsigned int& - ширина карты
Map::Map(const unsigned int& r_DLINA_KARTI, const unsigned int& r_SHIRINA_KARTI):
Granica()
{
	// чтобы змейка поместилась в своб. пространстве
    if (r_DLINA_KARTI < MIN_DLINA_PROSTRANSTVA)
    {
    	m_dlina_karti = MIN_DLINA_PROSTRANSTVA;
    }
    else
    {
    	m_dlina_karti = r_DLINA_KARTI;
    };
    	
    // чтобы змейка поместилась в своб. пространстве
    if (r_SHIRINA_KARTI < MIN_SHIRINA_PROSTRANSTVA)
    {
    	m_shirina_karti = MIN_SHIRINA_PROSTRANSTVA;
    }
    else
    {
    	m_shirina_karti = r_SHIRINA_KARTI;
    };

    // создаем карту
    m_p_map = new char [m_dlina_karti][m_shirina_karti];
    std::cout << "Videlena pamjt' dlj karty.\n";

    // заносим символы свободного пространства
    for (int i = 0; i < m_shirina_karti; i++)
    {
    	for (int j = 0; j < m_dlina_karti; j++)
    	{
    		m_p_map[i][j] = SYMBOL_PROSTRANSTVA;
    	}
    };

    // заносим символы границы (первые и последние строки и столбцы)
	for (int i = 0; i < m_dlina_karti; i++)
	{
		!!!
		//m_p_map[0][i] = SYMBOL_GRANICA;
		//m_p_map[m_shirina_karti - 1][i] = SYMBOL_GRANICA;
	};
	for (int i = 0; i < m_shirina_karti; i++)
	{
		//m_p_map[i][0] = SYMBOL_GRANICA;
		//m_p_map[i][i] = SYMBOL_GRANICA;
	};


    std::cout << "Karta sozdana.\n";
}

// деструктор
Map::~Map()
{
	delete [][] m_p_map;

	std::cout << "Karta osvobogdena.\n";
}
