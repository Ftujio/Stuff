class Block{
private:
	int x_, y_;
	bool wall_;
public:
	Block(int x, int y);

	int get_x() const;
	int get_y() const;
	void set_x(int x);
	void set_y(int y);
	void set_wall(bool wall);

	bool has_wall() const;
};