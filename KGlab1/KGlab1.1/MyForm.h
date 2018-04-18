#pragma once

#include "funcs.h"
#include "paint.h"

namespace KGlab11 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  add_btn;
	protected: 

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;


	private: System::Windows::Forms::Button^  change_btn;
	private: System::Windows::Forms::Button^  delete_btn;
	private: System::Windows::Forms::Button^  delete_all_btn;
	private: System::Windows::Forms::Button^  close_btn;





	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  btn_drw;

	private: System::Windows::Forms::Button^  clear_btn;

	private: System::Windows::Forms::Button^  drw_all_pnt;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;








	public:
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->add_btn = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->change_btn = (gcnew System::Windows::Forms::Button());
			this->delete_btn = (gcnew System::Windows::Forms::Button());
			this->delete_all_btn = (gcnew System::Windows::Forms::Button());
			this->close_btn = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btn_drw = (gcnew System::Windows::Forms::Button());
			this->clear_btn = (gcnew System::Windows::Forms::Button());
			this->drw_all_pnt = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// add_btn
			// 
			this->add_btn->Location = System::Drawing::Point(256, 53);
			this->add_btn->Name = L"add_btn";
			this->add_btn->Size = System::Drawing::Size(75, 35);
			this->add_btn->TabIndex = 0;
			this->add_btn->Text = L"Добавить";
			this->add_btn->UseVisualStyleBackColor = true;
			this->add_btn->Click += gcnew System::EventHandler(this, &MyForm::add_btn_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 53);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(118, 20);
			this->textBox1->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(33, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Координата X";
			// 
			// change_btn
			// 
			this->change_btn->Location = System::Drawing::Point(256, 108);
			this->change_btn->Name = L"change_btn";
			this->change_btn->Size = System::Drawing::Size(75, 34);
			this->change_btn->TabIndex = 11;
			this->change_btn->Text = L"Изменить";
			this->change_btn->UseVisualStyleBackColor = true;
			this->change_btn->Click += gcnew System::EventHandler(this, &MyForm::change_btn_Click);
			// 
			// delete_btn
			// 
			this->delete_btn->Location = System::Drawing::Point(256, 160);
			this->delete_btn->Name = L"delete_btn";
			this->delete_btn->Size = System::Drawing::Size(75, 33);
			this->delete_btn->TabIndex = 12;
			this->delete_btn->Text = L"Удалить";
			this->delete_btn->UseVisualStyleBackColor = true;
			this->delete_btn->Click += gcnew System::EventHandler(this, &MyForm::delete_btn_Click);
			// 
			// delete_all_btn
			// 
			this->delete_all_btn->Location = System::Drawing::Point(256, 222);
			this->delete_all_btn->Name = L"delete_all_btn";
			this->delete_all_btn->Size = System::Drawing::Size(103, 38);
			this->delete_all_btn->TabIndex = 13;
			this->delete_all_btn->Text = L"Удалить все точки";
			this->delete_all_btn->UseVisualStyleBackColor = true;
			this->delete_all_btn->Click += gcnew System::EventHandler(this, &MyForm::delete_all_btn_Click);
			// 
			// close_btn
			// 
			this->close_btn->Location = System::Drawing::Point(679, 710);
			this->close_btn->Name = L"close_btn";
			this->close_btn->Size = System::Drawing::Size(100, 54);
			this->close_btn->TabIndex = 14;
			this->close_btn->Text = L"Закрыть";
			this->close_btn->UseVisualStyleBackColor = true;
			this->close_btn->Click += gcnew System::EventHandler(this, &MyForm::close_btn_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(136, 53);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(114, 20);
			this->textBox2->TabIndex = 15;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(154, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 13);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Координата Y";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 266);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(661, 498);
			this->pictureBox1->TabIndex = 17;
			this->pictureBox1->TabStop = false;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 77);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(238, 183);
			this->dataGridView1->TabIndex = 18;
			// 
			// btn_drw
			// 
			this->btn_drw->Location = System::Drawing::Point(679, 325);
			this->btn_drw->Name = L"btn_drw";
			this->btn_drw->Size = System::Drawing::Size(95, 53);
			this->btn_drw->TabIndex = 19;
			this->btn_drw->Text = L"Нарисовать треугольник";
			this->btn_drw->UseVisualStyleBackColor = true;
			this->btn_drw->Click += gcnew System::EventHandler(this, &MyForm::btn_drw_Click);
			// 
			// clear_btn
			// 
			this->clear_btn->Location = System::Drawing::Point(376, 222);
			this->clear_btn->Name = L"clear_btn";
			this->clear_btn->Size = System::Drawing::Size(105, 38);
			this->clear_btn->TabIndex = 20;
			this->clear_btn->Text = L"Очистить холст";
			this->clear_btn->UseVisualStyleBackColor = true;
			this->clear_btn->Click += gcnew System::EventHandler(this, &MyForm::clear_btn_Click);
			// 
			// drw_all_pnt
			// 
			this->drw_all_pnt->Location = System::Drawing::Point(679, 266);
			this->drw_all_pnt->Name = L"drw_all_pnt";
			this->drw_all_pnt->Size = System::Drawing::Size(95, 53);
			this->drw_all_pnt->TabIndex = 21;
			this->drw_all_pnt->Text = L"Нарисовать все точки";
			this->drw_all_pnt->UseVisualStyleBackColor = true;
			this->drw_all_pnt->Click += gcnew System::EventHandler(this, &MyForm::drw_all_pnt_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(379, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(433, 70);
			this->label3->TabIndex = 22;
			this->label3->Text = resources->GetString(L"label3.Text");
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(679, 531);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 17);
			this->label4->TabIndex = 23;
			this->label4->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(824, 776);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->drw_all_pnt);
			this->Controls->Add(this->clear_btn);
			this->Controls->Add(this->btn_drw);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->close_btn);
			this->Controls->Add(this->delete_all_btn);
			this->Controls->Add(this->delete_btn);
			this->Controls->Add(this->change_btn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->add_btn);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



public: 
	cord *head;
	canvasstruct *Easel;

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void add_btn_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void change_btn_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void delete_btn_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void delete_all_btn_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void close_btn_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btn_drw_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void drw_all_pnt_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void clear_btn_Click(System::Object^  sender, System::EventArgs^  e);
		 
};
}
