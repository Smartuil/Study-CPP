﻿//#include	<iostream>
//using namespace	std;
//
//class	ABCD
//{
//public:
//	ABCD(int	a, int	b, int	c)
//	{
//		_a = a;
//		_b = b;
//		_c = c;
//		printf("ABCD()	construct,	a:%d,b:%d,c:%d		\n", _a, _b, _c);
//	}
//	~ABCD()
//	{
//		printf("~ABCD()	construct,a:%d,b:%d,c:%d		\n", _a, _b, _c);
//	}
//
//	int	getA()
//	{
//		return	_a;
//	}
//
//private:
//	int	_a;
//	int	_b;
//	int	_c;
//};
//
//class	MyE
//{
//public:
//	MyE() :abcd1(1, 2, 3), abcd2(4, 5, 6), m(100)
//	{
//		cout << "MyE()" << endl;
//	}
//
//	MyE(const	MyE	&	obj) :abcd1(7, 8, 9), abcd2(10, 11, 12), m(100)
//	{
//		printf("MyE(const MyE()	&	obj)\n");
//	}
//
//	~MyE()
//	{
//		cout << "~MyE()" << endl;
//	}
//public:
//	ABCD	abcd1;	//c++编译器不知道如何构造abc1
//	ABCD	abcd2;
//	const int	m;
//};
//
//int	doThing(MyE	mye1) //mye1 = myE //mye1.拷贝构造函数(myE)
//{
//	printf("doThing()	mye1.abc1.a:%d \n", mye1.abcd1.getA());
//
//	return 0;
//}
//
//
//int	run()
//{
//	MyE	myE; //调用的无参构造函数
//
//
//	doThing(myE);
//
//
//	return 0;
//}
//
//int	run2()
//{
//	printf("run2	start..\n");
//
//	ABCD(400, 500, 600);	//临时对象的⽣命周期		  //会产生一个临时的匿名对象。
//	//再次析构匿名对象														//匿名的临时对象，编译器会立刻销毁。不等到正常函数调用完毕。，
//	ABCD	abcd = ABCD(100, 200, 300);
//
//	printf("run2	end\n");
//
//
//	//在此析构abcd
//	return 0;
//}
//
//
//int	main(void)
//{
//	run();
//	run2();
//
//	return 0;
//}

#include	<iostream>
using namespace	std;
//构造中调⽤构造是危险的⾏为


class	MyTest
{
public:
	MyTest(int	a, int	b, int	c) //有参 构造函数
	{
		_a = a;
		_b = b;
		_c = c;
	}

	MyTest(int	a, int	b) //有参数的构造函数，两个参数
	{
		_a = a;
		_b = b;
		//构造函数中，无法嵌套构造函数 来通过构造函数给自己的成员变量赋值，
		//此构造函数已经又创建了另一个对象。
		MyTest(a, b, 100);	//产⽣新的匿名对象
		//新的匿名对象 a->1 b->2 c ->100

	}
	~MyTest()
	{
		printf("MyTest~:%d,	%d,	%d\n", _a, _b, _c);
	}

	int	getC()
	{
		return	_c;
	}
	void	setC(int	val)
	{
		_c = val;
	}

private:
	int	_a;
	int	_b;
	int	_c;
};

int	main()
{
	MyTest	t1(1, 2); //t1.a -->1  t1.b -->2 t1.c--->? 


	printf("c:%d\n", t1.getC());	//请问c的值是？

	return 0;
}