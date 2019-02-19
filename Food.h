#ifndef _FOOD_H_
#define _FOOD_H_

class Food
{
protected:
	// положение еды на карте
	//char** m_pp_food_on_map;

public:
	// конструктор
	Food()
	{
		std::cout << "Eda sozdana s parametrami:\n";
	};

	// деструктор
	~Food()
	{
		std::cout << "Eda osvobojdena.\n";
	};
};

#endif
