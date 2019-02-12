#include "defines.cpp" // содержит набор констант

#include <iostream>
#include <unistd.h> // для usleep(1000000); + sleep(1); [если задержка 1 сек]
#include <cstdlib>  // для очистки консоли - std::system("clear"); + rand();
#include <ctime>    // посев случайных чисел - srand(static_cast <unsigned int> (time(0)|clock()));
#include <deque>

#include "Korobka.h"
#include "Korobka.cpp"

int main()
{
	Korobka my_korobka(DLINA_KARTI, SHIRINA_KARTI);



	return 0;
}
