﻿#ifndef _MAP_H_
#define _MAP_H_

class Map
{
protected:
	// длина карты
	unsigned int m_dlina_karti;

	// ширина карты
	unsigned int m_shirina_karti;

	// карта
	char** m_pp_map;

public:
	// конструктор
	Map(const unsigned int&, const unsigned int&);

	// деструктор
	~Map();

	// оператор присваивания для копии карты
	//Map operator= (const Map&);

	// установить координаты головы змейки
	//void Get_coord_for_head(int*);

	// проверка на размещение объектов на карте
	bool Can_it_place(const int*) const;

	// вернуть длину карты
	unsigned int Get_dliny_karti() const;

	// вернуть ширину карты
	unsigned int Get_shiriny_karti() const;

	// вернуть значение по координате
	char Get_znachenie_po_coord(const unsigned int&, const unsigned int&) const;
};

#endif
