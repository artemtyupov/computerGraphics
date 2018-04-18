#pragma once
#include "funcs.h"

cord* CreatePointForm();

namespace KGlab11 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для addFrom
	/// </summary>
	public ref class addFrom : public System::Windows::Forms::Form
	{
	public:
		addFrom(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~addFrom()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnCancel;
	protected: 
	private: System::Windows::Forms::GroupBox^  groupBox2;
	public: System::Windows::Forms::TextBox^  txtY;
	private: 
	private: System::Windows::Forms::GroupBox^  groupBox1;
	public: 
	public: System::Windows::Forms::TextBox^  txtX;
	private: 
	private: System::Windows::Forms::Button^  btnAdd;
	public: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->txtY = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->txtX = (gcnew System::Windows::Forms::TextBox());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnCancel
			// 
			this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancel->Location = System::Drawing::Point(124, 63);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(70, 23);
			this->btnCancel->TabIndex = 7;
			this->btnCancel->Text = L"Отменить";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &addFrom::btnCancel_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->txtY);
			this->groupBox2->Location = System::Drawing::Point(118, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(82, 45);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Y:";
			// 
			// txtY
			// 
			this->txtY->Location = System::Drawing::Point(6, 19);
			this->txtY->Name = L"txtY";
			this->txtY->Size = System::Drawing::Size(70, 20);
			this->txtY->TabIndex = 1;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->txtX);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(82, 45);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"X:";
			// 
			// txtX
			// 
			this->txtX->Location = System::Drawing::Point(6, 19);
			this->txtX->Name = L"txtX";
			this->txtX->Size = System::Drawing::Size(70, 20);
			this->txtX->TabIndex = 0;
			// 
			// btnAdd
			// 
			this->btnAdd->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btnAdd->Location = System::Drawing::Point(18, 63);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(70, 23);
			this->btnAdd->TabIndex = 6;
			this->btnAdd->Text = L"ОК";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &addFrom::btnAdd_Click);
			// 
			// addFrom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(226, 112);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->btnAdd);
			this->Name = L"addFrom";
			this->Text = L"addFrom";
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e);
};
}
