#ifndef _GRANICA_H_
#define _GRANICA_H_

class Granica
{
protected:
	// символ, обозначающий границу
	const char m_granica;
public:
	// конструктор
	Granica():
	m_granica(SYMBOL_GRANICA)
	{
		std::cout << "Granica sozdana.\n";
	};

	// деструктор
	~Granica()
	{
		std::cout << "Granica osvobogdena.\n";
	};
};

#endif
