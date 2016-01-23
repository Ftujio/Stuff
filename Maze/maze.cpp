#include "iostream"
#include "cstdio"
#include "cstdlib"

#include "include/maze.h"
#include "include/rand.h"

using namespace std;

Maze::Maze(): width_(25), height_(20){ // Default width and height
	gen_maze(width_, height_);
}

Maze::Maze(int width, int height): width_(width), height_(height){
	gen_maze(width_, height_);
}

void Maze::place_block(int x, int y){}

void Maze::remove_block(int x, int y){}

void Maze::place_walls(){}

void Maze::create_path(){}

void Maze::gen_maze(int width, int height){}

int Maze::get_vec_pos(int x, int y) const {
	return y*10 + x;
}
