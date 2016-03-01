#include "headers/player.h"
#include "iostream"

using namespace std;

Player::Player(string name, int hp, int attack, int magic): name_(name), hp_(hp), attack_(attack), magic_(magic), taunt_num_(1){
	taunts_[0] = "GET REKT!";
}

Player::Player(): name_("Joe"), hp_(10), attack_(1), magic_(0), taunt_num_(1){}

string Player::get_name() const {
	return name_;
}

int Player::get_hp() const {
	return hp_;
}

int Player::get_attack() const {
	return attack_;
}

int Player::get_magic() const {
	return magic_;
}

string Player::get_taunt(int taunt_num)const{
	cout << taunt_num_ << endl;
	return taunts_[taunt_num];
}

void Player::set_hp(int hp){
	hp_ = hp;
}

void Player::set_attack(int attack){
	attack_ = attack;
}

void Player::set_magic(int magic){
	magic_ = magic;
}

void Player::add_taunt(string taunt, int set_place){
	if(set_place < 0 && taunt_num_ <= 5){
		taunts_[taunt_num_] = taunt;
		taunt_num_++;
	} else {
		if(taunts_[set_place] == "") taunt_num_++;
		taunts_[set_place] = taunt;
	}
}

void Player::add_xp(int amount){
	l.add_xp(amount);
}

int Player::get_xp() const {
	return l.get_xp();
}

int Player::get_level()const{
	return l.get_level();
}