#include "MyForm.h"
#include "addFrom.h"
#include "funcs.h"
#include "paint.h"


using namespace KGlab11;


System::Void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	head = nullptr; //инициализируем списки пустотой
	Easel = new canvasstruct;
	Easel->canvas = pictureBox1->CreateGraphics(); //инициализируем холст на пикчурбоксе
	Easel->width = pictureBox1->Width;
	Easel->height = pictureBox1->Height;
}

//Добавление точки
System::Void MyForm::add_btn_Click(System::Object^  sender, System::EventArgs^  e)
{

	if (textBox1->Text == "" || textBox2->Text == "")
	{
		MessageBox::Show("Пустые поля ввода");
	}
	else
	{
		String^ x = textBox1->Text;
		String^ y = textBox2->Text;
		head = add(head, x, y);
		dataGridView1->ColumnCount = 2;
		dataGridView1->Columns[0]->Name = "X";
		dataGridView1->Columns[1]->Name = "Y";
		change_table(dataGridView1, head);
	}
	
}

//Изменение точки
System::Void MyForm::change_btn_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (!head)
		return;
	int pos = dataGridView1->CurrentRow->Index;
	double x_to_remove = Convert::ToDouble(dataGridView1->CurrentRow->Cells[0]->Value);
	double y_to_remove = Convert::ToDouble(dataGridView1->CurrentRow->Cells[1]->Value);
	dataGridView1->Rows->Remove(dataGridView1->Rows[pos]);
	cord *to_remove = find_for_cord(head, x_to_remove, y_to_remove);
	head = remove_one(head, to_remove);
	cord *new_ptr = CreatePointForm();
	if (new_ptr != nullptr)
	{
		head = add_double(head, new_ptr->x, new_ptr->x, x_to_remove, y_to_remove);
		change_table(dataGridView1, head);
	}
}

//Удаление 1 точки
System::Void MyForm::delete_btn_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (!head)
		return;
	int pos = dataGridView1->CurrentRow->Index;
	double x_to_remove = Convert::ToDouble(dataGridView1->CurrentRow->Cells[0]->Value);
	double y_to_remove = Convert::ToDouble(dataGridView1->CurrentRow->Cells[1]->Value);
	dataGridView1->Rows->Remove(dataGridView1->Rows[pos]);
	cord *to_remove = find_for_cord(head, x_to_remove, y_to_remove);
	head = remove_one(head, to_remove);
	change_table(dataGridView1, head);
}

//Удаление всех точек
System::Void MyForm::delete_all_btn_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (!head)
		return;
	remove_all(head);
	head = nullptr;
	dataGridView1->Rows->Clear();
}

//Закрытие формы
System::Void MyForm::close_btn_Click(System::Object^  sender, System::EventArgs^  e)
{
	Close();
}


//Отрисовка всех точек из списка
System::Void MyForm::drw_all_pnt_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (count_list(head) < 3)
	{
		MessageBox::Show("Введено меньше трёх координат");
		return;
	}
	//Easel->canvas->Clear(Color::AliceBlue);
	bordersstruct *borders = get_borders_from_points(head);
	canvaspoint *Y1 = new canvaspoint;
	canvaspoint *Y2 = new canvaspoint;
	canvaspoint *X1 = new canvaspoint;
	canvaspoint *X2 = new canvaspoint;
	treangle *centr = new treangle;
	
	//Y1->x = 0; Y2->x = 0;
	//Y1->y = 0; Y2->y = easel->height;
	cord* for_y1_y = new cord;
	for_y1_y->x = 0;
	for_y1_y->y = 1 - Easel->height;
	centr->first = for_y1_y;

	cord* for_y1_x = new cord;
	for_y1_x->x = 0;
	for_y1_x->y = Easel->height - 1;
	centr->second = for_y1_x;

	//отрисовываем ось Y
	Y1 = ScalePointToCanvas(centr->first, Easel, borders);
	Y2 = ScalePointToCanvas(centr->second, Easel, borders);
	DrawLine(Easel->canvas, Y1, Y2, Color::Red, 2);

	//X1->x = 0; X2->x = easel->width;
	//X1->y = 0; X2->y = 0;
	cord* for_x1_y = new cord;
	for_x1_y->x = 1 - Easel->width;
	for_x1_y->y = 0;
	centr->third = for_x1_y;

	cord* for_x1_x = new cord;
	for_x1_x->x = Easel->width - 1;
	for_x1_x->y = 0;
	centr->V = for_x1_x;

	
	//отрисовываем ось X
	X1 = ScalePointToCanvas(centr->third, Easel, borders);
	X2 = ScalePointToCanvas(centr->V, Easel, borders);
	DrawLine(Easel->canvas, X1, X2, Color::Red, 2);
	delete for_y1_y, for_y1_x, for_x1_y, for_x1_x;
	delete X1, X2, Y1, Y2;
	delete centr;

    DrawPointsList(Easel, head, borders, Color::Green);
}

//Очистить холст
System::Void MyForm::clear_btn_Click(System::Object^  sender, System::EventArgs^  e)
{
	Easel->canvas->Clear(Color::AliceBlue);
}

//Отрисовка треугольника(ответ)
System::Void MyForm::btn_drw_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (count_list(head) < 3)
	{
		MessageBox::Show("Введено меньше трёх координат");
		return;
	}
	treangle *head_tr = make_treangles(head);
	if (head_tr)
	{
		head_tr = delete_smooth(head_tr);
		treangle *result = find_min_angle(head_tr);
		bordersstruct *borders = get_borders_from_points(head);
		treangle *res = DrawResult(Easel, borders, result);
		label4->Visible = true;
		System::String^ str, ^str2, ^str3;
		str = (int(res->angle * 180 / PI + 0.5)).ToString();
		str2 = "Угол равен = ";
		str3 = "°";
		label4->Text =  String::Concat(str2, str, str3);
		head_tr = nullptr;
		result = nullptr;
	}
	else
	{
		MessageBox::Show("Треугольника не существует");
		return;
	}

	//TODO равнобедренный когда медиана и высота в одной прямой проверить!!!!!!

}