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

			cbx		= (gcnew Windows::Forms::CheckBox());
			txt		= (gcnew Windows::Forms::TextBox());
			btnX	= (gcnew Windows::Forms::Button());
			SuspendLayout();




			// 
			// THIS (lineTask)
			// 
			Size						 = Drawing::Size(200, 48);
			MouseDown					+= gcnew Windows::Forms::MouseEventHandler(this, &lineTask::this_MouseDown);
			MouseMove					+= gcnew Windows::Forms::MouseEventHandler(this, &lineTask::this_MouseMove);
			MouseUp						+= gcnew Windows::Forms::MouseEventHandler(this, &lineTask::this_MouseUp);





			// 
			// [v]
			//
			cbx->Name					 = L"cbx";
			cbx->Text					 = this->header;
			cbx->AutoSize				 = true;
			cbx->Location				 = Drawing::Point(10, 15);
			cbx->Size					 = Drawing::Size(43, 17);
			cbx->TabIndex				 = 0;
			cbx->UseVisualStyleBackColor = true;
			//cbx->Paint					 += gcnew Windows::Forms::PaintEventHandler(this, &lineTask::cbx_Paint);



			// 
			// [_________]
			// 
			txt->Name					 = L"txt";
			txt->Location				 = Drawing::Point(60, 12);
			txt->Size					 = Drawing::Size(50, 20);
			txt->TabIndex				 = 1;




			// 
			// [X]
			// 
			btnX->Text					  = L"X";
			btnX->Name					  = L"btnX";
			btnX->Location				  = Drawing::Point(168, 11);
			btnX->Size					  = Drawing::Size(23, 23);
			btnX->TextAlign				  = Drawing::ContentAlignment::MiddleCenter;
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

		int posX	= 0;
		int posY	= 0;
		int offsetX = 0;
		int offsetY = 0;

		Void this_MouseDown(Object^ sender, Windows::Forms::MouseEventArgs^ e) {

			
			posX = e->X;
			posY = e->Y;

			Console::Write(posX);
			Console::Write(" : ");
			Console::WriteLine(posY);


			Parent->Size = Drawing::Size(Parent->Parent->Width, Parent->Height);
			Parent->Dock = Windows::Forms::DockStyle::None;


			/*
			//lineTask^ lneTask = (lineTask^)sender;

			Console::Write("\t");
			Console::Write(this->Parent->Name);
			Console::Write(" [");
			Console::Write(this->Name);
			Console::Write("]");
			Console::WriteLine();
			*/
		}
		Void this_MouseMove(Object^ sender, Windows::Forms::MouseEventArgs^ e) {

			

		}
		Void this_MouseUp(Object^ sender, Windows::Forms::MouseEventArgs^ e) {


			Parent->Dock = Windows::Forms::DockStyle::Top;

		}




	public:
		String^  header = gcnew String("");


	public:
		void		update_state() {

			cbx->Text = header;

		}


#pragma region }
	}; }
#pragma endregion