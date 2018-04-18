#include "select.h"


void SelectMethod(canvasstruct *Easel, int x1, int y1, int x2, 
				  int y2, int width, Color maincolor, Color backcolor, int method)
{
	//��������� ������ ��������� � ����� ���������
	x1 += Easel->width / 2;
	x2 += Easel->width / 2;
	y1 = -y1 + Easel->height / 2;
	y2 = -y2 + Easel->height / 2;
	//width++; //��� ���������� ���������

	//�������� ��������� �������� - ��� �������� � ��������, � �� � ��������
	if (method == 0)
	{
		standartDraw(Easel->canvas, x1, y1, x2, y2, width, maincolor);
		return;
	}


	Bitmap^ bm = gcnew Bitmap(Easel->width, Easel->height, Easel->canvas); //������� ������ ������� �������
	switch (method)
	{
	case 0:
		{
			standartDraw(Easel->canvas, x1, y1, x2, y2, width, maincolor);
			break;
		}
	case 1:
		{
			cdaDraw(bm, x1, y1, x2, y2, width, maincolor);
			break;
		}
	case 2:
		{
			doubleBrezDraw(bm, x1, y1, x2, y2, width, maincolor);
			break;
		}
	case 3:
		{
			integerBrezDraw(bm, x1, y1, x2, y2, width, maincolor);
			break;
		}
	case 4:
		{
			smoothBrezDraw(bm, x1, y1, x2, y2, width, maincolor, backcolor);
			break;
		}
	}
	Easel->canvas->DrawImageUnscaled(bm,0,0); //��������������� ������������ ���� ���������� �������, �� �������
	delete bm;
}

//�������� ����� ��� ��������� �������
double CalcMethod(canvasstruct *Easel, int x1, int y1, int x2, int y2, int width, Color maincolor, Color backcolor, int method)
{
	//��������� ������ ��������� � ����� ���������
	x1 += Easel->width / 2;
	x2 += Easel->width / 2;
	y1 = -y1 + Easel->height / 2;
	y2 = -y2 + Easel->height / 2;
	
	Bitmap^ bm = gcnew Bitmap(Easel->width, Easel->height, Easel->canvas); //������� ������ ������� �������
	//������ ������������ ��� �� �����! ������ ������ �������� �������� ������!

	FrequencyTimer *ticker = new FrequencyTimer(1000000); //������� ������ �� �������������
	ticker->Start();
	
	switch (method)
	{
	case 0:
		{
			for (int i=0; i<NMAX; i++)
				standartDraw(Easel->canvas, x1, y1, x2, y2, width, maincolor);
			break;
		}
	case 1: // ���
		{
			for (int i=0; i<NMAX; i++)
				cdaDraw(bm, x1, y1, x2, y2, width, maincolor);
			break;
		}
	case 2: //��������� ��������������
		{
			for (int i=0; i<NMAX; i++)
				doubleBrezDraw(bm, x1, y1, x2, y2, width, maincolor);
			break;
		}
	case 3: //��������� �������������
		{
			for (int i=0; i<NMAX; i++)
				integerBrezDraw(bm, x1, y1, x2, y2, width, maincolor);
			break;
		}
	case 4: //��������� ������������
		{
			for (int i=0; i<NMAX; i++)
				smoothBrezDraw(bm, x1, y1, x2, y2, width, maincolor, backcolor);
			break;
		}
	}
	ticker->Stop(); //������������� ������
	double res = ticker->GetTime();
	res /= NMAX;
	delete ticker;
	return res;
}


//�������� ����� � ������������ ������ �������� �� �����
void SpectreMethod(canvasstruct *Easel, int x1, int y1, int angle, int radius, int width, Color maincolor, Color backcolor, int method)
{
	//��������� ������ ��������� � ����� ���������
	x1 += Easel->width / 2;
	y1 +=  -y1 + Easel->height / 2;
	int x2 = 0, y2 = 0;

	//�������� ��������� �������� - ��� �������� � ������, � �� � ��������
	if (method == 0)
	{
		for (double i = 0; i < 360; i += angle)
		{
			x2 = x1 + radius * cos(i * M_PI / 180);
			y2 = y1 - radius * sin(i * M_PI / 180);
			standartDraw(Easel->canvas, x1, y1, x2, y2, width, maincolor);
		}
		return;
	}


	Bitmap^ bm = gcnew Bitmap(Easel->width, Easel->height, Easel->canvas); //������� ������ ������� �������

	for (double i = 0; i < 360; i += angle)
	{
		x2 = x1 + radius * cos(i * M_PI / 180);
		y2 = y1 - radius * sin(i * M_PI / 180);

		switch (method)
		{
		case 1: // ���
			{
				cdaDraw(bm, x1, y1, x2, y2, width, maincolor);
				break;
			}
		case 2: //��������� ��������������
			{
				doubleBrezDraw(bm, x1, y1, x2, y2, width, maincolor);
				break;
			}
		case 3: //��������� �������������
			{
				integerBrezDraw(bm, x1, y1, x2, y2, width, maincolor);
				break;
			}
		case 4: //��������� ������������
			{
				smoothBrezDraw(bm, x1, y1, x2, y2, width, maincolor, backcolor);
				break;
			}
		}
	}
	Easel->canvas->DrawImageUnscaled(bm, 0, 0); //��������������� ������������ ���� ���������� �������, �� �������, ������� �������
	delete bm;
}