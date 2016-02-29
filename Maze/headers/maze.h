#include "vector"

#include "block.h"

using namespace std;
using std::vector;

class Maze{
private:
	class MazeError{};

	int width_, height_;
	vector<Block> a;

	void place_wall(int x, int y);
	void remove_block(int x, int y);	
	void place_walls();
	void create_path();
	void gen_maze(int width, int height);
	
	int get_vec_pos(int x, int y) const;
public:
	Maze();
	Maze(int width, int height);
};
