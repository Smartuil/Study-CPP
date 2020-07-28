//#include<iostream>
//using namespace std;
//
////构造函数中调用虚函数能发生多态吗？
//class Parent {
//public:
//	Parent(int a = 0) {
//		this->a = a;
//		print();
//	}
//
//	virtual void print() {
//		cout << "Dad" << endl;
//	}
//protected:
//private:
//	int a;
//};
//
//class Child : public Parent {
//public:
//	Child(int a = 0, int b = 0) : Parent(a) {
//		this->b = b;
//		print();
//	}
//
//	virtual void print() {
//		cout << "Child" << endl;
//	}
//protected:
//private:
//	int b;
//};
//
//void howToPlay(Parent *base) {
//	base->print();
//}
//void main() {
//	Parent p1;
//	Child c1;//定义一个子类对象 在这个过程中，在父类构造函数中调用虚函数print
//	
//
//}

#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

// 不要在构造函数中去调用成员函数。

class Parent
{
public:
	Parent(int a)
	{
		cout << "Parent(int a)...." << endl;
		this->a = a;
		print(); //这个print打印的是 Parent 还是 Child的？
	}

	//虚函数
	virtual void print()
	{
		cout << "Parent::print():  " << a << endl;
	}
private:
	int a;
};

class Child : public Parent
{
public:
	Child(int a, int b) :Parent(a)
	{
		//vptr指针就执行的子类的虚函数表
		print(); //执行的child ？ 还是 parent?

		//再此处之前， 是构造父类的内存空间  此时child还有没构造完毕，vptr指针此时指向的是父类的虚函数表
		cout << "Child() ..." << endl;
		this->b = b;

	}

	//重写了父类的虚函数
	virtual void print()
	{
		cout << "Child::print()  " << " , " << b << endl;
	}

private:
	int b;
};

int main(void)
{

	Parent *p = new Child(10, 20);//在此调用Child 的构造函数
	p->print(); //此时发生了多态

	delete p;

	return 0;
}