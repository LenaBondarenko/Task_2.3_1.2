#pragma once

namespace Task1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
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
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBox1;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"1) Line", L"2) Rectangle", L"3) DrawRectangle",
					L"4) Ellipse", L"5) DrawEllipse", L"6) Sector", L"7) Star"
			});
			this->listBox1->Location = System::Drawing::Point(0, 0);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 95);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(570, 386);
			this->Controls->Add(this->listBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ graf = CreateGraphics();
		Pen^ pn = gcnew System::Drawing::Pen(Color::BlueViolet, 5);
		Brush^ br = gcnew System::Drawing::SolidBrush(Color::Coral);

		graf->Clear(SystemColors::Control);

		switch (listBox1->SelectedIndex)
		{
		case 0:graf->DrawLine(pn, 150, 40, 360, 180); break;
		case 1:graf->DrawRectangle(pn, 150, 30, 300, 110); break;
		case 2:graf->FillRectangle(br, 150, 30, 300, 110); break;
		case 3:graf->DrawEllipse(pn, 150, 30, 300, 110); break;
		case 4:graf->FillEllipse(br, 150, 30, 300, 110); break;
		case 5:graf->FillPie(br, 250, 50, 150, 160, 150, 50); break;
		case 6:array<Point> ^ star;
			star = gcnew array<Point>(11);
			star[0].X = 250; star[0].Y = 30;
			star[1].X = 300; star[1].Y = 120;
			star[2].X = 410; star[2].Y = 130;
			star[3].X = 340; star[3].Y = 205;
			star[4].X = 360; star[4].Y = 305;
			star[5].X = 260; star[5].Y = 260;
			star[6].X = 165; star[6].Y = 310;
			star[7].X = 180; star[7].Y = 212;
			star[8].X = 99; star[8].Y = 142;
			star[9].X = 205; star[9].Y = 125;
			star[10].X = 250; star[10].Y = 30;
			graf->FillPolygon(br, star); break;
		}
	}
	};
}
