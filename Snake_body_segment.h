#ifndef _SNAKE_BODY_SEGMENT_H_
#define _SNAKE_BODY_SEGMENT_H_

class Snake_head;
class Map;

class Snake_body_segment
{
protected:
	// координаты сегмента {коорд. по длине; коорд. по ширине}
	int m_coord_segm[2];

public:
	// конструктор
	Snake_body_segment(const Snake_head*, const Map*);

	// конструктор с координатами
	Snake_body_segment(const int*);

	// деструктор
	~Snake_body_segment();

	// помещает во входной массив координаты сегмента
	void Get_segment_coord(int*) const;

	// устанавливает новые координаты сегмента
	void Set_segment_coord(const int*);
};

#endif
