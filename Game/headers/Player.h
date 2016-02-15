#include "string"

using std::string;

class Player{
	string name_;
	int hp_, attack_, magic_;
public:
	Player();
	int get_name();
	int get_hp();
	int get_attack();
	int get_magic();
	
	void set_name();
	void set_hp();
	void set_attack();
	void set_magic();
	
	void attack();
};
