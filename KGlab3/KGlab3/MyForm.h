#pragma once
#include "paint.h"

namespace KGlab3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnCalc;
	protected: 
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::NumericUpDown^  nmrRadius;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::GroupBox^  groupBox4;

	private: System::Windows::Forms::PictureBox^  pctColorMain;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::PictureBox^  pctColorBack;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  btnClear;
	private: System::Windows::Forms::Button^  btnSpectre;
	private: System::Windows::Forms::Button^  btnDraw;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::ComboBox^  cmbMethods;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::NumericUpDown^  nmrY2;
	private: System::Windows::Forms::NumericUpDown^  nmrX2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::NumericUpDown^  nmrY1;
	private: System::Windows::Forms::NumericUpDown^  nmrX1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::NumericUpDown^  nmrSpectreStep;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::ColorDialog^  colorDialog2;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::NumericUpDown^  nmrWidth;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::CheckBox^  chkDrawBack;








	protected: 

	protected: 

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnCalc = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->nmrRadius = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->chkDrawBack = (gcnew System::Windows::Forms::CheckBox());
			this->pctColorMain = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pctColorBack = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->btnSpectre = (gcnew System::Windows::Forms::Button());
			this->btnDraw = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->cmbMethods = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->nmrY2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->nmrX2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->nmrY1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->nmrX1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->nmrSpectreStep = (gcnew System::Windows::Forms::NumericUpDown());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->colorDialog2 = (gcnew System::Windows::Forms::ColorDialog());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->nmrWidth = (gcnew System::Windows::Forms::NumericUpDown());
			this->label10 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrRadius))->BeginInit();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorMain))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorBack))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrY2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrX2))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrY1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrX1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrSpectreStep))->BeginInit();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrWidth))->BeginInit();
			this->SuspendLayout();
			// 
			// btnCalc
			// 
			this->btnCalc->Location = System::Drawing::Point(617, 92);
			this->btnCalc->Name = L"btnCalc";
			this->btnCalc->Size = System::Drawing::Size(75, 23);
			this->btnCalc->TabIndex = 32;
			this->btnCalc->Text = L"��������";
			this->btnCalc->UseVisualStyleBackColor = true;
			this->btnCalc->Click += gcnew System::EventHandler(this, &MyForm::btnCalc_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::SystemColors::HighlightText;
			this->label9->Location = System::Drawing::Point(663, 371);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(11, 13);
			this->label9->TabIndex = 29;
			this->label9->Text = L"�";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(606, 371);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(30, 13);
			this->label8->TabIndex = 30;
			this->label8->Text = L"���:";
			// 
			// nmrRadius
			// 
			this->nmrRadius->Location = System::Drawing::Point(642, 343);
			this->nmrRadius->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nmrRadius->Name = L"nmrRadius";
			this->nmrRadius->Size = System::Drawing::Size(48, 20);
			this->nmrRadius->TabIndex = 28;
			this->nmrRadius->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, 0});
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(592, 346);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(46, 13);
			this->label7->TabIndex = 27;
			this->label7->Text = L"������:";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->chkDrawBack);
			this->groupBox4->Controls->Add(this->pctColorMain);
			this->groupBox4->Controls->Add(this->label6);
			this->groupBox4->Controls->Add(this->pctColorBack);
			this->groupBox4->Controls->Add(this->label5);
			this->groupBox4->Location = System::Drawing::Point(581, 206);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(141, 128);
			this->groupBox4->TabIndex = 26;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"�����:";
			// 
			// chkDrawBack
			// 
			this->chkDrawBack->Location = System::Drawing::Point(13, 91);
			this->chkDrawBack->Name = L"chkDrawBack";
			this->chkDrawBack->Size = System::Drawing::Size(104, 30);
			this->chkDrawBack->TabIndex = 14;
			this->chkDrawBack->Text = L"�������� ������ ����";
			this->chkDrawBack->UseVisualStyleBackColor = true;
			this->chkDrawBack->CheckedChanged += gcnew System::EventHandler(this, &MyForm::chkDrawBack_CheckedChanged);
			// 
			// pctColorMain
			// 
			this->pctColorMain->BackColor = System::Drawing::Color::Black;
			this->pctColorMain->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pctColorMain->Location = System::Drawing::Point(6, 19);
			this->pctColorMain->Name = L"pctColorMain";
			this->pctColorMain->Size = System::Drawing::Size(30, 30);
			this->pctColorMain->TabIndex = 9;
			this->pctColorMain->TabStop = false;
			this->pctColorMain->Click += gcnew System::EventHandler(this, &MyForm::pctColorMain_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(42, 63);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(61, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"���� ����";
			// 
			// pctColorBack
			// 
			this->pctColorBack->BackColor = System::Drawing::Color::White;
			this->pctColorBack->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pctColorBack->Location = System::Drawing::Point(6, 55);
			this->pctColorBack->Name = L"pctColorBack";
			this->pctColorBack->Size = System::Drawing::Size(30, 30);
			this->pctColorBack->TabIndex = 10;
			this->pctColorBack->TabStop = false;
			this->pctColorBack->Click += gcnew System::EventHandler(this, &MyForm::pctColorBack_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(42, 27);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(59, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"���� ����";
			// 
			// btnClear
			// 
			this->btnClear->Location = System::Drawing::Point(361, 470);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(75, 23);
			this->btnClear->TabIndex = 25;
			this->btnClear->Text = L"��������";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &MyForm::btnClear_Click);
			// 
			// btnSpectre
			// 
			this->btnSpectre->Location = System::Drawing::Point(507, 451);
			this->btnSpectre->Name = L"btnSpectre";
			this->btnSpectre->Size = System::Drawing::Size(75, 23);
			this->btnSpectre->TabIndex = 24;
			this->btnSpectre->Text = L"������";
			this->btnSpectre->UseVisualStyleBackColor = true;
			this->btnSpectre->Click += gcnew System::EventHandler(this, &MyForm::btnSpectre_Click);
			// 
			// btnDraw
			// 
			this->btnDraw->Location = System::Drawing::Point(361, 440);
			this->btnDraw->Name = L"btnDraw";
			this->btnDraw->Size = System::Drawing::Size(75, 23);
			this->btnDraw->TabIndex = 23;
			this->btnDraw->Text = L"����������";
			this->btnDraw->UseVisualStyleBackColor = true;
			this->btnDraw->Click += gcnew System::EventHandler(this, &MyForm::btnDraw_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->cmbMethods);
			this->groupBox3->Location = System::Drawing::Point(581, 34);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(141, 52);
			this->groupBox3->TabIndex = 22;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"�������� ���������:";
			// 
			// cmbMethods
			// 
			this->cmbMethods->FormattingEnabled = true;
			this->cmbMethods->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"�����������", L"���", L"���������� (��������������)", 
				L"���������� (�������������)", L"���������� (�����������)"});
			this->cmbMethods->Location = System::Drawing::Point(6, 19);
			this->cmbMethods->Name = L"cmbMethods";
			this->cmbMethods->Size = System::Drawing::Size(129, 21);
			this->cmbMethods->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->nmrY2);
			this->groupBox2->Controls->Add(this->nmrX2);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Location = System::Drawing::Point(157, 415);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(100, 78);
			this->groupBox2->TabIndex = 21;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"����� 2:";
			// 
			// nmrY2
			// 
			this->nmrY2->Location = System::Drawing::Point(29, 52);
			this->nmrY2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nmrY2->Name = L"nmrY2";
			this->nmrY2->Size = System::Drawing::Size(63, 20);
			this->nmrY2->TabIndex = 7;
			this->nmrY2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, 0});
			// 
			// nmrX2
			// 
			this->nmrX2->Location = System::Drawing::Point(29, 22);
			this->nmrX2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nmrX2->Name = L"nmrX2";
			this->nmrX2->Size = System::Drawing::Size(63, 20);
			this->nmrX2->TabIndex = 6;
			this->nmrX2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {150, 0, 0, 0});
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 55);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(17, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Y:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(17, 13);
			this->label4->TabIndex = 2;
			this->label4->Text = L"X:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->nmrY1);
			this->groupBox1->Controls->Add(this->nmrX1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(22, 415);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(100, 78);
			this->groupBox1->TabIndex = 20;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"����� 1:";
			// 
			// nmrY1
			// 
			this->nmrY1->Location = System::Drawing::Point(29, 52);
			this->nmrY1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nmrY1->Name = L"nmrY1";
			this->nmrY1->Size = System::Drawing::Size(63, 20);
			this->nmrY1->TabIndex = 5;
			// 
			// nmrX1
			// 
			this->nmrX1->Location = System::Drawing::Point(29, 22);
			this->nmrX1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nmrX1->Name = L"nmrX1";
			this->nmrX1->Size = System::Drawing::Size(63, 20);
			this->nmrX1->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Y:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"X:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(563, 397);
			this->pictureBox1->TabIndex = 19;
			this->pictureBox1->TabStop = false;
			// 
			// nmrSpectreStep
			// 
			this->nmrSpectreStep->Location = System::Drawing::Point(642, 369);
			this->nmrSpectreStep->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {180, 0, 0, 0});
			this->nmrSpectreStep->Name = L"nmrSpectreStep";
			this->nmrSpectreStep->Size = System::Drawing::Size(48, 20);
			this->nmrSpectreStep->TabIndex = 31;
			this->nmrSpectreStep->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {20, 0, 0, 0});
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->nmrWidth);
			this->groupBox5->Controls->Add(this->label10);
			this->groupBox5->Location = System::Drawing::Point(586, 121);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(141, 79);
			this->groupBox5->TabIndex = 33;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"������ �������:";
			// 
			// nmrWidth
			// 
			this->nmrWidth->Enabled = false;
			this->nmrWidth->Location = System::Drawing::Point(43, 29);
			this->nmrWidth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nmrWidth->Name = L"nmrWidth";
			this->nmrWidth->Size = System::Drawing::Size(53, 20);
			this->nmrWidth->TabIndex = 8;
			this->nmrWidth->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 31);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(38, 13);
			this->label10->TabIndex = 7;
			this->label10->Text = L"Width:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(734, 505);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->btnCalc);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->nmrRadius);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->btnSpectre);
			this->Controls->Add(this->btnDraw);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->nmrSpectreStep);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrRadius))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorMain))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pctColorBack))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrY2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrX2))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrY1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrX1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrSpectreStep))->EndInit();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrWidth))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public:
		canvasstruct *Easel;

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void pctColorMain_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void pctColorBack_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnDraw_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnSpectre_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCalc_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void chkDrawBack_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
};
}
