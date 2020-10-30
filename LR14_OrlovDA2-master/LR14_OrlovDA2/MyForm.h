#pragma once
#include <ctime>
#include <iostream>
#include <fstream>
#include "Visualisation.h"
using namespace std;
ifstream fin2;

namespace LR14OrlovDA2 {

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
		int getN()
		{
			int n;
			int counter = 0;
			char* buffer3 = new char[8];

			fin2.open("forTable.txt");
			fin2.seekg(5, ios_base::beg);
			while (!fin2.eof())
			{
				fin2.getline(buffer3, 8, '\n');
				counter++;
			}
			n = counter;
			fin2.close();
			delete[] buffer3;
			return n - 1;
		};
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
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ X;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Y;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;


	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->X = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Y = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->X, this->Y });
			this->dataGridView1->Location = System::Drawing::Point(9, 27);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(107, 122);
			this->dataGridView1->TabIndex = 0;
			// 
			// X
			// 
			this->X->HeaderText = L"X";
			this->X->MinimumWidth = 6;
			this->X->Name = L"X";
			this->X->Width = 50;
			// 
			// Y
			// 
			this->Y->HeaderText = L"Y";
			this->Y->MinimumWidth = 6;
			this->Y->Name = L"Y";
			this->Y->Width = 50;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 11);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Таблица";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 154);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Кол-во пар:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(9, 171);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(108, 20);
			this->textBox1->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(9, 195);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(107, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Заполнить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(120, 27);
			this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(107, 37);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Заполнить из файла fortabel.txt";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(236, 231);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			srand(time(NULL));
			int n;

			n = Convert::ToInt32(textBox1->Text);

			int** tab = new int* [n];
			for (int i = 0; i < n; i++)
				tab[i] = new int[n];
			Visualisation t1(tab, n, 2);
			tab[n - 1][2] = t1.fillTable(&tab[0]);
			dataGridView1->RowCount = n;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < 2; j++) {
					dataGridView1->Rows[i]->Cells[j]->Value = Convert::ToString(tab[i][j]);
				}
			t1.putIntoFile(tab);
		}
		catch (System::FormatException^ ex) {
			MessageBox::Show("Заполните все поля", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		int n = getN();
		int** tab = new int* [n];
		Visualisation t1(tab, n, 2);
		dataGridView1->RowCount = n;
		t1.outOfFile(tab);
		for(int i = 0; i < n; i++)
			for (int j = 0; j < 2; j++) {
				dataGridView1->Rows[i]->Cells[j]->Value = Convert::ToString(tab[i][j]);
			}
	}
	catch (System::FormatException^ ex) {
		MessageBox::Show("Заполните все поля", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
}
};
}
