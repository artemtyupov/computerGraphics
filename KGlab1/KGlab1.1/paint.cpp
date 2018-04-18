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
	double MidX = (borders->Right + borders->Left)/2; //середина пр€моугольника
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

	//смещаем точку на координату середины граничного пр€моугольника
	PointInWorld->x = pt->x - MidX;
	PointInWorld->y = pt->y - MidY;

	//масштабируем еЄ относительно центра
	PointInWorld->x *= scale;
	PointInWorld->y *= scale;

	//получаем середину холста
	PointInCanvas->x = easel->width / 2;
	PointInCanvas->y = easel->height / 2;

	//отрисовываем точку относительно неЄ
	PointInCanvas->x += (int) PointInWorld->x;
	PointInCanvas->y -= (int) PointInWorld->y;

	delete PointInWorld;

	return PointInCanvas;

}

//рисует точку на холсте
void DrawPoint(Graphics^ canvas, canvaspoint *point, Color drawcolor)
{	
	//MessageBox::Show(String::Format("{0}, {1}",point->x, point->y));
	Pen^ drawpen = gcnew Pen(Color::Black, 1); //чЄрна€ обводка
	SolidBrush^ drawbrush = gcnew SolidBrush(drawcolor); //цветна€ заливка
	Rectangle rect = Rectangle(point->x-POINTRADIUS, point->y-POINTRADIUS, POINTRADIUS*2, POINTRADIUS*2); //пр€моугольнки заливки
	canvas->FillEllipse(drawbrush,rect);
	canvas->DrawEllipse(drawpen,rect);

	delete drawbrush;
	delete drawpen;
}

void DrawPointsList(canvasstruct *easel, cord *head, bordersstruct* borders, Color drawcolor)
{
	if (!head) //если чего-то не хватает, то ничего и не рисуем
		return;

	
	//проходимс€ по списку и отрисовываем все точки
	canvaspoint *PointInCanvas;
	cord *ptr = head;
	int i = 1;
	while (ptr)
	{
		PointInCanvas = ScalePointToCanvas(ptr, easel, borders);
		DrawPoint(easel->canvas,PointInCanvas,drawcolor);

		// Create string to draw.
		String^ drawString = String::Format("{0}({1}, {2})", i, ptr->x, ptr->y);

		// Create font and brush.
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Arial", 10 );
		SolidBrush^ drawBrush = gcnew SolidBrush( Color::Black );

		// Draw string to screen.
		easel->canvas->DrawString( drawString, drawFont, drawBrush, (float) PointInCanvas->x, (float) PointInCanvas->y );
		ptr = ptr->next;
		i++;
		delete PointInCanvas;
		delete drawString, drawFont, drawBrush;
	}
}

//рисует линию на холсте
void DrawLine(Graphics^ canvas, canvaspoint *A, canvaspoint *B, Color drawcolor, int width)
{	
	Pen^ drawpen = gcnew Pen(drawcolor, (float) width);
	canvas->DrawLine(drawpen, A->x, A->y, B->x, B->y);
	delete drawpen;
}

//рисует треугольник на холсте
void DrawTriangle(canvasstruct *easel, treangle *T, bordersstruct *borders, Drawing::Color drawcolor)
{	
	Pen^ drawpen = gcnew Pen(drawcolor, 2);
	canvaspoint *drA = ScalePointToCanvas(T->first, easel, borders);
	canvaspoint *drB = ScalePointToCanvas(T->second, easel, borders);
	canvaspoint *drC = ScalePointToCanvas(T->third, easel, borders);
	DrawLine(easel->canvas, drA, drB, drawcolor, 2);
	DrawLine(easel->canvas, drA, drC, drawcolor, 2);
	DrawLine(easel->canvas, drC, drB, drawcolor, 2);
	delete drawpen;
}

bordersstruct* SumBorders(bordersstruct* borders1, bordersstruct* borders2)
{
	bordersstruct *summary;
	if (borders1) //определ€ем границы, исход€ из "доступности" списков
		summary = borders1;
	if (borders2)
		summary = borders2;
	if (borders1 && borders2)
	{
		summary = new bordersstruct;
		summary->Left = MIN(borders1->Left, borders2->Left);
		summary->Down = MIN(borders1->Down, borders2->Down);
		summary->Up = MAX(borders1->Up, borders2->Up);
		summary->Right = MAX(borders1->Right, borders2->Right);
	}
	return summary;
}



//ищет координату медианы
cord * find_cord_med(treangle *head)
{
	cord *A, *B;
	if (head->V == head->first)
	{
		A = head->second;
		B = head->third;
	}

	if (head->V == head->second)
	{
		A = head->first;
		B = head->third;
	}

	if (head->V == head->third)
	{
		A = head->second;
		B = head->first;
	}
	cord *result = new cord;
	result->x = (A->x + B->x) / 2;
	result->y = (A->y + B->y) / 2;
	result->next = nullptr;
	return result;
}





void get_cord_height(T_point A, T_point B, T_point C, T_point& K)
{
    //“ак как основание K высоты AK лежит на пр€мой BC, то точку K можно 
    //представить в виде:
    //K = B + a * BC,                                                (1)
    //где a - действительное.
    //“огда AK = K - A = B + a * BC - A = AB + a * BC.
    //“ак как векторы AK и BC перпендикул€рны, а при делении комплексных чисел
    //их аргументы (углы) вычитаютс€, то частное AK/BC или (AB + a * BC)/BC 
    //или (AB / BC + a) будет иметь аргумент, равный по модулю 90 градусов, т.е.
    //будет числом чисто мнимым. —ледовательно (AB / BC).real() + a = 0, откуда
    // a = -(AB / BC).real().    
    //“огда из (1) получим:    
    T_point  AB = B - A;
    T_point  BC = C - B;
    K = B - (AB/BC).real() * BC;
}

cord *find_cord_height(treangle *res)
{
	cord *a, *b;
	if (res->V == res->first)
	{
		a = res->second;
		b = res->third;
	}

	if (res->V == res->second)
	{
		a = res->first;
		b = res->third;
	}

	if (res->V == res->third)
	{
		a = res->second;
		b = res->first;
	}
	T_point A(res->V->x, res->V->y);
	T_point B(a->x, a->y);
	T_point C(b->x, b->y);
	T_point K;
	get_cord_height(A, B, C, K);
	double x_height = K.real();
	double y_height = K.imag();
	cord *height = new cord;
	height->x = x_height;
	height->y = y_height;
	return height;
}

//отрисовывает результат вычислений
treangle *DrawResult(canvasstruct *easel, bordersstruct* borders, treangle *res)
{

	easel->canvas->Clear(Color::AliceBlue); //смываем уже нарисованное

	
	cord *trA, *trB, *trC, *median, *height;
	canvaspoint *median_pnt, *height_pnt;
	canvaspoint *V; //вершина
	
	//отрисовываем треугольник
	trA = res->first;
	trB = res->second;
	trC = res->third;
	DrawTriangle(easel, res, borders, Color::Green);

	//отрисовываем его медиану
	V = ScalePointToCanvas(res->V, easel, borders);
	median = find_cord_med(res);
	median_pnt = ScalePointToCanvas(median, easel, borders);
	DrawLine(easel->canvas, V, median_pnt, Color::Black, 1);
	delete V;

	//отрисовываем высоту
	V = ScalePointToCanvas(res->V, easel, borders);
	height = find_cord_height(res);
	height_pnt = ScalePointToCanvas(height, easel, borders);
	DrawLine(easel->canvas, V, height_pnt, Color::Black, 1);
	delete V;

	//отрисовываем точки поверх треугла
	V = ScalePointToCanvas(res->first, easel, borders);
	delete V;
	V = ScalePointToCanvas(res->second, easel, borders);
	delete V;
	V = ScalePointToCanvas(res->third, easel, borders);
	delete V;
	


	
	canvaspoint *Y1 = new canvaspoint;
	canvaspoint *Y2 = new canvaspoint;
	canvaspoint *X1 = new canvaspoint;
	canvaspoint *X2 = new canvaspoint;
	treangle *centr = new treangle;
	
	//Y1->x = 0; Y2->x = 0;
	//Y1->y = 0; Y2->y = easel->height;
	cord* for_y1_y = new cord;
	for_y1_y->x = 0;
	for_y1_y->y = 1 - easel->height;
	centr->first = for_y1_y;

	cord* for_y1_x = new cord;
	for_y1_x->x = 0;
	for_y1_x->y = easel->height - 1;
	centr->second = for_y1_x;

	//отрисовываем ось Y
	Y1 = ScalePointToCanvas(centr->first, easel, borders);
	Y2 = ScalePointToCanvas(centr->second, easel, borders);
	DrawLine(easel->canvas, Y1, Y2, Color::Red, 2);

	//X1->x = 0; X2->x = easel->width;
	//X1->y = 0; X2->y = 0;
	cord* for_x1_y = new cord;
	for_x1_y->x = 1 - easel->width;
	for_x1_y->y = 0;
	centr->third = for_x1_y;

	cord* for_x1_x = new cord;
	for_x1_x->x = easel->width - 1;
	for_x1_x->y = 0;
	centr->V = for_x1_x;

	
	//отрисовываем ось X
	X1 = ScalePointToCanvas(centr->third, easel, borders);
	X2 = ScalePointToCanvas(centr->V, easel, borders);
	DrawLine(easel->canvas, X1, X2, Color::Red, 2);

	delete for_y1_y, for_y1_x, for_x1_y, for_x1_x;
	delete median, height;
	delete X1, X2, Y1, Y2;
	delete centr;

	//ѕроверим не упала ли высота дальше основани€

	cord *a, *b, *c;
	if (res->V == res->first)
	{
		a = res->second;
		b = res->third;
	}

	if (res->V == res->second)
	{
		a = res->first;
		b = res->third;
	}

	if (res->V == res->third)
	{
		a = res->second;
		b = res->first;
	}
	c = height;
	canvaspoint *pnt1 = new canvaspoint;
	canvaspoint *pnt2 = new canvaspoint;
	canvaspoint *pnt3 = new canvaspoint;
	pnt1 = ScalePointToCanvas(a, easel, borders);
	pnt2 = ScalePointToCanvas(b, easel, borders);
	pnt3 = ScalePointToCanvas(c, easel, borders);
	//1
	if (c->x >= a->x && c->x >= b->x)
	{
		if (a->x > b->x)
			DrawLine(easel->canvas, pnt1, pnt3, Color::Green, 2);
		else
			DrawLine(easel->canvas, pnt2, pnt3, Color::Green, 2);
	}
	//2
	if (c->x <= a->x && c->x <= b->x)
	{
		if (a->x < b->x)
			DrawLine(easel->canvas, pnt1, pnt3, Color::Green, 2);
		else
			DrawLine(easel->canvas, pnt2, pnt3, Color::Green, 2);
	}
	delete pnt1, pnt2, pnt3;
	return res;
	
}