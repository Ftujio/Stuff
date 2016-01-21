class Maze{
private:

	int width_, height_;

	void place_block(int x, int y);
	void remove_block(int x, int y);
	void place_walls();
	void create_path();
	void gen_maze(int width, int height);
	
	int get_vec_pos(int x, int y) const;
public:
	class Block{
		private:
			
		public:
			
	};

	Maze();
	Maze(int width, int height);
};
