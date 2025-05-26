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








	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::Panel^ pnlBlanket;












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
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->pnlBlanket = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(742, 411);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(106, 108);
			this->listBox1->TabIndex = 1;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMain::listBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(742, 356);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"+ задача";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMain::button1_Click);
			// 
			// pnlTasks
			// 
			this->pnlTasks->AutoScroll = true;
			this->pnlTasks->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->pnlTasks->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlTasks->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pnlTasks->Location = System::Drawing::Point(0, 0);
			this->pnlTasks->Name = L"pnlTasks";
			this->pnlTasks->Size = System::Drawing::Size(380, 550);
			this->pnlTasks->TabIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(742, 385);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(106, 20);
			this->textBox1->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(609, 385);
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
			this->lbxSub->Location = System::Drawing::Point(854, 411);
			this->lbxSub->Name = L"lbxSub";
			this->lbxSub->Size = System::Drawing::Size(106, 108);
			this->lbxSub->TabIndex = 6;
			this->lbxSub->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMain::lbxSub_SelectedIndexChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(854, 385);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(106, 20);
			this->textBox2->TabIndex = 7;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(854, 356);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(106, 23);
			this->button3->TabIndex = 8;
			this->button3->Text = L"+ подзадача";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMain::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(477, 496);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Свободно";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmMain::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(477, 356);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(106, 23);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Посмотреть";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &frmMain::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button6->Location = System::Drawing::Point(609, 356);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 11;
			this->button6->Text = L"Add_test";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &frmMain::button6_Click);
			// 
			// btnRemTask
			// 
			this->btnRemTask->Location = System::Drawing::Point(712, 411);
			this->btnRemTask->Name = L"btnRemTask";
			this->btnRemTask->Size = System::Drawing::Size(24, 23);
			this->btnRemTask->TabIndex = 12;
			this->btnRemTask->Text = L"X";
			this->btnRemTask->UseVisualStyleBackColor = true;
			this->btnRemTask->Click += gcnew System::EventHandler(this, &frmMain::btnRemTask_Click);
			// 
			// btnRemSub
			// 
			this->btnRemSub->Location = System::Drawing::Point(966, 411);
			this->btnRemSub->Name = L"btnRemSub";
			this->btnRemSub->Size = System::Drawing::Size(25, 23);
			this->btnRemSub->TabIndex = 13;
			this->btnRemSub->Text = L"X";
			this->btnRemSub->UseVisualStyleBackColor = true;
			this->btnRemSub->Click += gcnew System::EventHandler(this, &frmMain::btnRemSub_Click);
			// 
			// btnClose
			// 
			this->btnClose->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnClose->FlatAppearance->BorderColor = System::Drawing::Color::WhiteSmoke;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->Location = System::Drawing::Point(1008, 0);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(42, 42);
			this->btnClose->TabIndex = 22;
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &frmMain::btnClose_Click);
			// 
			// pnlBlanket
			// 
			this->pnlBlanket->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlBlanket->Location = System::Drawing::Point(386, 348);
			this->pnlBlanket->Name = L"pnlBlanket";
			this->pnlBlanket->Size = System::Drawing::Size(652, 190);
			this->pnlBlanket->TabIndex = 23;
			this->pnlBlanket->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::pnlBlanket_MouseDoubleClick);
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1050, 550);
			this->Controls->Add(this->btnClose);
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
			this->Controls->Add(this->pnlBlanket);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"frmMain";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"frmMain";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &frmMain::frmMain_FormClosed);
			this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmMain::frmMain_Paint);
			this->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::frmMain_MouseDoubleClick);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::frmMain_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::frmMain_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::frmMain_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		

#pragma endregion main {



#pragma region variables

private:
// Tasks & Subtasks
	Logic*				    logic;			 /// DELETE
	std::vector <Task*>*    tasks		     = new std::vector <Task*>();
						    
	int					    task_selected    = 0;  // -1;
	int					    subtask_selected = 0;	// -1; -> proverka
						    
	static int			    ptask_counter	 = 0;
	int					    ptask_selected	 = -1;
	pnlTask^ ptask							 = gcnew pnlTask();


// Drag & Drop
	bool				    _is_mouse_down   = false;
	int					    _x_offset;
	int					    _y_offset;
	System::Drawing::Point^ _mouse_offset;
#pragma endregion



#pragma region events
	Void ptask_click(Object^ sender, EventArgs^ e) {
	
		pnlTask^ ptask = (pnlTask^)sender;

		w('\t'); w(sts(ptask->Name)); w(" : "); wl(sts(ptask->header));

		ptask->update_state();

	}

	Void frmMain_Load(Object^ sender, EventArgs^ e) {

		logic = new Logic();


		this->DoubleBuffered = true;				// Двойная буфферизация вкл.
		SetStyle(ControlStyles::OptimizedDoubleBuffer, true);
		this->SetStyle(ControlStyles::DoubleBuffer, true);
		this->SetStyle(ControlStyles::UserPaint, true);



	}
	Void frmMain_FormClosed(Object^ sender, Windows::Forms::FormClosedEventArgs^ e) {

		task_delete_all();
		delete logic;

	}
	Void frmMain_MouseDoubleClick(Object^ sender, Windows::Forms::MouseEventArgs^ e) {

		Width = (Width == 430) ? 1050 : 430;

	}
	Void frmMain_MouseDown(Object^ sender, Windows::Forms::MouseEventArgs^ e) {

		if (e->Button == Windows::Forms::MouseButtons::Left)
		{
			_x_offset = -e->X - SystemInformation::FrameBorderSize.Width;
			_y_offset = -e->Y - SystemInformation::FrameBorderSize.Height;
			_mouse_offset = System::Drawing::Point(_x_offset, _y_offset);
			_is_mouse_down = true;
		}

	}
	Void frmMain_MouseMove(Object^ sender, Windows::Forms::MouseEventArgs^ e) {

		if (_is_mouse_down)
		{
			Point mouse_pos = Control::MousePosition;
			mouse_pos.Offset(_mouse_offset->X, _mouse_offset->Y);
			Location = mouse_pos;
		}

	}	
	Void frmMain_MouseUp(Object^ sender, Windows::Forms::MouseEventArgs^ e) {

		if (e->Button == Windows::Forms::MouseButtons::Left) _is_mouse_down = false;
		
	}
	Void frmMain_Paint(Object^ sender, Windows::Forms::PaintEventArgs^ e) {

		e->Graphics->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
		System::Drawing::Drawing2D::GraphicsPath^ path = gcnew System::Drawing::Drawing2D::GraphicsPath();
		int r = 20;
		int w = this->Width;
		int h = this->Height;

		path->AddArc(0, 0, r, r, 180, 90);
		path->AddArc(w - r, 0, r, r, 270, 90);
		path->AddArc(w - r, h - r, r, r, 0, 90);
		path->AddArc(0, h - r, r, r, 90, 90);

		this->Region = gcnew Drawing::Region(path);

	}

	Void btnClose_Click(Object^ sender, EventArgs^ e) {

		this->Close();

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

		

	}
	Void button5_Click(Object^ sender, EventArgs^ e) {

		ptask_update();

	}
	Void button6_Click(Object^ sender, EventArgs^ e) {

		test_tasks();

		//update_all()
		task_to_list(listBox1);
		subtask_to_list(lbxSub);
		ptask_update();

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
	Void lbxSub_SelectedIndexChanged(Object^ sender, EventArgs^ e) {

		subtask_selection(lbxSub->SelectedIndex);

	}


	Void pnlBlanket_MouseDoubleClick(Object^ sender, Windows::Forms::MouseEventArgs^ e) {

		pnlBlanket->Parent->Controls->GetChildIndex(pnlBlanket) == 0 ?
			pnlBlanket->SendToBack() :
			pnlBlanket->BringToFront();

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

			w("\t"); w(t->get_text()); w("\t\tstt: "); wl(t->get_state());
			for (const auto& st : t->get_subtasks_vector()) {

				w("\t\t"); w(st->get_text()); w("\t\tstt: "); wl(st->get_state());

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
	inline void task_remove_one(int tsk) {

		task_remove(tsk);

	}
	inline void	task_swap(int ind, int plc) {

		bool diap_ind = ind >= 0 && ind < tasks->size();
		bool diap_plc = plc >= 0 && plc < tasks->size();
		if (!diap_ind || !diap_plc) return;
		std::swap(tasks->at(ind), tasks->at(plc));

	}
	inline void	task_up(int ind) {

		bool diap_ind = ind > 0 && ind < tasks->size();
		if (!diap_ind) return;
		std::swap(tasks->at(ind), tasks->at(ind - 1));

	}
	inline void	task_dn(int ind) {

		bool diap_ind = ind >= 0 && ind < tasks->size() - 1;
		if (!diap_ind) return;
		std::swap(tasks->at(ind), tasks->at(ind + 1));

	}
	inline void	task_set_name(int ind, String^ str) {

		tasks->at(ind)->set_text(sts(str));

	}
	inline bool task_get_state(int tsk) {

		return tasks->at(tsk)->get_state();

	}
	inline void task_set_state(int ind, bool state) {

		tasks->at(ind)->set_state(state);

	}



	inline void subtask_add(String^ string) {

		tasks->at(task_selected)->new_subtask(sts(string));

	}
	inline void subtask_to_list(Windows::Forms::ListBox^ lbx) {

		lbx->Items->Clear();

		if (!tasks->empty())
			for (const auto& st : tasks->at(task_selected)->get_subtasks_vector())
				lbx->Items->Add(sts(st->get_text()));

	}
	inline void subtask_selection(const int& ind) {

		subtask_selected = ind;

	}
	inline bool subtask_get_state(int tsk, int sub) {

		return tasks->at(tsk)->get_subtask(sub)->get_state();			

	}
	inline void subtask_set_state(int tsk, int sub, bool state) {

		tasks->at(tsk)->get_subtask(sub)->set_state(state);

	}



	inline void ptask_add(const std::string& name) {

		ptask_counter++;

		ptask = (gcnew pnlTask());


		ptask->parForm = this;
		//ptask->nomber = tasks->size() - ptask_counter;
		ptask->nomber = ptask_counter - 1;

		if (!name.empty()) ptask->header = sts(name);
		else			   ptask->header = L"noname";

		ptask->name  = L"pnlTask_" + ptask_counter.ToString();
		ptask->Name  = L"pnlTask_" + ptask_counter.ToString();
		ptask->state = task_get_state(ptask_counter - 1);

		ptask->Location = Drawing::Point(0, 0);
		ptask->Size = Drawing::Size(140, 100);
		ptask->Dock = Windows::Forms::DockStyle::Top;
		ptask->TabIndex = 0;
		//ptask->BorderStyle = Windows::Forms::BorderStyle::FixedSingle;
		ptask->BorderStyle = Windows::Forms::BorderStyle::None;
		ptask->Click += gcnew EventHandler(this, &frmMain::ptask_click);

		pnlTasks->Controls->Add(ptask);
		ptask->BringToFront();

		ptask->update_state();

	}
	inline void ptask_update() {

		ptask_counter = 0;
		pnlTasks->Controls->Clear();

		for (const auto& t : *tasks) {

			ptask_add(t->get_text());
			for (const auto& st : t->get_subtasks_vector())
				ptask->subtask_add_GOAL(sts(st->get_text()));

		}

		ptask->update_state();

	}

	inline void update_all() {

		task_to_list(listBox1);
		subtask_to_list(lbxSub);
		ptask_update();

	}
	inline void update_lists() {

		task_to_list(listBox1);
		subtask_to_list(lbxSub);

	}

	inline void test_tasks() {

		tasks->push_back(
			new Task({
				"Гавка"
				})
		);
		tasks->push_back(
			new Task({
				"Когтик",
				{
					new Subtask("20")
				}
				})
		);
		tasks->push_back(
			new Task({
				"Эбука",
				{
					new Subtask("30"),
					new Subtask("31"),
				}
				})
		);
		tasks->push_back(
			new Task({
				"Бупка",
				{
					new Subtask("Дышать"),
					new Subtask("Видеть"),
					new Subtask("Смотреть"),
					new Subtask("Держать"),
					new Subtask("Гнать"),
				}
				})
		);
		tasks->push_back(
			new Task({
				"Свистосвинья"
			})
		);

		task_to_list(listBox1);
		subtask_to_list(lbxSub);

	}
#pragma endregion 



#pragma region }


}; }

#pragma endregion