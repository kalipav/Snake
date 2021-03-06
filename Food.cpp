﻿#include "Food.h"
#include "Map.h"
#include "Other.h"
#include "defines.h"
#include "Snake.h"

// конструктор
// [in] const Map* - карта
// [in] const Snake* - змейка
Food::Food(const Map* p_MAP, const Snake* p_SNAKE)
{
	// получаем размеры карты
	m_dlina_karti = const_cast<Map*>(p_MAP)->Get_dliny_karti();
	m_shirina_karti = const_cast<Map*>(p_MAP)->Get_shiriny_karti();

	// создаем пространство для размещения силуэта
	m_pp_food_on_map = new char* [m_dlina_karti];
	for (unsigned int i = 0; i < m_dlina_karti; i++)
	{
		m_pp_food_on_map[i] = new char [m_shirina_karti];
	};
    //std::cout << "Videlena pamjt' dlj silueta edi.\n";

    // заполняем массив символами пространства
    for (unsigned int i = 0; i < m_dlina_karti; i++)
    {
    	for (unsigned int j = 0; j < m_shirina_karti; j++)
    	{
    		m_pp_food_on_map[i][j] = SYMBOL_PROSTRANSTVA;
    	}
    };

    // временные координаты
    int temp_coord[2];

    // проверка на возможность размещения
    do
    {
    	// генерация случайной позиции
    	temp_coord[0] = Back_random(m_dlina_karti);
    	temp_coord[1] = Back_random(m_shirina_karti);
    } while (const_cast <Map*>(p_MAP)->Can_it_place(temp_coord)||
    		 const_cast <Snake*>(p_SNAKE)->Can_it_place(temp_coord)); // необходим знак "или", а не "и"

    // размещение силуэта еды
    m_dlina_coord = temp_coord[0];
    m_shirina_coord = temp_coord[1];
    m_pp_food_on_map[m_dlina_coord][m_shirina_coord] = SYMBOL_FOOD;

    // удалить или закомментировать
    /*
    std::cout << "Otrisovka silueta edi:\n";  // отрисовка идет построчно, поэтому i - ширина, j - длина
    for (unsigned int i = 0; i < m_shirina_karti; i++)
    {
    	for (unsigned int j = 0; j < m_dlina_karti; j++)
    	{
    		std::cout << m_pp_food_on_map[j][i];
    	};
    	std::cout << "\n";
    };
    std::cout << "\n";
    */

	//std::cout << "Eda sozdana.\n";
}

// деструктор
Food::~Food()
{
	// сначала освобождаем каждый массив символов, а потом массив указателей на массивы символов
	for (unsigned int i = 0; i < m_dlina_karti; i++)
	{
		delete [] m_pp_food_on_map[i];
	};
	delete [] m_pp_food_on_map;


	//std::cout << "Eda osvobojdena.\n";
}

// вернуть значение по координате
// [in] const unsigned int& - конст. ссылка на значение координаты по длине
// [in] const unsigned int& - конст. ссылка на значение координаты по ширине
// [out] char - значение по координате силуэта еды
char Food::Get_znachenie_po_coord(const unsigned int& r_COORD_PO_DLINE, const unsigned int& r_COORD_PO_SHIRINE) const
{
	return m_pp_food_on_map[r_COORD_PO_DLINE][r_COORD_PO_SHIRINE];
}

// проверка на размещение объектов на карте, чтобы не попасть на еду
// [in] const int* - массив координат
// [out] bool - результат: можно или нельзя разместить
bool Food::Can_it_place(const int* p_COORD) const
{
	// координаты
	int first = p_COORD[0];
	int second = p_COORD[1];

	// если координата не занята - true (объект можно разместить), иначе - false
	if (m_pp_food_on_map[first][second] == SYMBOL_PROSTRANSTVA)
	{
		return false; // возвращает false, чтобы можно было выйти из вызывающего цикла без использования инверсии
	}
	else
	{
		return true; // означает продолжить вызывающий цикл, то есть координата не найдена
	};
}

// помещает во входной массив координаты еды
// [in/out] int* - массив координат еды
void Food::Get_food_coord(int* p_mas_coord) const
{
	p_mas_coord[0] = m_dlina_coord;
	p_mas_coord[1] = m_shirina_coord;
}

