// Math.cpp

#include "Math.h"
#include <iostream>
#include <cstdlib>
/*
#include <winternl.h>

char format[] = "%s %s\n";
char hello[] = "Hello";
char world[] = "world";

__declspec(naked) int nice() {
	__asm
	{
		mov  eax, offset world
		push eax
		mov  eax, offset hello
		push eax
		mov  eax, offset format
		push eax
		call printf
		//clean up the stack so that main can exit cleanly
		//use the unused register ebx to do the cleanup
		pop  ebx
		pop  ebx
		pop  ebx
		ret
	}
}
*/

using namespace std;

int main()
{
	cout  << "Pi values: " << endl;
	cout << "Pi    : " << e::GetPi() << endl;
	cout << "Pi / 2: " << e::GetPi() / 2 << endl;
	cout << "Pi / 3: " << e::GetPi() / 3 << endl;
	//test pow
	cout << endl << "power function: " << endl;
	cout << "pow(3,3): " << e::pow(3, 3) << endl;//27
	cout << "pow<char>(11,2): " << e::pow<char>(11, 2) << endl; // y

	//2.7182818284
	cout << endl << "euler number with types of precision - e: " << endl;
	cout << e::GetEulerNumber(2) << endl;
	cout << e::GetEulerNumber(3) << endl;
	cout << e::GetEulerNumber(4) << endl;
	cout << e::GetEulerNumber(5) << endl;
	cout << e::GetEulerNumber(6) << endl;
	cout << e::GetEulerNumber(7) << endl;
	cout << e::GetEulerNumber(8) << endl;
	cout << e::GetEulerNumber(9) << endl;
	cout << "const: " << EULER << endl;

	cout << endl << "Exponencial function: " << endl;
	cout << "exp(2) : " << e::exp(2) << endl;
	cout << "exp(0) : " << e::exp(0) << endl;

	cout << endl << "absolute value: " << endl;
	cout << "abs(-5,05) : " << e::abs(-5.05f) << endl;

	cout << endl << "sigma function: " << endl;
	cout << "sign(-2) : " << e::sign(-2) << endl;
	cout << "sign(2)  : " << e::sign(2) << endl;

	cout << endl << "Gonimetric functions: " << endl;
	cout << "sin(Pi/3): " << e::sin(e::GetPi() / 3) << endl;
	cout << "sin(90)  : " << e::sin(e::DegreesToX(90, 0, 0)) << endl;
	cout << "cos(0)   : " << e::cos(0.00f) << endl;
	cout << "cos(90)  : " << e::cos(e::GetPi()) << endl;
	/*cout << "tg(0)   : " << e::tg(0.00f) << endl;
	cout << "tg(89)  : " << e::tg(e::DegreesToX(89, 0, 0)) << endl;
	cout << "cotg(0)   : " << e::cotg(0.00f) << endl;
	cout << "cotg(89)  : " << e::cotg(e::DegreesToX(89, 0, 0)) << endl;
	cout << "sec(0)   : " << e::sec(0.00f) << endl;
	cout << "sec(90)  : " << e::sec(e::DegreesToX(90, 0, 0)) << endl;
	cout << "cosec(0)   : " << e::cosec(0.00f) << endl;
	cout << "cosec(90)  : " << e::cosec(e::DegreesToX(90, 0, 0)) << endl;*/

	cout << endl << "Hyperbolic functions: " << endl;
	cout << "sinh(0)  : " << e::sinh(0.00f) << endl;
	cout << "sinh(60) : " << e::sinh(e::DegreesToX(60, 0, 0)) << endl;
	cout << "cosh(0)  : " << e::cosh(0) << endl;
	cout << "cosh(pi/2)  : " << e::cosh(e::GetPi() / 2) << endl;

	cout << endl << "Cyclometric functions: " << endl;
	cout << "arcsin(0.866025): " << e::arcsin(0.866025, 20) << endl;
	cout << "arcsin(sin(60)) : " << e::arcsin(e::sin(e::GetPi() / 3), 20) << endl;
	cout << "arccos(0.5))    : " << e::arccos(0.5, 20) << endl;
	cout << "arccos(cos(60)) : " << e::arccos(e::cos(e::GetPi() / 3), 20) << endl;

	cout << endl << "Degrees to Radians: " << endl;
	cout << "pi / 3               : " << e::GetPi() / 3 << endl;
	cout << "60 degrees to radians: " << e::DegreesToRadians(60, 0, 0) << endl << endl;

	cout << "Logarithm + sqrt function: " << endl;
	cout << "ln(1): " << e::ln(1, 9) << endl;
	cout << "ln(2): " << e::ln(2, 10) << endl;
	cout << "ln(e): " << e::ln(e::GetEulerNumber(9)) << endl;

	cout << "log10(2): " << e::log10(2, 20) << endl;

	cout << "sqrt(16): " << e::sqrt7(16) << endl << endl;


	uint32_t i = 4000000000, y = 2000000;
	e::swap<uint32_t>(i, y);
	cout << i << endl << y << endl << endl;
	e::swap<uint32_t>(i, y);
	cout << i << endl << y << endl << endl;
	/*e::_3D::Valcove v = {6,135,100};//better initialize
	v.z = 6;
	v.psi = 135;
	v.r = 100;
	e::_3D::Valcove _v = e::_3D::NaValcove(e::_3D::NaKartezske(v));
	cout << v.psi << "-" << _v.psi << endl;
	cout << v.r << "-" << _v.r << endl;
	cout << v.z << "-" << _v.z << endl;*/
	return 0;
}
