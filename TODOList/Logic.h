#pragma once
#include <Windows.h>
#include <vector>
#include <string>
#include <initializer_list>
using namespace System;

/// DELETE
//inline void cw(std::string msg) {
//
//	String^ str = gcnew String(msg.c_str());
//
//	Console::Write((String^)str);
//
//	delete str;
//
//}
//inline void cwl(std::string msg) {
//
//	String^ str = gcnew String(msg.c_str());
//
//	Console::WriteLine((String^)str);
//
//	delete str;
//
//};





struct Subtask {



#pragma region ctors/destr
	Subtask(const std::string& text)
		: _text(text)
		, _state(false)
	{

		w("\t+Subtask( "); w(_text); wl(" )");

	}
	~Subtask() {
		
		w("\t~Subtask( "); w(_text); wl(" )");		
	
	}
#pragma endregion



#pragma region methods
	std::string			   get_text() {

		return _text;

	}
	void				   set_text(const std::string& text) {

		_text = text;

	}
	bool				   get_state() const {

		return _state;

	}
	void				   set_state(const bool& state) {

		_state = state;

	}
	void				   switch_state() {

		_state = !_state;

	}

	//int					   get_id() {
	//
	//	return _id;
	//
	//}

	void				   remove() {
		
		this->~Subtask();		// nel'za

	}
#pragma endregion



#pragma region fields
private:
	static int			   _counter;
	std::string			   _text;
	bool				   _state;
	//int					   _id;
#pragma endregion



};
//int Subtask::_counter = -1;




struct Task {



#pragma region ctors/destr
	Task(const std::string& text)
		: _text(text)
		, _state(false)
	{

		w("\t+Task( "); w(_text); wl(" )");

	}
	Task(const std::string& text, std::initializer_list <Subtask*> list)
		: _text(text)
		, _state(false)
		, _subtasks(list)
	{
	
		w("\t+Task( "); w(_text); wl(", {...} )");

	}
	Task(const Task& othr)
		: _text(othr._text)
		, _state(false)
		//, _id(othr._id)
	{

		w("\t+Task( "); w(_text); wl(" (copy) )");

		//_counter--;
		//_subtasks = othr._subtasks;

	}
	~Task() {

		w("\t~Task( "); w(_text); wl(" )");
		_delete_subtasks();

	}
#pragma endregion



#pragma region methods
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
	bool				   get_state() const {

		return _state;

	}
	void				   set_state(const bool& state) {

		_state = state;

	}
	void				   switch_state() {

		_state = !_state;

	}

	//int					   get_id() {
	//
	//	return _id;
	//
	//}
	
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
	void				   _delete_subtasks() {

		for (const auto& st : _subtasks)
			delete st;

	}
#pragma endregion



#pragma region fields
private:
	static int			   _counter;
	std::string			   _text;
	std::vector <Subtask*> _subtasks;
	bool				   _state;
	//int					   _id = ++_counter;
#pragma endregion



};
//int Task::_counter = -1;











struct Logic {		// singletone?

	Logic() {

		wl("\tLogic ctor()");

	}
	~Logic() {

		wl("\t~Logic");

	}

private:


};