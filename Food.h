#ifndef _FOOD_H_
#define _FOOD_H_

class Food
{
protected:
	// положение еды на карте
	char** m_pp_food_on_map;

	// длина карты
	unsigned int m_dlina_karti;

	// ширина карты
	unsigned int m_shirina_karti;

public:
	// конструктор
	Food(const Map*, const Snake*);

	// деструктор
	~Food();

	// вернуть значение по координате
	char Get_znachenie_po_coord(const unsigned int&, const unsigned int&) const;
};

#endif
