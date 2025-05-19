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
	private: System::Windows::Forms::Button^	btnU;
	private: System::Windows::Forms::Button^	btnD;
	private: System::Windows::Forms::CheckBox^	cbx;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {

			cbx		= (gcnew Windows::Forms::CheckBox());
			txt		= (gcnew Windows::Forms::TextBox());
			btnX	= (gcnew Windows::Forms::Button());
			btnU	= (gcnew Windows::Forms::Button());
			btnD	= (gcnew Windows::Forms::Button());
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
			txt->Location				 = Drawing::Point(80, 12);
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
			btnX->BackColor				  = Drawing::Color::Transparent;
			btnX->TabIndex				  = 2;
			btnX->UseVisualStyleBackColor = true;





			// 
			// [^]
			// 
			btnU->Text					  = L"^";
			btnU->Name					  = L"btnX";
			btnU->Location				  = Drawing::Point(188, 11);
			btnU->Size					  = Drawing::Size(23, 23);
			btnU->TextAlign				  = Drawing::ContentAlignment::MiddleCenter;
			btnU->BackColor				  = Drawing::Color::Transparent;
			btnU->TabIndex				  = 2;
			btnU->UseVisualStyleBackColor = true;
			
			btnU->Click					 += gcnew EventHandler(this, &lineTask::btnU_Click);





			// 
			// [v]
			// 
			btnD->Text					  = L"v";
			btnD->Name					  = L"btnX";
			btnD->Location				  = Drawing::Point(208, 11);
			btnD->Size					  = Drawing::Size(23, 23);
			btnD->TextAlign				  = Drawing::ContentAlignment::MiddleCenter;
			btnD->BackColor				  = Drawing::Color::Transparent;
			btnD->TabIndex				  = 2;
			btnD->UseVisualStyleBackColor = true;

			btnD->Click					 += gcnew EventHandler(this, &lineTask::btnD_Click);





			Controls->Add(btnX); Controls->Add(btnU); Controls->Add(btnD);
			Controls->Add(cbx);  Controls->Add(txt);

			ResumeLayout(false);
			PerformLayout();

		}
#pragma endregion

#pragma endregion main {


	private:


		/* D&D 
		bool _drag_start = false;
		int  _posX	= 0;
		int  _posY	= 0;
		int  _offsetX = 0;
		int  _offsetY = 0;

		_drag_start = true;
		_posX = e->X;
		_posY = e->Y;

		Parent->Size = Drawing::Size(200, 100); //(Parent->Parent->Width, Parent->Height);
		Parent->Dock = Windows::Forms::DockStyle::None;

		//if (_drag_start) {
			//	//Parent->Left = _posX + MousePosition.X;
			//	//Parent->Top  = _posY - MousePosition.Y;
			//}

		_drag_start = false;
		Parent->TabIndex = 3;
		Parent->Dock = Windows::Forms::DockStyle::Top;

		*/


		Void this_MouseDown(Object^ sender, Windows::Forms::MouseEventArgs^ e) {

			Console::WriteLine(Parent->Parent->TabIndex);

		}
		Void this_MouseMove(Object^ sender, Windows::Forms::MouseEventArgs^ e) {



		}
		Void this_MouseUp(Object^ sender, Windows::Forms::MouseEventArgs^ e) {

			

		}









		Void btnU_Click(Object^ sender, EventArgs^ e) {

			

			//Console::WriteLine(Parent->Parent->Parent->Name);
			
				
				

		}
		Void btnD_Click(Object^ sender, EventArgs^ e) {


			Console::WriteLine(Parent->Name);
			

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