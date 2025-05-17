#pragma once



#pragma region void

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace TODOList {

	public ref class pnlTask : public System::Windows::Forms::Panel {

	public:		pnlTask(void) { InitializeComponent(); }
	protected: ~pnlTask() { if (components) delete components; }

	private:	System::Windows::Forms::CheckBox^ cbxTask;
	private:	System::Windows::Forms::TextBox^ txtTask;
	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			cbxTask = (gcnew System::Windows::Forms::CheckBox());
			txtTask = (gcnew System::Windows::Forms::TextBox());
			SuspendLayout();
			
			// pnlTask
			// 
			//
			//Name							 = L"pnlOleg ";
			BackColor						 = System::Drawing::SystemColors::ButtonHighlight;
			BorderStyle						 = System::Windows::Forms::BorderStyle::FixedSingle;								 
			Dock							 = System::Windows::Forms::DockStyle::Top;
			Size							 = System::Drawing::Size(140, 44);

			// cbxTask
			// 
			//
			cbxTask->Name					 = L"cbxTask";
			cbxTask->AutoSize				 = true;
			cbxTask->Location				 = System::Drawing::Point(10, 10);
			cbxTask->Size					 = System::Drawing::Size(67, 17);
			cbxTask->TabIndex				 = 0;
			cbxTask->Text					 = this->Name;
			cbxTask->UseVisualStyleBackColor = true;
			cbxTask->CheckedChanged			+= gcnew System::EventHandler(this, &pnlTask::cbxTask_CheckedChanged);
			 
			// txtTask
			//
			//
			txtTask->Visible				 = false;
			txtTask->Name					 = L"txtTask";
			txtTask->Location				 = System::Drawing::Point(25, 7);
			txtTask->Size					 = System::Drawing::Size(100, 20);
			txtTask->TabIndex				 = 0;			
			txtTask->KeyPress				+= gcnew System::Windows::Forms::KeyPressEventHandler(this, &pnlTask::txtTask_KeyPress);

			Controls->Add(this->cbxTask);
			Controls->Add(this->txtTask);
			ResumeLayout(false);
			PerformLayout();

		}
#pragma endregion

#pragma endregion main {

	private:

		int						  subtask_counter = 0;
		Windows::Forms::CheckBox^ cbxSubtask	  = gcnew CheckBox();




		Void txtTask_KeyPress(Object^ sender, Windows::Forms::KeyPressEventArgs^ e) {

			//if (e->KeyChar == 13) {
			//	cbxTask->Text	 = txtTask->Text;
			//	txtTask->Visible = false;
			//}

		}
		Void cbxTask_CheckedChanged(Object^ sender, EventArgs^ e) {

			txtTask->Visible = !txtTask->Visible;
			txtTask->BringToFront();

		}




public:
	bool    start  = false;
	String^ header = gcnew String ("");
	//std::vector <String^>* subs = new std::vector <String^>();

public:
	inline void subtask_add(String^ name) {

		subtask_counter++;

		cbxSubtask			 = (gcnew CheckBox());

		cbxSubtask->Name	 = L"cbxSubtask " + subtask_counter.ToString();
		cbxSubtask->Text	 = name;
		cbxSubtask->Size	 = System::Drawing::Size(140, 44);
		cbxSubtask->Dock	 = System::Windows::Forms::DockStyle::Top;
		cbxSubtask->TabIndex = 0;
		//cbxSubtask->Click   += gcnew System::EventHandler(this, &frmMain::task_Click);

		Controls->Add(cbxSubtask);


	}
	void		update_state() {

		cbxTask->Text = header;

		Console::WriteLine("\tU P D A T E ");

	}
#pragma region }





}; }

#pragma endregion
