#include "paint.h"

bordersstruct *get_borders_from_points(cord *head)
{
	if (!head)
		return nullptr;
	cord *cord_ptr = head;

	bordersstruct *brd_ptr = new bordersstruct;

	brd_ptr->Up = cord_ptr->y;
	brd_ptr->Down = cord_ptr->y;
	brd_ptr->Left = cord_ptr->x;
	brd_ptr->Right = cord_ptr->x;
	cord_ptr = cord_ptr->next;

	while (cord_ptr)
	{
		if (cord_ptr->y > brd_ptr->Up)
			brd_ptr->Up = cord_ptr->y;
		if (cord_ptr->y < brd_ptr->Down)
			brd_ptr->Down = cord_ptr->y;
		if (cord_ptr->x < brd_ptr->Left)
			brd_ptr->Left = cord_ptr->x;
		if (cord_ptr->x > brd_ptr->Right)
			brd_ptr->Right = cord_ptr->x;
		cord_ptr = cord_ptr->next;
	}

	return brd_ptr;

}

canvaspoint* ScalePointToCanvas(cord *pt, canvasstruct *easel, bordersstruct *borders)
{
	double scale;
	double scaleX, scaleY; //из двух масштабов выберем наименьший
	double MidX = (borders->Right + borders->Left)/2; //середина прямоугольника
	double MidY = (borders->Up + borders->Down)/2;
	double RealHeight = borders->Up - borders->Down; //действительные размеры, по сравнению с размерами холста
	double RealWidth = borders->Right - borders->Left;

	//выбираем наименьший масштаб
	scaleX = (easel->width - OTSTUP * 2) / RealWidth;
	scaleY = (easel->height - OTSTUP * 2) / RealHeight;
	if ((borders->Up != borders->Down) || (borders->Left != borders->Right))
		scale = MIN(scaleX, scaleY);

	canvaspoint *PointInCanvas = new canvaspoint;
	cord *PointInWorld = new cord;

	//смещаем точку на координату середины граничного прямоугольника
	PointInWorld->x = pt->x - MidX;
	PointInWorld->y = pt->y - MidY;

	//масштабируем её относительно центра
	PointInWorld->x *= scale;
	PointInWorld->y *= scale;

	//получаем середину холста
	PointInCanvas->x = easel->width / 2;
	PointInCanvas->y = easel->height / 2;

	//отрисовываем точку относительно неё
	PointInCanvas->x += (int) PointInWorld->x;
	PointInCanvas->y -= (int) PointInWorld->y;

	delete PointInWorld;

	return PointInCanvas;

}

cord* CanvasToScalePoint(canvaspoint *pt, canvasstruct *easel, bordersstruct *borders)
{
	double scale;
	double scaleX, scaleY; //из двух масштабов выберем наименьший
	double MidX = (borders->Right + borders->Left)/2; //середина прямоугольника
	double MidY = (borders->Up + borders->Down)/2;
	double RealHeight = borders->Up - borders->Down; //действительные размеры, по сравнению с размерами холста
	double RealWidth = borders->Right - borders->Left;

	//выбираем наименьший масштаб
	scaleX = (easel->width - OTSTUP * 2) / RealWidth;
	scaleY = (easel->height - OTSTUP * 2) / RealHeight;
	if ((borders->Up != borders->Down) || (borders->Left != borders->Right))
		scale = MIN(scaleX, scaleY);

	cord *PointInCord = new cord;
	canvaspoint *PointInWorld = new canvaspoint;

	//смещаем точку на координату середины граничного прямоугольника
	PointInWorld->x = pt->x - easel->width / 2;
	PointInWorld->y = pt->y - easel->height / 2;

	//масштабируем её относительно центра
	PointInWorld->x /= (int)scale;
	PointInWorld->y /= (int)scale;

	//получаем середину холста
	PointInCord->x = MidX;
	PointInCord->y = MidY;

	//отрисовываем точку относительно неё
	PointInCord->x += (int) PointInWorld->x;
	PointInCord->y -= (int) PointInWorld->y;

	delete PointInWorld;

	return PointInCord;

}



//рисует линию на холсте
void DrawLine(Graphics^ canvas, canvaspoint *A, canvaspoint *B, Color drawcolor, int width)
{	
	Pen^ drawpen = gcnew Pen(drawcolor, (float) width);
	canvas->DrawLine(drawpen, A->x, A->y, B->x, B->y);
	delete drawpen;
}

//рисует точку на холсте
void DrawPoint(Graphics^ canvas, canvaspoint *point, Color drawcolor)
{	
	//MessageBox::Show(String::Format("{0}, {1}",point->x, point->y));
	Pen^ drawpen = gcnew Pen(Color::Black, 1); //чёрная обводка
	SolidBrush^ drawbrush = gcnew SolidBrush(drawcolor); //цветная заливка
	Rectangle rect = Rectangle(point->x-POINTRADIUS, point->y-POINTRADIUS, POINTRADIUS*2, POINTRADIUS*2); //прямоугольнки заливки
	canvas->FillEllipse(drawbrush,rect);
	canvas->DrawEllipse(drawpen,rect);

	delete drawbrush;
	delete drawpen;
}

void DrawPicture_pov(Graphics^ canvas, canvasstruct *easel, bordersstruct *border,
				 lev_glaz *ptr_lev, prav_glaz *ptr_prav, volos *ptr_vls,
				 golova *ptr_glv, rot *ptr_rot, nos *ptr_nos, angle *tetta, double x, double y)
{
	
	Pen^ drawpen = gcnew Pen(Color::OrangeRed, (float) 2);
	//Отрисовка головы
	//Отрисовка левого глаза
	//Отрисовка правого глаза
	cord *prav = new cord;
    cord *lev = new cord, *pnt = new cord;
	cord *centr = new cord;
	centr->x = ptr_glv->x;
	centr->y = ptr_glv->y;
	lev->x = ptr_lev->x;
	lev->y =  ptr_lev->y;
	prav->x = ptr_prav->x;
	prav->y =  ptr_prav->y;
	pnt->x = x;
	pnt->y = y;
	canvaspoint *new_centr = ScalePointToCanvas(centr, easel, border);
	canvaspoint *new_lev = ScalePointToCanvas(lev, easel, border);
	canvaspoint *new_prav = ScalePointToCanvas(prav, easel, border);
	canvaspoint *new_pnt = ScalePointToCanvas(pnt, easel, border);
	
	int scale = ptr_glv->scale;
	int scale1 = 1.1;
	double arad = (tetta->ugol + tetta->prev->ugol) * PI / 180;
	double xx, yy;
	canvas->TranslateTransform(new_pnt->x, new_pnt->y);
	canvas->RotateTransform(tetta->ugol + tetta->prev->ugol);

	new_centr->x = new_centr->x  - new_pnt->x;
	new_centr->y = new_centr->y - new_pnt->y;
	xx = new_centr->x * cos(arad) + new_centr->y * sin(arad);
	yy = new_centr->y * cos(arad) - new_centr->x * sin(arad);
	new_centr->x = xx;
	new_centr->y = yy;
	canvas->DrawEllipse(drawpen, new_centr->x, new_centr->y,
		ptr_glv->lenx*scale, ptr_glv->leny*scale);

	new_prav->x = new_prav->x  - new_pnt->x;
	new_prav->y = new_prav->y - new_pnt->y;
	xx = new_prav->x * cos(arad) + new_prav->y * sin(arad);
	yy = new_prav->y * cos(arad) - new_prav->x * sin(arad);
	new_prav->x = xx;
	new_prav->y = yy;
	canvas->DrawEllipse(drawpen, new_prav->x, new_prav->y, 
		ptr_prav->lenx * scale, ptr_prav->leny * scale);

	//cord *prav_new = CanvasToScalePoint(new_prav, easel, border);
	//ptr_prav->x = prav_new->x;
	//ptr_prav->y = prav_new->y;
	new_lev->x = new_lev->x - new_pnt->x;
	new_lev->y = new_lev->y - new_pnt->y;
	xx = new_lev->x * cos(arad) + new_lev->y * sin(arad);
	yy = new_lev->y * cos(arad) - new_lev->x * sin(arad);
	new_lev->x = xx;
	new_lev->y = yy;
	canvas->DrawEllipse(drawpen, new_lev->x, new_lev->y, 
		ptr_lev->lenx * scale, ptr_lev->leny * scale);
	//cord *lev_new = CanvasToScalePoint(new_prav, easel, border);
	//ptr_lev->x = lev_new->x;
	//ptr_lev->y = lev_new->y;

	scale1 *= scale1;

	canvas->RotateTransform(360 - tetta->ugol - tetta->prev->ugol);
	tetta->prev->ugol += tetta->ugol;
	canvas->TranslateTransform(-new_pnt->x, -new_pnt->y);
	delete centr, new_centr;
	delete lev, new_lev;

	delete prav, new_prav ;

	//Отрисовка рта
	cord *tr_A = new cord, *tr_B= new cord, *tr_C = new cord;
	tr_A->x = ptr_rot->x1;
	tr_A->y = ptr_rot->y1;
	tr_B->x = ptr_rot->x2;
	tr_B->y = ptr_rot->y2;
	tr_C->x = ptr_rot->x3;
	tr_C->y = ptr_rot->y3;
	canvaspoint *new_A = ScalePointToCanvas(tr_A, easel, border);
	canvaspoint *new_B = ScalePointToCanvas(tr_B, easel, border);
	canvaspoint *new_C = ScalePointToCanvas(tr_C, easel, border);
	DrawLine(easel->canvas, new_A, new_B, Color::OrangeRed, 2);
	DrawLine(easel->canvas, new_B, new_C, Color::OrangeRed, 2);
	DrawLine(easel->canvas, new_C, new_A, Color::OrangeRed, 2);
	delete tr_A, tr_B, tr_C, new_A, new_B, new_C;

	//Отрисовка носа
	tr_A = new cord, tr_B= new cord,  tr_C = new cord;
	tr_A->x = ptr_nos->x1;
	tr_A->y = ptr_nos->y1;
	tr_B->x = ptr_nos->x2;
	tr_B->y = ptr_nos->y2;
	tr_C->x = ptr_nos->x3;
	tr_C->y = ptr_nos->y3;
	new_A = ScalePointToCanvas(tr_A, easel, border);
	new_B = ScalePointToCanvas(tr_B, easel, border);
	new_C = ScalePointToCanvas(tr_C, easel, border);
	DrawLine(easel->canvas, new_A, new_B, Color::OrangeRed, 2);
	DrawLine(easel->canvas, new_B, new_C, Color::OrangeRed, 2);
	DrawLine(easel->canvas, new_C, new_A, Color::OrangeRed, 2);
	delete tr_A, tr_B, tr_C, new_A, new_B, new_C;

	

	//Отрисовка волос
	cord *tr_1 = new cord, *tr_2= new cord, *tr_3 = new cord;
	cord *tr_4 = new cord, *tr_5= new cord, *tr_c1 = new cord;
	cord *tr_c2 = new cord, *tr_c3= new cord, *tr_c4 = new cord, *tr_c5 = new cord;
	tr_1->x = ptr_vls->x1;
	tr_1->y = ptr_vls->y1;
	tr_2->x = ptr_vls->x2;
	tr_2->y = ptr_vls->y2;
	tr_3->x = ptr_vls->x3;
	tr_3->y = ptr_vls->y3;
	tr_4->x = ptr_vls->x4;
	tr_4->y = ptr_vls->y4;
	tr_5->x = ptr_vls->x5;
	tr_5->y = ptr_vls->y5;
	tr_c1->x = ptr_vls->cx1;
	tr_c1->y = ptr_vls->cy1;
	tr_c2->x = ptr_vls->cx2;
	tr_c2->y = ptr_vls->cy2;
	tr_c3->x = ptr_vls->cx3;
	tr_c3->y = ptr_vls->cy3;
	tr_c4->x = ptr_vls->cx4;
	tr_c4->y = ptr_vls->cy4;
	tr_c5->x = ptr_vls->cx5;
	tr_c5->y = ptr_vls->cy5;
	canvaspoint *new_1 = ScalePointToCanvas(tr_1, easel, border);
	canvaspoint *new_2 = ScalePointToCanvas(tr_2, easel, border);
	canvaspoint *new_3 = ScalePointToCanvas(tr_3, easel, border);
	canvaspoint *new_4 = ScalePointToCanvas(tr_4, easel, border);
	canvaspoint *new_5 = ScalePointToCanvas(tr_5, easel, border);
	canvaspoint *new_c1 = ScalePointToCanvas(tr_c1, easel, border);
	canvaspoint *new_c2 = ScalePointToCanvas(tr_c2, easel, border);
	canvaspoint *new_c3 = ScalePointToCanvas(tr_c3, easel, border);
	canvaspoint *new_c4 = ScalePointToCanvas(tr_c4, easel, border);
	canvaspoint *new_c5 = ScalePointToCanvas(tr_c5, easel, border);
	DrawLine(easel->canvas, new_c1, new_1, Color::OrangeRed, 2);
	DrawLine(easel->canvas, new_c2, new_2, Color::OrangeRed, 2);
	DrawLine(easel->canvas, new_c3, new_3, Color::OrangeRed, 2);
	DrawLine(easel->canvas, new_c4, new_4, Color::OrangeRed, 2);
	DrawLine(easel->canvas, new_c5, new_5, Color::OrangeRed, 2);
	delete tr_1, tr_2, tr_3, tr_4, tr_5, tr_c1,
		new_1, new_2, new_3, new_4, new_5, new_c1,
		tr_c2, tr_c3, tr_c4, tr_c5, new_c2, new_c3,
		new_c4, new_c5;
}

void DrawPicture(Graphics^ canvas, canvasstruct *easel, bordersstruct *border,
				 lev_glaz *ptr_lev, prav_glaz *ptr_prav, volos *ptr_vls,
				 golova *ptr_glv, rot *ptr_rot, nos *ptr_nos)
{
	//Отрисовка головы

	cord *centr = new cord;
	centr->x = ptr_glv->x;
	centr->y = ptr_glv->y;
	canvaspoint *new_centr = ScalePointToCanvas(centr, easel, border);
	
	Pen^ drawpen = gcnew Pen(Color::OrangeRed, (float) 2);

	int scale = ptr_glv->scale;
	canvas->DrawEllipse(drawpen, new_centr->x,
		new_centr->y, ptr_glv->lenx*scale, ptr_glv->leny*scale);
	delete centr, new_centr;

	//Отрисовка рта
	cord *tr_A = new cord, *tr_B= new cord, *tr_C = new cord;
	tr_A->x = ptr_rot->x1;
	tr_A->y = ptr_rot->y1;
	tr_B->x = ptr_rot->x2;
	tr_B->y = ptr_rot->y2;
	tr_C->x = ptr_rot->x3;
	tr_C->y = ptr_rot->y3;
	canvaspoint *new_A = ScalePointToCanvas(tr_A, easel, border);
	canvaspoint *new_B = ScalePointToCanvas(tr_B, easel, border);
	canvaspoint *new_C = ScalePointToCanvas(tr_C, easel, border);
	DrawLine(easel->canvas, new_A, new_B, Color::OrangeRed, 2);
	DrawLine(easel->canvas, new_B, new_C, Color::OrangeRed, 2);
	DrawLine(easel->canvas, new_C, new_A, Color::OrangeRed, 2);
	delete tr_A, tr_B, tr_C, new_A, new_B, new_C;

	//Отрисовка носа
	tr_A = new cord, tr_B= new cord,  tr_C = new cord;
	tr_A->x = ptr_nos->x1;
	tr_A->y = ptr_nos->y1;
	tr_B->x = ptr_nos->x2;
	tr_B->y = ptr_nos->y2;
	tr_C->x = ptr_nos->x3;
	tr_C->y = ptr_nos->y3;
	new_A = ScalePointToCanvas(tr_A, easel, border);
	new_B = ScalePointToCanvas(tr_B, easel, border);
	new_C = ScalePointToCanvas(tr_C, easel, border);
	DrawLine(easel->canvas, new_A, new_B, Color::OrangeRed, 2);
	DrawLine(easel->canvas, new_B, new_C, Color::OrangeRed, 2);
	DrawLine(easel->canvas, new_C, new_A, Color::OrangeRed, 2);
	delete tr_A, tr_B, tr_C, new_A, new_B, new_C;

	//Отрисовка левого глаза
    cord *lev = new cord;
	lev->x = ptr_lev->x;
	lev->y =  ptr_lev->y;
	canvaspoint *new_lev = ScalePointToCanvas(lev, easel, border);
	//canvas->RotateTransform(45);
	canvas->DrawEllipse(drawpen, new_lev->x,
		new_lev->y, ptr_lev->lenx * scale, ptr_lev->leny * scale);
	//canvas->RotateTransform(360 - 45);
	delete lev, new_lev;

	//Отрисовка правого глаза
    cord *prav = new cord;
	prav->x = ptr_prav->x;
	prav->y =  ptr_prav->y;
	canvaspoint *new_prav = ScalePointToCanvas(lev, easel, border);

	canvas->DrawEllipse(drawpen, new_prav->x,
		new_prav->y, ptr_prav->lenx * scale, ptr_prav->leny * scale);

	delete prav, new_prav;

	//Отрисовка волос
	cord *tr_1 = new cord, *tr_2= new cord, *tr_3 = new cord;
	cord *tr_4 = new cord, *tr_5= new cord, *tr_c1 = new cord;
	cord *tr_c2 = new cord, *tr_c3= new cord, *tr_c4 = new cord, *tr_c5 = new cord;
	tr_1->x = ptr_vls->x1;
	tr_1->y = ptr_vls->y1;
	tr_2->x = ptr_vls->x2;
	tr_2->y = ptr_vls->y2;
	tr_3->x = ptr_vls->x3;
	tr_3->y = ptr_vls->y3;
	tr_4->x = ptr_vls->x4;
	tr_4->y = ptr_vls->y4;
	tr_5->x = ptr_vls->x5;
	tr_5->y = ptr_vls->y5;
	tr_c1->x = ptr_vls->cx1;
	tr_c1->y = ptr_vls->cy1;
	tr_c2->x = ptr_vls->cx2;
	tr_c2->y = ptr_vls->cy2;
	tr_c3->x = ptr_vls->cx3;
	tr_c3->y = ptr_vls->cy3;
	tr_c4->x = ptr_vls->cx4;
	tr_c4->y = ptr_vls->cy4;
	tr_c5->x = ptr_vls->cx5;
	tr_c5->y = ptr_vls->cy5;
	canvaspoint *new_1 = ScalePointToCanvas(tr_1, easel, border);
	canvaspoint *new_2 = ScalePointToCanvas(tr_2, easel, border);
	canvaspoint *new_3 = ScalePointToCanvas(tr_3, easel, border);
	canvaspoint *new_4 = ScalePointToCanvas(tr_4, easel, border);
	canvaspoint *new_5 = ScalePointToCanvas(tr_5, easel, border);
	canvaspoint *new_c1 = ScalePointToCanvas(tr_c1, easel, border);
	canvaspoint *new_c2 = ScalePointToCanvas(tr_c2, easel, border);
	canvaspoint *new_c3 = ScalePointToCanvas(tr_c3, easel, border);
	canvaspoint *new_c4 = ScalePointToCanvas(tr_c4, easel, border);
	canvaspoint *new_c5 = ScalePointToCanvas(tr_c5, easel, border);
	DrawLine(easel->canvas, new_c1, new_1, Color::OrangeRed, 2);
	DrawLine(easel->canvas, new_c2, new_2, Color::OrangeRed, 2);
	DrawLine(easel->canvas, new_c3, new_3, Color::OrangeRed, 2);
	DrawLine(easel->canvas, new_c4, new_4, Color::OrangeRed, 2);
	DrawLine(easel->canvas, new_c5, new_5, Color::OrangeRed, 2);
	delete tr_1, tr_2, tr_3, tr_4, tr_5, tr_c1,
		new_1, new_2, new_3, new_4, new_5, new_c1,
		tr_c2, tr_c3, tr_c4, tr_c5, new_c2, new_c3,
		new_c4, new_c5;
}