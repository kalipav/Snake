#ifndef _SNAKE_HEAD_H_
#define _SNAKE_HEAD_H_

class Snake_head
{
protected:
	// символ головы змейки
	const char m_head;
public:
	// конструктор
	Snake_head():
	m_head(SYMBOL_SNAKE_HEAD)
	{
		std::cout << "Sozdana golova zmei.\n";
	};
	
	// деструктор
	~Snake_head()
	{
		std::cout << "Golova zmei osvobogdena.\n";
	};
};

#endif