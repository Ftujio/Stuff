#include "headers/player.h"

Player::Player(string name, int hp, int attack, int magic): name_(name), hp_(hp), attack_(attack), magic_(magic), taunt_num_(2){
	taunts_[0] = "N00b!";
	taunts_[1] = "GET REKT!";
}

Player::Player(): name_("Joe"), hp_(10), attack_(1), magic_(0){}

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

void Player::add_taunt(string taunt){
	taunts_[taunt_num_] = taunt;
	taunt_num_++;
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
