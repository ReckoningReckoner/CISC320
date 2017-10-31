#pragma once
#include <iostream>
#include "Fraction_DLL.h"

namespace GUI_Part {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::TextBox^  numerator2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  denominator2;
	private: System::Windows::Forms::TextBox^  numerator1;
	private: System::Windows::Forms::TextBox^  denominator1;
	private: System::Windows::Forms::RadioButton^  plusRadio;
	private: System::Windows::Forms::RadioButton^  minusRadio;
	private: System::Windows::Forms::RadioButton^  multiplyRadio;
	private: System::Windows::Forms::RadioButton^  divideRadio;

	private: System::Windows::Forms::Button^  equalsButton;
	private: System::Windows::Forms::Label^  solutionLabel;
	private: System::Windows::Forms::Label^  solutionNumber;
	private: System::Windows::Forms::Label^  label5;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->numerator2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->denominator2 = (gcnew System::Windows::Forms::TextBox());
			this->numerator1 = (gcnew System::Windows::Forms::TextBox());
			this->denominator1 = (gcnew System::Windows::Forms::TextBox());
			this->plusRadio = (gcnew System::Windows::Forms::RadioButton());
			this->minusRadio = (gcnew System::Windows::Forms::RadioButton());
			this->multiplyRadio = (gcnew System::Windows::Forms::RadioButton());
			this->divideRadio = (gcnew System::Windows::Forms::RadioButton());
			this->equalsButton = (gcnew System::Windows::Forms::Button());
			this->solutionLabel = (gcnew System::Windows::Forms::Label());
			this->solutionNumber = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// numerator2
			// 
			this->numerator2->Location = System::Drawing::Point(136, 47);
			this->numerator2->Name = L"numerator2";
			this->numerator2->Size = System::Drawing::Size(75, 20);
			this->numerator2->TabIndex = 7;
			this->numerator2->TextChanged += gcnew System::EventHandler(this, &GUI::fractionTextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 13);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Numerator 1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 83);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Denominator 1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(133, 31);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Numerator 2";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(135, 83);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(76, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Denominator 2";
			// 
			// denominator2
			// 
			this->denominator2->Location = System::Drawing::Point(136, 99);
			this->denominator2->Name = L"denominator2";
			this->denominator2->Size = System::Drawing::Size(75, 20);
			this->denominator2->TabIndex = 8;
			this->denominator2->TextChanged += gcnew System::EventHandler(this, &GUI::fractionTextChanged);
			// 
			// numerator1
			// 
			this->numerator1->Location = System::Drawing::Point(18, 47);
			this->numerator1->Name = L"numerator1";
			this->numerator1->Size = System::Drawing::Size(75, 20);
			this->numerator1->TabIndex = 1;
			this->numerator1->TextChanged += gcnew System::EventHandler(this, &GUI::fractionTextChanged);
			// 
			// denominator1
			// 
			this->denominator1->Location = System::Drawing::Point(18, 99);
			this->denominator1->Name = L"denominator1";
			this->denominator1->Size = System::Drawing::Size(75, 20);
			this->denominator1->TabIndex = 2;
			this->denominator1->TextChanged += gcnew System::EventHandler(this, &GUI::fractionTextChanged);
			// 
			// radioButton1
			// 
			this->plusRadio->AutoSize = true;
			this->plusRadio->Checked = true;
			this->plusRadio->Location = System::Drawing::Point(99, 40);
			this->plusRadio->Name = L"radioButton1";
			this->plusRadio->Size = System::Drawing::Size(31, 17);
			this->plusRadio->TabIndex = 3;
			this->plusRadio->TabStop = true;
			this->plusRadio->Text = L"+";
			this->plusRadio->UseVisualStyleBackColor = true;
			this->plusRadio->CheckedChanged += gcnew System::EventHandler(this, &GUI::operatorChanged);
			// 
			// radioButton2
			// 
			this->minusRadio->AutoSize = true;
			this->minusRadio->Location = System::Drawing::Point(99, 63);
			this->minusRadio->Name = L"radioButton2";
			this->minusRadio->Size = System::Drawing::Size(28, 17);
			this->minusRadio->TabIndex = 4;
			this->minusRadio->TabStop = true;
			this->minusRadio->Text = L"-";
			this->minusRadio->UseVisualStyleBackColor = true;
			this->minusRadio->CheckedChanged += gcnew System::EventHandler(this, &GUI::operatorChanged);
			// 
			// radioButton3
			// 
			this->multiplyRadio->AutoSize = true;
			this->multiplyRadio->Location = System::Drawing::Point(99, 86);
			this->multiplyRadio->Name = L"radioButton3";
			this->multiplyRadio->Size = System::Drawing::Size(29, 17);
			this->multiplyRadio->TabIndex = 5;
			this->multiplyRadio->TabStop = true;
			this->multiplyRadio->Text = L"*";
			this->multiplyRadio->UseVisualStyleBackColor = true;
			this->multiplyRadio->CheckedChanged += gcnew System::EventHandler(this, &GUI::operatorChanged);
			// 
			// radioButton4
			// 
			this->divideRadio->AutoSize = true;
			this->divideRadio->Location = System::Drawing::Point(99, 109);
			this->divideRadio->Name = L"radioButton4";
			this->divideRadio->Size = System::Drawing::Size(30, 17);
			this->divideRadio->TabIndex = 6;
			this->divideRadio->TabStop = true;
			this->divideRadio->Text = L"/";
			this->divideRadio->UseVisualStyleBackColor = true;
			this->divideRadio->CheckedChanged += gcnew System::EventHandler(this, &GUI::operatorChanged);
			// 
			// equalsButton
			// 
			this->equalsButton->Location = System::Drawing::Point(225, 69);
			this->equalsButton->Name = L"equalsButton";
			this->equalsButton->Size = System::Drawing::Size(45, 20);
			this->equalsButton->TabIndex = 13;
			this->equalsButton->Text = L"=";
			this->equalsButton->UseVisualStyleBackColor = true;
			this->equalsButton->Click += gcnew System::EventHandler(this, &GUI::equalsButton_Click);
			// 
			// solutionLabel
			// 
			this->solutionLabel->AutoSize = true;
			this->solutionLabel->Location = System::Drawing::Point(280, 47);
			this->solutionLabel->Name = L"solutionLabel";
			this->solutionLabel->Size = System::Drawing::Size(48, 13);
			this->solutionLabel->TabIndex = 14;
			this->solutionLabel->Text = L"Solution:";
			// 
			// solutionNumber
			// 
			this->solutionNumber->AutoSize = true;
			this->solutionNumber->Location = System::Drawing::Point(280, 73);
			this->solutionNumber->Name = L"solutionNumber";
			this->solutionNumber->Size = System::Drawing::Size(0, 13);
			this->solutionNumber->TabIndex = 15;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(18, 15);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 16;
			this->label5->Text = L"Press <Enter> to compute the fraction, <Alt-C> to close the program";
			// 
			// GUI
			// 
			this->AcceptButton = this->equalsButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(437, 143);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->solutionNumber);
			this->Controls->Add(this->solutionLabel);
			this->Controls->Add(this->equalsButton);
			this->Controls->Add(this->divideRadio);
			this->Controls->Add(this->multiplyRadio);
			this->Controls->Add(this->minusRadio);
			this->Controls->Add(this->plusRadio);
			this->Controls->Add(this->denominator1);
			this->Controls->Add(this->numerator1);
			this->Controls->Add(this->denominator2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numerator2);
			this->Name = L"GUI";
			this->Text = L"Fraction Calculator";
			this->Load += gcnew System::EventHandler(this, &GUI::GUI_Load);
			this->KeyDown += gcnew KeyEventHandler(this, &GUI::HandleKeyPressed);
			this->KeyPreview = true;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GUI_Load(System::Object^  sender, System::EventArgs^  e) { }
	private: System::Void HandleKeyPressed(System::Object^  sender, KeyEventArgs^  e) {
		if (e->Alt && (char)e->KeyCode == (char)67) {
			this->Close();
		}
	}
	private: System::Void fractionTextChanged(System::Object^  sender, System::EventArgs^  e) {
		this->solutionNumber->Text = "";
	}
	private: System::Void operatorChanged(System::Object^  sender, System::EventArgs^  e) {
		this->solutionNumber->Text = "";
	}
	private: System::Void equalsButton_Click(System::Object^  sender, System::EventArgs^  e) {
		updateSolution();
	}
	private: void updateSolution() {
		try {
			int num1 = Int32::Parse(this->numerator1->Text, System::Globalization::NumberStyles::AllowLeadingSign);
			int num2 = Int32::Parse(this->numerator2->Text, System::Globalization::NumberStyles::AllowLeadingSign);
			int denom1 = Int32::Parse(this->denominator1->Text, System::Globalization::NumberStyles::AllowLeadingSign);
			int denom2 = Int32::Parse(this->denominator2->Text, System::Globalization::NumberStyles::AllowLeadingSign);

			if (denom1 == 0 || denom2 == 0) {
				this->solutionNumber->Text = "Divide by zero encountered.";
				return;
			}

			Fraction solution;
			if (this->plusRadio->Checked) {
				solution = Fraction(num1, denom1) + Fraction(num2, denom2);
			}
			else if (this->minusRadio->Checked) {
				solution = Fraction(num1, denom1) - Fraction(num2, denom2);
			}
			else if (this->multiplyRadio->Checked) {
				solution = Fraction(num1, denom1) * Fraction(num2, denom2);
			}
			else if (this->divideRadio->Checked) {
				solution = Fraction(num1, denom1) / Fraction(num2, denom2);
			}

			String^ solutionNum = Convert::ToString(solution.numerator());
			String^ solutionDenom = Convert::ToString(solution.denominator());

			if (solutionNum == "0") {
				this->solutionNumber->Text = "0";
			}
			else if (solutionDenom == "1") {
				this->solutionNumber->Text = solutionNum;
			}
			else {
				this->solutionNumber->Text = solutionNum + "/" + solutionDenom;
			}
		}
		catch (System::FormatException^) {
			this->solutionNumber->Text = "Invalid format.";
		}
		catch (System::OverflowException^) {
			this->solutionNumber->Text = "Number is too large.";
		}
		catch (System::Runtime::InteropServices::SEHException^) {
			this->solutionNumber->Text = "Divide by zero encountered.";
		}
	}
};
}
