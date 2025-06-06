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

	return msclr::interop::marshal_as <std::string>(text);

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
	private: System::ComponentModel::Container^ components;
	private: Windows::Forms::ListBox^ listBox1;
	private: Windows::Forms::Button^ button1;
	private: Windows::Forms::Panel^ pnlTasks;
	private: Windows::Forms::Button^ button2;
	private: Windows::Forms::ListBox^ lbxSub;
	private: Windows::Forms::TextBox^ textBox2;
	private: Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ btnDemo;

	private: Windows::Forms::Button^ button5;
	private: Windows::Forms::Button^ button6;
	private: Windows::Forms::Button^ btnRemTask;
	private: Windows::Forms::Button^ btnRemSub;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::Panel^ pnlBlanket;
	private: System::Windows::Forms::Button^ btnAddTask;
	private: System::Windows::Forms::PictureBox^ pbxBack;



	private: Windows::Forms::TextBox^ textBox1;




		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMain::typeid));
			   this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->pnlTasks = (gcnew System::Windows::Forms::Panel());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->lbxSub = (gcnew System::Windows::Forms::ListBox());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->btnDemo = (gcnew System::Windows::Forms::Button());
			   this->button5 = (gcnew System::Windows::Forms::Button());
			   this->button6 = (gcnew System::Windows::Forms::Button());
			   this->btnRemTask = (gcnew System::Windows::Forms::Button());
			   this->btnRemSub = (gcnew System::Windows::Forms::Button());
			   this->btnClose = (gcnew System::Windows::Forms::Button());
			   this->pnlBlanket = (gcnew System::Windows::Forms::Panel());
			   this->btnAddTask = (gcnew System::Windows::Forms::Button());
			   this->pbxBack = (gcnew System::Windows::Forms::PictureBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxBack))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // listBox1
			   // 
			   this->listBox1->FormattingEnabled = true;
			   this->listBox1->Location = System::Drawing::Point(699, 452);
			   this->listBox1->Name = L"listBox1";
			   this->listBox1->Size = System::Drawing::Size(106, 108);
			   this->listBox1->TabIndex = 1;
			   this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMain::listBox1_SelectedIndexChanged);
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(699, 397);
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
			   this->pnlTasks->Size = System::Drawing::Size(380, 600);
			   this->pnlTasks->TabIndex = 3;
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(699, 426);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(106, 20);
			   this->textBox1->TabIndex = 4;
			   // 
			   // button2
			   // 
			   this->button2->Location = System::Drawing::Point(566, 426);
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
			   this->lbxSub->Location = System::Drawing::Point(811, 452);
			   this->lbxSub->Name = L"lbxSub";
			   this->lbxSub->Size = System::Drawing::Size(106, 108);
			   this->lbxSub->TabIndex = 6;
			   this->lbxSub->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMain::lbxSub_SelectedIndexChanged);
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(811, 426);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(106, 20);
			   this->textBox2->TabIndex = 7;
			   // 
			   // button3
			   // 
			   this->button3->Location = System::Drawing::Point(811, 397);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(106, 23);
			   this->button3->TabIndex = 8;
			   this->button3->Text = L"+ подзадача";
			   this->button3->UseVisualStyleBackColor = true;
			   this->button3->Click += gcnew System::EventHandler(this, &frmMain::button3_Click);
			   // 
			   // btnDemo
			   // 
			   this->btnDemo->Location = System::Drawing::Point(434, 537);
			   this->btnDemo->Name = L"btnDemo";
			   this->btnDemo->Size = System::Drawing::Size(75, 23);
			   this->btnDemo->TabIndex = 9;
			   this->btnDemo->Text = L"ДЕМО";
			   this->btnDemo->UseVisualStyleBackColor = true;
			   this->btnDemo->Click += gcnew System::EventHandler(this, &frmMain::button4_Click);
			   // 
			   // button5
			   // 
			   this->button5->Location = System::Drawing::Point(434, 397);
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
			   this->button6->Location = System::Drawing::Point(566, 397);
			   this->button6->Name = L"button6";
			   this->button6->Size = System::Drawing::Size(75, 23);
			   this->button6->TabIndex = 11;
			   this->button6->Text = L"Add_test";
			   this->button6->UseVisualStyleBackColor = false;
			   this->button6->Click += gcnew System::EventHandler(this, &frmMain::button6_Click);
			   // 
			   // btnRemTask
			   // 
			   this->btnRemTask->Location = System::Drawing::Point(669, 452);
			   this->btnRemTask->Name = L"btnRemTask";
			   this->btnRemTask->Size = System::Drawing::Size(24, 23);
			   this->btnRemTask->TabIndex = 12;
			   this->btnRemTask->Text = L"X";
			   this->btnRemTask->UseVisualStyleBackColor = true;
			   this->btnRemTask->Click += gcnew System::EventHandler(this, &frmMain::btnRemTask_Click);
			   // 
			   // btnRemSub
			   // 
			   this->btnRemSub->Location = System::Drawing::Point(923, 452);
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
			   this->btnClose->Location = System::Drawing::Point(923, 0);
			   this->btnClose->Name = L"btnClose";
			   this->btnClose->Size = System::Drawing::Size(79, 50);
			   this->btnClose->TabIndex = 22;
			   this->btnClose->UseVisualStyleBackColor = true;
			   this->btnClose->Click += gcnew System::EventHandler(this, &frmMain::btnClose_Click);
			   // 
			   // pnlBlanket
			   // 
			   this->pnlBlanket->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->pnlBlanket->Location = System::Drawing::Point(386, 367);
			   this->pnlBlanket->Name = L"pnlBlanket";
			   this->pnlBlanket->Size = System::Drawing::Size(602, 233);
			   this->pnlBlanket->TabIndex = 23;
			   this->pnlBlanket->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::pnlBlanket_MouseDoubleClick);
			   // 
			   // btnAddTask
			   // 
			   this->btnAddTask->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				   static_cast<System::Int32>(static_cast<System::Byte>(192)));
			   this->btnAddTask->FlatAppearance->BorderSize = 0;
			   this->btnAddTask->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnAddTask->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->btnAddTask->ForeColor = System::Drawing::Color::White;
			   this->btnAddTask->Location = System::Drawing::Point(434, 439);
			   this->btnAddTask->Name = L"btnAddTask";
			   this->btnAddTask->Size = System::Drawing::Size(60, 55);
			   this->btnAddTask->TabIndex = 24;
			   this->btnAddTask->Text = L"+";
			   this->btnAddTask->UseVisualStyleBackColor = false;
			   // 
			   // pbxBack
			   // 
			   this->pbxBack->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxBack.ErrorImage")));
			   this->pbxBack->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxBack.Image")));
			   this->pbxBack->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbxBack.InitialImage")));
			   this->pbxBack->Location = System::Drawing::Point(434, 56);
			   this->pbxBack->Name = L"pbxBack";
			   this->pbxBack->Size = System::Drawing::Size(500, 500);
			   this->pbxBack->TabIndex = 25;
			   this->pbxBack->TabStop = false;
			   this->pbxBack->Click += gcnew System::EventHandler(this, &frmMain::pbxBack_Click);
			   this->pbxBack->DoubleClick += gcnew System::EventHandler(this, &frmMain::pbxBack_DoubleClick);
			   this->pbxBack->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::pbxBack_MouseDown);
			   this->pbxBack->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::pbxBack_MouseMove);
			   this->pbxBack->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::pbxBack_MouseUp);
			   // 
			   // frmMain
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1000, 600);
			   this->Controls->Add(this->btnAddTask);
			   this->Controls->Add(this->btnClose);
			   this->Controls->Add(this->btnRemSub);
			   this->Controls->Add(this->btnRemTask);
			   this->Controls->Add(this->button6);
			   this->Controls->Add(this->button5);
			   this->Controls->Add(this->btnDemo);
			   this->Controls->Add(this->button3);
			   this->Controls->Add(this->textBox2);
			   this->Controls->Add(this->lbxSub);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->textBox1);
			   this->Controls->Add(this->pnlTasks);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->listBox1);
			   this->Controls->Add(this->pnlBlanket);
			   this->Controls->Add(this->pbxBack);
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
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxBack))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }




#pragma endregion main {



#pragma region variables

	private:
		// Tasks & Subtasks
		Logic* logic;			 /// DELETE
		std::vector <Task*>* tasks = new std::vector <Task*>();

		int					    task_selected = 0;  // -1;
		int					    subtask_selected = 0;	// -1; -> proverka

		static int			    ptask_counter = 0;
		int					    ptask_selected = -1;
		pnlTask^ ptask = gcnew pnlTask();


		// MODEs
		bool is_mode_demo;


		// Drag & Drop
		bool				    _is_mouse_down = false;
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

			is_mode_demo = !is_mode_demo;
			MODE_DEMO(is_mode_demo);

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

		Void pbxBack_DoubleClick(Object^ sender, EventArgs^ e) {

			pbxBack->Parent->Controls->GetChildIndex(pbxBack) == 0 ?
				pbxBack->SendToBack() :
				pbxBack->BringToFront();

		}
		Void pbxBack_Click(Object^ sender, EventArgs^ e) {

			button2_Click(sender, e);

		}
		Void pbxBack_MouseDown(Object^ sender, Windows::Forms::MouseEventArgs^ e) {

			/// DRY

			if (e->Button == Windows::Forms::MouseButtons::Left)
			{
				_x_offset = -e->X - SystemInformation::FrameBorderSize.Width - pbxBack->Left;
				_y_offset = -e->Y - SystemInformation::FrameBorderSize.Height - pbxBack->Top;
				_mouse_offset = System::Drawing::Point(_x_offset, _y_offset);
				_is_mouse_down = true;
			}

		}
		Void pbxBack_MouseMove(Object^ sender, Windows::Forms::MouseEventArgs^ e) {

			if (_is_mouse_down)
			{
				Point mouse_pos = Control::MousePosition;
				mouse_pos.Offset(_mouse_offset->X, _mouse_offset->Y);
				Location = mouse_pos;
			}

		}
		Void pbxBack_MouseUp(Object^ sender, Windows::Forms::MouseEventArgs^ e) {

			if (e->Button == Windows::Forms::MouseButtons::Left) _is_mouse_down = false;

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

				w("\t"); w(t->get_text());  w("\t\thid: "); wl(t->get_hidden());	// w("\t\tstt: "); wl(t->get_state());
				for (const auto& st : t->get_subtasks_vector()) {

					w("\t\t"); w(st->get_text()); w("\t\tstt: "); wl(st->get_state());

				}
				wl();

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

			// Invoke не смог в полиморфизм, поэтому окак
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
		inline bool task_get_hidden(int tsk) {

			return tasks->at(tsk)->get_hidden();

		}
		inline void task_set_hidden(int tsk, bool state) {

			tasks->at(tsk)->set_hidden(state);

		}




		inline void subtask_add(String^ string) {

			tasks->at(task_selected)->new_subtask(sts(string));

		}
		inline void subtask_to_list(Windows::Forms::ListBox^ lbx) {

			if (task_selected > tasks->size() - 1)
				task_selected = tasks->size() - 1;
			if (task_selected < 0) {};														///?

			lbx->Items->Clear();

			if (!tasks->empty())
				for (const auto& st : tasks->at(task_selected)->get_subtasks_vector())
					lbx->Items->Add(sts(st->get_text()));

		}
		inline void subtask_selection(const int& ind) {

			subtask_selected = ind;

		}
		inline void subtask_remove(int tsk, int sub) {

			task_remove(tsk, sub);

		}
		inline void	subtask_swap(int tsk, int sub1, int sub2) {
			// Лень

			//bool diap_ind = ind >= 0 && ind < tasks->size();
			//bool diap_plc = plc >= 0 && plc < tasks->size();
			//if (!diap_ind || !diap_plc) return;
			//std::swap(tasks->at(ind), tasks->at(plc));

		}
		inline void	subtask_up(int tsk, int sub) {

			bool diap_tsk = tsk > 0 && tsk < tasks->size() - 1;
			bool diap_sub = sub > 0 && sub < tasks->at(tsk)->get_subtasks_vector().size();
			if (!diap_sub || !diap_tsk) return;
			std::swap(
				*tasks->at(tsk)->get_subtasks_vector().at(sub),
				*tasks->at(tsk)->get_subtasks_vector().at(sub - 1)
			);

		}
		inline void	subtask_dn(int tsk, int sub) {

			bool diap_tsk = tsk > 0 && tsk < tasks->size() - 1;
			bool diap_sub = sub >= 0 && sub < tasks->at(tsk)->get_subtasks_vector().size() - 1;
			if (!diap_sub || !diap_tsk) return;
			std::swap(
				*tasks->at(tsk)->get_subtasks_vector().at(sub),
				*tasks->at(tsk)->get_subtasks_vector().at(sub + 1)
			);

		}
		inline bool subtask_get_state(int tsk, int sub) {

			return tasks->at(tsk)->get_subtask(sub)->get_state();

		}
		inline void subtask_set_state(int tsk, int sub, bool state) {

			tasks->at(tsk)->get_subtask(sub)->set_state(state);

		}
		inline void	subtask_set_name(int tsk, int sub, String^ str) {

			tasks->at(tsk)->get_subtasks_vector().at(sub)->set_text(sts(str));

		}




		inline void ptask_add(const std::string& name) {

			ptask_counter++;
			ptask = (gcnew pnlTask());


			ptask->nomber = ptask_counter - 1;

			if (!name.empty()) ptask->header = sts(name);
			else			   ptask->header = L"noname";



			ptask->name = L"pnlTask_" + ptask_counter.ToString();
			ptask->Name = L"pnlTask_" + ptask_counter.ToString();
			ptask->state = task_get_state(ptask_counter - 1);

			for (auto st : tasks->at(ptask_counter - 1)->get_subtasks_vector())		// Передача states
				ptask->states->push_back(st->get_state());

			ptask->Location = Drawing::Point(0, 0);
			ptask->Size = Drawing::Size(140, 100);
			ptask->Dock = Windows::Forms::DockStyle::Top;
			ptask->TabIndex = 0;
			ptask->BorderStyle = Windows::Forms::BorderStyle::None;
			ptask->Click += gcnew EventHandler(this, &frmMain::ptask_click);



			pnlTasks->Controls->Add(ptask);
			ptask->BringToFront();

			ptask->update_state();													// Udpdate

		}
		inline void ptask_update() {

			ptask_counter = 0;
			pnlTasks->Controls->Clear();

			for (const auto& t : *tasks) {

				ptask_add(t->get_text());
				for (const auto& st : t->get_subtasks_vector())
					ptask->subtask_add(sts(st->get_text()));			

			}

			ptask->update_state();													// Udpdate



			
			for (int i = 1; i < ptask_counter; ++i) {
			// Hidden/showed subtasks control

				Panel^ panel =
					static_cast <Panel^> (
						pnlTasks->Controls->Find(
							"pnlTask_" + (i + 1).ToString(), 0)[0]);

				Type^ type = panel->GetType();

				MethodInfo^ method = type->GetMethod("subtasks_hide_show",
					BindingFlags::NonPublic | BindingFlags::Instance);

				if (tasks->at(i)->get_hidden()) 
					method->Invoke(panel, nullptr);

			}

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
						new Subtask("Задача 20")
					}
					})
			);
			tasks->push_back(
				new Task({
					"Эбука",
					{
						new Subtask("Задача 30"),
						new Subtask("Задача 31"),
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


		void MODE_DEMO(bool state) {

			std::string taskbar_hide_ = "";

			if (state == false) {

				taskbar_hide_ += "powershell -command \"& {$p='HKCU:SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\StuckRects3';";
				taskbar_hide_ += "$v=(Get-ItemProperty -Path $p).Settings;";
				taskbar_hide_ += "$v[8]=3;&Set-ItemProperty -Path $p -Name Settings -Value $v;";
				taskbar_hide_ += "&Stop-Process -f -ProcessName explorer}\"";

			}
			else {

				taskbar_hide_ += "powershell -command \"& {$p='HKCU:SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\StuckRects3';";
				taskbar_hide_ += "$v=(Get-ItemProperty -Path $p).Settings;";
				taskbar_hide_ += "$v[8]=2;&Set-ItemProperty -Path $p -Name Settings -Value $v;";
				taskbar_hide_ += "&Stop-Process -f -ProcessName explorer}\"";

			}

			system(taskbar_hide_.c_str());

		}
#pragma endregion 



#pragma region }



};
}

#pragma endregion