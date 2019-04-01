/**
 * Virtual Table Watch.
 * Author: Ofir Pele.
 * Since: 2017.
 */

#ifndef __VIRTUALTABLEWATCH_H__
#define	__VIRTUALTABLEWATCH_H__	

class CBaseClass
{
public:
	CBaseClass();
	virtual void function_1();
private:
	int m_iBaseData;
};

class CDerivedClass : public CBaseClass
{
public:
	CDerivedClass();

	virtual void function_2();

private:
	int m_iDerivedData;
};

class CGrandsonClass : public CDerivedClass
{
public:
	CGrandsonClass();

	virtual void function_1();
	virtual void function_3();
};
#endif // !__VIRTUALTABLEWATCH_H__
