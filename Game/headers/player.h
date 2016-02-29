#include "string"
#include "iostream"

using namespace std;
using std::string;

class Player{
	string name_, taunts_[5];
	int hp_, attack_, magic_, taunt_num_;

	class Level{
		int xp_, level_;

		int calc_level(){
			int level = 0, xp = xp_;
			while(xp/2.5 >= 100){
				level++;
				xp /= 2.5;
			}
			level_ = level;
			return level_;
		}
	public:
		void add_xp(int amount){
			xp_ += amount;
			level_ = calc_level();
		}

		int get_xp() const {
			return xp_;
		}

		int get_level()  const {
			return level_;
		}

		Level(): level_(1), xp_(100){}
	};

	Level l;

public:
	Player(string name, int hp, int attack, int magic);
	Player();
	
	string get_name()const;
	int get_hp()const;
	int get_attack()const;
	int get_magic()const;

	string get_taunt(int taunt_num)const;

	int get_xp()const;
	int get_level()const;
	
	void set_name(string name);
	void set_hp(int hp);
	void set_attack(int attack);
	void set_magic(int magic);
	void add_taunt(string taunt, int set_place);
	void add_xp(int amount);
	
	virtual int attack() = 0;
};
