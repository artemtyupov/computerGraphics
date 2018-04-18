#include "addFrom.h"
#include "funcs.h"

using namespace KGlab11;

cord* CreatePointForm()
{
	addFrom^ Adder = gcnew addFrom;
	cord* pt = new cord;
	pt = nullptr;
	if (Adder->ShowDialog() == DialogResult::OK)
		if ( Adder->txtX->Text == "" || Adder->txtY->Text == "")
		{
			MessageBox::Show("Пустые поля ввода");
			return nullptr;
		}
		else
			pt = add(pt, Adder->txtX->Text, Adder->txtY->Text);
	else
		pt = nullptr;

	return pt;
}

System::Void addFrom::btnAdd_Click(System::Object^  sender, System::EventArgs^  e)
{
	Close();
}
System::Void addFrom::btnCancel_Click(System::Object^  sender, System::EventArgs^  e)
{
	Close();
}