#ifndef _MAP_H_
#define _MAP_H_

class Map
{
protected:
	// длина карты
	const unsigned int m_dlina_karti;

	// ширина карты
	const unsigned int m_shirina_karti;

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
	bool Can_it_place(int*);
};

#endif
