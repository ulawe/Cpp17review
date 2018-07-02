/*** Hello World Compile and Run ***/

#include <iostream>
#include <cstdint>
#include <string>
using namespace std;

int main(){

	int x(1), y(2);
	char      myChar = 0;  // -128   to +127
	short     myShort = 0; // -32768 to +32767
	int       myInt = 0;   // -2^31  to +2^31-1
	long      myLong = 0;  // -2^31  to +2^31-1
	long long myL2 = 0;    // -2^63 to +2^63-1

	cout<<sizeof(myChar)<<endl // 1 byte (per definition)
		<<sizeof(myShort)<<endl  // 2
		<<sizeof(myInt)<<endl    // 4
		<<sizeof(myLong)<<endl   // 4
		<<sizeof(myL2)<<endl;    // 8

	cout<<"Hello World!"<<endl;
	cout<<x<<y<<endl; //"12"

	int8_t   myInt8 = 0; // 8 bits
	int16_t  myInt16 = 0; // 16 bits
	int32_t  myInt32 = 0; // 32 bits
	int64_t  myInt64 = 0; // 64 bits

	signed char  smyChar = 0; // -128   to +127
	signed short smyShort = 0; // -32768 to +32767
	signed int   smyInt = 0; // -2^31  to +2^31-1
	signed long  smyLong = 0; // -2^31  to +2^31-1
	signed long long smyL2 = 0; // -2^63  to +2^63-1

	unsigned char  umyChar = 0; // 0 to 255
	unsigned short umyShort = 0; // 0 to 32767
	unsigned int   umyInt = 0; // 0 to 2^32-1
	unsigned long  umyLong = 0; // 0 to 2^32-1
	unsigned long long umyL2 = 0; // 0 to 2^64-1

	unsigned uInt(0); // unsigned int
	signed sInt(1);   // signed int

											// Floating-point types
	float  myFloat = 3.14F; // 3.4E +/- 38 (7 digits)
	double myDouble = 3.14; // 1.7E +/- 308 (15 digits)
	long double myLongDouble = 3.14; // same as double

	myFloat = 12345.678F; // rounded to 12345.68
	cout<<myFloat<<endl;
	myFloat = 3E2; // 3*10^2 = 300
	cout<<"new myFloat:"<<myFloat<<endl;

								 // Char type
	char c = 'x'; // assigns 120 (ASCII for 'x')
	cout<<c; // prints 'x'

	int i = c;            // assigns 120
	cout<<i;       // prints 120
	cout<<(char) i<<endl; // prints 'x'

	char ascii =u8'x'; // use UTF-8 encoding
	cout << ascii<<endl;
											// Bool type
	bool b = false; // true or false value

									// String encodings
	wstring s1 = L"Hello";
	const wchar_t* s2 = L"Hello";
	string s3 = "Compiler-defined encoding";
	string s4 = u8"UTF-8 string";
	u16string s5 = u"UTF-16 string";
	u32string s6 = U"UTF-32 string";
	string s7 = u8"An asterisk: \u002A";
	cout<<s7<<endl;
	string s = "Hello \
World!";
	cout<<s<<endl;
	s = "\tHello\rWorld";
	cout<<s<<endl;
	s = R"(Hello World -\_0_/-
               |
	      /*\)";
	cout<<s<<endl;
	cin.get();
}
