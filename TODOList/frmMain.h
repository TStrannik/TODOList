#pragma once
#include "sugar.h"
#include "Logic.h"

#include <vector>
#include <string>
#include <iostream>
#include <msclr\marshal_cppstd.h>


std::string		sts(System::String^ text) {

	return msclr::interop::marshal_as <std::string> (text);

}
System::String^ sts(std::string text) {

	return gcnew String(text.c_str());

}



#pragma region void

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
	private: System::Windows::Forms::ListBox^ lbxSub;
	private: System::Windows::Forms::TextBox^ textBox1;



#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->lbxSub = (gcnew System::Windows::Forms::ListBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(15, 6);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(80, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(242, 170);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(106, 69);
			this->listBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(475, 56);
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
			this->textBox1->Location = System::Drawing::Point(242, 58);
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
			// lbxSub
			// 
			this->lbxSub->FormattingEnabled = true;
			this->lbxSub->Location = System::Drawing::Point(402, 94);
			this->lbxSub->Name = L"lbxSub";
			this->lbxSub->Size = System::Drawing::Size(106, 69);
			this->lbxSub->TabIndex = 6;
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(659, 292);
			this->Controls->Add(this->lbxSub);
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

#pragma endregion main {

	Logic*				 logic;
	std::vector <Task*>* tasks = new std::vector <Task*>();
	
	
	
	Void frmMain_Load(Object^ sender, EventArgs^ e) {

			logic = new Logic();

		}
	Void frmMain_FormClosed(Object^ sender, Windows::Forms::FormClosedEventArgs^ e) {

			task_delete_all();
			delete logic;

		}
	
	Void button1_Click(Object^ sender, EventArgs^ e) {
			
			task_add_1(textBox1->Text);
			task_to_list(listBox1);
		
		}
	Void button2_Click(Object^ sender, EventArgs^ e) {
			
			task_show();
		
		}
	
	
	
	inline void task_to_list(Windows::Forms::ListBox^ lbx) {

			lbx->Items->Clear();

			for (const auto& el : *tasks)
				lbx->Items->Add(sts(el->get_text()));

		}
	inline void task_delete_all() {

			for (const auto& el : *tasks)
				delete el;

			tasks->clear();
			delete tasks;

		}
	inline void task_add_1(String^ string) {

			std::string* str = new std::string(sts(textBox1->Text));

			if (!(str->empty()))
				tasks->push_back(new Task{ *str });

			delete str;

		}
	inline void task_show() {

			wl(); wl("tasks: ");

			for (const auto& el : *tasks) {
				w("\t"); wl(el->get_text());
			}

			wl();

		}

#pragma region }

};}

#pragma endregion