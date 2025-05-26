#pragma once
#include <vector>
#include "lineTask.h"
#include "lineSubtask.h"
#include "CBX.h"







#pragma region void

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace TODOList {
	public ref class pnlTask : public System::Windows::Forms::Panel {

	public:		pnlTask(void) { InitializeComponent();			   }
	protected: ~pnlTask()	  { if (components) delete components; }

	

	private:	lineTask^				  lneTask;
	private:	Windows::Forms::Panel^	  pnlSubtasks;
	protected:

	private:	System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {

			lneTask		= (gcnew lineTask());
			pnlSubtasks = (gcnew Windows::Forms::Panel());
			SuspendLayout();
			




			// 
			// THIS (pnlTask)
			//

			Name							 = name;
			BackColor						 = Drawing::SystemColors::ButtonHighlight;
			BorderStyle						 = Windows::Forms::BorderStyle::FixedSingle;								 
			Dock							 = Windows::Forms::DockStyle::Top;
			Size							 = Drawing::Size(140, 44);
			


			// 
			// [ lneTask ]
			//

			lneTask->header					 = this->header;
			lneTask->Text					 = this->header;
			lneTask->AutoSize				 = true;
			lneTask->Location				 = Drawing::Point(10, 10);
			lneTask->Size					 = Drawing::Size(140, 48);
			lneTask->Padding				 = Windows::Forms::Padding(15);
			lneTask->TabIndex				 = 0;
			lneTask->Dock					 = Windows::Forms::DockStyle::Top;
			//lneTask->BackColor				 = Color::FromArgb(212, 42, 148);
			lneTask->BackColor				 = Color::FromArgb(202, 10, 202);
			lneTask->ForeColor				 = Color::White;
			lneTask->parForm				 = parForm;
			



			//	|				  |
			//	|	pnlSubtasks   |
			//	|_________________|
			
			pnlSubtasks->Name				 = L"pnlSubtask";
			pnlSubtasks->Location			 = Drawing::Point(0, 0);
			pnlSubtasks->Size				 = Drawing::Size(140, 250);
			pnlSubtasks->Dock				 = Windows::Forms::DockStyle::Top;
			pnlSubtasks->TabIndex			 = 0;




			Controls->Add(pnlSubtasks);
			Controls->Add(this->lneTask);

			ResumeLayout(false);
			PerformLayout();

		}
#pragma endregion

#pragma endregion main {



private:
	int						  subtasks_visible_counter = 0;
	int						  subtask_counter		   = 0;
	Windows::Forms::CheckBox^ cbxSubtask = gcnew CheckBox();
	lineSubtask^			  lneSubtask = gcnew lineSubtask();


public:
	bool      start    = false;
	String^   header   = gcnew String ("");
	String^   name     = gcnew String ("");
	int		  nomber;
	bool	  state;

	/// DELETE ?
public: System::Windows::Forms::Form^ parForm;
		  //public: frmMain^					  owner;

	  std::vector <bool>* _checks = new std::vector <bool>();



public:
	inline void subtask_add(String^ name) {

		subtask_counter++;
		subtasks_visible_counter = subtask_counter;


		lneSubtask = (gcnew lineSubtask());

		lneSubtask->Name = L"lneSubtask_" + subtask_counter.ToString();
		lneSubtask->Text = name;
		lneSubtask->header = name->ToString();
		lneSubtask->par_nomber = nomber;




		// lneSubtask->state = parForm->subtask_get_state(subtask_counter - 1);
		lneSubtask->state = _checks->at(subtask_counter - 1);

		

		lneSubtask->Size = Drawing::Size(140, 30);
		lneSubtask->Dock = Windows::Forms::DockStyle::Top;
		lneSubtask->BackColor = Color::FromArgb(212 - 8 * subtask_counter, 8 * subtask_counter + 42, 148);
		lneSubtask->ForeColor = Color::White;
		lneSubtask->TabIndex = 0;

		pnlSubtasks->Controls->Add(lneSubtask);
		lneSubtask->BringToFront();

		update_state();

	}
	void		update_state() {

		lneTask->Name = L"lne_" + header;
		lneTask->Text = header;
		lneTask->header = header;
		lneTask->nomber = nomber;
		lneTask->state = state;
		lneTask->update_state();

		//lneSubtask->header = lneSubtask->Name;
		//lneSubtask->header = 
		lneSubtask->nomber = subtask_counter - 1;
		lneSubtask->par_nomber = nomber;
		lneSubtask->update_state();

		size_reset();

	}




private:
	void		set_header(String^ str) {

		header = str;

	}
	void		__print_header() {

		Console::WriteLine(header);

	}

	inline void subtasks_hide_show() {

		// pnlSubtasks->Controls->Count ??
		for (int i = 1; i <= subtask_counter; ++i) {

			if (lneSubtask->Visible) {
				pnlSubtasks->Controls->Find("lneSubtask_" + i.ToString(), 0)[0]->Visible = false;
				subtasks_visible_counter = 0;
			}
			else {
				pnlSubtasks->Controls->Find("lneSubtask_" + i.ToString(), 0)[0]->Visible = true;
				subtasks_visible_counter = subtask_counter;
			}

		}

		size_reset();

	}
	inline void size_reset() {

		// subtask_counter
//this->Height = (subtasks_visible_counter) * 20 + 48;
		this->Height = (subtasks_visible_counter) * 30 + 48;

	}





private:
	//void call_method_main(String^ method_name, std::initializer_list <Object^> list) {
	//
	//	Type^ type = Parent->GetType();
	//	
	//	MethodInfo^ method = type->GetMethod(method_name,
	//		BindingFlags::NonPublic | BindingFlags::Instance);
	//	
	//	
	//	cli::array<Object^>^ args =
	//		gcnew cli::array <Object^>(list.size());
	//	
	//	if (list.size() != 0)
	//		for (int i = 0; i < list.size(); ++i)
	//			args[i] = *(list.begin() + i);
	//	else
	//		args = nullptr;
	//	
	//	
	//	if (method != nullptr)
	//		method->Invoke(Parent, args);
	//	else
	//		Console::WriteLine("call_method_error ");
	//		//Console::WriteLine(Parent->Parent->Parent->Name);
	//
	//}


#pragma region }


}; }

#pragma endregion