#pragma once
#include "Logic.h"
#include <utility>
#include <string>
#include <iostream>
#include <msclr\marshal_cppstd.h>


std::string sts(System::String^ string) {

	return msclr::interop::marshal_as<std::string>(string);

}


#pragma region Kernel

namespace TODOList {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class frmMain : public System::Windows::Forms::Form {

	public:		frmMain(void) { InitializeComponent(); }
	protected:  ~frmMain() { if (components) delete components; }
	private: System::Windows::Forms::CheckBox^ checkBox1;
	protected:
	private: System::ComponentModel::Container ^components;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;

#pragma endregion Kernel

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(15, 13);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(80, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(242, 131);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(311, 108);
			this->listBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(478, 84);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMain::button1_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->checkBox1);
			this->panel1->Location = System::Drawing::Point(32, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(140, 227);
			this->panel1->TabIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(242, 87);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(237, 20);
			this->textBox1->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(179, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMain::button2_Click);
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(659, 292);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Name = L"frmMain";
			this->Text = L"frmMain";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &frmMain::frmMain_FormClosed);
			this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		Logic*				 logic;
		std::vector <Task*>* tasks = new std::vector <Task*>();



		Void frmMain_Load(System::Object^ sender, System::EventArgs^ e) {

			logic = new Logic();

		}
		Void frmMain_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {


			for (int i = 0; i < tasks->size(); ++i)
				delete tasks->at(i);

			tasks->clear();
			delete tasks;


			delete logic;

		}



		Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

			std::string* str = new std::string (sts(textBox1->Text));

			if (!(str->empty()))
				tasks->push_back(new Task{ *str });

			delete str;

		}



		Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

			std::cout << std::endl << "tasks:" << std::endl;

			for (int i = 0; i < tasks->size(); ++i) {

				std::cout << '\t' << tasks->at(i)->get_text() << std::endl;

			}

			std::cout << std::endl;

		}

	};// frmMain
}