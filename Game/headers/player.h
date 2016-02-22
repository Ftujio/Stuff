#include "string"

using std::string;

class Player{
	string name_;
	int hp_, attack_, magic_;
public:
	Player(string name, int hp, int attack, int magic);
	Player();
	
	string get_name()const;
	int get_hp()const;
	int get_attack()const;
	int get_magic()const;
	
	void set_name(string name);
	void set_hp(int hp);
	void set_attack(int attack);
	void set_magic(int magic);
	
	int attack();
};
