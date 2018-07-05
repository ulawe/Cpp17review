/*C++ Quick Syntax Reference*/

#include <string>
#include <tuple>
#include <iostream>
using namespace std;



// Implicit conversion methods
class MyNum
{
 public:
	int value;
	MyNum(int i) { value = i; }
};

void Main()
{
	
	MyNum a = 5;        // error
	MyNum b(5);         // allowed
	MyNum c = MyNum(5); // allowed
}



#ifdef DEBUG
 // …
#endif

#ifndef DEBUG
 // …
#endif

// Error directive
#error Compilation aborted

// Line directive
#line 5 "My MyApp Error"

// Pragma directive
#pragma message( "Hello Compiler" )
#pragma warning(disable : 4507)


// Attributes
[[deprecated]] void foo() {} // mark as deprecated

// Mark as deprecated with comment
[[deprecated("foo() is unsafe, use bar() instead")]] void foo() {}

[[noreturn]] void f()
{
	exit(0); // terminate program
}



*** Headers ***

// MyFunc.c
void myFunc()
{
	// …
}

// MyApp.c
int main()
{
	myFunc(); // error: myFunc identifier not found
}


// MyApp.c
void myFunc(); // prototype

int main()
{
	myFunc(); // ok
}


// MyFunc.h
void myFunc(); // prototype

// MyApp.c
#include "MyFunc.h"


// MyApp.h - Interface
#define DEBUG 0
const double E = 2.72;
typedef unsigned long ulong;
void myFunc();

class MyClass
{
 public:
	void myMethod();
};

// MyApp.c
void MyClass::myMethod() {}


// MyApp.h
extern int myGlobal;

// MyApp.cpp
int myGlobal = 0;


// MyApp.h
inline void myFunc() {}

class MyClass
{
 public:
	void myMethod() {}
};

template<class T>
void templateFunction()
{
	// …
}


#include <cstdlib> // rand, srand
#include <ctime> // time

struct MyStruct {
	static const int die;
};
inline const int MyStruct::die = (srand((unsigned)time(0)), rand()%6+1); // 1-6


// Include guards
// MyApp.h
#ifndef MYAPP
#define MYAPP
// …
#endif

#if __has_include("myapp.h")
#include("myapp.h") */
#endif
