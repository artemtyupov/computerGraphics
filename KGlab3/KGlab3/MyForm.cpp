#include "MyForm.h"
#include "paint.h"
#include "select.h"

using namespace KGlab3;

System::Void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	Easel = new canvasstruct;
	Easel->canvas = pictureBox1->CreateGraphics(); //инициализируем холст на пикчурбоксе
	Easel->width = pictureBox1->Width;
	Easel->height = pictureBox1->Height;
	cmbMethods->SelectedIndex = 0;
	nmrX1->Maximum = Easel->width / 2;
	nmrX1->Minimum = -Easel->width / 2;
	nmrY1->Maximum = Easel->height / 2;
	nmrY1->Minimum = -Easel->height / 2;
	nmrX2->Maximum = nmrX1->Maximum;
	nmrX2->Minimum = nmrX1->Minimum;
	nmrY2->Maximum = nmrY1->Maximum;
	nmrY2->Minimum = nmrY1->Minimum;
	nmrWidth->Minimum = 1;
	nmrWidth->Maximum = 5;
	ClearCanvas(Easel, pctColorBack->BackColor);
}


//отрезок из точки А в точку Б
System::Void MyForm::btnDraw_Click(System::Object^  sender, System::EventArgs^  e)
{
	SelectMethod(Easel,
		Convert::ToInt32(nmrX1->Value), Convert::ToInt32(nmrY1->Value),
		Convert::ToInt32(nmrX2->Value), Convert::ToInt32(nmrY2->Value), Convert::ToInt32(nmrWidth->Value),
		pctColorMain->BackColor, pctColorBack->BackColor, cmbMethods->SelectedIndex);
}

System::Void MyForm::pctColorMain_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (colorDialog1->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		return;
	pctColorMain->BackColor = colorDialog1->Color;
}

System::Void MyForm::pctColorBack_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (colorDialog2->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		return;
	pctColorBack->BackColor = colorDialog2->Color;
}

System::Void MyForm::btnSpectre_Click(System::Object^  sender, System::EventArgs^  e)
{
	SpectreMethod(Easel, 0, 0, Convert::ToInt32(nmrSpectreStep->Value), 
		Convert::ToInt32(nmrRadius->Value), Convert::ToInt32(nmrWidth->Value), pctColorMain->BackColor,pctColorBack->BackColor,
		cmbMethods->SelectedIndex);
}
System::Void MyForm::btnCalc_Click(System::Object^  sender, System::EventArgs^  e)
{
	double timepass = CalcMethod(Easel, Convert::ToInt32(nmrX1->Value), Convert::ToInt32(nmrY1->Value),
		Convert::ToInt32(nmrX2->Value), Convert::ToInt32(nmrY2->Value), Convert::ToInt32(nmrWidth->Value),
		pctColorMain->BackColor,pctColorBack->BackColor, cmbMethods->SelectedIndex);
	ClearCanvas(Easel, pctColorBack->BackColor);
	MessageBox::Show(String::Format("Метод #{0} занял ~{1:0.000000} секунд", cmbMethods->SelectedIndex, timepass));
}

System::Void MyForm::chkDrawBack_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (chkDrawBack->Checked)
	{
		pctColorMain->Enabled = false;
		pctColorMain->BackColor = pctColorBack->BackColor;
	}
	else
	{
		pctColorMain->BackColor = Color::Black;
		pctColorMain->Enabled = true;
	}
}

System::Void MyForm::btnClear_Click(System::Object^  sender, System::EventArgs^  e)
{
	ClearCanvas(Easel, pctColorBack->BackColor);
}




