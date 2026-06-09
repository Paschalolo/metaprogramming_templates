

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
 struct foo{
	int a ; 
	bool operator>(foo const & f){return a > f.a;}
 };

template <typename T> 
int partition(T arr[] , int const low , int const high){
	T pivot = arr[high] ; 
	int i = (low -1);
	for(int j = low ; j <= high -1; j++ ){
		if(arr[j] < pivot){
	i++; 
	std::swap(&(arr[i], &(arr[j])));
		}
	}
	return i +1 ;
}

int main(){
	foo f1{}, f2{}; 
	max<foo>(f1,f2);
	return 0;
}
