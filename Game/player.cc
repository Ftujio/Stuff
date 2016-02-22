#include "headers/player.h"

Player::Player(string name, int hp, int attack, int magic): name_(name), hp_(hp), attack_(attack), magic_(magic){}

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

void Player::set_hp(int hp){
	hp_ = hp;
}

void Player::set_attack(int attack){
	attack_ = attack;
}

void Player::set_magic(int magic){
	magic_ = magic;
}