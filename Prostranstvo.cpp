#include "Prostranstvo.h"

// конструктор
// [in] const unsigned int& - длина пространства
// [in] const unsigned int& - ширина пространства
Prostranstvo::Prostranstvo(const unsigned int& r_DLINA_PROSTRANSTVA, const unsigned int& r_SHIRINA_PROSTRANSTVA)
{
	// чтобы змейка поместилась в своб. пространстве
    if (r_DLINA_PROSTRANSTVA < MIN_DLINA_PROSTRANSTVA)
    {
    	m_dlina_prostranstva = MIN_DLINA_ZABORA - 2 * TOLSCHINA_ZABORA;
    }
    else
    {
    	m_dlina_prostranstva = r_DLINA_ZABORA - 2 * TOLSCHINA_ZABORA;
    };

    // чтобы змейка поместилась в своб. пространстве
    if (r_SHIRINA_ZABORA < MIN_SHIRINA_ZABORA)
    {
    	m_shirina_prostranstva = MIN_SHIRINA_ZABORA - 2 * TOLSCHINA_ZABORA;
    }
    else
    {
    	m_shirina_prostranstva = r_SHIRINA_ZABORA - 2 * TOLSCHINA_ZABORA;
    };

	std::cout << "Prostranstvo sozdano.\n";
}

// деструктор
Prostranstvo::~Prostranstvo()
{
	std::cout << "Prostranstvo osvobogdeno.\n";
};
