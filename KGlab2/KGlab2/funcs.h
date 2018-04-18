#pragma once

#include <iostream>
#include <cmath>


#define PI 3.141592
#define ALPH "qwertyuiopasdfghjklzxcvbnméöóêåíãøùçõúôûâàïðîëäæýÿ÷ñìèòüáþ\/|?!@#$%^&*()¹;:*=¸`~"
#define dbl_err 1.143123432154352345324532

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

struct cord
{
	double x;
	double y;
	cord *next;
};

struct lev_glaz
{
	double x;
	double y;
	double lenx;
	double leny;
	lev_glaz *prev;
};

struct prav_glaz
{
	double x;
	double y;
	double lenx;
	double leny;
	prav_glaz *prev;
};

struct volos
{
	double x1, y1;
	double x2, y2;
	double x3, y3;
	double x4, y4;
	double x5, y5;
	double cx1, cy1;
	double cx2, cy2;
	double cx3, cy3;
	double cx4, cy4;
	double cx5, cy5;
	volos *prev;
}; 

struct golova
{
	double x;
	double y;
	double lenx;
	double leny;
	double scale;
	golova *prev;
};

struct rot
{
	double x1, y1;
	double x2, y2;
	double x3, y3;
	rot *prev;
};

struct nos
{
	double x1, y1;
	double x2, y2;
	double x3, y3;
	nos *prev;
};

struct angle
{
	double ugol;
	angle *prev;
};

void Init_lists(lev_glaz *ptr_lev, prav_glaz *ptr_prav, volos *ptr_vls,
				 golova *ptr_glv, rot *ptr_rot, nos *ptr_nos);
double check_and_convert(String ^str);

void Mashtab(double x, double y, double kx, double ky, lev_glaz *ptr_lev,
			 prav_glaz *ptr_prav, volos *ptr_vls, golova *ptr_glv,
			 rot *ptr_rot, nos *ptr_nos);

void Perenos(double dx, double dy, lev_glaz *ptr_lev, 
			 prav_glaz *ptr_prav, volos *ptr_vls,
			 golova *ptr_glv, rot *ptr_rot, nos *ptr_nos);

void Povorot(double x, double y, double a, lev_glaz *ptr_lev,
			 prav_glaz *ptr_prav, volos *ptr_vls, golova *ptr_glv,
			 rot *ptr_rot, nos *ptr_nos);

void init_prev(lev_glaz *ptr_lev, prav_glaz *ptr_prav, volos *ptr_vls,
		   golova *ptr_glv, rot *ptr_rot, nos *ptr_nos);

void init_prev_to_new(lev_glaz *ptr_lev, prav_glaz *ptr_prav, volos *ptr_vls,
		   golova *ptr_glv, rot *ptr_rot, nos *ptr_nos);