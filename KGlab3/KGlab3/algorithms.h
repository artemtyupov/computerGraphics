#pragma once
#include "paint.h"
#define I 256 //количество уровней интенсивности
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define SIGN(x) ( (x) < 0 ? (-1) : ((x)==0 ? 0 : (1)) )
#define ABS(x) ( (x) < 0 ? (x)*(-1) : (x) )

void standartDraw(Graphics^ canvas, int x1, int y1, int x2, int y2, int width, Color drawcolor);
void cdaDraw(Bitmap^ bm, int x1, int y1, int x2, int y2, int width, Color drawcolor);
void doubleBrezDraw(Bitmap^ bm, int x1, int y1, int x2, int y2, int width, Color drawcolor);
void integerBrezDraw(Bitmap^ bm, int x1, int y1, int x2, int y2, int width, Color drawcolor);
void smoothBrezDraw(Bitmap^ bm, int x1, int y1, int x2, int y2, int width, Color maincolor, Color backcolor);