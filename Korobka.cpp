#include "Korobka.h"

// конструктор
//[in] const unsigned int& - длина карты
//[in] const unsigned int& - ширина карты
Korobka::Korobka(const unsigned int& r_DLINA_MAP, const unsigned int& r_SHIRINA_MAP)
{
	// конструктор карты
	m_p_map = new Map(r_DLINA_MAP, r_SHIRINA_MAP);

	// конструктор змейки
	m_p_snake = new Snake(m_p_map);

	// еда
	m_p_food = NULL;

    std::cout << "Korobka sozdana.\n";
}

// деструктор
Korobka::~Korobka()
{
	delete m_p_map;
	delete m_p_snake;
	delete m_p_food;

	std::cout << "Korobka osvobojdena.\n";
}

// поместить еду в коробку
void Korobka::Generate_food()
{
	m_p_food = new Food(m_p_map, m_p_snake);
}

// возвращает длину коробки
// [out] unsigned int - длина коробки
unsigned int Korobka::Get_dlina_box() const
{
	return m_p_map->Get_dliny_karti();
}

// возвращает ширину коробки
// [out] unsigned int - ширина коробки
unsigned int Korobka::Get_shirina_box() const
{
	return m_p_map->Get_shiriny_karti();
}

// создает комплексный слой, содержащий все объекты
// [in/out] char** - указатель на комплексный слой, который нужно заполнить
void Korobka::Get_complex_layer(char** pp_complex_layer) const
{
	// заполняет комплексный слой значениями с карты
	for (unsigned int i = 0; i < m_p_map->Get_dliny_karti(); i++)
	{
		for (unsigned int j = 0; j < m_p_map->Get_shiriny_karti(); j++)
		{
			pp_complex_layer[i][j] = m_p_map->Get_znachenie_po_coord(i, j);
		}
	};

	// заполняет комплексный слой значениями с силуэта змейки
	for (unsigned int i = 0; i < m_p_map->Get_dliny_karti(); i++)
	{
		for (unsigned int j = 0; j < m_p_map->Get_shiriny_karti(); j++)
		{
			if (m_p_snake->Get_znachenie_po_coord(i, j) == SYMBOL_PROSTRANSTVA)
			{
				continue;
			}
			else
			{
				pp_complex_layer[i][j] = m_p_snake->Get_znachenie_po_coord(i, j);
			};
		}
	};

	// заполняет комплексный слой значениями с силуэта еды
	if (m_p_food != NULL) // еда присутствует в поле
	{
		for (unsigned int i = 0; i < m_p_map->Get_dliny_karti(); i++)
		{
			for (unsigned int j = 0; j < m_p_map->Get_shiriny_karti(); j++)
			{
				if (m_p_food->Get_znachenie_po_coord(i, j) == SYMBOL_PROSTRANSTVA)
				{
					continue;
				}
				else
				{
					pp_complex_layer[i][j] = m_p_food->Get_znachenie_po_coord(i, j);
				};
			}
		};
	}
	else // еда отсутствует в поле
	{
		return;
	}
}

// отрисовка кадра
void Korobka::Draw_frame() const
{
	// длина области отрисовки
	const unsigned int dlina = m_p_map->Get_dliny_karti();

	// ширина области отрисовки
	const unsigned int shirina = m_p_map->Get_shiriny_karti();

	// массив с комплексным слоем, на котором находятся и карта, и змейка, и еда
	char** pp_complex_layer = new char* [dlina];
	for (unsigned int i = 0; i < dlina; i++)
	{
		pp_complex_layer[i] = new char [shirina];
	};

		// запись комплексного слоя
	// заполняет комплексный слой значениями с карты
	for (unsigned int i = 0; i < dlina; i++)
	{
		for (unsigned int j = 0; j < shirina; j++)
		{
			pp_complex_layer[i][j] = m_p_map->Get_znachenie_po_coord(i, j);
		}
	};

	// заполняет комплексный слой значениями с силуэта змейки
	for (unsigned int i = 0; i < dlina; i++)
	{
		for (unsigned int j = 0; j < shirina; j++)
		{
			if (m_p_snake->Get_znachenie_po_coord(i, j) == SYMBOL_PROSTRANSTVA)
			{
				continue;
			}
			else
			{
				pp_complex_layer[i][j] = m_p_snake->Get_znachenie_po_coord(i, j);
			};
		}
	};

	// заполняет комплексный слой значениями с силуэта еды
	if (m_p_food != NULL) // если еда присутствует в поле
	{
		for (unsigned int i = 0; i < dlina; i++)
		{
			for (unsigned int j = 0; j < shirina; j++)
			{
				if (m_p_food->Get_znachenie_po_coord(i, j) == SYMBOL_PROSTRANSTVA)
				{
					continue;
				}
				else
				{
					pp_complex_layer[i][j] = m_p_food->Get_znachenie_po_coord(i, j);
				};
			}
		};
	};

	// отрисовка комплексного слоя
	std::cout << "-----------------------------------------------\n\n";
    for (unsigned int i = 0; i < shirina; i++)
    {
    	for (unsigned int j = 0; j < dlina; j++)
    	{
    		std::cout << pp_complex_layer[j][i];
    	};
    	std::cout << "\n";
    };
    std::cout << "\n-----------------------------------------------\n";

	// очистка массива
	for (unsigned int i = 0; i < dlina; i++)
	{
		delete [] pp_complex_layer[i];
	};
	delete [] pp_complex_layer;
}

// игровая механика
void Korobka::Game_mechanic()
{
	// передвинуть змейку
	m_p_snake->Snake_move(m_p_map);




	// поместить еду в коробку
	//Generate_food();
}
