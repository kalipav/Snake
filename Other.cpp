#include "Other.h"
#include <cstdlib>  // для очистки консоли - std::system("clear"); + rand();
#include "defines.h"
#include <ctime>    // посев случайных чисел - srand(static_cast <unsigned int> (time(0)|clock()));
#include <windows.h>

/*
// отрисовка кадра
// [in] const Korobka* - коробка для чтения
void Draw_frame(const Korobka* p_BOX)
{
	// длина области отрисовки
	const unsigned int dlina = p_BOX->Get_dlina_box();

	// ширина области отрисовки
	const unsigned int shirina = p_BOX->Get_shirina_box();

	// массив с комплексным слоем, на котором находятся и карта, и змейка, и еда
	char** complex_layer = new char* [dlina];
	for (unsigned int i = 0; i < dlina; i++)
	{
		complex_layer[i] = new char [shirina];
	};

	// запись комплексного слоя
	p_BOX->Get_complex_layer(complex_layer);

	// отрисовка комплексного слоя
	std::cout << "-----------------------------------------------\n\n";
    for (unsigned int i = 0; i < shirina; i++)
    {
    	for (unsigned int j = 0; j < dlina; j++)
    	{
    		std::cout << complex_layer[j][i];
    	};
    	std::cout << "\n";
    };
    std::cout << "\n-----------------------------------------------\n";

	// очистка массива
	for (unsigned int i = 0; i < dlina; i++)
	{
		delete [] complex_layer[i];
	};
	delete [] complex_layer;
}
*/

// возвращает случайное значение из указанного диапазона [0; n - 1]
// [in] const int& - численно равно верхнему значению диапазона + 1
// [out] int - случайное значение из диапазона
int Back_random(const unsigned int& r_DIAPAZON)
{
	unsigned int rand_num;
	srand(static_cast <unsigned int> (time(0)|clock()));
	rand_num = rand()%r_DIAPAZON;
	Sleep(PAUSE_FOR_RANDOM);
	return rand_num;


	// для проверки работы
	/*
	int counter = 0;
	int kolvo = 1000;
	int diapazon = 1000;

	for (int i; i < kolvo; i++)
	{
		srand(static_cast <unsigned int> (time(0)|clock()));
		int n = rand()%diapazon;
		std::cout << n << "\n";
		usleep(PAUSE_FOR_RANDOM);
		counter += n;
	};
	std::cout << "srednee = " << counter/kolvo << "\n";
	*/

}
