#include "string"

using std::string;

class Player{
	string name_, taunts_[5];
	int hp_, attack_, magic_, taunt_num_;

	class Level{
		friend class Player;

		int xp_, level_;
	public:
		int calc_level(){
			int level = 0;
			while(xp_/2.5 >= 100){
				level++;
			}
			return level;
		}
	};

public:
	Player(string name, int hp, int attack, int magic);
	Player();
	
	string get_name()const;
	int get_hp()const;
	int get_attack()const;
	int get_magic()const;
	string get_taunt(int taunt_num)const;
	
	void set_name(string name);
	void set_hp(int hp);
	void set_attack(int attack);
	void set_magic(int magic);
	void add_taunt(string taunt);
	
	virtual int attack() = 0;
};
