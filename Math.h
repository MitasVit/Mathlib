#pragma once
// Math.h

#pragma once



#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"          // warning: control reaches end of non-void function
#endif

#if defined(_MSC_VER)
#pragma warning (push)
#pragma warning (disable: 4244) // int - > float warning
#pragma warning (disable: 4305) // double -> float warning
#pragma warning (disable: 4715) // sign return value
#endif

namespace e {

	//experimental constants
#define PI 3.1415926535
#define EULER 2.7182818284

//factorial function - computes factorial of number ( n! )
	int factorial(int n) {
		if (n > 1) {
			return n * factorial(n - 1);
		}
		else {
			return 1;
		}
	}

	float GetPi() {
		//return (float)355.00f/113.00f;
		return (float)52163.00f / 16604.00f;
	}

	float pow(float x, int a) {
		float tmp = x;
		for (int i = 0; i < a - 1; i++) {
			tmp = tmp * x;
		}
		return tmp;
	}

	//predefine for powf
	float ln(float x, int precision);
	float exp(float x, int precision);

	//nefunguje
	float powf(float x, float a) {
		return exp(a * ln(x, 12), 10);
	}

	template<typename T>
	T pow(T x, int a) {
		T tmp = x;
		for (int i = 0; i < a - 1; i++) {
			tmp = tmp * x;
		}
		return tmp;
	}

	//Computes Eluler's number - default with 2 useable decimal numbers
	//     precision 5 -> 1 decimal number useable
	//     precision 6 -> 2 decimal numbers useable
	//     precision 7 -> 3 decimal numbers useable
	//     precision 8 -> 4 decimal numbers useable
	//max: precision 9 -> 5 decimal numbers useable
	float GetEulerNumber(int precision = 6) {
		float tmp = 0;
		for (int i = 0; i < precision; i++) {
			tmp = tmp + (1.00f / factorial(i));
		}
		return tmp;
	}

	//e on x
	float exp(float x, int precision = 9) {
		if (x == 0) {
			return 1;
		}
		return e::pow(e::GetEulerNumber(precision), x);
	}

	float DegreesToX(float degrees, float minutes, float seconds) {
		return (((e::GetPi() / 180) * degrees) + (((e::GetPi() / 180) / 60) * minutes) + ((((e::GetPi() / 180) / 60) / 60) * seconds));
	}

	float DegreesToRadians(float degrees, float minutes, float seconds) {
		return((e::GetPi() / 180) * (degrees + (minutes * 60) + (seconds * 360)));
	}

	int sign(float x) {
		if (x == 0) {
			return 0;
		}
		else if (x < 0) {
			return -1;
		}
		else {
			return 1;
		}
	}

	float abs(float x) {
		if (x < 0) {
			return x * -1;
		}
		else {
			return x;
		}
	}

	float sin(float x, int precision = 6) {
		float tmp = x;
		for (int i = 3; i < precision; i = i + 2) {
			if (((i - 1) % 4) == 0) {
				tmp = tmp + (e::pow(x, i) / e::factorial(i));
			}
			else {
				tmp = tmp - (e::pow(x, i) / e::factorial(i));
			}
		}
		return tmp;
	}

	//cos, tg, cotg, sec a cosec zatim nefunguji

	float cos(float x, int precision = 6) {
		//taylor's polynom
		float tmp = 1;
		for (int i = 2; i < precision; i = i + 2) {
			if (((i - 1) % 4) == 0) {
				tmp = tmp + (e::pow(x, i) / e::factorial(i));
			}
			else {
				tmp = tmp - (e::pow(x, i) / e::factorial(i));
			}
		}
		return tmp;   
	}

	float tg(float x, int precision = 6) {
		//trigonometry
		return (sin(x, precision) / cos(x, precision));
	}

	float cotg(float x, int precision = 6) {
		//trigonometry
		return (cos(x, precision) / sin(x, precision));
	}

	//secans
	float sec(float x, int precision = 6) {
		return (1 / cos(x, precision));
	}

	//cosecans
	float cosec(float x, int precision = 6) {
		return (1 / sin(x, precision));
	}

	float sinh(float x, int precision = 6) {
		float tmp = x;
		for (int i = 3; i < precision; i = i + 2) {
			tmp = tmp + (e::pow(x, i) / e::factorial(i));
		}
		return tmp;
	}

	float cosh(float x, int precision = 6) {
		float tmp = 1;
		for (int i = 2; i < precision; i = i + 2) {
			tmp = tmp + (e::pow(x, i) / e::factorial(i));
		}
		return tmp;
	}

	float arcsin(float x, int precision = 12) {
		float tmp = x;
		for (int i = 3; i < precision; i = i + 2) {
			float licha = 1.0f, suda = 1.0f;
			for (int y = i - 1; y > 0; y--) {
				if ((y % 2) == 0) {
					if (suda != 0) {
						suda = suda * y;
					}
					else {
						suda = y;
					}

				}
				else {
					if (licha != 0) {
						licha = licha * y;
					}
					else {
						licha = y;
					}
				}
			}
			tmp = tmp + ((float)(licha / suda) * ((e::pow(x, i) / i)));
		}
		return tmp;
	}

	float arccos(float x, int precision = 12) {
		float tmp = (e::GetPi() / 2) - x;
		for (int i = 3; i < precision; i = i + 2) {
			float licha = 1.0f, suda = 1.0f;
			for (int y = i - 1; y > 0; y--) {
				if ((y % 2) == 0) {
					if (suda != 0) {
						suda = suda * y;
					}
					else {
						suda = y;
					}

				}
				else {
					if (licha != 0) {
						licha = licha * y;
					}
					else {
						licha = y;
					}
				}
			}
			tmp = tmp - ((float)(licha / suda) * ((e::pow(x, i) / i)));
		}
		return tmp;
	}

	float ln(float x, int precision = 10) {
		float tmp = (x - 1) / x;
		for (int i = 2; i < precision; i++) {
			tmp = tmp + (e::pow(x - 1, i) / (i * pow(x, i)));
		}
		return tmp;
	}

	float log10(float x, int precision = 10) {
		return (e::ln(x, precision) / e::ln(10, precision));
	}

	int floor(float x) {
		return (int)x;
	}

	float sqrt7(float x)
	{
		//https://bits.stephan-brumme.com/squareRoot.html
		unsigned int i = *(unsigned int*)&x;
		// adjust bias
		i += 127 << 23;
		// approximation of square root
		i >>= 1;
		return *(float*)&i;
	}

	//nth square root of x
	float sqrtn(float x, float n) {
		//nefunguje
		return powf(x, 1.00f / n);
	}

	float Percentagef(float src, float from) {
		return (src * (from / 100));
	}

	int Percentage(int src, int from) {
		return (src * (from / 100));
	}

	template<typename T>
	void swap(T _1, T _2) {
		T tmp = _2;
		_2 = _1;
		_1 = tmp;
	}

	namespace _3D {
		struct Valcove;
		struct Kartezske {
			//R3
			float x;
			float y;
			float z;
		};

		struct Valcove {
			float psi;
			float r;
			float z;
		};
		Kartezske NaKartezske(Valcove src, int precision = 6) {
			Kartezske tmp;
			tmp.z = src.z;
			tmp.x = src.r * e::cos(e::DegreesToX(src.psi,0,0), precision);
			tmp.y = src.r * e::sin(e::DegreesToX(src.psi, 0, 0), precision);
			return tmp;
		}
		Valcove NaValcove(Kartezske src, int precision = 6) {
			Valcove tmp;
			tmp.z = src.z;
			tmp.r = sqrt7(e::pow(src.x, 2) + e::pow(src.y, 2));
			if (src.y >= 0) {
				tmp.psi = e::arccos(src.x / (sqrt7(e::pow(src.x, 2) + e::pow(src.y, 2))), precision);
			}
			else {
				tmp.psi = (e::GetPi() / 2) - e::arccos(src.x / (sqrt7(e::pow(src.x, 2) + e::pow(src.y, 2))), precision);
			}
			return tmp;
		}
	}
}

/*
* 
* #ifndef NO_DEPENDENCY

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <initializer_list>

	using namespace std;
	namespace statistics {
		template<typename T>
		T* initializer_list_to_array(initializer_list<T> data) {
			T* elements = new T[data.size()];
			copy(data.begin(), data.end(), begin(elements));
			return elements;
		}

		float aritmetic_average(initializer_list<int> data) {
			int* arr = initializer_list_to_array(data);
			int tmp = 0;
			for (int i = 0; i < data.size(); i++) {
				tmp = tmp + arr[i];
			}
			return tmp / data.size();
		}
		float harmonic_average(initializer_list<int> data) {
			int* arr = initializer_list_to_array(data);
			float tmp = 0;
			for (int i = 0; i < data.size(); i++) {
				tmp = tmp + (1 / arr[i]);
			}
			return data.size() / tmp;
		}
		float kvadratic_average(initializer_list<int> data) {
			int* arr = initializer_list_to_array(data);
			unsigned long tmp = 0;
			for (int i = 0; i < data.size(); i++) {
				tmp = tmp + e::pow(arr[i], 2);
			}
			return ((1 / e::sqrt7(data.size())) * e::sqrt7(tmp));
		}

		float GetIntervalCount(double rows) {
			//Stuges's formula
			return 1 + 3.3 * log10(rows);
		}
	}
#define MAX_STR 50
	class Statistics_file {
	public:
		int rows, collums;//radky, sloupce
		char** collums_names;
		int** values;
		Statistics_file(int _rows, int _collums, int** _values) {
			rows = _rows;
			collums = _collums;
			collums_names = new char* [collums];
			values = _values;
		}
		~Statistics_file() {
			rows = 0;
			collums = 0;
			collums_names = NULL;
			values = NULL;
		}
		float aritmetic_average(int collum) {
			int tmp = 0;
			for (int i = 0; i < rows; i++) {
				tmp = tmp + values[i][collum];
			}
			return tmp / rows;
		}
		float harmonic_average(int collum) {
			float tmp = 0;
			for (int i = 0; i < rows; i++) {
				tmp = tmp + (1 / values[i][collum]);
			}
			return rows / tmp;
		}
		float kvadratic_average(int collum) {
			unsigned long tmp = 0;
			for (int i = 0; i < rows; i++) {
				tmp = tmp + pow(values[i][collum], 2);
			}
			return ((1 / sqrt(rows)) * sqrt(tmp));
		}
		float GetIntervalCount() {
			//Stuges's formula
			return 1 + 3.3 * log(rows);
		}

	}; */