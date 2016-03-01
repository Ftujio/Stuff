#include "string"
#include "iostream"

using namespace std;
using std::string;

class Player{
	string name_, taunts_[5];
	int hp_, attack_, magic_, taunt_num_;

	class Level{
		int xp_, level_, prev_xp_, next_xp_;

		int calc_level(){
			next_xp_ = prev_xp_*2.5;

			if(xp_ >= next_xp_){
				prev_xp_ *= 2.5;
				level_++;
			}
		}
	public:
		Level(): level_(1), xp_(100), prev_xp_(100), next_xp_(0){}

		void add_xp(int amount){
			xp_ += amount;
			calc_level();
		}

		int get_xp() const {
			return xp_;
		}

		int get_level()  const {
			return level_;
		}
	};

	Level l;

public:
	Player(string name, int hp, int attack, int magic);
	Player();
	
	string get_name()const;
	void set_name(string name);

	int get_hp()const;
	int get_attack()const;
	int get_magic()const;
	void set_hp(int hp);
	void set_attack(int attack);
	void set_magic(int magic);

	void add_taunt(string taunt, int set_place);
	string get_taunt(int taunt_num)const;

	int get_xp()const;
	int get_level()const;
	void add_xp(int amount);	
	
	virtual int attack(int attack) = 0;
};
