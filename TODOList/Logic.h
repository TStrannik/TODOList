#pragma once
#include <Windows.h>

using namespace System;



ref struct Logic {

	Logic() { Console::WriteLine(L"\tLogic ctor()"); }
	~Logic() { Console::WriteLine(L"\t~Logic"); }

private:

};