class Rand{
private:
	class RandError{
	public:
		RandError();
		RandError(int err);
	};
public:
	Rand();
	int get_rand();
	int get_rand(int from, int to);
};
