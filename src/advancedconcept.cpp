#include <type_traits>
#include <memory>
#include <concepts>
#include <iostream>
template <typename T>
struct processor;

void handle([[maybe_unused]]double value ){}
template <typename T> 
struct base_parser{
	using value_type = int;
	void inti(){

		std::cout << "init";}
};

template <typename T> 
struct parser {
	[[no_unique_address]] base_parser<T> bp{};
	void parse(){
		typename base_parser<T>::value_type jj{};
		bp.inti(); 
		std::cout << "parse";
}
};

struct account_t{int number ;};

struct foo{int data ; } ;

void f(foo& ) {std::cout << "foo&";}; 
void f(foo&&){std::cout << "foo&&";}


template <typename T , typename... Args > 
auto make_unique(Args&&... args){
	return std::unique_ptr<T>{new T (std::forward<Args>(args)...)};
}
int main(){

	return 0;
}
