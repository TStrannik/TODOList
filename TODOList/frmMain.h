#pragma once
#include "Logic.h"

namespace TODOList {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class frmMain : public System::Windows::Forms::Form {

#pragma region Kernel

	public:		frmMain(void) { InitializeComponent(); }
	protected:  ~frmMain() { if (components) delete components; }
	private: System::Windows::Forms::CheckBox^ checkBox1;
	protected:
	private: System::ComponentModel::Container ^components;

	private:
		Logic^ logic;


#pragma endregion Kernel

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(172, 106);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(80, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(659, 292);
			this->Controls->Add(this->checkBox1);
			this->Name = L"frmMain";
			this->Text = L"frmMain";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &frmMain::frmMain_FormClosed);
			this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:


		Void frmMain_Load(System::Object^ sender, System::EventArgs^ e) {

			logic = gcnew Logic();

		}

		Void frmMain_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {

			delete logic;

		}


	};// frmMain
}
