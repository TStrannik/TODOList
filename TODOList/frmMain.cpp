#include "frmMain.h"

#include <Windows.h>
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]


void CODE() {

	wl("\t������ ���� ���������� TODOList");

}

void APPLICATION_START() {
	setlocale(LC_ALL, "RU_ru");
	system("color 70");
	std::cout << "\n APPLICATION START\n\n";
	//std::cout << "\tStatistic:\n\n";

	// Let's code
	//wl("\t������ ���� ���������� TODOList");
	CODE();

	std::cout << "\n\n";
}
void APPLICATION_FORM() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	TODOList::frmMain form;
	Application::Run(% form);
}
void APPLICATION_END() {
	std::cout << "\n APPLICATION END\n\n";
	system("pause");
}

/// ver 0.1.2
int main(array <String^>^ args) {
	_CrtSetDbgFlag(
		_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) |
		_CRTDBG_LEAK_CHECK_DF);


	APPLICATION_START();
	APPLICATION_FORM();
	APPLICATION_END();
	return 0;
}



/// TODO:
// 
// (+) MVP
// (+) GIT Connection
// (+) GIT Make "Develop" branch
// 
// (+) pnlTask
// (+) lineTask
// (+) lineSutbask
// (+) �� ���
// (+) ������ ����������
// (+) UI/UX
// (+) ����������� state � T
// (+) ����������� state � ST
// (+) ��������� ��������
// -------------------
// (+) ����������� ������� � Subtask
// -------------------
// ( ) ���������� �����������
// ( ) ������ ������ ^ v X
// (+) ��������� �������� ST
// ( ) 
// ( ) ��� ������� ������ � ���-� ������ �������
// ( ) 
// ( ) 
// ( ) 
// ( ) 
// ( ) struct Subtask : public Task { _subtasks = delete; } ��� �������� struct Task : public Subtask
// ( ) 
// ( ) 
// 
// ver 0.2.0
// ( ) Drag&Drop
// ( ) ����������� ����������
// ( ) ���������� ��������� T/ST � .json
// ( ) �������� ��������� T/ST
// 
//
/// BUGS:
//
// ( ) Component: the essence of the problem
// ( ) 