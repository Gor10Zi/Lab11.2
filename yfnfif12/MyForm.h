#pragma once

namespace yfnfif12 {

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
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(68, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(822, 42);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Обчислення членів рекурентної послідовності";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(239, 265);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(24, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"a";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(197, 433);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(227, 63);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Обчислення";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(466, 433);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(232, 64);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Очищення";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(312, 259);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(310, 31);
			this->textBox1->TabIndex = 4;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(315, 329);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(306, 31);
			this->textBox2->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(155, 320);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(113, 25);
			this->label3->TabIndex = 6;
			this->label3->Text = L"результат";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(958, 633);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	int n = 0;
	if (!Int32::TryParse(textBox1->Text, n)) {
		MessageBox::Show("Введіть ціле число!");
		return;
	}

	if (n < 2) {
		MessageBox::Show("Кількість елементів має бути >= 2");
		return;
	}

	double a0 = 1.0;
	double a1 = 2.0;
	double a2;
	textBox2->AppendText(a0.ToString() + "\r\n");
	textBox2->AppendText(a1.ToString() + "\r\n");
	for (int i = 2; i < n; i++) {
		a2 = Math::Pow(3 * a1 - 2 * a0, 2) + 1; 
		textBox2->AppendText(a2.ToString() + "\r\n");
		a0 = a1;
		a1 = a2;
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Clear();
	textBox2->Clear();
}
};
}
