#pragma once
#include <Windows.h>
#include <vector>
#include <string>
using namespace System;

/// DELETE
inline void cw(std::string msg) {

	String^ str = gcnew String(msg.c_str());

	Console::Write((String^)str);

	delete str;

}
inline void cwl(std::string msg) {

	String^ str = gcnew String(msg.c_str());

	Console::WriteLine((String^)str);

	delete str;

};



struct Subtask;
struct Task;


struct Logic {		// singletone?

	Logic() {
		
		wl("\tLogic ctor()");
	
	}
	~Logic() {
		
		wl("\t~Logic");
	
	}

private:


};


struct Subtask {

	Subtask(const std::string& text)
		: _text(text)
	{}
	~Subtask() {}

	std::string			   get_text() {

		return _text;

	}
	void				   set_text(const std::string& text) {

		_text = text;

	}

private:
	std::string			   _text;
	//int				   _id;

};



struct Task {

	Task(const std::string& text)
		: _text(text)
	{

		w("\t+Task( "); w(_text); wl(" )");

	}
	~Task() {

		w("\t~Task( "); w(_text); wl(" )");

	}

	std::string			   get_text() {

		return _text;

	}
	void				   set_text(const std::string& text) {

		_text = text;

	}
	Subtask*			   get_subtask(const int& ind) {

		return _subtasks.at(ind);

	}
	void				   new_subtask(const std::string& text) {

		_subtasks.push_back(new Subtask(text));

	}
	std::vector <Subtask*> get_subtasks_vector() {

		return _subtasks;

	}

private:
	std::string			   _text;
	std::vector <Subtask*> _subtasks;
	//int				   _id;

};



