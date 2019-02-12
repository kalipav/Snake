#ifndef _FOOD_H_
#define _FOOD_H_

class Food
{
protected:
	const char m_food;

public:
	// конструктор
	Food():
	m_food(SYMBOL_FOOD)
	{
		std::cout << "Eda sozdana.\n";
	};

	// деструктор
	~Food()
	{
		std::cout << "Eda osvobojdena.\n";
	};
};

#endif
