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
	public:		lineTask(void)  { InitializeComponent(); }
	protected: ~lineTask()		{ if (components) delete components; }
#pragma endregion



	private: System::Windows::Forms::TextBox^	txt;
	private: System::Windows::Forms::Button^	btnX;
	private: System::Windows::Forms::CheckBox^	cbx;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {

			cbx		= (gcnew System::Windows::Forms::CheckBox());
			txt		= (gcnew System::Windows::Forms::TextBox());
			btnX	= (gcnew System::Windows::Forms::Button());
			SuspendLayout();




			// THIS (lineTask)
			// 
			// 
			Size						 = System::Drawing::Size(200, 48);
			MouseDown					+= gcnew System::Windows::Forms::MouseEventHandler(this, &lineTask::this_MouseDown);



			// 
			// [v]
			//
			cbx->Name					 = L"cbx";
			cbx->Text					 = this->header;
			cbx->AutoSize				 = true;
			cbx->Location				 = System::Drawing::Point(10, 15);
			cbx->Size					 = System::Drawing::Size(43, 17);
			cbx->TabIndex				 = 0;
			cbx->UseVisualStyleBackColor = true;
			//cbx->Paint					 += gcnew Windows::Forms::PaintEventHandler(this, &lineTask::cbx_Paint);



			// 
			// [_________]
			// 
			txt->Name					 = L"txt";
			txt->Location				 = System::Drawing::Point(60, 12);
			txt->Size					 = System::Drawing::Size(50, 20);
			txt->TabIndex				 = 1;




			// 
			// [X]
			// 
			btnX->Text					  = L"X";
			btnX->Name					  = L"btnX";
			btnX->Location				  = System::Drawing::Point(168, 11);
			btnX->Size					  = System::Drawing::Size(23, 23);
			btnX->TextAlign				  = System::Drawing::ContentAlignment::MiddleCenter;
			btnX->TabIndex				  = 2;
			btnX->UseVisualStyleBackColor = true;





			Controls->Add(btnX);
			Controls->Add(txt);
			Controls->Add(cbx);

			ResumeLayout(false);
			PerformLayout();

		}
#pragma endregion

#pragma endregion main {


	private:
		Void this_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

			lineTask^ lneTask = (lineTask^)sender;
			Console::WriteLine(this->Name);

		}



	public:
		String^ header = gcnew String("");

		void		update_state() {

			cbx->Text = header;

		}


#pragma region }
	}; }
#pragma endregion