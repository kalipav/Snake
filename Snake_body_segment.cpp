#include "Snake_body_segment.h"

// конструктор
// [in] const Snake_head* - голова змейки
// [in] const Map* - карта
Snake_body_segment::Snake_body_segment(const Snake_head* p_HEAD, const Map* p_MAP)
{
	// получает координаты головы
	int head_coord[2];
	const_cast <Snake_head*>(p_HEAD)->Get_head_coord(head_coord); // ругается на константность

	// выбирает возможное из 4-х положений
	int choise;
	do
	{
		// генерация случайного выбора
		choise = Back_random(4);
		switch(choise)
		{
		case 0:
			m_coord_segm[0] = head_coord[0] + 1;
			m_coord_segm[1] = head_coord[1];
			break;
		case 1:
			m_coord_segm[0] = head_coord[0];
			m_coord_segm[1] = head_coord[1] + 1;
			break;
		case 2:
			m_coord_segm[0] = head_coord[0] - 1;
			m_coord_segm[1] = head_coord[1];
			break;
		case 3:
			m_coord_segm[0] = head_coord[0];
			m_coord_segm[1] = head_coord[1] - 1;
			break;
		};
	} while (const_cast <Map*>(p_MAP)->Can_it_place(m_coord_segm)); // ругается на константность

	std::cout << "Sozdan segment zmei s parametrami:\n";
	std::cout << "Koordinati segmenta: " << m_coord_segm[0] << " " << m_coord_segm[1] << "\n\n";
}

// деструктор
Snake_body_segment::~Snake_body_segment()
{
	std::cout << "Segment zmei osvobogden.\n";
}

// помещает во входной массив координаты сегмента
// [in/out] int* - массив координат сегмента
void Snake_body_segment::Get_segment_coord(int* p_in_coord) const
{
	p_in_coord[0] = m_coord_segm[0];
	p_in_coord[1] = m_coord_segm[1];
}

// устанавливает новые координаты сегмента
// [in] const int* - новые координаты
void Snake_body_segment::Set_segment_coord(const int* p_COORD)
{
	m_coord_segm[0] = p_COORD[0];
	m_coord_segm[1] = p_COORD[1];
}

