/*
 *
 *	Author : Paschal Ahanmisi 
 *	Topic : Varaidic templates 
 * */

#include <iostream>
#include <type_traits>
#include <stdarg.h>

int min(int count , ...){
	va_list args ; 
	va_start(args, count); 
	int val = va_arg(args, int);
	for(int i = 0 ; i < count ; i++){
		int n = va_arg(args, int);
		if(n < val ){val = n;}
	}
	va_end(args);
	return val ;
}

// cpp varaidic types 

template <  typename... Args > 
std::common_type_t<Args...>  min2(Args... args){
	if(sizeof...(args) == 0 ){
		return 0;
	}
	return (args < ...);
}

template <typename T ,typename... Args> 
T sum (T a , Args... args){
	if constexpr (sizeof...(args) == 0 ) {
		return a;
	}
	 return (a + ... + args);
}

template <typename... Ts > 
constexpr auto get_type_size(){
	return std::array<std::size_t , sizeof... (Ts)>{sizeof(Ts)... };
}

// Multip acks 
template <typename... Ts , typename... Us> 
constexpr auto multipacks(Ts... args1 , Us... args2){
	std::cout << sizeof...(args1) << " " <<  sizeof...(args2);
}
int main(){
	[[maybe_unused]] int i =  sum(10, 20 ,30);
	auto m = get_type_size<double , int , char ,  long double , unsigned long>();
	for(auto const t : m){
		std::cout << t<< " " ; 
	}
}
