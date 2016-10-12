#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <time.h>
#include <ctime>

using namespace std;

class Cell{
	int x_, y_, num_;
	char content_;
	
public:
	Cell(int x, int y): x_(x), y_(y), content_('*'), num_(0){}

	int get_x(){
		return x_;
	}
	
	int get_y(){
		return y_;
	}
	
	int get_num(){
		return num_;
	}
	
	void add_num(){
		num_++;
	}
	
	char get_content(){
		return content_;
	}
	
	void set_content(char content){
		content_ = content;
	}
};

class Field{
	int width_, height_;
	vector<Cell> field_;
	int bomb_num;
	
	void gen_field(int width, int height){
		for(int i = 0; i < height; i++){
			for(int j = 0; j < width; j++){
				Cell cell(j, i);
				//cout << "(" << j << ", " << i << ")" << endl;
				field_.push_back(cell);
			}
		}
	}
	
public:
	Field(int width, int height): width_(width), height_(height){
		gen_field(width_, height_);
		bomb_num = width_*height_ - width_;
		plant_field();
		set_cell_num();
		draw_field();
	}
	
	void plant_field(){
		int rand_vec_pos;
		for(int i = 0; i < bomb_num; i++){
			//const long double sysTime = time(0);
			//const long double sysTimeMS = sysTime*1000;
			srand(time(0) + i);
			rand_vec_pos = rand()&(width_*height_);
			
			if(is_empty(rand_vec_pos)){
				field_[rand_vec_pos].set_content('^');
			} else {
			}
		}
		cout << endl;
	}
	
	void set_cell_num(){
		int x = 0, y = 0;
		bool top = false, bottom = false, left = false , right = false;
		
		for(int i = 0; i < field_.size(); i++){
			x = field_[i].get_x();
			y = field_[i].get_y();
			
			top = false; bottom = false; left = false; right = false;
			
			//cout << "(" << x << ", " << y << ")" << endl;
			
			if(x == 0) left = true;
			if(x == width_ - 1) right = true;
			if(y == 0) top = true;
			if(y == height_ - 1) bottom = true;
			
			//cout << "top: " << top << " bottom: " << bottom << " left: " << left << " right: " << right << endl;
			
			if(!top && !bottom && !left && !right){
				if(is_bomb(get_vec_pos(x-1, y-1))){ 	// ^ * *
					field_[i].add_num();						// * X *
				}													// * * *
			
				if(is_bomb(get_vec_pos(x, y-1))){		// * ^ *
					field_[i].add_num();						// * X *
				}													// * * *
		
				if(is_bomb(get_vec_pos(x+1, y-1))){		// * * ^
					field_[i].add_num();						// * X *
				}													// * * *
		
				if(is_bomb(get_vec_pos(x+1, y))){		// * * *
					field_[i].add_num();						// * X ^
				}													// * * *
		
				if(is_bomb(get_vec_pos(x+1, y+1))){		// * * *
					field_[i].add_num();						// * X *
				}													// * * ^
		
				if(is_bomb(get_vec_pos(x, y+1))){		// * * *
					field_[i].add_num();						// * X *
				}													// * ^ *
		
				if(is_bomb(get_vec_pos(x-1, y+1))){		// * * *
					field_[i].add_num();						// * X *
				}													// ^ * *
		
				if(is_bomb(get_vec_pos(x-1, y))){		// * * *
					field_[i].add_num();						// ^ X *
				}													// * * *
			} else {
				if(top){
					if(left){ //top left corner
						if(is_bomb(get_vec_pos(x+1, y))){		// * * *
							field_[i].add_num();						// * X ^
						}													// * * *
		
						if(is_bomb(get_vec_pos(x+1, y+1))){		// * * *
							field_[i].add_num();						// * X *
						}													// * * ^
		
						if(is_bomb(get_vec_pos(x, y+1))){		// * * *
							field_[i].add_num();						// * X *
						}													// * ^ *
					} else if(right){ //top right corner
						if(is_bomb(get_vec_pos(x, y+1))){		// * * *
							field_[i].add_num();						// * X *
						}													// * ^ *
		
						if(is_bomb(get_vec_pos(x-1, y+1))){		// * * *
							field_[i].add_num();						// * X *
						}													// ^ * *
		
						if(is_bomb(get_vec_pos(x-1, y))){		// * * *
							field_[i].add_num();						// ^ X *
						}													// * * *
					} else { //not a corner
						if(is_bomb(get_vec_pos(x+1, y))){		// * * *
							field_[i].add_num();						// * X ^
						}													// * * *
		
						if(is_bomb(get_vec_pos(x+1, y+1))){		// * * *
							field_[i].add_num();						// * X *
						}													// * * ^
		
						if(is_bomb(get_vec_pos(x, y+1))){		// * * *
							field_[i].add_num();						// * X *
						}													// * ^ *
		
						if(is_bomb(get_vec_pos(x-1, y+1))){		// * * *
							field_[i].add_num();						// * X *
						}													// ^ * *
		
						if(is_bomb(get_vec_pos(x-1, y))){		// * * *
							field_[i].add_num();						// ^ X *
						}													// * * *
					}
				} else if(bottom){
					if(left){ //bottom left corner
						if(is_bomb(get_vec_pos(x, y-1))){		// * ^ *
							field_[i].add_num();						// * X *
						}													// * * *
		
						if(is_bomb(get_vec_pos(x+1, y-1))){		// * * ^
							field_[i].add_num();						// * X *
						}													// * * *
		
						if(is_bomb(get_vec_pos(x+1, y))){		// * * *
							field_[i].add_num();						// * X ^
						}													// * * *
					} else if(right){ //bottom right corner
						if(is_bomb(get_vec_pos(x-1, y-1))){ 	// ^ * *
							field_[i].add_num();						// * X *
						}													// * * *
			
						if(is_bomb(get_vec_pos(x, y-1))){		// * ^ *
							field_[i].add_num();						// * X *
						}													// * * *
						
						if(is_bomb(get_vec_pos(x-1, y))){		// * * *
							field_[i].add_num();						// ^ X *
						}													// * * *
					} else { //not a corner
						if(is_bomb(get_vec_pos(x-1, y-1))){ 	// ^ * *
							field_[i].add_num();						// * X *
						}													// * * *
			
						if(is_bomb(get_vec_pos(x, y-1))){		// * ^ *
							field_[i].add_num();						// * X *
						}													// * * *
		
						if(is_bomb(get_vec_pos(x+1, y-1))){		// * * ^
							field_[i].add_num();						// * X *
						}													// * * *
		
						if(is_bomb(get_vec_pos(x+1, y))){		// * * *
							field_[i].add_num();						// * X ^
						}													// * * *
						
						if(is_bomb(get_vec_pos(x-1, y))){		// * * *
							field_[i].add_num();						// ^ X *
						}													// * * *
					}
				}
				
				if(left && !top && !bottom){ //not a corner
					if(is_bomb(get_vec_pos(x, y-1))){		// * ^ *
						field_[i].add_num();						// * X *
					}													// * * *
		
					if(is_bomb(get_vec_pos(x+1, y-1))){		// * * ^
						field_[i].add_num();						// * X *
					}													// * * *
		
					if(is_bomb(get_vec_pos(x+1, y))){		// * * *
						field_[i].add_num();						// * X ^
					}													// * * *
		
					if(is_bomb(get_vec_pos(x+1, y+1))){		// * * *
						field_[i].add_num();						// * X *
					}													// * * ^
		
					if(is_bomb(get_vec_pos(x, y+1))){		// * * *
						field_[i].add_num();						// * X *
					}													// * ^ *
				}
				
				if(right && !top && !bottom){ //not a corner
					if(is_bomb(get_vec_pos(x, y+1))){		// * * *
						field_[i].add_num();						// * X *
					}													// * ^ *
		
					if(is_bomb(get_vec_pos(x-1, y+1))){		// * * *
						field_[i].add_num();						// * X *
					}													// ^ * *
		
					if(is_bomb(get_vec_pos(x-1, y))){		// * * *
						field_[i].add_num();						// ^ X *
					}													// * * *
					
					if(is_bomb(get_vec_pos(x-1, y-1))){ 	// ^ * *
						field_[i].add_num();						// * X *
					}													// * * *
					
					if(is_bomb(get_vec_pos(x, y-1))){		// * ^ *
						field_[i].add_num();						// * X *
					}													// * * *
				}
			}
		}
	}
	
	bool is_empty(int vec_pos){
		return field_[vec_pos].get_content() != '^';
	}
	
	bool is_bomb(int vec_pos){
		if(field_[vec_pos].get_content() == '^'){
			return true;
		}
		return false;
	}
	
	void print_colored_char(int color, int bg_color, char text) const {
		cout << "\E[37;" << bg_color << "m\033[3;" << color << "m" << text << "\033[0m ";
	}
	
	int get_vec_pos(int x, int y) const {
		return y*width_ + x;
	}
	
	void plant_bomb(int x, int y){
		field_[get_vec_pos(x, y)].set_content('^');
	}
	
	void draw_field(){
		for(int i = 0; i < width_*height_; i++){
			if(i % width_ == 0 && i != 0){
				cout << endl;
			}
			if(field_[i].get_content() == '^'){ // bomb
				print_colored_char(30, 47, field_[i].get_content());
			} else { // normal cell
				cout << field_[i].get_num() << " ";
			}
		}
		cout << endl;
	}
};

int main(){
	Field field(25,20);
	
	//cout << "\E[37;47m\033[3;30mContact List\033[0m" << endl << "Others text" << endl;

	return 0;
}
