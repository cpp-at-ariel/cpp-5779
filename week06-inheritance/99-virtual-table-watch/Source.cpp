/**
 * Virtual Table Watch.
 * Author: Ofir Pele.
 * Since: 2017.
 */

#include "Header.h"
#include <iostream>

CBaseClass::CBaseClass()
{
	std::cout << "inside CBaseClass Ctor" << std::endl;
}

void CBaseClass::function_1()
{
	std::cout << "inside CBaseClass::function_1";
}

CDerivedClass::CDerivedClass()
{
	std::cout << "inside CDerivedClass Ctor" << std::endl;
}

void CDerivedClass::function_2()
{
	std::cout << "inside CDerivedClass::function_2";
}

CGrandsonClass::CGrandsonClass()
{
	std::cout << "inside CGrandsonClass Ctor" << std::endl;
}

void CGrandsonClass::function_1()
{
	std::cout << "inside CGrandsonClass::function_1";
}

void CGrandsonClass::function_3()
{
	std::cout << "inside CGrandsonClass::function_3";
}
