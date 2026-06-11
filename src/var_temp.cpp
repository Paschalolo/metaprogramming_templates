/*
 *
 *	Author : Paschal Ahanmisi 
 *	Topic : Varaidic templates 
 * */


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

int main(){}
