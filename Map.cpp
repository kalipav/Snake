#include "Map.h"

// конструктор
// [in] const unsigned int& - длина карты
// [in] const unsigned int& - ширина карты
Map::Map(const unsigned int& r_DLINA_KARTI, const unsigned int& r_SHIRINA_KARTI):
// чтобы змейка поместилась в своб. пространстве
m_dlina_karti(r_DLINA_KARTI < MIN_DLINA_KARTI ? MIN_DLINA_KARTI : r_DLINA_KARTI),
m_shirina_karti(r_SHIRINA_KARTI < MIN_SHIRINA_KARTI ? MIN_SHIRINA_KARTI : r_SHIRINA_KARTI)
{
	// создаем карту
	// сначала создается массив указателей на char, а потом массивы типа char
	m_pp_map = new char* [m_dlina_karti];
	for (unsigned int i = 0; i < m_dlina_karti; i++)
	{
		m_pp_map[i] = new char [m_shirina_karti];
	};
    std::cout << "Videlena pamjt' dlj karti.\n";

    // заносим символы свободного пространства
    for (unsigned int i = 0; i < m_dlina_karti; i++)
    {
    	for (unsigned int j = 0; j < m_shirina_karti; j++)
    	{
    		m_pp_map[i][j] = SYMBOL_PROSTRANSTVA;
    	}
    };

    // заносим символы границы в первую и последнюю строки
	for (unsigned int i = 0; i < m_dlina_karti; i++)
	{
		m_pp_map[i][0] = SYMBOL_GRANICA;
		m_pp_map[i][m_shirina_karti - 1] = SYMBOL_GRANICA;
	};

	 // заносим символы границы в первый и последний столбец
	for (unsigned int i = 0; i < m_shirina_karti; i++)
	{
		m_pp_map[0][i] = SYMBOL_GRANICA;
		m_pp_map[m_dlina_karti-1][i] = SYMBOL_GRANICA;
	};
    std::cout << "Karta sozdana, dlina = " << m_dlina_karti << ", shirina = " << m_shirina_karti << "\n\n";

    // удалить или закомментировать
    std::cout << "Otrisovka karti:\n";  // отрисовка идет построчно, поэтому i - ширина, j - длина
    for (unsigned int i = 0; i < m_shirina_karti; i++)
    {
    	for (unsigned int j = 0; j < m_dlina_karti; j++)
    	{
    		std::cout << m_pp_map[j][i];
    	};
    	std::cout << "\n";
    };
    std::cout << "\n";
}

// деструктор
Map::~Map()
{
	// сначала освобождаем каждый массив символов, а потом массив указателей на массивы символов
	for (unsigned int i = 0; i < m_dlina_karti; i++)
	{
		delete [] m_pp_map[i];
	};
	delete [] m_pp_map;

	std::cout << "Karta osvobogdena.\n";
}

// оператор присваивания для копии карты
// [in] const Map& - ссылка на карту
// [out] Map - возвращает копию карты
/*
Map Map::operator= (const Map& r_MAP_FOR_COPY)
{
	if (this != &r_MAP_FOR_COPY)
	{
		// копируем размеры карты
		this->m_dlina_karti = r_MAP_FOR_COPY.m_dlina_karti;
		this->m_shirina_karti = r_MAP_FOR_COPY.m_shirina_karti;

		// создаем новую пустую карту
		this->m_pp_map = new char* [this->m_dlina_karti];
		for (unsigned int i = 0; i < this->m_dlina_karti; i++)
		{
			this->m_pp_map[i] = new char [this->m_shirina_karti];
		};

		// заполняем пустую карту
		for (unsigned int i = 0; i < this->m_dlina_karti; i++)
		{
			for (unsigned int j = 0; j < this->m_shirina_karti; j++)
			{
				this->m_pp_map[i][j] = r_MAP_FOR_COPY.m_pp_map[i][j];
			}
		};
	}; // конец if

    // удалить или закомментировать
    std::cout << "Otrisovka kopii karti:\n";
    for (unsigned int i = 0; i < m_dlina_karti; i++)
    {
    	for (unsigned int j = 0; j < m_shirina_karti; j++)
    	{
    		std::cout << m_pp_map[i][j];
    	};
    	std::cout << "\n";
    };

	std::cout << "Karta skopirovana.\n";
	return *this;
}
*/

// установить координаты головы змейки
// [in/out] int* - координаты [по длине, по ширине] головы змейки
/*
void Map::Get_coord_for_head(int* p_coord_head)
{
	// реализовать функцию случайного размещения
	p_coord_head[0] = 1;
	p_coord_head[1] = 1;
}
*/

// проверка на размещение объектов на карте
// [in] const int* - массив координат для чтения
bool Map::Can_it_place(const int* p_COORD) const
{
	// координаты
	int first = p_COORD[0];
	int second = p_COORD[1];

	// если координата не занята - true (объект можно разместить), иначе - false
	if (m_pp_map[first][second] == SYMBOL_PROSTRANSTVA)
	{
		return false; // возвращает false, чтобы можно было выйти из вызывающего цикла без использования инверсии
	}
	else
	{
		return true; // означает продолжить вызывающий цикл, то есть координата не найдена
	};
}

// вернуть длину карты
unsigned int Map::Get_dliny_karti() const
{
	return m_dlina_karti;
}

// вернуть ширину карты
unsigned int Map::Get_shiriny_karti() const
{
	return m_shirina_karti;
}

// вернуть значение по координате
char Map::Get_znachenie_po_coord(const unsigned int& r_COORD_PO_DLINE, const unsigned int& r_COORD_PO_SHIRINE) const
{
	return m_pp_map[r_COORD_PO_DLINE][r_COORD_PO_SHIRINE];
}
