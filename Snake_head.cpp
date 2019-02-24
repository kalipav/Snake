﻿#include "Snake_head.h"

// конструктор
// [in] const Map* - указатель на карту
Snake_head::Snake_head(const Map* p_MAP)
{
	// перебор возможных координат размещения головы
	do
	{
		// генерация случайного положения головы змейки
		m_head_coord[0] = Back_random(const_cast <Map*>(p_MAP)->Get_dliny_karti());
		m_head_coord[1] = Back_random(const_cast <Map*>(p_MAP)->Get_shiriny_karti());
	} while (const_cast <Map*>(p_MAP)->Can_it_place(m_head_coord)); // ругается на константность

	std::cout << "Sozdana golova zmei s parametrami:\n";
	std::cout << "Koordinati golovi: " << m_head_coord[0] << " " << m_head_coord[1] << "\n\n";
}

// деструктор
Snake_head::~Snake_head()
{
	std::cout << "Golova zmei osvobogdena.\n";
}

// помещает во входной массив координаты головы
// [in/out] int* - массив координат головы
void Snake_head::Get_head_coord(int* p_mas_coord) const
{
	p_mas_coord[0] = m_head_coord[0];
	p_mas_coord[1] = m_head_coord[1];
}
