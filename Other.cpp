// отрисовка кадра
// [in] const Korobka* - коробка для чтения
void Draw_frame(const Korobka* p_BOX)
{
	// длина области отрисовки
	const unsigned int dlina = p_BOX->Get_dlina_box();

	// ширина области отрисовки
	const unsigned int shirina = p_BOX->Get_shirina_box();

	// массив с комбинированным слоем, на котором находятся и карта, и змейка, и еда
	char** complex_layer = new char* [dlina];
	for (unsigned int i = 0; i < dlina; i++)
	{
		complex_layer[i] = new char [shirina];
	};

	// запись комбинированного слоя
	p_BOX->Get_complex_layer(complex_layer);

	// отрисовка
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
