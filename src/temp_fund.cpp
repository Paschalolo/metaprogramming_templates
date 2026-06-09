#include <type_traits>
#include <vector> 
#include <array>
#include <iostream>
#include <functional>
template <typename T> 
T add(const T a , const T b){
	return a+ b;
}

class foo{
	int m_value ; 
	public : 
		explicit constexpr  foo(int const i) : m_value(i){}
		explicit operator int()const {return m_value;}
};

template <typename Input , typename Output , typename Predicate> 
int count_if(Input start , Output end , Predicate pred){
	int total = 0 ; 
	for(Input i = start ; i != end;i++ ){
		/* std::invoke(pred , *start); */
		if( pred(*start)) total++;
	}
	return total;
}

template <typename T> 
class wrapper {
	public : 
		wrapper(T const v) : value(v){}
		const T& get() const  { return value;}

		template <typename U> 
		U as() const;
	private : 
		T value ; 
};
template <typename T> 
template <typename U> 
U wrapper<T>::as() const{
	return static_cast<U>(value);	
}
class compositon{
	public : 
		template <typename T> 
		T add(T a , T b ){return a+b ;}
};
void T1(){
	[[maybe_unused]] auto  y = add(3,4);
	std::array<int, 10> ko{1, 23, 4, 5, 6, 7 , 8 , 3, 2}; 
	[[maybe_unused]] auto jj = count_if(ko.begin() , ko.end() , [](const int a ){return a % 2 == 1 ;});
	
	wrapper<int> w1{12};
	[[maybe_unused]] auto j1 = w1.as<double>();
}
int main(){
	
	return 0;
}
