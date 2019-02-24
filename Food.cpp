#include "Food.h"

// конструктор
Food::Food(const Map* p_MAP, const Snake* p_SNAKE)
{
	// получаем размеры карты
	m_dlina_karti = const_cast<Map*>(p_MAP)->Get_dliny_karti();
	m_shirina_karti = const_cast<Map*>(p_MAP)->Get_shiriny_karti();

	// создаем пространство для размещения силуэта
	m_pp_food_on_map = new char* [m_dlina_karti];
	for (unsigned int i = 0; i < m_dlina_karti; i++)
	{
		m_pp_food_on_map[i] = new char [m_shirina_karti];
	};
    std::cout << "Videlena pamjt' dlj silueta edi.\n";

    // заполняем массив символами пространства
    for (unsigned int i = 0; i < m_dlina_karti; i++)
    {
    	for (unsigned int j = 0; j < m_shirina_karti; j++)
    	{
    		m_pp_food_on_map[i][j] = SYMBOL_PROSTRANSTVA;
    	}
    };

    // временные координаты
    int temp_coord[2];

    // проверка на возможность размещения
    do
    {
    	// генерация случайной позиции
    	temp_coord[0] = Back_random(m_dlina_karti);
    	temp_coord[1] = Back_random(m_shirina_karti);
    } while (const_cast <Map*>(p_MAP)->Can_it_place(temp_coord)||
    		 const_cast <Snake*>(p_SNAKE)->Can_it_place(temp_coord)); // необходим знак "или", а не "и"

    // размещение силуэта еды
    int first = temp_coord[0];
    int second = temp_coord[1];
    m_pp_food_on_map[first][second] = SYMBOL_FOOD;

    // удалить или закомментировать
    std::cout << "Otrisovka silueta edi:\n";  // отрисовка идет построчно, поэтому i - ширина, j - длина
    for (unsigned int i = 0; i < m_shirina_karti; i++)
    {
    	for (unsigned int j = 0; j < m_dlina_karti; j++)
    	{
    		std::cout << m_pp_food_on_map[j][i];
    	};
    	std::cout << "\n";
    };
    std::cout << "\n";

	std::cout << "Eda sozdana.\n";
}

// деструктор
Food::~Food()
{
	// сначала освобождаем каждый массив символов, а потом массив указателей на массивы символов
	for (unsigned int i = 0; i < m_dlina_karti; i++)
	{
		delete [] m_pp_food_on_map[i];
	};
	delete [] m_pp_food_on_map;


	std::cout << "Eda osvobojdena.\n";
}

// вернуть значение по координате
char Food::Get_znachenie_po_coord(const unsigned int& r_COORD_PO_DLINE, const unsigned int& r_COORD_PO_SHIRINE) const
{
	return m_pp_food_on_map[r_COORD_PO_DLINE][r_COORD_PO_SHIRINE];
}

