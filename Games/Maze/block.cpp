#include "headers/block.h"

Block::Block(int x, int y): x_(x), y_(y), wall_(false){}

int Block::get_x() const {
	return x_;
}

int Block::get_y() const {
	return y_;
}

bool Block::has_wall() const {
	return wall_;
}

void Block::set_x(int x){
	x_ = x;
}

void Block::set_y(int y){
	y_ = y;
}

void Block::set_wall(bool wall){
	wall_ = wall;
}