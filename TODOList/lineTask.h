#pragma once


#pragma region void

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace TODOList {
	public ref struct lineTask : public System::Windows::Forms::Control {


	

#pragma region ctors/destr
	public:	
		lineTask(void) {
			
			InitializeComponent();
			this->cbx	= (gcnew System::Windows::Forms::CheckBox());
			this->txt	= (gcnew System::Windows::Forms::TextBox());
			this->btnX	= (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// cbx
			// 
			this->cbx->AutoSize = true;
			this->cbx->Location = System::Drawing::Point(10, 15);
			this->cbx->Name = L"cbx";
			this->cbx->Size = System::Drawing::Size(43, 17);
			this->cbx->TabIndex = 0;
			this->cbx->Text = L"cbx";
			this->cbx->UseVisualStyleBackColor = true;
			// 
			// txt
			// 
			this->txt->Location = System::Drawing::Point(49, 12);
			this->txt->Name = L"txt";
			this->txt->Size = System::Drawing::Size(100, 20);
			this->txt->TabIndex = 1;
			// 
			// btnX
			// 
			this->btnX->Location = System::Drawing::Point(168, 11);
			this->btnX->Name = L"btnX";
			this->btnX->Size = System::Drawing::Size(20, 23);
			this->btnX->TabIndex = 2;
			this->btnX->Text = L"X";
			this->btnX->UseVisualStyleBackColor = true;
			// 
			// lineTask
			// 
			this->Controls->Add(this->btnX);
			this->Controls->Add(this->txt);
			this->Controls->Add(this->cbx);
			this->Name = L"lineTask";
			this->Size = System::Drawing::Size(200, 48);
			this->ResumeLayout(false);
			this->PerformLayout();

		
		}

	protected:
		~lineTask() {

			if (components) delete components;
		
		}
#pragma endregion



	private: System::Windows::Forms::TextBox^ txt;
	private: System::Windows::Forms::Button^ btnX;
	private: System::Windows::Forms::CheckBox^ cbx;
	private:	System::ComponentModel::Container^  components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			
		}
#pragma endregion

#pragma endregion main {

	private:


#pragma region }
	}; }
#pragma endregion