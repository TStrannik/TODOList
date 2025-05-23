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

	public ref struct lineSubtask : public System::Windows::Forms::Control {




#pragma region ctors/destr
	public:		lineSubtask(void) { InitializeComponent(); }
	protected: ~lineSubtask() { if (components) delete components; }
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
			   // THIS (lineSubtask)
			   // 
			   Size = Drawing::Size(200, 30);
			   MouseDown += gcnew Windows::Forms::MouseEventHandler(this, &lineSubtask::this_MouseDown);
			   MouseMove += gcnew Windows::Forms::MouseEventHandler(this, &lineSubtask::this_MouseMove);
			   MouseUp += gcnew Windows::Forms::MouseEventHandler(this, &lineSubtask::this_MouseUp);
			   MouseDoubleClick += gcnew Windows::Forms::MouseEventHandler(this, &lineSubtask::this_DoubleClick);




			   // 
			   // [v]
			   //
			   cbx->Name = L"cbx";
			   cbx->AutoSize = true;
			   cbx->Location = Drawing::Point(25, 15);
			   cbx->Size = Drawing::Size(43, 17);
			   cbx->TabIndex = 0;
			   cbx->UseVisualStyleBackColor = true;
			   //cbx->Paint					 += gcnew Windows::Forms::PaintEventHandler(this, &lineSubtask::cbx_Paint);






			   // 
			   // ..label..
			   //
			   lbl->Name = L"lbl";
			   lbl->Size = System::Drawing::Size(35, 13);
			   lbl->Location = System::Drawing::Point(45, 13);
			   lbl->Font = gcnew System::Drawing::Font("Arial", 12);
			   lbl->ForeColor = Color::White;
			   lbl->AutoSize = true;
			   lbl->TabIndex = 0;
			   lbl->Click += gcnew EventHandler(this, &lineSubtask::lbl_Click);





			   // 
			   // [_________]
			   // 
			   txt->Name = L"txt";
			   txt->Visible = false;
			   txt->Location = Drawing::Point(45, 10);
			   txt->Size = Drawing::Size(50, 20);
			   txt->Font = gcnew System::Drawing::Font("Arial", 12);
			   txt->ForeColor = Color::White;
			   txt->BackColor = Color::FromArgb(248, 8, 128);
			   txt->TabIndex = 1;
			   txt->KeyPress += gcnew Windows::Forms::KeyPressEventHandler(this, &lineSubtask::txt_KeyPress);
			   txt->TextChanged += gcnew System::EventHandler(this, &lineSubtask::txt_TextChanged);
			   txt->AutoSize = false;






			   // 
			   // [X]
			   // 
			   btnX->Text = L"X";
			   btnX->Name = L"btnX";
			   btnX->Location = Drawing::Point(328, 11);
			   btnX->Size = Drawing::Size(20, 20);
			   btnX->TextAlign = Drawing::ContentAlignment::MiddleCenter;
			   btnX->TabIndex = 2;
			   btnX->UseVisualStyleBackColor = true;
			   btnX->Click += gcnew EventHandler(this, &lineSubtask::btnX_Click);





			   // 
			   // [^]
			   // 
			   btnU->Text = L"^";
			   btnU->Name = L"btnX";
			   btnU->Location = Drawing::Point(238, 11);
			   btnU->Size = Drawing::Size(20, 20);
			   btnU->TextAlign = Drawing::ContentAlignment::MiddleCenter;
			   btnU->TabIndex = 2;
			   btnU->UseVisualStyleBackColor = true;
			   btnU->Click += gcnew EventHandler(this, &lineSubtask::btnU_Click);





			   // 
			   // [v]
			   // 
			   btnD->Text = L"v";
			   btnD->Name = L"btnX";
			   btnD->Location = Drawing::Point(258, 11);
			   btnD->Size = Drawing::Size(20, 20);
			   btnD->TextAlign = Drawing::ContentAlignment::MiddleCenter;
			   btnD->TabIndex = 2;
			   btnD->UseVisualStyleBackColor = true;
			   btnD->Click += gcnew EventHandler(this, &lineSubtask::btnD_Click);





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
		Void this_DoubleClick(Object^ sender, Windows::Forms::MouseEventArgs^ e) {

			call_method_parent("subtasks_hide_show", {});

		}
		Void this_MouseDown(Object^ sender, Windows::Forms::MouseEventArgs^ e) {

			//Console::WriteLine(Parent->Name);
			//Console::WriteLine(Parent->Parent->TabIndex);
			Console::WriteLine(nomber);

			//txt_append_close();

		}
		Void this_MouseMove(Object^ sender, Windows::Forms::MouseEventArgs^ e) {



		}
		Void this_MouseUp(Object^ sender, Windows::Forms::MouseEventArgs^ e) {



		}

		Void txt_TextChanged(System::Object^ sender, System::EventArgs^ e) {

			txt_resize();

		}
		Void txt_KeyPress(Object^ sender, Windows::Forms::KeyPressEventArgs^ e) {

			if (e->KeyChar == 13) txt_append_close();

		}

		Void lbl_Click(Object^ sender, EventArgs^ e) {

			txt_open();

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
				gcnew cli::array <Object^>(list.size());

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
		void call_method_parent(String^ method_name, std::initializer_list <Object^> list) {

			Type^ type = Parent->GetType();

			MethodInfo^ method = type->GetMethod(method_name,
				BindingFlags::NonPublic | BindingFlags::Instance);


			cli::array<Object^>^ args =
				gcnew cli::array <Object^>(list.size());

			if (list.size() != 0)
				for (int i = 0; i < list.size(); ++i)
					args[i] = *(list.begin() + i);
			else
				args = nullptr;


			if (method != nullptr)
				method->Invoke(Parent, args);
			else
				Console::WriteLine("call_method_error");

		}


		inline void txt_open() {

			txt->Text = header;
			txt_resize();
			txt->Visible = true;
			lbl->Visible = false;
			txt->Focus();

		}
		inline void txt_append_close() {

			//Parent->header = txt->Text;			
			call_method_parent("set_header", { header });				// Не прёт
			call_method_main("task_set_name", { nomber, header });


			header = txt->Text;
			lbl->Text = header;
			txt->Visible = false;
			lbl->Visible = true;

		}
		inline void txt_resize() {

			if (txt->Text->Length > 5)
				txt->Width = TextRenderer::MeasureText(txt->Text, txt->Font).Width + 10;
			else
				txt->Width = 56;


			//txt->AutoSize = false;
			//txt->Width = (txt->Text->Length * 8) + (20 * (int)(txt->Text->Length * 0.1));
				//txt->Width = txt->Text->Length * 12 * 0.75;

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
			txt->Text = header;

			//txt->Visible = text_open;


			BackColor = Color::FromArgb(212 - 8 * nomber, 8 * nomber + 42, 148);

			btnU->FlatStyle = FlatStyle::Flat;
			btnD->FlatStyle = FlatStyle::Flat;
			btnX->FlatStyle = FlatStyle::Flat;

			btnU->FlatAppearance->BorderSize = 0;
			btnD->FlatAppearance->BorderSize = 0;
			btnX->FlatAppearance->BorderSize = 0;

			btnU->BackColor = BackColor;
			btnD->BackColor = BackColor;
			btnX->BackColor = BackColor;


			btnX->Location = Drawing::Point(Width - btnX->Width - 20, 11);
			btnD->Location = Drawing::Point(btnX->Left - btnD->Width, 11);
			btnU->Location = Drawing::Point(btnD->Left - btnU->Width, 11);

		}


#pragma region }
	};
}
#pragma endregion
