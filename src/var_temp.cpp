/*
 *
 *	Author : Paschal Ahanmisi 
 *	Topic : Varaidic templates 
 * */
#include <cstddef>
#include <functional>
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

template <typename , typename > 
struct func_pair ; 

template <typename R1 , typename... A1 , typename R2 , typename... A2> 
struct func_pair<R1(A1...) , R2(A2...)>{
	std::function<R1(A1...)>f{};
	std::function<R1(A1...)>m{};
};

template <typename... T > 
void captures(T... args){
	auto l = [args...](){};
}

template <typename... T> 
auto make_array(T... args){
	return std::array<std::common_type_t<T...>, sizeof...(args)>{args...};
}

// Alignment specifier 
template <typename... T> 
struct alignment1{
	alignas(T...) char a;
};


// tupele 
template <typename T , typename ... Ts > 
struct tuple {
	tuple(const T& t , const Ts& ... ts): value{t}, rest{ts...}{}
	private : 
		T value ; 
		tuple<Ts...> rest;
};
template <typename... T> 
struct tuple_c ;

template <typename T> 
struct tuple_c<T>{
	tuple_c(T m):m_data(m){}
	T m_data ; 
	constexpr size_t size() const {return 1;}
};
template <size_t N>
struct getter;
template <typename T , typename... Args> 
struct tuple_c<T , Args...>{


		// template <size_t N, typename B , typename... Argg> 
		// friend B& get_t(tuple_c<B, Argg...>& );
		alignas(32)   T m_data ;
		tuple_c<Args...> m_args;
	public :
		constexpr tuple_c(const T& tt , const Args&... args): m_data(tt),m_args(args...) {}
		T& get_data(){
			return m_data;
		}
		
		constexpr size_t size() const {return 1 + sizeof...(Args);}
		auto& get_next_tuple(){
			return m_args;
		}
};

template <>
struct getter<0> {
		template <typename Tuple>
		constexpr static  auto& get_t(Tuple& tup){
			return tup.m_data;
		}
};
template <size_t N>
struct getter {
		template <typename Tuple>
		constexpr static  auto& get_t(Tuple& tup){
			constexpr size_t size = tup.size();
			static_assert(N < size,"Data must be less than the value of struct " );
			return getter<N-1>::get_t(tup.get_next_tuple());
}
};
int main(){

	tuple_c<int , int  , double , float> mm {8,9,10.34f, 12.3f};
	std::cout << getter<2>::get_t(mm);
}
