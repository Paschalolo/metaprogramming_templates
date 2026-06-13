#include <variant>
#include <concepts> 
#include <iostream> 
#include <type_traits>
#include <utility>
#include <vector>
/* 
 * Dynamic vs Static Polymorphism 
g++-14 -Wall -Wextra -Werror -Wpedantic -Wnull-dereference  -Wshadow -Wconversion -
 * */

struct game_unit{
	virtual void attack() = 0 ;
};

template <typename T > 
struct game_u_crtp {
	public :
	void attack(){
		static_cast<T*>(this)->attack_impl();
	}
	void attack() const {
		static_cast<const T&>(std::as_const(*this)).attack_impl();
	}
};
struct knight1 : game_u_crtp<knight1> {
	private : 
	friend struct game_u_crtp<knight1>;
	void attack_impl() {
		std::cout << "overide";
	}
	void attack_impl()const  {
		std::cout << "overide";
	}
};
struct knight : game_unit {
	void attack() override {
		std::cout << "overide";
	}
};
struct mage : public game_unit{
	void attack() override {
		std::cout << "overide mAGE";
	}
};

struct mage1 : public game_u_crtp<mage1>{

	private:
	friend struct game_u_crtp<mage1>;
	void attack_impl() {
		std::cout << "overide mAGE";
	}

	void attack_impl() const  {
		std::cout << "overide mAGE";
	}
};
void print(std::vector<game_unit*> const& units ){
	for(auto & v : units){
		v->attack();
	}
}

template <typename T> 
void print_crtp(std::vector<T> const  & units){
	for(auto& v : units) {
		std::visit([](auto& arg){
				using A = std::decay_t<decltype(arg)>;
				if constexpr((std::is_same_v<A, mage1>) || (std::is_same_v<A, knight1>) ){
					arg.attack();
				}else {
					static_assert(false , "non exhaustive type");
				}
		
				},v);
		
	}
}
using v_type = std::variant<mage1,knight1 >;
int main(){
	std::vector<v_type> jo{mage1{} , knight1{}, knight1{}};
	print_crtp(jo);
	return 0;
}
