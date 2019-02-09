#ifndef _PROSTRANSTVO_H_
#define _PROSTRANSTVO_H_

class Prostranstvo
{
protected:
	unsigned int m_dlina_prostranstva;
	unsigned int m_shirina_prostranstva;
public:
	// конструктор
	Prostranstvo(const unsigned int&, const unsigned int&);

	// деструктор
	~Prostranstvo();
};

#endif
