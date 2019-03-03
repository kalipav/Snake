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
    //std::cout << "Videlena pamjt' dlj silueta zmeiki.\n";

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
    /*
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
    */

	//std::cout << "Zmeika sozdana. Segmentov tel'ca zmei: " << m_body.size() << "\n\n";
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

	//std::cout << "Zmeika osvobojdena.\n";
}

// проверка на размещение объектов на карте, чтобы не попасть на змейку
// [in] const int* - массив координат
// [out] bool - результат: можно или нельзя разместить
bool Snake::Can_it_place(const int* p_COORD) const
{
	// координаты
	int first = p_COORD[0];
	int second = p_COORD[1];

	// если координата не занята - true (объект можно разместить), иначе - false
	if (m_pp_snake_on_map[first][second] == SYMBOL_PROSTRANSTVA)
	{
		return false; // возвращает false, чтобы можно было выйти из вызывающего цикла без использования инверсии
	}
	else
	{
		return true; // означает продолжить вызывающий цикл, то есть координата не найдена
	};
}

// вернуть значение по координате
// [in] const unsigned int& - координата по длине
// [in] const unsigned int& - координата по ширине
// [out] char - символ c силуэта змейки по входящим координатам
char Snake::Get_znachenie_po_coord(const unsigned int& r_COORD_PO_DLINE, const unsigned int& r_COORD_PO_SHIRINE) const
{
	return m_pp_snake_on_map[r_COORD_PO_DLINE][r_COORD_PO_SHIRINE];
}

// передвинуть змейку
// [in] const Map* - карта
// [in] bool - если true, то добавляется новый сегмент тельца змейки, иначе - нет
// [in] const int* - массив с координатами еды
void Snake::Snake_move(const Map* p_MAP, bool status, const int* p_FOOD_COORD)
{
	// создаем массив для размещения старых координат головы
	int old_head[2];

	// получаем координаты головы
	m_p_head->Get_head_coord(old_head);

	// массив с новыми координатами головы
	int new_head[2];

	// вычисляем координату, которая наиболее быстро приведёт к еде
	Fast_move(old_head, p_FOOD_COORD, new_head);

	// проверяем, можно ли переместиться в новое положение
	// если нельзя - осуществится вход в if
	if (const_cast<Map*>(p_MAP)->Can_it_place(new_head) || // ругается на константность, необходим символ "или"
	    this->Can_it_place(new_head))
	{
		// переменная сгенерированного выбора
		int choise;

		// цикл выбора новых координат головы
		do
		{
			// генерация случайного числа из диапазона [0;3]
			choise = Back_random(4);

			switch(choise)
			{
			case 0:
				new_head[0] = old_head[0] + 1;
				new_head[1] = old_head[1];
				break;
			case 1:
				new_head[0] = old_head[0];
				new_head[1] = old_head[1] + 1;
				break;
			case 2:
				new_head[0] = old_head[0] - 1;
				new_head[1] = old_head[1];
				break;
			case 3:
				new_head[0] = old_head[0];
				new_head[1] = old_head[1] - 1;
				break;
			};
		} while (const_cast<Map*>(p_MAP)->Can_it_place(new_head) || // ругается на константность, необходим символ "или"
				 this->Can_it_place(new_head));
	}

	// устанавливаем новые координаты головы
	m_p_head->Set_head_coord(new_head);

		// редактируем тельце
	// добавляем новый сегмент со старыми координатами головы перед остальными сегментами
	m_body.push_front(new Snake_body_segment(old_head));

	// удаляем сегмент, если координата еды не совпала со старыми координатами головы
	if (status == false)
	{
		m_body.pop_back();
	};

	// перерисовываем силуэт змейки
	this->Redraw_siluet();
}

// перерисовать силуэт змейки
void Snake::Redraw_siluet()
{
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
}

// поместить во входной массив координаты последнего сегмента
// [in/out] int* - массив, в который нужно разместить координаты
void Snake::Get_last_segm_coord(int* p_coord) const
{
	// итератор на последний элемент дека (последний сегмент тельца змейки)
	std::deque<Snake_body_segment*>::const_iterator ITER = m_body.end() - 1;

	// копирование координат последнего сегмента
	(*ITER)->Get_segment_coord(p_coord);
}

// вычисляет координату, которая наиболее быстро приведёт к еде
// [in] const int* - старые координаты головы
// [in] const int* - координаты еды
// [in/out] int* - заполняемый массив с новыми координатами головы
void Snake::Fast_move(const int* p_OLD_HEAD, const int* p_COORD_FOOD, int* p_new_head) const
{
	// копируем координаты
	p_new_head[0] = p_OLD_HEAD[0];
	p_new_head[1] = p_OLD_HEAD[1];

	// калибровка по длине и ширине, необходимо выбрать только один сдвиг
	if (p_COORD_FOOD[0] < p_new_head[0])
	{
		p_new_head[0]--;
	}
	else
	{
		if (p_COORD_FOOD[0] > p_new_head[0])
		{
			p_new_head[0]++;
		}
		else
		{
			if (p_COORD_FOOD[1] > p_new_head[1])
			{
				p_new_head[1]++;
			}
			else // в любом случае двигаться вниз, если нет препятствий
			{
				p_new_head[1]--;
			}
		};
	};
}

// поместить во входной массив координаты головы
// [in/out] int* - массив, в который нужно разместить координаты
void Snake::Get_head_coord(int* p_coord) const
{
	 m_p_head->Get_head_coord(p_coord);
}
