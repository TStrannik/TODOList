#pragma once
#include <Windows.h>
#include <vector>
#include <string>
#include <initializer_list>
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





struct Subtask {

	Subtask(const std::string& text)
		: _text(text)
	{

		w("\t+Subtask( "); w(_text); wl(" )");

	}
	~Subtask() {
		
		w("\t~Subtask( "); w(_text); wl(" )");		
	
	}

	std::string			   get_text() {

		return _text;

	}
	void				   set_text(const std::string& text) {

		_text = text;

	}
	void				   remove() {
		
		this->~Subtask();		// nel'za

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
	Task(const std::string& text, std::initializer_list <Subtask*> list)
		: _text(text)
		, _subtasks(list)
	{
	
		w("\t+Task( "); w(_text); wl(", {...} )");

	}
	~Task() {

		w("\t~Task( "); w(_text); wl(" )");
		_delete_subtasks();

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
	
	void				   remove() {
		// Удалить весь Task
		
		for (int i = 0; i < _subtasks.size(); ++i) {
			_subtasks.at(i)->remove();
			_subtasks.erase(begin(_subtasks) + i);
		}

		this->~Task();

	}																		   
	void				   remove(const int& ind) {
		// Удалить Subtask(ind)
		
		_subtasks.at(ind)->remove();
		_subtasks.erase(begin(_subtasks) + ind);

	}

private:
	std::string			   _text;
	std::vector <Subtask*> _subtasks;
	//int				   _id;

private:
	void				   _delete_subtasks() {

		for (const auto& st : _subtasks)
			delete st;

	}

};



struct Logic {		// singletone?

	Logic() {

		wl("\tLogic ctor()");

	}
	~Logic() {

		wl("\t~Logic");

	}

private:


};
