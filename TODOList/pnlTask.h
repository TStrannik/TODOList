#pragma once
#include "lineTask.h"


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
			lneTask->BackColor				 = Color::FromArgb(248, 8, 128);
			lneTask->ForeColor				 = Color::White;
			lneTask->parForm				 = parForm;
			



			//	[]	pnlSubtasks
			//	[]	pnlSubtasks
			//	[]	pnlSubtasks
			
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

	int						  subtask_counter = 0;
	Windows::Forms::CheckBox^ cbxSubtask = gcnew CheckBox();


private:
	void set_header(String^ str) {

		header = str;

	}

public:
	bool      start    = false;
	String^   header   = gcnew String ("");
	String^   name     = gcnew String ("");
	int		  nomber;


	/// DELETE
	public: System::Windows::Forms::Form^ parForm;
		  //public: frmMain^					  owner;


public:
	inline void subtask_add(String^ name) {

		subtask_counter++;

		cbxSubtask			  = (gcnew CheckBox());

		cbxSubtask->Name	  = L"cbxSubtask " + subtask_counter.ToString();
		cbxSubtask->Text	  = name;
		cbxSubtask->Size	  = Drawing::Size(140, 20);
		cbxSubtask->Dock	  = Windows::Forms::DockStyle::Top;
		cbxSubtask->BackColor = Color::FromArgb(255 - 8 * subtask_counter, 8 * subtask_counter, 128);
		cbxSubtask->ForeColor = Color::White;
		cbxSubtask->Padding   = Windows::Forms::Padding(25, 15, 0, 15);		
		cbxSubtask->TabIndex  = 0;
		//cbxSubtask->Click   += gcnew System::EventHandler(this, &frmMain::task_Click);

		pnlSubtasks->Controls->Add(cbxSubtask);

		update_state();

	}
	void		update_state() {

		lneTask->Name	= L"lne_" + header;
		lneTask->Text	= header;
		lneTask->header = header;
		lneTask->nomber = nomber;
		lneTask->update_state();
		

		// Пересчёт размера
		this->Height = (subtask_counter) * 20 + 48;

	}

#pragma region }





}; }

#pragma endregion






