#pragma once

#include "paint.h"
#include "algorithms.h"
#include "ticker.h"
#define _USE_MATH_DEFINES
#include <cmath>  
#define NMAX 10 //��� ������� ������������
//������������ ������ ����� ����� ������� �����-���� �������
void SelectMethod(canvasstruct *Easel, int x1, int y1, int x2, int y2, int width,
				  Color maincolor, Color backcolor, int method);

//�������� ����� ��� ��������� �������
double CalcMethod(canvasstruct *Easel, int x1, int y1, int x2, int y2, int width,
				  Color maincolor, Color backcolor, int method);

//�������� ����� � ������������ ������ �������� �� �����
void SpectreMethod(canvasstruct *Easel, int x1, int y1, int angle, int radius, int width,
				   Color maincolor, Color backcolor, int method);