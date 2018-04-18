#include "MyForm.h"


using namespace KGlab2;
bool otk = true;

System::Void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	head = nullptr;

	head_lev = new lev_glaz;
	head_prav = new prav_glaz;
	head_vls = new volos;
	head_glv =  new golova;
	head_rot = new rot;
	head_nos = new nos;
	head_lev->prev = new lev_glaz;
	head_prav->prev = new prav_glaz;
	head_vls->prev = new volos;
	head_glv->prev =  new golova;
	head_rot->prev = new rot;
	head_nos->prev = new nos;
	alph = new angle;
	alph->prev = new angle;
	alph->ugol = 0;
	alph->prev->ugol = 0;

	Easel = new canvasstruct;
	Easel->canvas = pictureBox1->CreateGraphics(); //инициализируем холст на пикчурбоксе
	Easel->width = pictureBox1->Width;
	Easel->height = pictureBox1->Height;

	border = new bordersstruct;
	border->Down = -10;
	border->Up = 10;
	border->Right = 10;
	border->Left = -10;
	otk = false;
	
	Easel->canvas->Clear(Color::AliceBlue);
	Init_lists(head_lev, head_prav, head_vls, head_glv, head_rot, head_nos);
	DrawPicture(Easel->canvas, Easel, border,
		head_lev, head_prav, head_vls, head_glv, head_rot, head_nos);
	alph->ugol = 0;
	alph->prev->ugol = 0;
}



//Отрисовка начального изображения
System::Void MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	Easel->canvas->Clear(Color::AliceBlue);
	Init_lists(head_lev, head_prav, head_vls, head_glv, head_rot, head_nos);
	DrawPicture(Easel->canvas, Easel, border,
		head_lev, head_prav, head_vls, head_glv, head_rot, head_nos);
	alph->ugol = 0;
	alph->prev->ugol = 0;
	otk = false;
}

//Масштабирование
System::Void MyForm::scale_btn_Click(System::Object^  sender, System::EventArgs^  e)
{
	//1 - x, 2 - y, 3 - kx, 4 - ky
	if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "" || textBox4->Text == "")
	{
		MessageBox::Show("Пустые поля ввода");
	}
	else
	{
		String^ X = textBox1->Text;
		String^ Y = textBox2->Text;
		String^ KX = textBox3->Text;
		String^ KY = textBox4->Text;
		double x = check_and_convert(X);
		if (x != dbl_err)
		{
			double y = check_and_convert(Y);
			if (y != dbl_err)
			{
				double kx = check_and_convert(KX);
				if (kx != dbl_err)
				{
					double ky = check_and_convert(KY);

					if (ky != dbl_err)
					{
						init_prev(head_lev, head_prav, head_vls, 
							head_glv, head_rot, head_nos);
						Mashtab(x, y, kx, ky, head_lev, head_prav, head_vls, 
							head_glv, head_rot, head_nos);
						Easel->canvas->Clear(Color::AliceBlue);
						alph->ugol = 0;
						DrawPicture_pov(Easel->canvas, Easel, border,
							head_lev, head_prav, head_vls, head_glv, head_rot, head_nos,
							alph, x, y);
						otk = true;
					}
					else
						return;
				}
				else
					return;
			}
			else
				return;
		}
		else
			return;
	}
}


//Перенос
System::Void MyForm::forward_btn_Click(System::Object^  sender, System::EventArgs^  e)
{
	//5 - dx, 6 - dy
	if (textBox5->Text == "" || textBox6->Text == "" )
	{
		MessageBox::Show("Пустые поля ввода");
	}
	else
	{
		String^ DX = textBox5->Text;
		String^ DY = textBox6->Text;
		double dx = check_and_convert(DX);
		if (dx != dbl_err)
		{
			double dy = check_and_convert(DY);
			if (dy != dbl_err)
			{
				init_prev(head_lev, head_prav, head_vls, 
							head_glv, head_rot, head_nos);
				Perenos(dx, dy, head_lev, head_prav, head_vls, 
							head_glv, head_rot, head_nos);
				Easel->canvas->Clear(Color::AliceBlue);
				alph->ugol = 0;
				DrawPicture_pov(Easel->canvas, Easel, border,
					head_lev, head_prav, head_vls, head_glv, head_rot, head_nos, alph , dx, dy);
				otk = true;
			}
			else
				return;
		}
		else
			return;
	}
}


//Поворот
System::Void MyForm::circle_btn_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (textBox7->Text == "" || textBox8->Text == "" || textBox9->Text == "")
	{
		MessageBox::Show("Пустые поля ввода");
	}
	else
	{
		String^ X = textBox7->Text;
		String^ Y = textBox8->Text;
		String^ A = textBox9->Text;
		double x = check_and_convert(X);
		if (x != dbl_err)
		{
			double y = check_and_convert(Y);
			if (y != dbl_err)
			{
				double a = check_and_convert(A);
				if (a != dbl_err)
				{
					init_prev(head_lev, head_prav, head_vls, 
						head_glv, head_rot, head_nos);
					Povorot(x, y, a, head_lev, head_prav, head_vls, 
						head_glv, head_rot, head_nos);
					Easel->canvas->Clear(Color::AliceBlue);
					alph->ugol = a;
					DrawPicture_pov(Easel->canvas, Easel, border,
						head_lev, head_prav, head_vls, head_glv, head_rot, head_nos,
						alph , x, y);
					otk = true;
				}
				else
					return;
			}
			else
				return;
		}
		else
			return;
	}
}


//Откат
System::Void MyForm::back_btn_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (otk)
	{
		init_prev_to_new(head_lev, head_prav, head_vls, 
			head_glv, head_rot, head_nos);
		Easel->canvas->Clear(Color::AliceBlue);
		double x,y;
		x = 0;
		y = 0;
		alph->ugol = -alph->ugol;
		DrawPicture_pov(Easel->canvas, Easel, border,
			head_lev, head_prav, head_vls, head_glv, head_rot, head_nos, alph , x, y);
		otk = false;
	}
	else
	{
		MessageBox::Show("Откат доступен только на одну позицию");
	}

}


//Закрыть форму
System::Void MyForm::close_btn_Click(System::Object^  sender, System::EventArgs^  e)
{
	Close();
}