#include "Snake.h"

// конструктор
// [in] const Map* - карта
Snake::Snake(const Map* p_MAP)
{
		// создаем голову змейки
	m_p_head = new Snake_head(p_MAP);

		// создаем тело змейки
	m_body.clear();
	m_body.push_front(new Snake_body_segment(m_p_head, p_MAP));

		// размещение силуэта змейки

	// получаем размеры карты
	m_dlina_karti = const_cast<Map*>(p_MAP)->Get_dliny_karti();
	m_shirina_karti = const_cast<Map*>(p_MAP)->Get_shiriny_karti();

	// создаем пространство для размещения силуэта
	m_pp_snake_on_map = new char* [m_dlina_karti];
	for (unsigned int i = 0; i < m_dlina_karti; i++)
	{
		m_pp_snake_on_map[i] = new char [m_shirina_karti];
	};
    std::cout << "Videlena pamjt' dlj silueta zmeiki.\n";

    // заполняем массив символами пространства
    for (unsigned int i = 0; i < m_dlina_karti; i++)
    {
    	for (unsigned int j = 0; j < m_shirina_karti; j++)
    	{
    		m_pp_snake_on_map[i][j] = SYMBOL_PROSTRANSTVA;
    	}
    };

    // размещаем голову змейки в массиве
    int temp_coord[2]; // объявляем временные координаты
    m_p_head->Get_head_coord(temp_coord); // получаем координаты головы
    int first = temp_coord[0];
    int second = temp_coord[1];
    m_pp_snake_on_map[first][second] = SYMBOL_SNAKE_HEAD;

    // размещаем сегменты змейки в массиве
    for (std::deque<Snake_body_segment*>::const_iterator IT = m_body.begin(); IT != m_body.end(); IT++)
    {
    	const_cast<Snake_body_segment*>(*IT)->Get_segment_coord(temp_coord); // иначе ругается на константность
        first = temp_coord[0];
        second = temp_coord[1];
        m_pp_snake_on_map[first][second] = SYMBOL_SNAKE_BODY;
    };

    // удалить или закомментировать
    std::cout << "Otrisovka silueta zmeiki:\n";  // отрисовка идет построчно, поэтому i - ширина, j - длина
    for (unsigned int i = 0; i < m_shirina_karti; i++)
    {
    	for (unsigned int j = 0; j < m_dlina_karti; j++)
    	{
    		std::cout << m_pp_snake_on_map[j][i];
    	};
    	std::cout << "\n";
    };
    std::cout << "\n";

	std::cout << "Zmeika sozdana. Segmentov tel'ca zmei: " << m_body.size() << "\n\n";
}

// деструктор
Snake::~Snake()
{
	// освобождаем объект "голова"
	delete m_p_head;

	// сначала освобождаем каждый массив символов, а потом массив указателей на массивы символов
	for (unsigned int i = 0; i < m_dlina_karti; i++)
	{
		delete [] m_pp_snake_on_map[i];
	};
	delete [] m_pp_snake_on_map;

	// освобождаем указатели на сегменты из дека
    for (std::deque<Snake_body_segment*>::const_iterator IT = m_body.begin(); IT != m_body.end(); IT++)
    {
    	delete *IT;
    };
    m_body.clear();

	std::cout << "Zmeika osvobojdena.\n";
}
