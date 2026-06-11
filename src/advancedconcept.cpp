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

template <typename T , typename U> 
auto minimum(T&& a , U&& b)-> decltype(a < b ? a : b){
	return a < b ? a : b ;
}

struct wrapper{
	wrapper(int i ) : val(i) {}
	int val ; 
	friend wrapper operator+(int const a , wrapper const & w){
		return wrapper(a + w.val);
	}
	friend wrapper operator+(wrapper const & w , int const a ){
		return wrapper(w.val + a );
	}
	friend void print3(wrapper const & w);
	template <typename T> 
	friend struct printer;
};
void print3(wrapper const& w){
	std::cout << w.val << '\n'; 
}

template <typename T> 
struct printer {
	void operator()(wrapper const & w){
		std::cout <<w.val << " " ; 
	}
};
int main(){

	return 0;
}
