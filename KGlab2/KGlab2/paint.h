#pragma once

#include <iostream>
#include "funcs.h"
#include <gcroot.h>

#define POINTRADIUS 2	//радиус точки при отрисовке
#define OTSTUP 20		//отступ от краёв холста

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

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

void DrawPoint(Graphics^ canvas, canvaspoint *point, Color drawcolor);
bordersstruct *get_borders_from_points(cord *head);
void DrawLine(Graphics^ canvas, canvaspoint *A, canvaspoint *B, Color drawcolor, int width);
canvaspoint* ScalePointToCanvas(cord *pt, canvasstruct *easel, bordersstruct *borders);
void DrawPicture(Graphics^ canvas, canvasstruct *easel, bordersstruct *borders,
				 lev_glaz *ptr_lev, prav_glaz *ptr_prav, volos *ptr_vls,
				 golova *ptr_glv, rot *ptr_rot, nos *ptr_nos);
void DrawPicture_pov(Graphics^ canvas, canvasstruct *easel, bordersstruct *borders,
				 lev_glaz *ptr_lev, prav_glaz *ptr_prav, volos *ptr_vls,
				 golova *ptr_glv, rot *ptr_rot, nos *ptr_nos, angle *tetta, double x, double y);