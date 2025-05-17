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
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button3;
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
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
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
			this->listBox1->Location = System::Drawing::Point(264, 137);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(106, 69);
			this->listBox1->TabIndex = 1;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMain::listBox1_SelectedIndexChanged);
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
			this->lbxSub->Location = System::Drawing::Point(376, 137);
			this->lbxSub->Name = L"lbxSub";
			this->lbxSub->Size = System::Drawing::Size(106, 69);
			this->lbxSub->TabIndex = 6;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(376, 111);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(106, 20);
			this->textBox2->TabIndex = 7;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(488, 108);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 8;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMain::button3_Click);
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(659, 292);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->lbxSub);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Name = L"frmMain";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
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
	std::vector <Task*>* tasks		   = new std::vector <Task*>();
	int					 task_selected = -1;
	
	
	
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

	Void listBox1_SelectedIndexChanged(Object^ sender, EventArgs^ e) {
		
		task_selection(listBox1->SelectedIndex);
	
	}
	Void button3_Click(Object^ sender, EventArgs^ e) {

		tasks->at(task_selected)->new_subtask(sts(textBox2->Text));
		subtask_to_list(lbxSub);

	}
	
	
	inline void task_to_list(Windows::Forms::ListBox^ lbx) {

		lbx->Items->Clear();

		for (const auto& t : *tasks)
			lbx->Items->Add(sts(t->get_text()));

	}
	inline void task_delete_all() {

			for (const auto& t : *tasks)
				delete t;

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

			for (const auto& t : *tasks) {

				w("\t"); wl(t->get_text());
				for (const auto& st : t->get_subtasks_vector()) {

					w("\t\t"); wl(st->get_text());

				}
				
			}

			wl();

		}
	inline void task_selection(const int& ind) {

		task_selected = ind;

		w(tasks->at(ind)->get_text()); wl(" ->selected");

		subtask_to_list(lbxSub);

	}
	inline void subtask_to_list(Windows::Forms::ListBox^ lbx) {

		lbx->Items->Clear();

		for (const auto& st : tasks->at(task_selected)->get_subtasks_vector())
			lbx->Items->Add(sts(st->get_text()));

	}

#pragma region }

	

}; }

#pragma endregion