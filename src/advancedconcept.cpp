#include <type_traits>
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
int main(){

	return 0;
}
