class Rand{
private:
	class RandError{
	public:
		RandError(int err);
		RandError();
	};
public:
	Rand();
	int get_rand();
	int get_rand(int from, int to);
};
