/*** Hello World Compile and Run ***/

#include <iostream>
#include <cstdint>
#include <string>
#include <tuple>
#include <functional>
#include <bitset>

#include <cstddef>
#include <stdexcept>
#include <cstring>
#include <ostream>
using namespace std;

class MyRectangle{
public:
	enum Color:unsigned short int{ Infrarosu, Rosu, Oranj, Galben, Verde, Albastru, Indigo, Violet, Ultraviolet };
	int x, y;
	int getArea();
	MyRectangle(initializer_list<int>);
};
int MyRectangle::getArea(){ return x*y; }
MyRectangle::MyRectangle(initializer_list<int> args){
	decltype(auto) li = args.begin();
	x = *li++;
	y = *li;
}

tuple<int, double, char> getTuple(){ return {1, 1.2, 'b'}; }

void call(function<void()> f){ f(); }

union Mix{
	char c[4];                 // 4 bytes
	struct{ short lo, hi; } s;  // 4 bytes
	int i;                     // 4 bytes
} m;

class MyNum{
public:
	int value;
	//explicit MyNum(int i):value(i){};
	operator int(){ return value; };
};



#ifndef _MSC_VER
#  if __cplusplus < 201103
#    define CONSTEXPR11_TN
#    define CONSTEXPR14_TN
#    define NOEXCEPT_TN
#  elif __cplusplus < 201402
#    define CONSTEXPR11_TN constexpr
#    define CONSTEXPR14_TN
#    define NOEXCEPT_TN noexcept
#  else
#    define CONSTEXPR11_TN constexpr
#    define CONSTEXPR14_TN constexpr
#    define NOEXCEPT_TN noexcept
#  endif
#else  // _MSC_VER
#  if _MSC_VER < 1900
#    define CONSTEXPR11_TN
#    define CONSTEXPR14_TN
#    define NOEXCEPT_TN
#  elif _MSC_VER < 2000
#    define CONSTEXPR11_TN constexpr
#    define CONSTEXPR14_TN
#    define NOEXCEPT_TN noexcept
#  else
#    define CONSTEXPR11_TN constexpr
#    define CONSTEXPR14_TN constexpr
#    define NOEXCEPT_TN noexcept
#  endif
#endif  // _MSC_VER
inline std::ostream& operator<<(std::ostream& os, string_view const& s){
	return os.write(s.data(), s.size());
}
template <class T> constexpr std::string_view type_name(){
	using namespace std;
#ifdef __clang__
	string_view p = __PRETTY_FUNCTION__;
	return string_view(p.data()+34, p.size()-34-1);
#elif defined(__GNUC__)
	string_view p = __PRETTY_FUNCTION__;
#  if __cplusplus < 201402
	return string_view(p.data()+36, p.size()-36-1);
#  else
	return string_view(p.data()+49, p.find(';', 49)-49);
#  endif
#elif defined(_MSC_VER)
	string_view p = __FUNCSIG__;
	return string_view(p.data()+84, p.size()-84-7);
#endif
}



int main(){
	auto&&[i, d, c] = getTuple();
	cout<<i<<" "<<c<<endl;
	cout<<type_name<decltype(i)>()<<" "<<type_name<decltype(c)>()<<endl;
	int ii(i);
	[=, b = 2]() mutable {b++; ii += b; }();
	cout<<ii<<endl;
	MyRectangle r{2, 6};
	cout<<r.x<<" "<<r.y<<" "<<r.getArea()<<endl;
	MyRectangle::Color colour = MyRectangle::Color::Rosu;
	cout<<to_string(colour)<<endl;
	m.i = 0xFF00F00F;
	cout<<(bitset<32>)m.i<<endl;              // 11111111 00000000 11110000 00001111
	cout<<(bitset<16>)m.s.hi<<endl;           // 11111111 00000000
	cout<<(bitset<16>)m.s.lo<<endl;           //                   11110000 00001111
	cout<<(bitset<8>)m.c[3]<<endl;            // 11111111
	cout<<(bitset<8>)m.c[2]<<endl;            //          00000000
	cout<<(bitset<8>)m.c[1]<<endl;            //                   11110000
	cout<<(bitset<8>)m.c[0]<<endl;            //                            00001111
	MyNum C = {'H'};
	MyNum A{5};
	int iii = A;
	cout<<iii<<endl;
	cin.get();
}
