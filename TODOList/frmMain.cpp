#include "frmMain.h"

#include <Windows.h>
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]


void CODE() {

	wl("\tВедётся ярая разработка TODOList");

}

void APPLICATION_START() {
	setlocale(LC_ALL, "RU_ru");
	system("color 70");
	std::cout << "\n APPLICATION START\n\n";
	//std::cout << "\tStatistic:\n\n";

	// Let's code
	//wl("\tВедётся ярая разработка TODOList");
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

/// ver 0.1.1
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
// -------------------
// ( ) Логика компонента
// -------------------
// ( ) Перемещение компонента
// ( ) Идентификаторы Subtask
// ( ) Task
//
//
/// BUGS:
//
// ( ) Component: the essence of the problem
// ( ) 