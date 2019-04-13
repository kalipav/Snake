#ifndef _DEFINES_H_
#define _DEFINES_H_

// объявление символов
#define SYMBOL_GRANICA      '0'  // символ столба
#define SYMBOL_PROSTRANSTVA ' '  // символ пространства
#define SYMBOL_SNAKE_HEAD   'X'  // символ головы змейки
#define SYMBOL_SNAKE_BODY   'O'  // символ тельца змейки
#define SYMBOL_FOOD         'S'  // символ еды


// объявление параметров карты
#define DLINA_KOROBKI   30  // устанавливает длину карты
#define SHIRINA_KOROBKI 30  // устанавливает ширину карты

#define MIN_DLINA_KOROBKI   4  // минимальная длина карты, чтобы разместить змейку
#define MIN_SHIRINA_KOROBKI 4  // минимальная ширина карты, чтобы разместить змейку


// прочее
#define PAUSE_DRAW_FRAME 1   // задержка скрипта после отрисовки фрейма, мс
#define PAUSE_FOR_RANDOM 1   // задержка для функции рандом, мс

#endif