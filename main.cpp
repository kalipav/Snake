#include "defines.cpp" // содержит набор констант

#include <iostream>
#include <unistd.h> // для usleep(1000000); + sleep(1); [если задержка 1 сек]
#include <cstdlib>  // для очистки консоли - std::system("clear"); + rand();
#include <ctime>    // посев случайных чисел - srand(static_cast <unsigned int> (time(0)|clock()));
#include <deque>

#include "Other.h"   // содержит функции, не вошедшие ни в какие классы
#include "Korobka.h"
#include "Other.cpp"
#include "Korobka.cpp"

int main()
{
	for (;;)
	{
		// создаем коробку
		Korobka my_korobka(DLINA_KARTI, SHIRINA_KARTI);

		// создаем еду
		my_korobka.Generate_food();

		// отрисовка
		my_korobka.Draw_frame();

		// пауза между отрисовками
		usleep(PAUSE_DRAW_FRAME);

		// очистка экрана
		std::system("clear");
	};
	return 0;
}
