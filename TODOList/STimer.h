// Eto visokotexnologichniy profiler za 500 deneg

#pragma once
#include <iostream>
#include <string>
#include <chrono>

//using namespace std;
//using namespace std::chrono;


#define UNIQ_ID_IMPL(Lineno) _SimpleTimer_from_line_##Lineno
#define UNIQ_ID(Lineno) UNIQ_ID_IMPL(Lineno)

#define DURTMR(name) \
	STimer UNIQ_ID(__LINE__)(#name);



struct STimer {

	STimer() {

		_name = "";
		_start = std::chrono::high_resolution_clock::now();
		_exist = true;

	}
	explicit STimer(std::string name) {

		_name = name;
		_start = std::chrono::high_resolution_clock::now();
		_exist = true;

	}
	~STimer() {

		if (_exist) {
			_end = std::chrono::high_resolution_clock::now();
			std::chrono::duration <float> duration = _end - _start;

			if (_name == "") std::cout << "DURATION: " << duration.count() << " sec" << std::endl;
			else			 std::cout << "DURATION [" << _name << "]: " << duration.count() << " sec" << std::endl;
		}
		_exist = false;

	}

	void stop() { this->~STimer(); }

private:
	bool   _exist = false;
	std::string _name = "";
	std::chrono::time_point <std::chrono::steady_clock> _start, _end;

};