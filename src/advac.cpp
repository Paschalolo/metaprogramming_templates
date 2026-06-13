#include <string_view>
#include <type_traits>
#include <iostream> 
#include <concepts>


struct hero{
	hero(std::string_view n): name (n.begin(), n.end()){}
	std::string name ;
};

struct moderate_style {
	void fight(){
		std::cout << "attack the defend";
	}
};

template <typename T> 
struct lone_warrior: T {
	void fight(){
		std::cout << "figthing alone"; 
		ml.fight();
	}
	[[no_unique_address]] T ml {}; 
	};
int main(){
	lone_warrior<moderate_style> lm {}; 
	lm.fight();

	return 0;
}
