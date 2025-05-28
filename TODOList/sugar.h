#include "STimer.h"
#include <iostream>
#include <chrono>
#include <thread>


#define vv(x) std::cout << #x << " - " << x << std::endl;
#define kv(x) vv(x);
#define ba(b) \
	b == true ? std::cout << #b << " - true"  << std::endl : \
				std::cout << #b << " - false" << std::endl;

//#define v(x) to_string()

#define for0(N)		for (int i = 0; i <  N; ++i)
#define for0s(N, s) for (int i = 0; i <  N; i += s)
#define for1(N)		for (int i = 1; i <= N; ++i)
#define for1s(N, s) for (int i = 1; i <= N; i += s)

#define for0c(c, N)	for (int c = 0; c <  N; ++c)

#define rep(N) for0(N)


template <typename T>
inline void w (T s) { std::cout << s;			}
template <typename T>
inline void wl(T s) { std::cout << s << '\n'; }
inline void wt()    { std::cout << '\t';		}
inline void w()     { std::cout << ' ' ;		}
inline void wl()	{ std::cout << '\n';		}

template <typename ... Args>
void wl(const Args& ... args) {
	((std::cout << args), ..., (std::cout << endl));
}
template <typename ... Args>
void w(const Args& ... args) {
	((std::cout << args), ...);
}

inline void ttsleep(float t) { 
  std::this_thread::sleep_for(
	  std::chrono::milliseconds((int)(t * 1000))
  );
}

inline void cls()   { system("cls");   }
inline void pause() { system("pause"); }


template <typename T>
inline void test(T func, T val) {

	if (func == val) {
		w("���� �������. ������: "); wl(__LINE__);
	}
	else {
		w("������: ����� �����. ������: "); wl(__LINE__);
		w("����: "); wl(__FILE__);
		exit(-1);
	}	

}

#include <bitset>

template <typename T>
std::string _bytes_spaces(T& bset) {

	int size = sizeof(bset) * 8;

	std::string sample = (std::bitset <sizeof(bset) * 8>(bset)).to_string();
	std::string result = "";

	result = sample[0];
	for (int i = 1; i < size; ++i) {
		if (i % 4 == 0) result += " ";
		if (i % 8 == 0) result += " ";
		result += sample[i];
	}

	return result;

}
std::string _bytes(uint8_t&  bset) { return _bytes_spaces(bset); }
std::string _bytes(uint16_t& bset) { return _bytes_spaces(bset); }
std::string _bytes(uint32_t& bset) { return _bytes_spaces(bset); }
std::string _bytes(uint64_t& bset) { return _bytes_spaces(bset); }
void print_bytes(uint8_t& bset)  { wl(_bytes(bset)); }
void print_bytes(uint16_t& bset) { wl(_bytes(bset)); }
void print_bytes(uint32_t& bset) { wl(_bytes(bset)); }
void print_bytes(uint64_t& bset) { wl(_bytes(bset)); }