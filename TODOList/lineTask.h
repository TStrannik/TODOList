#pragma once
#include <array>
//#using <system.drawing.dll>



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
	//private: CBX^ cbx;
	private: System::Windows::Forms::Label^ lbl;
	private: System::ComponentModel::Container^ components;


		   void InitializeComponent(void) {

			   cbx = (gcnew Windows::Forms::CheckBox());
			   //cbx = (gcnew CBX());
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
			   MouseDoubleClick += gcnew Windows::Forms::MouseEventHandler(this, &lineTask::this_DoubleClick);
			   MouseClick       += gcnew Windows::Forms::MouseEventHandler(this, &lineTask::this_MouseClick);
			   
			   



			   // 
			   // []
			   //
			   cbx->Name = L"cbx";
			   cbx->AutoSize = true;
			   cbx->Location = Drawing::Point(10, 16);
			   cbx->Size = Drawing::Size(43, 17);
			   cbx->TabIndex = 0;
			   cbx->UseVisualStyleBackColor = true;
			   cbx->Paint					 += gcnew Windows::Forms::PaintEventHandler(this, &lineTask::cbx_Paint);
			   cbx->CheckedChanged			 += gcnew System::EventHandler(this, &lineTask::cbx_CheckedChanged);





			   // 
			   // ..label..
			   //
			   lbl->Name = L"lbl";
			   lbl->Size = System::Drawing::Size(35, 13);
			   lbl->Location = System::Drawing::Point(30, 12);

			   lbl->Font = gcnew System::Drawing::Font("Bahnschrift Light", 12);
			   lbl->Font = gcnew System::Drawing::Font("Bahnschrift", 12, FontStyle::Bold);
			   
			   lbl->ForeColor = Color::White;
			   lbl->AutoSize = true;
			   lbl->TabIndex = 0;
			   lbl->Click += gcnew EventHandler(this, &lineTask::lbl_Click);





			   // 
			   // [_________]
			   // 
			   txt->Name = L"txt";
			   txt->Visible = false;
			   txt->Location = Drawing::Point(30, 10);
			   txt->Size = Drawing::Size(50, 20);
			   txt->Font = lbl->Font;
			   txt->ForeColor = Color::White;
			   txt->BackColor = Color::FromArgb(248, 8, 128);
			   txt->TabIndex = 1;
			   txt->KeyPress += gcnew Windows::Forms::KeyPressEventHandler(this, &lineTask::txt_KeyPress);
			   txt->TextChanged += gcnew System::EventHandler(this, &lineTask::txt_TextChanged);
			   txt->AutoSize = false;






			   // 
			   // [X]
			   // 
			   btnX->Text = L"";
			   btnX->Name = L"btnX";
			   btnX->Location = Drawing::Point(328, 11);
			   btnX->Size = Drawing::Size(20, 20);			   
			   btnX->TextAlign = Drawing::ContentAlignment::MiddleCenter;
			   btnX->TabIndex = 2;
			   btnX->UseVisualStyleBackColor = true;
			   btnX->Click += gcnew EventHandler(this, &lineTask::btnX_Click);





			   // 
			   // [^]
			   // 
			   btnU->Text = ""; // L"^";;
			   btnU->Name = L"btnX";
			   btnU->Location = Drawing::Point(238, 11);
			   btnU->Size = Drawing::Size(20, 20);
			   btnU->TextAlign = Drawing::ContentAlignment::MiddleCenter;
			   btnU->TabIndex = 2;
			   btnU->UseVisualStyleBackColor = true;
			   btnU->Click += gcnew EventHandler(this, &lineTask::btnU_Click);





			   // 
			   // [v]
			   // 
			   btnD->Text							= ""; // L"v";;
			   btnD->Name							= L"btnX";
			   btnD->Location						= Drawing::Point(258, 11);
			   btnD->Size							= Drawing::Size(20, 20);
			   btnD->TextAlign						= Drawing::ContentAlignment::MiddleCenter;
			   btnD->TabIndex						= 2;
			   btnD->UseVisualStyleBackColor		= true;
			   btnD->Click += gcnew EventHandler(this, &lineTask::btnD_Click);





			   Controls->Add(btnX); Controls->Add(btnU); Controls->Add(btnD);
			   Controls->Add(cbx);  Controls->Add(txt);  Controls->Add(lbl);

			   ResumeLayout(false);
			   PerformLayout();

		   }


#pragma endregion main {

	private:


		Void this_DoubleClick(Object^ sender, Windows::Forms::MouseEventArgs^ e) {

			if (e->Button == Windows::Forms::MouseButtons::Left)
				cbx_switch();

		}
		Void this_MouseClick(Object^ sender, Windows::Forms::MouseEventArgs^ e) {

			if (e->Button == Windows::Forms::MouseButtons::Right)
				call_method_parent("subtasks_hide_show", {});
		
		}
		Void this_MouseDown(Object^ sender, Windows::Forms::MouseEventArgs^ e) {

			txt_append_close();

			call_method_parent("print_header", {});

			//Console::WriteLine(Parent->Name);
			//Console::WriteLine(Parent->Text);
			//Console::WriteLine(nomber);
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


		Void cbx_Paint(Object^ sender, Windows::Forms::PaintEventArgs^ e) {

			Graphics^ g = e->Graphics;
			g->Clear(BackColor);
			
			

#pragma region Square
			Pen^ penSquare = gcnew Pen(Color::White);
			penSquare->Width = 1;

			g->DrawLine(penSquare, 2, 0, 12, 0);

			g->DrawLine(penSquare, 12, 1, 13, 1);
			g->DrawLine(penSquare, 13, 2, 14, 2);

			g->DrawLine(penSquare, 14, 2, 14, 11);

			g->DrawLine(penSquare, 14, 11, 13, 11);
			g->DrawLine(penSquare, 13, 12, 12, 12);

			g->DrawLine(penSquare, 0, 2, 0, 11);

			g->DrawLine(penSquare, 2, 12, 1, 12);
			g->DrawLine(penSquare, 1, 11, 0, 11);

			g->DrawLine(penSquare, 2, 13, 12, 13);

			g->DrawLine(penSquare, 0, 2, 1, 2);
			g->DrawLine(penSquare, 1, 1, 2, 1);
#pragma endregion			



#pragma region Ñheckmark
			if (cbx->Checked) {
				Pen^ penÑheckmark = gcnew Pen(Color::White);
				penÑheckmark->Width = 2;

				g->DrawLine(penÑheckmark, 2, 6, 5, 10);
				g->DrawLine(penÑheckmark, 5, 10, 11, 3);
			}
#pragma endregion

		}
		Void cbx_CheckedChanged(Object^ sender, EventArgs^ e) {

			call_method_main("task_set_state", { nomber, cbx->Checked });

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

			header = txt->Text;
			lbl->Text = header;
			txt->Visible = false;
			lbl->Visible = true;

			//Parent->header = txt->Text;								/// TODO:
			call_method_parent("set_header", { header });				// Íå ïð¸ò 
			call_method_main("task_set_name", { nomber, header });
			call_method_main("update_lists", {});						// Äëÿ list'îâ


		}
		inline void txt_resize() {

			if (txt->Text->Length > 5)
				txt->Width = TextRenderer::MeasureText(txt->Text, txt->Font).Width + 10;
			else 
				txt->Width = 56;

		}

		inline void cbx_switch() {

			cbx->CheckState = !cbx->Checked ?
				CheckState::Checked :
				CheckState::Unchecked;

			call_method_main("task_set_state", { nomber, cbx->Checked });
			call_method_main("update_lists", {});

		}
		inline void cbx_switch(bool state) {

			cbx->CheckState = state ?
				CheckState::Checked :
				CheckState::Unchecked;

			call_method_main("task_set_state", { nomber, state });
			
		}

	public:
		String^ header = gcnew String("");
		int		nomber;
		bool	state;

		Windows::Forms::Form^ parForm;
		//public: frmMain^ owner;

	public:
		void		update_state() {

			lbl->Text = header;
			txt->Text = header;

			btnU->FlatStyle = FlatStyle::Flat;
			btnD->FlatStyle = FlatStyle::Flat;
			btnX->FlatStyle = FlatStyle::Flat;

			btnU->FlatAppearance->BorderSize = 0;
			btnD->FlatAppearance->BorderSize = 0;
			btnX->FlatAppearance->BorderSize = 0;


			btnU->BackColor = Color::FromArgb(202, 10, 202);
			btnD->BackColor = Color::FromArgb(202, 10, 202);
			btnX->BackColor = Color::FromArgb(202, 10, 202);

			
			//btnX->Location = Drawing::Point(Parent->Width - btnX->Width - 10, 11);
			btnX->Location = Drawing::Point(330, 11);
			btnD->Location = Drawing::Point(btnX->Left - btnD->Width, 11);
			btnU->Location = Drawing::Point(btnD->Left - btnU->Width, 11);

			cbx->Checked = state;
			//cbx->Invalidate(); cbx->Update(); cbx->Refresh();


		}


#pragma region }
	};
}
#pragma endregion
