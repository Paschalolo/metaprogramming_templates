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

template <typename T , size_t S> 
class buffer {
	T m_data[S] ; 
	public : 
		constexpr const T* data () const {return m_data;}
		constexpr T& operator[](size_t const index) {return m_data[index];}
		constexpr const  T& operator[](size_t const index)const {return m_data[index];}
};
template <typename T , typename U > 
struct food ; 

template <typename T , typename U > 
struct food {
	T m_data ; 
	U m_food;
};

template <typename T  > 
struct food<T, double> {
	double m ;
};
void T1(){
	[[maybe_unused]] auto  y = add(3,4);
	std::array<int, 10> ko{1, 23, 4, 5, 6, 7 , 8 , 3, 2}; 
	[[maybe_unused]] auto jj = count_if(ko.begin() , ko.end() , [](const int a ){return a % 2 == 1 ;});
	
	wrapper<int> w1{12};
	[[maybe_unused]] auto j1 = w1.as<double>();
}
template <typename T> 
struct is_floaater{
	constexpr static inline bool value = false ;
};

template <> 
struct is_floaater<double>{
	constexpr static inline bool value = true;
};

template <typename T> 
concept is_floaater_v = is_floaater<T>::value;

template <typename T , size_t S> 
std::ostream& pretty_print(const std::ostream& os , std::array<T,S> const & arr){
	os << '[' ;
	if(S<0 ) {
		size_t i = 0 ; 
		for(; i < S-1 ; ++i)os << arr[i] << "," ; 
		os << arr[S-1];
	}
	os << ']';
	return os;
}
int main(){
	
	return 0;
}
