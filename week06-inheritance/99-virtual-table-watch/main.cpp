/**
 * Virtual Table Watch.
 * Author: Ofir Pele.
 * Since: 2017.
 */

#include "Header.h"

int main()
{
	CGrandsonClass cGrandObj;
	CBaseClass* p = &cGrandObj;
	p->function_1();
}