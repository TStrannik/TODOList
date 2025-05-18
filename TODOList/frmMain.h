#pragma once
#include "sugar.h"
#include "Logic.h"

#include <vector>
#include <string>
#include <iostream>
#include <msclr\marshal_cppstd.h>

#include "pnlTask.h"



#pragma region methods
std::string		sts(System::String^ text) {

	return msclr::interop::marshal_as <std::string> (text);

}
System::String^ sts(std::string text) {

	return gcnew String(text.c_str());

}
#pragma endregion


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
	private: Windows::Forms::ListBox^ listBox1;
	private: Windows::Forms::Button^  button1;
	private: Windows::Forms::Panel^   pnlTasks;

	private: Windows::Forms::Button^  button2;
	private: Windows::Forms::ListBox^ lbxSub;
	private: Windows::Forms::TextBox^ textBox2;
	private: Windows::Forms::Button^  button3;
	private: Windows::Forms::Button^  button4;
	private: Windows::Forms::Button^  button5;
	private: Windows::Forms::Button^  button6;
	private: Windows::Forms::Button^  btnRemTask;
	private: Windows::Forms::Button^  btnRemSub;







	private: Windows::Forms::TextBox^ textBox1;



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
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->btnRemTask = (gcnew System::Windows::Forms::Button());
			this->btnRemSub = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(653, 120);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(106, 108);
			this->listBox1->TabIndex = 1;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMain::listBox1_SelectedIndexChanged);
			this->listBox1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::listBox1_MouseDoubleClick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(653, 65);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 23);
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
			this->pnlTasks->Size = System::Drawing::Size(380, 546);
			this->pnlTasks->TabIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(653, 94);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(106, 20);
			this->textBox1->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(765, 250);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 53);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Отобр структ";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMain::button2_Click);
			// 
			// lbxSub
			// 
			this->lbxSub->FormattingEnabled = true;
			this->lbxSub->Location = System::Drawing::Point(765, 120);
			this->lbxSub->Name = L"lbxSub";
			this->lbxSub->Size = System::Drawing::Size(106, 108);
			this->lbxSub->TabIndex = 6;
			this->lbxSub->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMain::lbxSub_SelectedIndexChanged);
			this->lbxSub->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::lbxSub_MouseDoubleClick);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(765, 94);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(106, 20);
			this->textBox2->TabIndex = 7;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(765, 65);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(106, 23);
			this->button3->TabIndex = 8;
			this->button3->Text = L"+ подзадача";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMain::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(386, 31);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 9;
			this->button4->Text = L"заолежить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmMain::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(386, 170);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(106, 23);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Посмотреть";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &frmMain::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(653, 250);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 11;
			this->button6->Text = L"Add_test";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &frmMain::button6_Click);
			// 
			// btnRemTask
			// 
			this->btnRemTask->Location = System::Drawing::Point(572, 120);
			this->btnRemTask->Name = L"btnRemTask";
			this->btnRemTask->Size = System::Drawing::Size(75, 23);
			this->btnRemTask->TabIndex = 12;
			this->btnRemTask->Text = L"Загубить";
			this->btnRemTask->UseVisualStyleBackColor = true;
			this->btnRemTask->Click += gcnew System::EventHandler(this, &frmMain::btnRemTask_Click);
			// 
			// btnRemSub
			// 
			this->btnRemSub->Location = System::Drawing::Point(877, 120);
			this->btnRemSub->Name = L"btnRemSub";
			this->btnRemSub->Size = System::Drawing::Size(75, 23);
			this->btnRemSub->TabIndex = 13;
			this->btnRemSub->Text = L"Стереть";
			this->btnRemSub->UseVisualStyleBackColor = true;
			this->btnRemSub->Click += gcnew System::EventHandler(this, &frmMain::btnRemSub_Click);
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(959, 546);
			this->Controls->Add(this->btnRemSub);
			this->Controls->Add(this->btnRemTask);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
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



#pragma region variables
	Logic*				   logic;
	std::vector <Task*>*   tasks		    = new std::vector <Task*>();
	int					   task_selected    = 0;  // -1;
	int					   subtask_selected = 0;	// -1; -> proverka
	
	static int			   ptask_counter	= 0;
	int					   ptask_selected	= -1;
	pnlTask^ ptask							= gcnew pnlTask();
#pragma endregion



#pragma region events
	inline void ptask_add(const std::string& name) {

		ptask_counter++;

		ptask			   = (gcnew pnlTask());
		
		if (!name.empty()) ptask->header = sts(name);
		else			   ptask->header = L"";

		ptask->Name		   = L"pnlTask_" + sts(std::to_string(ptask_counter));
		ptask->Location	   = System::Drawing::Point(0, 0);
		ptask->Size		   = System::Drawing::Size(140, 100);		
		ptask->Dock		   = System::Windows::Forms::DockStyle::Top;
		ptask->TabIndex	   = 0;
		ptask->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		ptask->Click	  += gcnew System::EventHandler(this, &frmMain::ptask_click);

		pnlTasks->Controls->Add(ptask);

		ptask->update_state();

	}
	Void ptask_click(Object^ sender, EventArgs^ e) {
	
		pnlTask^ ptask = (pnlTask^)sender;

		w('\t'); w(sts(ptask->Name)); w(" : "); wl(sts(ptask->header));

		ptask->update_state();

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

		subtask_add(textBox2->Text);
		subtask_to_list(lbxSub);

	}
	Void button4_Click(Object^ sender, EventArgs^ e) {

		ptask_add("O L E G");

	}
	Void button5_Click(Object^ sender, EventArgs^ e) {

		ptask_add(tasks->back()->get_text());

		for (const auto& t : *tasks)
		{

			for (const auto& st : t->get_subtasks_vector())
			{
				ptask->subtask_add(sts(st->get_text()));
			}			
		}
		

	}
	Void button6_Click(Object^ sender, EventArgs^ e) {

		test_tasks();

	}
	Void btnRemSub_Click(Object^ sender, EventArgs^ e) {

		task_remove(task_selected, subtask_selected);
		subtask_to_list(lbxSub);

	}
	Void btnRemTask_Click(Object^ sender, EventArgs^ e) {

		task_remove(task_selected);
		task_to_list(listBox1);
		subtask_to_list(lbxSub);

	}

	Void listBox1_SelectedIndexChanged(Object^ sender, EventArgs^ e) {
		
		task_selection(listBox1->SelectedIndex);
	
	}
	Void listBox1_MouseDoubleClick(Object^ sender, MouseEventArgs^ e) {

		w("\t#id^ "); wl(tasks->at(task_selected)->get_id());

	}
	Void lbxSub_SelectedIndexChanged(Object^ sender, EventArgs^ e) {

		subtask_selection(lbxSub->SelectedIndex);

	}
	Void lbxSub_MouseDoubleClick(Object^ sender, MouseEventArgs^ e) {

		w("\t#id^ "); w(tasks->at(task_selected)->get_id());
		w(" sub^"); wl(tasks->at(task_selected)->get_subtasks_vector().at(subtask_selected)->get_id());

	}
#pragma endregion	

	

#pragma region operations
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
		subtask_to_list(lbxSub);
		

		//w(tasks->at(ind)->get_text()); wl(" ->selected");

	}
	inline void task_remove(int tsk) {

		tasks->at(tsk)->remove();
		tasks->erase(tasks->begin() + tsk);

	}
	inline void task_remove(int tsk, int sub) {

		tasks->at(tsk)->remove(sub);

	}

	inline void subtask_add(String^ string) {

		tasks->at(task_selected)->new_subtask(sts(string));

	}
	inline void subtask_to_list(Windows::Forms::ListBox^ lbx) {

		lbx->Items->Clear();

		for (const auto& st : tasks->at(task_selected)->get_subtasks_vector())
			lbx->Items->Add(sts(st->get_text()));

	}
	
	inline void subtask_selection(const int& ind) {

		subtask_selected = ind;

	}

	inline void test_tasks() {

		tasks->push_back(
			new Task({
				"Gavka"
			})
		);
		tasks->push_back(
			new Task({
				"Kogtic",
				{
					new Subtask("20")
				}
			})
		);
		tasks->push_back(
			new Task({
				"Ebuca",
				{
					new Subtask("30"),
					new Subtask("31"),
				}
			})
		);
		tasks->push_back(
			new Task({
				"Bupca",
				{
					new Subtask("40"),
					new Subtask("41"),
					new Subtask("42"),
					new Subtask("43"),
					new Subtask("44"),
				}
				})
		);

		task_to_list(listBox1);
		subtask_to_list(lbxSub);

	}
#pragma endregion 



#pragma region }

}; }

#pragma endregion