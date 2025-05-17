#pragma once
#include "sugar.h"
#include "Logic.h"

#include <vector>
#include <string>
#include <iostream>
#include <msclr\marshal_cppstd.h>

#include "pnlTask.h"


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

	protected:
	private: System::ComponentModel::Container ^components;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ pnlTasks;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ListBox^ lbxSub;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;






	private: System::Windows::Forms::TextBox^ textBox1;



#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pnlTasks = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->lbxSub = (gcnew System::Windows::Forms::ListBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(482, 165);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(106, 69);
			this->listBox1->TabIndex = 1;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMain::listBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(594, 111);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"+ задача";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMain::button1_Click);
			// 
			// pnlTasks
			// 
			this->pnlTasks->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pnlTasks->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlTasks->Location = System::Drawing::Point(0, 0);
			this->pnlTasks->Name = L"pnlTasks";
			this->pnlTasks->Size = System::Drawing::Size(235, 546);
			this->pnlTasks->TabIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(482, 113);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(106, 20);
			this->textBox1->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(482, 69);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(122, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Отобр структ";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMain::button2_Click);
			// 
			// lbxSub
			// 
			this->lbxSub->FormattingEnabled = true;
			this->lbxSub->Location = System::Drawing::Point(594, 165);
			this->lbxSub->Name = L"lbxSub";
			this->lbxSub->Size = System::Drawing::Size(106, 69);
			this->lbxSub->TabIndex = 6;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(594, 139);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(106, 20);
			this->textBox2->TabIndex = 7;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(706, 136);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(114, 23);
			this->button3->TabIndex = 8;
			this->button3->Text = L"+ подзадача";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMain::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(269, 34);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 9;
			this->button4->Text = L"заолежить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmMain::button4_Click);
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(959, 546);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->lbxSub);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pnlTasks);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Name = L"frmMain";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"frmMain";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &frmMain::frmMain_FormClosed);
			this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private:

#pragma endregion main {

	Logic*				 logic;
	std::vector <Task*>* tasks		   = new std::vector <Task*>();
	int					 task_selected = -1;
	
	//std::vector <Windows::Forms::Panel^>* drags = 
	//	new std::vector <Windows::Forms::Panel^>();
	static int oleg_counter = 0;
	int		   oleg_selected = -1;


	// Experemental
	Windows::Forms::Panel^ oleg = gcnew pnlTask();
	inline void make_oleg() {

		oleg_counter++;

		this->oleg = (gcnew pnlTask());

		this->oleg->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		//this->oleg->BackColor = System::Drawing::SystemColors::ButtonShadow;
		this->oleg->Dock = System::Windows::Forms::DockStyle::Top;
		this->oleg->Location = System::Drawing::Point(0, 0);
		this->oleg->Name = L"pnlOleg " + sts(std::to_string(oleg_counter));
		this->oleg->Size = System::Drawing::Size(140, 44);
		this->oleg->TabIndex = 0;
		this->oleg->Click += gcnew System::EventHandler(this, &frmMain::oleg_Click);

		this->pnlTasks->Controls->Add(oleg);

	}
	Void oleg_Click(Object^ sender, EventArgs^ e) {
	
		Windows::Forms::Panel^ oleg = (Panel^)sender;

		w('\t'); wl(sts(oleg->Name));

	}

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
	Void button3_Click(Object^ sender, EventArgs^ e) {

		tasks->at(task_selected)->new_subtask(sts(textBox2->Text));
		subtask_to_list(lbxSub);

	}
	Void button4_Click(Object^ sender, EventArgs^ e) {

		make_oleg();

	}

	Void listBox1_SelectedIndexChanged(Object^ sender, EventArgs^ e) {
		
		task_selection(listBox1->SelectedIndex);
	
	}
	
	Void checkBox1_CheckedChanged(Object^ sender, EventArgs^ e) {



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