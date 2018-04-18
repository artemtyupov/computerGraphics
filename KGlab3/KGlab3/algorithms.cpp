#include "algorithms.h"

void standartDraw(Graphics^ canvas, int x1, int y1, int x2, int y2, int width, Color drawcolor)
{
	Pen^ drawpen = gcnew Pen(drawcolor, width);

	canvas->DrawLine(drawpen, x1, y1, x2, y2);

	delete drawpen;
}

void cdaDraw(Bitmap^ bm, int x1, int y1, int x2, int y2, int width, Color drawcolor)
{
	if (x1 == x2 && y1 == y2)
	{
		if (!((x1 >= bm->Width) || (x1 < 0) || (y1 >= bm->Height) || (y1 < 0)))
			bm->SetPixel(x1, y1, drawcolor);
	}
	else
	{
		double x = x1;
		double y = y1;

		double dx = x2 - x1;
		double dy = y2 - y1;

		double l = MAX(ABS(dx), ABS(dy));

		dx = dx / l;
		dy = dy / l;

		for (int i = 1; i < l + 1; i++)
		{
			if (!((x >= bm->Width) || (x < 0) || (y >= bm->Height) || (y < 0)))
				bm->SetPixel(int(x + 0.5), int(y + 0.5), drawcolor);

			x += dx;
			y += dy;
		}
	}
}

void doubleBrezDraw(Bitmap^ bm, int x1, int y1, int x2, int y2, int width, Color drawcolor)
{
	if (x2 == x1 && y2 == y1)
	{
		if (!((x1 >= bm->Width) || (x1 < 0) || (y1 >= bm->Height) || (y1 < 0)))
			bm->SetPixel(x1,y1,drawcolor);
	}
	else
	{
		int dx = x2 - x1, dy = y2 - y1; //приращение координат
		int sx = SIGN(dx), sy = SIGN(dy); //шаг по X и по Y
		dx = ABS(dx); dy = ABS(dy); //абсолютируем приращени€
		bool swap; //флаг обмена
		if (dy > dx)
		{
			swap = true;
			int t = dy;
			dy = dx;
			dx = t;
		}
		else
		{
			swap = false;
		}
		double m = (double)dy / dx; //тангенс угла наклона
		double e = m - 0.5; //ошибка
		int xt = x1, yt = y1; //текущие координаты

		//в цикле анализируем ошибку
		for (int i = 1; i <= dx + 1; i++)
		{
			if (!((xt >= bm->Width) || (xt < 0) || (yt >= bm->Height) || (yt < 0)))
				bm->SetPixel(xt, yt, drawcolor);

			if (e >= 0)
			{
				if (swap)
					xt += sx;
				else
				{
					yt += sy;
				}
				e--;
			}
			if (swap)
				yt += sy;
			else
			{
				xt += sx;
			}
			e += m;	
		}
	}
}

void integerBrezDraw(Bitmap^ bm, int x1, int y1, int x2, int y2, int width, Color drawcolor)
{
	//если отрезок вырожденный, то отрисовываем только одну точку
	if (x2 == x1 && y2 == y1)
	{
		if (!((x1 >= bm->Width) || (x1 < 0) || (y1 >= bm->Height) || (y1 < 0)))
			bm->SetPixel(x1,y1,drawcolor);
	}
	else
	{
		int dx= x2 - x1, dy = y2 - y1; //приращение координат
		int sx = SIGN(dx), sy = SIGN(dy); //шаг по X и по Y
		dx = ABS(dx); dy = ABS(dy); //абсолютируем приращени€
		bool swap; //флаг обмена
		if (dy <= dx)
			swap = false;
		else
		{
			swap = true;
			int t = dx;
			dx = dy;
			dy = t;
		}

		int _E = 2 * dy - dx; //ошибка
		int xt = x1, yt = y1; //текущие координаты
		//в цикле анализируем ошибку
		for (int i = 1; i <= dx + 1; i++)
		{
			if (!((xt >= bm->Width) || (xt < 0) || (yt >= bm->Height) || (yt < 0)))
			{
				bm->SetPixel(xt, yt, drawcolor);
			}
			
			if (_E >= 0)
			{
				if (swap)
					xt += sx;
				else
				{
					yt += sy;
				}
				_E = _E - 2 * dx;
			}
			if (_E < 0)
			{
				if (swap)
					yt += sy;
				else
				{
					xt += sx;
				}
			}
			_E = _E + 2 * dy;			
		}
	}
}

void smoothBrezDraw(Bitmap^ bm, int x1, int y1, int x2, int y2, int width, Color maincolor, Color backcolor)
{
	
	if (x2 == x1 && y2 == y1)
	{
		if (!((x1 >= bm->Width) || (x1 < 0) || (y1 >= bm->Height) || (y1 < 0)))
			bm->SetPixel(x1, y1, maincolor);
	}
	else
	{
		int dx = x2 - x1, dy = y2 - y1; //приращение координат
		int sx = SIGN(dx), sy = SIGN(dy); //шаг по X и по Y
		dx = ABS(dx); dy = ABS(dy); //абсолютируем приращени€
		double m = (double) dy / dx; //тангенс угла наклона
		bool swap; //флаг обмена
		if (m <= 1)
			swap = false;
		else
		{
			swap = true;
			int t = dx;
			dx = dy;
			dy = t;
			m = 1 / m;
		}
		double e = I / 2; //ошибка
		int xt = x1, yt = y1; //текущие координаты
		m *= I; //корректируем тангенс
		double W = I - m; //коэффициент
		//в цикле анализируем ошибку
		for (int i = 1; i <= dx; i++)
		{
			int r, g, b; //ргб-составл€ющие цвета дл€ закраски
			double C = e/I;
			r = maincolor.R + C * (backcolor.R - maincolor.R);
			g = maincolor.G + C * (backcolor.G - maincolor.G);
			b = maincolor.B + C * (backcolor.B - maincolor.B);
			Color drawcolor = Color::FromArgb(255, r, g, b);
			if (!((xt >= bm->Width) || (xt < 0) || (yt >= bm->Height) || (yt < 0)))
			{
				bm->SetPixel(xt, yt, drawcolor);
				//»зменение ширины(необ€зательно)
				/*int k = width - 1;
				for (int j = width - 1; j > 0; j--)
				{
				
					if (j % 2 == 0)
						bm->SetPixel(xt, yt - width + k, drawcolor);
					else
					{
						bm->SetPixel(xt, yt + width - k, drawcolor);
						k++;
					}
				}*/
			}
			if (e <= W)
			{
				if (swap)
					yt += sy;
				else
				{
					xt += sx;
				}
				e = e + m;
			}
			else
			{
				xt += sx;
				yt += sy;
				e = e - W;
			}
		}
	}
}