#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace TODOList {

	public ref class pnlTask : public System::Windows::Forms::Panel
	{
	public:
		pnlTask(void)
		{
			InitializeComponent();

		}

	protected:
		~pnlTask()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^ cbxTask;
	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->cbxTask = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->cbxTask->AutoSize = true;
			this->cbxTask->Location = System::Drawing::Point(10, 10);
			this->cbxTask->Name = L"cbxTask";
			this->cbxTask->Size = System::Drawing::Size(104, 24);
			this->cbxTask->TabIndex = 0;
			this->cbxTask->Text = L"cbxTask";
			this->cbxTask->UseVisualStyleBackColor = true;
			this->Controls->Add(cbxTask);
			// 
			// pnlTask
			// 
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Dock = System::Windows::Forms::DockStyle::Top;
			this->Name = L"pnlOleg ";
			this->Size = System::Drawing::Size(140, 44);
			this->ResumeLayout(false);

		}
#pragma endregion
		Void pnlTask_Load(System::Object^ sender, System::EventArgs^ e) {


		}

	};
}
