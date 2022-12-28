#pragma once
#include "Math.h"

#include <chrono>
#include <stdio.h>
#include <time.h>

using namespace std;

using namespace std::chrono;

#define FUNC_TIME_MILI(func, funcname)					\
	auto t1 = high_resolution_clock::now();			\
	func											\
	auto t2 = high_resolution_clock::now();			\
	duration<float, milli> ms_double = t2 - t1;		\
	cout << funcname << " duration: " << ms_double.count() << "ms\n";\

#define FUNC_TIME_SEC(func, funcname)					\
	auto t1 = high_resolution_clock::now();			\
	func											\
	auto t2 = high_resolution_clock::now();			\
	duration<float> ms_double = t2 - t1;		\
	cout << funcname << " duration: " << ms_double.count() << "s\n";\

#define FUNC_TIME_OWN(func, funcname, periode, periode_suffix)					\
	auto t1 = high_resolution_clock::now();			\
	func											\
	auto t2 = high_resolution_clock::now();			\
	duration<float, periode> ms_double = t2 - t1;		\
	cout << funcname << " duration: " << ms_double.count() << periode_suffix << "\n";


void compute_test1() {
	cout << "computing test: " << endl;
	auto t1 = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10; i++) {
		// pow can be defined for every number/char type - including own types(must have * operator)
		e::pow<uint16_t>(10, 2);               // 100
		e::pow<uint32_t>(10000, 2);            // 100000000
		e::pow<uint64_t>(100000, 2);           // 10000000000
		e::pow<uint_least64_t>(10000000, 2);   // 100000000000000
		e::pow<int>(-10, 2);                   // 100
		e::pow<float>(5.2, 2);                 // 27.04
		e::pow<double>(4.23, 2);               // 17.8929
		e::pow<char>(11, 2);                   // y
		e::pow<wchar_t>(L'\n', 2);             // d
	}
	auto t2 = high_resolution_clock::now();

	//miliseconds
	duration<float> s_double = t2 - t1;
	duration<float, milli> ms_double = t2 - t1;
	duration<float, micro> mc_double = t2 - t1;
	duration<float, nano> na_double = t2 - t1;
	duration<float, pico> pi_double = t2 - t1;

	cout << "9x funciton pow with some types of parametres cost: " << s_double.count() << " seconds/" << ms_double.count() << " miliseconds/" << mc_double.count() << " microseconds/" << na_double.count() << " nanoseconds" << pi_double.count() << " picoseconds" << endl;
}

void compute_test2() {
	cout << endl << "computing test 2: " << endl;
	auto _t1 = high_resolution_clock::now();

	for (int i = 0; i < 10; i++) {
		// pow can be defined for every number/char type - including own types(must have * operator)
		cout << e::pow<uint16_t>(10, 2) << endl;               // 100
		cout << e::pow<uint32_t>(10000, 2) << endl;            // 100000000
		cout << e::pow<uint64_t>(100000, 2) << endl;           // 10000000000
		cout << e::pow<uint_least64_t>(10000000, 2) << endl;   // 100000000000000
		cout << e::pow<int>(-10, 2) << endl;                   // 100
		cout << e::pow<float>(5.2, 2) << endl;                 // 27.04
		cout << e::pow<double>(4.23, 2) << endl;               // 17.8929
		cout << e::pow<char>(11, 2) << endl;                   // y
		cout << e::pow<wchar_t>(L'\n', 2) << endl;             // d
	}
	auto _t2 = high_resolution_clock::now();

	//miliseconds
	duration<float> _s_double = _t2 - _t1;
	duration<float, milli> _ms_double = _t2 - _t1;
	duration<float, micro> _mc_double = _t2 - _t1;
	duration<float, nano> _na_double = _t2 - _t1;
	duration<float, pico> _pi_double = _t2 - _t1;

	cout << "9x funciton pow with some types of parametres and with cout for printing cost: " << _s_double.count() << " seconds/" << _ms_double.count() << " miliseconds/" << _mc_double.count() << " microseconds/" << _na_double.count() << " nanoseconds" << _pi_double.count() << " picoseconds" << endl;

}