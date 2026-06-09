

/*
 * Author : Paschal Aahanmisi 
 * Exploring template metadata programming
 *
 * */

#include <iostream> 
#include <type_traits>
#include <concepts> 
int max(const int a  , const int b ) {
	return a < b ? b : a ;
}

/* the concept is valid for a arithmetic or floating point type */ 
template <typename T> 
concept ArithFlot_t = requires(T a , T b ){
	{ a > b}-> std::same_as<bool>;
};


template <typename T> 
requires (ArithFlot_t<T>) 
T max(T a , T b ){
	return a > b ? a : b ;	
}

int main(){
	[[maybe_unused]] auto t = max(900U, 7.0f);
	return 0;
}
