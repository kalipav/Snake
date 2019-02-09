#ifndef _SNAKE_BODY_H_
#define _SNAKE_BODY_H_

class Snake_body
{
protected:
	// символ тельца змейки
	const char m_body;
public:
	// конструктор
	Snake_body():
	m_body(SYMBOL_SNAKE_BODY)
	{
		std::cout << "Sozdano tel'ce zmei.\n";
	};

	// деструктор
	~Snake_body()
	{
		std::cout << "Tel'ce zmei osvobogdeno.\n";
	};
};

#endif
