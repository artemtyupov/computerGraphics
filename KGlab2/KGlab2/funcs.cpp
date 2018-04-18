#include "funcs.h"
#include <stdlib.h>
#include<vcclr.h>

void Init_lists(lev_glaz *ptr_lev, prav_glaz *ptr_prav, volos *ptr_vls,
		   golova *ptr_glv, rot *ptr_rot, nos *ptr_nos)
{
	//Заполняем левый глаз
	ptr_lev->lenx = 2;
	ptr_lev->leny = 1;
	ptr_lev->x = -3.5;
	ptr_lev->y = 1.5;

	//Заполняем правый глаз
	ptr_prav->lenx = 2;
	ptr_prav->leny = 1;
	ptr_prav->x = 1;
	ptr_prav->y = 1.5;

	//Заполняем волосы
	ptr_vls->x1 = -3;
	ptr_vls->x2 = -2;
	ptr_vls->x3 = 0;
	ptr_vls->x4 = 2;
	ptr_vls->x5 = 3;
	ptr_vls->y1 = 3;
	ptr_vls->y2 = 3;
	ptr_vls->y3 = 3;
	ptr_vls->y4 = 3;
	ptr_vls->y5 = 3;
	ptr_vls->cx1 = -1.5;
	ptr_vls->cx2 = -1;
	ptr_vls->cx3 = 0;
	ptr_vls->cx4 = 1;
	ptr_vls->cx5 = 1.5;
	ptr_vls->cy1 = 4.8;
	ptr_vls->cy2 = 4.9;
	ptr_vls->cy3 = 5;
	ptr_vls->cy4 = 4.9;
	ptr_vls->cy5 = 4.8;

	//Заполняем голову
	ptr_glv->lenx = 8;
	ptr_glv->leny = 8;
	ptr_glv->scale = 37;
	ptr_glv->x = -5;
	ptr_glv->y = 5;

	//Заполняем рот
	ptr_rot->x1 =  -2;
	ptr_rot->x2 =  2;
	ptr_rot->x3 =  0;
	ptr_rot->y1 =  -3;
	ptr_rot->y2 =  -3;
	ptr_rot->y3 =  -4;

	//Заполняем нос
	ptr_nos->x1 =  0;
	ptr_nos->x2 =  0.5;
	ptr_nos->x3 =  -0.5;
	ptr_nos->y1 =  0;
	ptr_nos->y2 =  -2;
	ptr_nos->y3 =  -2;
}

void init_prev(lev_glaz *ptr_lev, prav_glaz *ptr_prav, volos *ptr_vls,
		   golova *ptr_glv, rot *ptr_rot, nos *ptr_nos)
{
	ptr_glv->prev->scale = ptr_glv->scale;

	//Переносим левый глаз
	ptr_lev->prev->x = ptr_lev->x;
	ptr_lev->prev->y = ptr_lev->y;
	ptr_lev->prev->lenx = ptr_lev->lenx;
	ptr_lev->prev->leny = ptr_lev->leny;

	//Переносим правый глаз
	ptr_prav->prev->x = ptr_prav->x;
	ptr_prav->prev->y = ptr_prav->y;
	ptr_prav->prev->lenx = ptr_prav->lenx;
	ptr_prav->prev->leny = ptr_prav->leny;
	

	//Переносим волосы
	ptr_vls->prev->x1 = ptr_vls->x1;
	ptr_vls->prev->x2 = ptr_vls->x2;
	ptr_vls->prev->x3 = ptr_vls->x3;
	ptr_vls->prev->x4 = ptr_vls->x4;
	ptr_vls->prev->x5 = ptr_vls->x5;
	ptr_vls->prev->y1 = ptr_vls->y1;
	ptr_vls->prev->y2 = ptr_vls->y2;
	ptr_vls->prev->y3 = ptr_vls->y3;
	ptr_vls->prev->y4 = ptr_vls->y4;
	ptr_vls->prev->y5 = ptr_vls->y5;
	ptr_vls->prev->cx1 = ptr_vls->cx1;
	ptr_vls->prev->cx2 = ptr_vls->cx2;
	ptr_vls->prev->cx3 = ptr_vls->cx3;
	ptr_vls->prev->cx4 = ptr_vls->cx4;
	ptr_vls->prev->cx5 = ptr_vls->cx5;
	ptr_vls->prev->cy1 = ptr_vls->cy1;
	ptr_vls->prev->cy2 = ptr_vls->cy2;
	ptr_vls->prev->cy3 = ptr_vls->cy3;
	ptr_vls->prev->cy4 = ptr_vls->cy4;
	ptr_vls->prev->cy5 = ptr_vls->cy5;

	//Переносим голову
	ptr_glv->prev->x = ptr_glv->x;
	ptr_glv->prev->y = ptr_glv->y;

	//Переносим рот
	ptr_rot->prev->x1 = ptr_rot->x1;
	ptr_rot->prev->x2 = ptr_rot->x2;
	ptr_rot->prev->x3 = ptr_rot->x3;
	ptr_rot->prev->y1 = ptr_rot->y1;
	ptr_rot->prev->y2 = ptr_rot->y2;
	ptr_rot->prev->y3 = ptr_rot->y3;

	//Переносим нос
	ptr_nos->prev->x1 = ptr_nos->x1;
	ptr_nos->prev->x2 = ptr_nos->x2;
	ptr_nos->prev->x3 = ptr_nos->x3;
	ptr_nos->prev->y1 = ptr_nos->y1;
	ptr_nos->prev->y2 = ptr_nos->y2;
	ptr_nos->prev->y3 = ptr_nos->y3;
}

void init_prev_to_new(lev_glaz *ptr_lev, prav_glaz *ptr_prav, volos *ptr_vls,
		   golova *ptr_glv, rot *ptr_rot, nos *ptr_nos)
{
	ptr_glv->scale = ptr_glv->prev->scale;

	//Переносим левый глаз
	ptr_lev->x = ptr_lev->prev->x;
	ptr_lev->y = ptr_lev->prev->y;
	ptr_lev->lenx = ptr_lev->prev->lenx;
	ptr_lev->leny = ptr_lev->prev->leny;

	//Переносим правый глаз
	ptr_prav->x = ptr_prav->prev->x;
	ptr_prav->y = ptr_prav->prev->y;
	ptr_prav->lenx = ptr_prav->prev->lenx;
	ptr_prav->leny = ptr_prav->prev->leny;
	

	//Переносим волосы
	ptr_vls->x1 = ptr_vls->prev->x1;
	ptr_vls->x2 = ptr_vls->prev->x2;
	ptr_vls->x3 = ptr_vls->prev->x3;
	ptr_vls->x4 = ptr_vls->prev->x4;
	ptr_vls->x5 = ptr_vls->prev->x5;
	ptr_vls->y1 = ptr_vls->prev->y1;
	ptr_vls->y2 = ptr_vls->prev->y2;
	ptr_vls->y3 = ptr_vls->prev->y3;
	ptr_vls->y4 = ptr_vls->prev->y4;
	ptr_vls->y5 = ptr_vls->prev->y5;
	ptr_vls->cx1 = ptr_vls->prev->cx1;
	ptr_vls->cx2 = ptr_vls->prev->cx2;
	ptr_vls->cx3 = ptr_vls->prev->cx3;
	ptr_vls->cx4 = ptr_vls->prev->cx4;
	ptr_vls->cx5 = ptr_vls->prev->cx5;
	ptr_vls->cy1 = ptr_vls->prev->cy1;
	ptr_vls->cy2 = ptr_vls->prev->cy2;
	ptr_vls->cy3 = ptr_vls->prev->cy3;
	ptr_vls->cy4 = ptr_vls->prev->cy4;
	ptr_vls->cy5 = ptr_vls->prev->cy5;

	//Переносим голову
	ptr_glv->x = ptr_glv->prev->x;
	ptr_glv->y = ptr_glv->prev->y;

	//Переносим рот
	ptr_rot->x1 = ptr_rot->prev->x1;
	ptr_rot->x2 = ptr_rot->prev->x2;
	ptr_rot->x3 = ptr_rot->prev->x3;
	ptr_rot->y1 = ptr_rot->prev->y1;
	ptr_rot->y2 = ptr_rot->prev->y2;
	ptr_rot->y3 = ptr_rot->prev->y3;

	//Переносим нос
	ptr_nos->x1 = ptr_nos->prev->x1;
	ptr_nos->x2 = ptr_nos->prev->x2;
	ptr_nos->x3 = ptr_nos->prev->x3;
	ptr_nos->y1 = ptr_nos->prev->y1;
	ptr_nos->y2 = ptr_nos->prev->y2;
	ptr_nos->y3 = ptr_nos->prev->y3;
}

double check_and_convert(String ^str)
{
	String ^alph = ALPH;
	array<Char>^anyOf = alph->ToCharArray();
	if (str->LastIndexOfAny(anyOf) != -1)
	{
		MessageBox::Show("Введите цифры");
		return dbl_err;
	}
	else
	{
		str = str->Replace('.',',');
		return Convert::ToDouble(str);
	}
}

void Mashtab(double x, double y, double kx, double ky, lev_glaz *ptr_lev, 
			 prav_glaz *ptr_prav, volos *ptr_vls,
			 golova *ptr_glv, rot *ptr_rot, nos *ptr_nos)
{
	/*
	X1=KX*X +XM*(1-KX);
	Y1=KY*Y +YM*(1-KY),
	*/

	ptr_glv->scale = ptr_glv->scale * kx;

	//Переносим левый глаз
	ptr_lev->x = ptr_lev->x * kx + x * (1 - kx);
	ptr_lev->y = ptr_lev->y * ky + y * (1 - ky);

	//Переносим правый глаз
	ptr_prav->x = ptr_prav->x * kx + x * (1 - kx);
	ptr_prav->y = ptr_prav->y * ky + y * (1 - ky);

	//Переносим волосы
	ptr_vls->x1 = ptr_vls->x1 * kx + x * (1 - kx);
	ptr_vls->x2 = ptr_vls->x2 * kx + x * (1 - kx);
	ptr_vls->x3 = ptr_vls->x3 * kx + x * (1 - kx);
	ptr_vls->x4 = ptr_vls->x4 * kx + x * (1 - kx);
	ptr_vls->x5 = ptr_vls->x5 * kx + x * (1 - kx);
	ptr_vls->y1 = ptr_vls->y1 * ky + y * (1 - ky);
	ptr_vls->y2 = ptr_vls->y2 * ky + y * (1 - ky);
	ptr_vls->y3 = ptr_vls->y3 * ky + y * (1 - ky);
	ptr_vls->y4 = ptr_vls->y4 * ky + y * (1 - ky);
	ptr_vls->y5 = ptr_vls->y5 * ky + y * (1 - ky);
	ptr_vls->cx1 = ptr_vls->cx1 * kx + x * (1 - kx);
	ptr_vls->cx2 = ptr_vls->cx2 * kx + x * (1 - kx);
	ptr_vls->cx3 = ptr_vls->cx3 * kx + x * (1 - kx);
	ptr_vls->cx4 = ptr_vls->cx4 * kx + x * (1 - kx);
	ptr_vls->cx5 = ptr_vls->cx5 * kx + x * (1 - kx);
	ptr_vls->cy1 = ptr_vls->cy1 * ky + y * (1 - ky);
	ptr_vls->cy2 = ptr_vls->cy2 * ky + y * (1 - ky);
	ptr_vls->cy3 = ptr_vls->cy3 * ky + y * (1 - ky);
	ptr_vls->cy4 = ptr_vls->cy4 * ky + y * (1 - ky);
	ptr_vls->cy5 = ptr_vls->cy5 * ky + y * (1 - ky);

	//Переносим голову
	ptr_glv->x = ptr_glv->x * kx + x * (1 - kx);
	ptr_glv->y = ptr_glv->y * ky + y * (1 - ky);

	//Переносим рот
	ptr_rot->x1 = ptr_rot->x1 * kx + x * (1 - kx);
	ptr_rot->x2 = ptr_rot->x2 * kx + x * (1 - kx);
	ptr_rot->x3 = ptr_rot->x3 * kx + x * (1 - kx);
	ptr_rot->y1 = ptr_rot->y1 * ky + y * (1 - ky);
	ptr_rot->y2 = ptr_rot->y2 * ky + y * (1 - ky);
	ptr_rot->y3 = ptr_rot->y3 * ky + y * (1 - ky);

	//Переносим нос
	ptr_nos->x1 = ptr_nos->x1 * kx + x * (1 - kx);
	ptr_nos->x2 = ptr_nos->x2 * kx + x * (1 - kx);
	ptr_nos->x3 = ptr_nos->x3 * kx + x * (1 - kx);
	ptr_nos->y1 = ptr_nos->y1 * ky + y * (1 - ky);
	ptr_nos->y2 = ptr_nos->y2 * ky + y * (1 - ky);
	ptr_nos->y3 = ptr_nos->y3 * ky + y * (1 - ky);
}

void Perenos(double dx, double dy,  lev_glaz *ptr_lev, 
			 prav_glaz *ptr_prav, volos *ptr_vls,
			 golova *ptr_glv, rot *ptr_rot, nos *ptr_nos)
{

	//Переносим левый глаз
	ptr_lev->x = ptr_lev->x + dx;
	ptr_lev->y = ptr_lev->y + dy;

	//Переносим правый глаз
	ptr_prav->x = ptr_prav->x + dx;
	ptr_prav->y = ptr_prav->y + dy;
	

	//Переносим волосы
	ptr_vls->x1 = ptr_vls->x1 + dx;
	ptr_vls->x2 = ptr_vls->x2 + dx;
	ptr_vls->x3 = ptr_vls->x3 + dx;
	ptr_vls->x4 = ptr_vls->x4 + dx;
	ptr_vls->x5 = ptr_vls->x5 + dx;
	ptr_vls->y1 = ptr_vls->y1 + dy;
	ptr_vls->y2 = ptr_vls->y2 + dy;
	ptr_vls->y3 = ptr_vls->y3 + dy;
	ptr_vls->y4 = ptr_vls->y4 + dy;
	ptr_vls->y5 = ptr_vls->y5 + dy;
	ptr_vls->cx1 = ptr_vls->cx1 + dx;
	ptr_vls->cx2 = ptr_vls->cx2 + dx;
	ptr_vls->cx3 = ptr_vls->cx3 + dx;
	ptr_vls->cx4 = ptr_vls->cx4 + dx;
	ptr_vls->cx5 = ptr_vls->cx5 + dx;
	ptr_vls->cy1 = ptr_vls->cy1 + dy;
	ptr_vls->cy2 = ptr_vls->cy2 + dy;
	ptr_vls->cy3 = ptr_vls->cy3 + dy;
	ptr_vls->cy4 = ptr_vls->cy4 + dy;
	ptr_vls->cy5 = ptr_vls->cy5 + dy;

	//Переносим голову
	ptr_glv->x = ptr_glv->x + dx;
	ptr_glv->y = ptr_glv->y + dy;

	//Переносим рот
	ptr_rot->x1 = ptr_rot->x1 + dx;
	ptr_rot->x2 = ptr_rot->x2 + dx;
	ptr_rot->x3 = ptr_rot->x3 + dx;
	ptr_rot->y1 = ptr_rot->y1 + dy;
	ptr_rot->y2 = ptr_rot->y2 + dy;
	ptr_rot->y3 = ptr_rot->y3 + dy;

	//Переносим нос
	ptr_nos->x1 = ptr_nos->x1 + dx;
	ptr_nos->x2 = ptr_nos->x2 + dx;
	ptr_nos->x3 = ptr_nos->x3 + dx;
	ptr_nos->y1 = ptr_nos->y1 + dy;
	ptr_nos->y2 = ptr_nos->y2 + dy;
	ptr_nos->y3 = ptr_nos->y3 + dy;
}

void Povorot(double x, double y, double a, lev_glaz *ptr_lev,
			 prav_glaz *ptr_prav, volos *ptr_vls, golova *ptr_glv,
			 rot *ptr_rot, nos *ptr_nos)
{
	/*
	X1=XC+(X-XC)*COS(a)+(Y-YC)*SIN(a) (3)
	Y1=YC+(Y-YC)*COS(a)-(X-XC)*SIN(a),
	*/
	a = a * PI / 180;
	//Переносим левый глаз
	double new_x, new_y, c;
	new_x = x + (ptr_lev->x - x) * cos(a) + (ptr_lev->y - y) * sin(a);
	new_y = y + (ptr_lev->y - y) * cos(a) - (ptr_lev->x - x) * sin(a);
	ptr_lev->x = new_x;
	ptr_lev->y = new_y;
	/*
	new_x = ptr_lev->lenx * cos(a) - ptr_lev->leny * sin(a);
	new_y = ptr_lev->leny * cos(a) + ptr_lev->lenx * sin(a);
	ptr_lev->lenx = new_x;
	ptr_lev->leny = new_y;
	*/
	

	//Переносим правый глаз
	new_x = x + (ptr_prav->x - x) * cos(a) + (ptr_prav->y - y) * sin(a);
	new_y = y + (ptr_prav->y - y) * cos(a) - (ptr_prav->x - x) * sin(a);
	ptr_prav->x = new_x;
	ptr_prav->y = new_y;
	/*
	new_x = ptr_prav->lenx * cos(a) - ptr_prav->leny * sin(a);
	new_y = ptr_prav->leny * cos(a) + ptr_prav->lenx * sin(a);
	ptr_prav->lenx = new_x;
	ptr_prav->leny = new_y;
	*/
	

	//Переносим волосы
	new_x = x + (ptr_vls->x1 - x) * cos(a) + (ptr_vls->y1 - y) * sin(a);
	new_y = y + (ptr_vls->y1 - y) * cos(a) - (ptr_vls->x1 - x) * sin(a);
	ptr_vls->x1 = new_x;
	ptr_vls->y1 = new_y;
	new_x = x + (ptr_vls->x2 - x) * cos(a) + (ptr_vls->y2 - y) * sin(a);
	new_y = y + (ptr_vls->y2 - y) * cos(a) - (ptr_vls->x2 - x) * sin(a);
	ptr_vls->x2 = new_x;
	ptr_vls->y2 = new_y;
	new_x = x + (ptr_vls->x3 - x) * cos(a) + (ptr_vls->y3 - y) * sin(a);
	new_y = y + (ptr_vls->y3 - y) * cos(a) - (ptr_vls->x3 - x) * sin(a);
	ptr_vls->x3 = new_x;
	ptr_vls->y3 = new_y;
	new_x = x + (ptr_vls->x4 - x) * cos(a) + (ptr_vls->y4 - y) * sin(a);
	new_y = y + (ptr_vls->y4 - y) * cos(a) - (ptr_vls->x4 - x) * sin(a);
	ptr_vls->x4 = new_x;
	ptr_vls->y4 = new_y;
	new_x = x + (ptr_vls->x5- x) * cos(a) + (ptr_vls->y5 - y) * sin(a);
	new_y = y + (ptr_vls->y5- y) * cos(a) - (ptr_vls->x5 - x) * sin(a);
	ptr_vls->x5 = new_x;
	ptr_vls->y5 = new_y;
	new_x = x + (ptr_vls->cx1 - x) * cos(a) + (ptr_vls->cy1 - y) * sin(a);
	new_y = y + (ptr_vls->cy1 - y) * cos(a) - (ptr_vls->cx1 - x) * sin(a);
	ptr_vls->cx1 = new_x;
	ptr_vls->cy1 = new_y;
	new_x = x + (ptr_vls->cx2 - x) * cos(a) + (ptr_vls->cy2 - y) * sin(a);
	new_y = y + (ptr_vls->cy2 - y) * cos(a) - (ptr_vls->cx2 - x) * sin(a);
	ptr_vls->cx2 = new_x;
	ptr_vls->cy2 = new_y;
	new_x = x + (ptr_vls->cx3 - x) * cos(a) + (ptr_vls->cy3 - y) * sin(a);
	new_y = y + (ptr_vls->cy3 - y) * cos(a) - (ptr_vls->cx3 - x) * sin(a);
	ptr_vls->cx3 = new_x;
	ptr_vls->cy3 = new_y;
	new_x = x + (ptr_vls->cx4 - x) * cos(a) + (ptr_vls->cy4 - y) * sin(a);
	new_y = y + (ptr_vls->cy4 - y) * cos(a) - (ptr_vls->cx4 - x) * sin(a);
	ptr_vls->cx4 = new_x;
	ptr_vls->cy4 = new_y;
	new_x = x + (ptr_vls->cx5- x) * cos(a) + (ptr_vls->cy5 - y) * sin(a);
	new_y = y + (ptr_vls->cy5- y) * cos(a) - (ptr_vls->cx5 - x) * sin(a);
	ptr_vls->cx5 = new_x;
	ptr_vls->cy5 = new_y;


	//Переносим голову
	new_x = x + (ptr_glv->x - x) * cos(a) + (ptr_glv->y - y) * sin(a);
	new_y = y + (ptr_glv->y - y) * cos(a) - (ptr_glv->x - x) * sin(a);
	ptr_glv->x = new_x;
	ptr_glv->y = new_y;
	/*
	new_x = ptr_glv->lenx * cos(a) - ptr_glv->leny * sin(a);
	new_y = ptr_glv->leny * cos(a) + ptr_glv->lenx * sin(a);
	ptr_glv->lenx = new_x;
	ptr_glv->leny = new_y;
	*/

	//Переносим рот
	new_x = x + (ptr_rot->x1 - x) * cos(a) + (ptr_rot->y1 - y) * sin(a);
	new_y = y + (ptr_rot->y1 - y) * cos(a) - (ptr_rot->x1 - x) * sin(a);
	ptr_rot->x1 = new_x;
	ptr_rot->y1 = new_y;
	new_x = x + (ptr_rot->x2 - x) * cos(a) + (ptr_rot->y2 - y) * sin(a);
	new_y = y + (ptr_rot->y2 - y) * cos(a) - (ptr_rot->x2 - x) * sin(a);
	ptr_rot->x2 = new_x;
	ptr_rot->y2 = new_y;
	new_x = x + (ptr_rot->x3 - x) * cos(a) + (ptr_rot->y3 - y) * sin(a);
	new_y = y + (ptr_rot->y3 - y) * cos(a) - (ptr_rot->x3 - x) * sin(a);
	ptr_rot->x3 = new_x;
	ptr_rot->y3 = new_y;

	//Переносим нос
	new_x = x + (ptr_nos->x1 - x) * cos(a) + (ptr_nos->y1 - y) * sin(a);
	new_y = y + (ptr_nos->y1 - y) * cos(a) - (ptr_nos->x1 - x) * sin(a);
	ptr_nos->x1 = new_x;
	ptr_nos->y1 = new_y;
	new_x = x + (ptr_nos->x2 - x) * cos(a) + (ptr_nos->y2 - y) * sin(a);
	new_y = y + (ptr_nos->y2 - y) * cos(a) - (ptr_nos->x2 - x) * sin(a);
	ptr_nos->x2 = new_x;
	ptr_nos->y2 = new_y;
	new_x = x + (ptr_nos->x3 - x) * cos(a) + (ptr_nos->y3 - y) * sin(a);
	new_y = y + (ptr_nos->y3 - y) * cos(a) - (ptr_nos->x3 - x) * sin(a);
	ptr_nos->x3 = new_x;
	ptr_nos->y3 = new_y;
}