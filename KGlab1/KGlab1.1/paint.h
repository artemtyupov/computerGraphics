#pragma once

#include <iostream>
#include "funcs.h"
#include <gcroot.h>
#include <complex>

#define POINTRADIUS 2	//радиус точки при отрисовке
#define OTSTUP 50		//отступ от краёв холста

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;


typedef double                 T_coord;
typedef std::complex<T_coord>  T_point;

struct bordersstruct
{
	double	Left,
			Right,
			Down,
			Up;
};

struct canvaspoint
{
	int x;
	int y;
};

struct canvasstruct
{
	gcroot<Graphics^> canvas;
	int width;
	int height;
};


#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

bordersstruct *get_borders_from_points(cord *head);
void DrawPointsList(canvasstruct *easel, cord *head, bordersstruct* borders, Color drawcolor);
treangle *DrawResult(canvasstruct *easel, bordersstruct* borders, treangle *res);
cord *find_cord_med(treangle *head);
void DrawLine(Graphics^ canvas, canvaspoint *A, canvaspoint *B, Color drawcolor, int width);
canvaspoint* ScalePointToCanvas(cord *pt, canvasstruct *easel, bordersstruct *borders);