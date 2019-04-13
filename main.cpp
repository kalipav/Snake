#include "defines.h" // содержит набор констант

#include <iostream>
#include <cstdlib>  // для очистки консоли - std::system("clear"); + rand();
#include <ctime>    // посев случайных чисел - srand(static_cast <unsigned int> (time(0)|clock()));
#include <deque>
#include <windows.h>

#include "Other.h"   // содержит функции, не вошедшие ни в какие классы
#include "Korobka.h"

int main()
{
	// создаем коробку
	Korobka my_korobka(DLINA_KOROBKI, SHIRINA_KOROBKI);

	// очистка экрана
	std::system("cls");

	for (;;)
	{
		// отрисовка
		my_korobka.Draw_frame();

		// игровая механика
		my_korobka.Game_mechanic();

		// пауза между отрисовками
		Sleep(PAUSE_DRAW_FRAME);

		// очистка экрана
		std::system("cls");
	};

	return 0;
}
