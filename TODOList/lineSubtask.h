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
			   VisibleChanged += gcnew System::EventHandler(this, &lineSubtask::this_VisibleChanged);





			   // 
			   // []
			   //
			   cbx->Name = L"cbx";
			   cbx->AutoSize = true;
			   cbx->Location = Drawing::Point(25, 10);
			   cbx->Size = Drawing::Size(43, 17);
			   cbx->Padding = Windows::Forms::Padding(0);
			   cbx->TabIndex = 0;
			   cbx->UseVisualStyleBackColor = true;
			   cbx->Paint					 += gcnew Windows::Forms::PaintEventHandler(this, &lineSubtask::cbx_Paint);
			   cbx->CheckedChanged			 += gcnew System::EventHandler(this, &lineSubtask::cbx_CheckedChanged);





			   // 
			   // ..label..
			   //
			   lbl->Name = L"lbl";
			   lbl->Size = System::Drawing::Size(35, 13);
			   lbl->Location = System::Drawing::Point(45, 7);
			   lbl->Font = gcnew System::Drawing::Font("Bahnschrift Light", 10);
			   lbl->ForeColor = Color::White;
			   lbl->AutoSize = true;
			   lbl->TabIndex = 0;
			   lbl->Click += gcnew EventHandler(this, &lineSubtask::lbl_Click);





			   // 
			   // [_________]
			   // 
			   txt->Name = L"txt";
			   txt->Visible = false;
			   txt->Location = Drawing::Point(45, 6);
			   txt->Size = Drawing::Size(50, 20);
			   txt->Font = lbl->Font;
			   txt->ForeColor = Color::White;
			   txt->BackColor = Color::FromArgb(202, 10, 202);
			   txt->TabIndex = 1;
			   txt->KeyPress += gcnew Windows::Forms::KeyPressEventHandler(this, &lineSubtask::txt_KeyPress);
			   txt->TextChanged += gcnew System::EventHandler(this, &lineSubtask::txt_TextChanged);
			   txt->AutoSize = false;






			   // 
			   // [X]
			   // 
			   btnX->Text = L"";
			   btnX->Name = L"btnX";

			   btnX->Location = Drawing::Point(328, 6);
			   btnX->Size = Drawing::Size(20, 20);
			   btnX->TextAlign = Drawing::ContentAlignment::MiddleCenter;
			   btnX->TabIndex = 2;
			   btnX->UseVisualStyleBackColor = true;
			   btnX->Click += gcnew EventHandler(this, &lineSubtask::btnX_Click);





			   // 
			   // [^]
			   // 
			   btnU->Text = ""; // L"^";
			   btnU->Name = L"btnX";
			   btnU->Location = Drawing::Point(238, 6);
			   btnU->Size = Drawing::Size(20, 20);
			   btnU->TextAlign = Drawing::ContentAlignment::MiddleCenter;
			   btnU->TabIndex = 2;
			   btnU->UseVisualStyleBackColor = true;
			   btnU->Click += gcnew EventHandler(this, &lineSubtask::btnU_Click);





			   // 
			   // [v]
			   // 
			   btnD->Text = ""; // L"v";
			   btnD->Name = L"btnX";
			   btnD->Location = Drawing::Point(258, 6);
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





#pragma endregion main {

	private:
		Void this_DoubleClick(Object^ sender, Windows::Forms::MouseEventArgs^ e) {

			if (e->Button == Windows::Forms::MouseButtons::Left)
				cbx_switch();

		}
		Void this_MouseDown(Object^ sender, Windows::Forms::MouseEventArgs^ e) {

			txt_append_close();
			//Console::WriteLine(nomber);											/// TEST
			//call_method_parent("__print_header", {});								/// TEST

		}
		Void this_MouseMove(Object^ sender, Windows::Forms::MouseEventArgs^ e) {



		}
		Void this_MouseUp(Object^ sender, Windows::Forms::MouseEventArgs^ e) {



		}
		/// DELETE ?
		Void this_VisibleChanged(Object^ sender, EventArgs^ e) {				

			/// DELETE ?
			// Console::Write(Name); Console::WriteLine(" => Visible Changed");

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

			call_method_main("subtask_remove", { par_nomber, nomber });
			call_method_main("update_all", {});

		}
		Void btnU_Click(Object^ sender, EventArgs^ e) {

			call_method_main("subtask_up", { par_nomber, nomber });
			call_method_main("update_all", {});

		}
		Void btnD_Click(Object^ sender, EventArgs^ e) {

			call_method_main("subtask_dn", { par_nomber, nomber });
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

			call_method_main("subtask_set_state", { par_nomber, nomber, cbx->Checked });

		}



	private:
		void call_method_main(String^ method_name, std::initializer_list <Object^> list) {

			Type^ type = Parent->Parent->Parent->Parent->GetType();

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
				method->Invoke(Parent->Parent->Parent->Parent, args);
			else				
				Console::WriteLine("call_method_error ");
			//Console::WriteLine(Parent->Parent->Parent->Name);

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

			call_method_main("subtask_set_name", { par_nomber, nomber, header });
			call_method_main("update_lists", {});								// Äëÿ list'îâ

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

		inline void cbx_switch() {

			cbx->CheckState = !cbx->Checked ?
				CheckState::Checked :
				CheckState::Unchecked;

			call_method_main("subtask_set_state", { par_nomber, nomber, cbx->Checked });

		}
		inline void cbx_switch(bool state) {

			cbx->CheckState = state ?
				CheckState::Checked :
				CheckState::Unchecked;

							// subtask V
			call_method_main("subtask_set_state", { par_nomber, nomber, cbx->Checked });

		}



	public:
		String^ header = gcnew String("");
		int		nomber;
		int		par_nomber;
		bool	state;



	public:
		void		update_state() {

			//cbx->Text = header;
			lbl->Text = header;
			txt->Text = header;

			//txt->Visible = text_open;

			BackColor = Color::FromArgb(192, 0, 192);

#pragma region repaint
			btnU->FlatStyle = FlatStyle::Flat;
			btnD->FlatStyle = FlatStyle::Flat;
			btnX->FlatStyle = FlatStyle::Flat;

			btnU->FlatAppearance->BorderSize = 0;
			btnD->FlatAppearance->BorderSize = 0;
			btnX->FlatAppearance->BorderSize = 0;

			btnU->BackColor = BackColor;
			btnD->BackColor = BackColor;
			btnX->BackColor = BackColor;

			btnX->Location = Drawing::Point(310, 11);
			btnD->Location = Drawing::Point(btnX->Left - btnD->Width, 11);
			btnU->Location = Drawing::Point(btnD->Left - btnU->Width, 11);
#pragma endregion		^ v X

			cbx->Checked = state;

		}

#pragma region }
	};
}
#pragma endregion
