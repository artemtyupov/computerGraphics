#pragma once

#include "paint.h"
#include "algorithms.h"
#include "ticker.h"
#define _USE_MATH_DEFINES
#include <cmath>  
#define NMAX 10 //для чистоты эксперимента
//отрисовываем прямую между двумя точками каким-либо методом
void SelectMethod(canvasstruct *Easel, int x1, int y1, int x2, int y2, int width,
				  Color maincolor, Color backcolor, int method);

//выбираем метод для измерения времени
double CalcMethod(canvasstruct *Easel, int x1, int y1, int x2, int y2, int width,
				  Color maincolor, Color backcolor, int method);

//выбираем метод и отрисовываем спектр отрезков из точки
void SpectreMethod(canvasstruct *Easel, int x1, int y1, int angle, int radius, int width,
				   Color maincolor, Color backcolor, int method);