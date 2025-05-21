#pragma once
#include <array>


#pragma region void



using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Reflection;



namespace TODOList {

	public ref struct lineTask : public System::Windows::Forms::Control {




#pragma region ctors/destr
	public:		lineTask(void) { InitializeComponent(); }
	protected: ~lineTask() { if (components) delete components; }
#pragma endregion



	private: System::Windows::Forms::TextBox^ txt;
	private: System::Windows::Forms::Button^ btnX;
	private: System::Windows::Forms::Button^ btnU;
	private: System::Windows::Forms::Button^ btnD;
	private: System::Windows::Forms::CheckBox^ cbx;
	private: System::Windows::Forms::Label^ lbl;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void) {

			   cbx = (gcnew Windows::Forms::CheckBox());
			   txt = (gcnew Windows::Forms::TextBox());
			   lbl = (gcnew Windows::Forms::Label());
			   btnX = (gcnew Windows::Forms::Button());
			   btnU = (gcnew Windows::Forms::Button());
			   btnD = (gcnew Windows::Forms::Button());
			   SuspendLayout();




			   // 
			   // THIS (lineTask)
			   // 
			   Size = Drawing::Size(200, 48);
			   MouseDown += gcnew Windows::Forms::MouseEventHandler(this, &lineTask::this_MouseDown);
			   MouseMove += gcnew Windows::Forms::MouseEventHandler(this, &lineTask::this_MouseMove);
			   MouseUp += gcnew Windows::Forms::MouseEventHandler(this, &lineTask::this_MouseUp);




			   // 
			   // [v]
			   //
			   cbx->Name = L"cbx";
			   cbx->AutoSize = true;
			   cbx->Location = Drawing::Point(10, 15);
			   cbx->Size = Drawing::Size(43, 17);
			   cbx->TabIndex = 0;
			   cbx->UseVisualStyleBackColor = true;
			   //cbx->Paint					 += gcnew Windows::Forms::PaintEventHandler(this, &lineTask::cbx_Paint);






			   // 
			   // ..label..
			   //
			   lbl->Name = L"lbl";
			   lbl->Size = System::Drawing::Size(35, 13);
			   lbl->Location = System::Drawing::Point(30, 13);
			   lbl->Font = gcnew System::Drawing::Font("Arial", 12);
			   lbl->ForeColor = Color::White;
			   lbl->AutoSize = true;
			   lbl->TabIndex = 0;
			   




			   // 
			   // [_________]
			   // 
			   txt->Name = L"txt";
			   txt->Location = Drawing::Point(100, 12);
			   txt->Size = Drawing::Size(50, 20);
			   txt->TabIndex = 1;




			   // 
			   // [X]
			   // 
			   btnX->Text = L"X";
			   btnX->Name = L"btnX";
			   btnX->Location = Drawing::Point(228, 11);
			   btnX->Size = Drawing::Size(20, 20);
			   btnX->TextAlign = Drawing::ContentAlignment::MiddleCenter;
			   btnX->BackColor = Color::Black;
			   btnX->TabIndex = 2;
			   btnX->UseVisualStyleBackColor = true;
			   btnX->Click += gcnew EventHandler(this, &lineTask::btnX_Click);





			   // 
			   // [^]
			   // 
			   btnU->Text = L"^";
			   btnU->Name = L"btnX";
			   btnU->Location = Drawing::Point(188, 11);
			   btnU->Size = Drawing::Size(20, 20);
			   btnU->TextAlign = Drawing::ContentAlignment::MiddleCenter;
			   btnU->BackColor = Color::FromArgb(255, 0, 128);	
			   btnU->TabIndex = 2;
			   btnU->UseVisualStyleBackColor = true;

			   btnU->Click += gcnew EventHandler(this, &lineTask::btnU_Click);





			   // 
			   // [v]
			   // 
			   btnD->Text							= L"v";
			   btnD->Name							= L"btnX";
			   btnD->Location						= Drawing::Point(208, 11);
			   btnD->Size							= Drawing::Size(20, 20);
			   btnD->TextAlign						= Drawing::ContentAlignment::MiddleCenter;
			   btnD->BackColor						= Color::FromArgb(255, 0, 128);
			   btnD->TabIndex						= 2;
			   btnD->UseVisualStyleBackColor		= true;

			   btnD->Click += gcnew EventHandler(this, &lineTask::btnD_Click);





			   Controls->Add(btnX); Controls->Add(btnU); Controls->Add(btnD);
			   Controls->Add(cbx);  Controls->Add(txt);  Controls->Add(lbl);

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

			//Console::WriteLine(Parent->Parent->TabIndex);
			Console::WriteLine(nomber);


		}
		Void this_MouseMove(Object^ sender, Windows::Forms::MouseEventArgs^ e) {



		}
		Void this_MouseUp(Object^ sender, Windows::Forms::MouseEventArgs^ e) {



		}


		Void btnX_Click(Object^ sender, EventArgs^ e) {


			call_method_main("task_remove_one", { nomber });
			call_method_main("update_all", {});


		}
		Void btnU_Click(Object^ sender, EventArgs^ e) {

			call_method_main("task_up", { nomber });
			call_method_main("update_all", {});

		}
		Void btnD_Click(Object^ sender, EventArgs^ e) {


			call_method_main("task_dn", { nomber });
			call_method_main("update_all", {});


		}


		
	
		void call_method_main(String^ method_name, std::initializer_list <Object^> list) {
			
			Type^ type = Parent->Parent->Parent->GetType();

			MethodInfo^ method = type->GetMethod(method_name,
				BindingFlags::NonPublic | BindingFlags::Instance);


			cli::array<Object^>^ args =
				gcnew cli::array <Object^> (list.size());

			if (list.size() != 0)
				for (int i = 0; i < list.size(); ++i) 
					args[i] = *(list.begin() + i);
			else 
				args = nullptr;
			
			
			if (method != nullptr)
				method->Invoke(Parent->Parent->Parent, args);
			else
				Console::WriteLine("call_method_error ");

		}




	public:
		String^ header = gcnew String("");
		int nomber;

		Windows::Forms::Form^ parForm;
		//public: frmMain^ owner;

	public:
		void		update_state() {

			//cbx->Text = header;
			lbl->Text = header;

		}


#pragma region }
	};
}
#pragma endregion