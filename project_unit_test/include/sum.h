#include <cassert>

class sum_worker
{
private:	
	int value_left;
	bool left_set;

	int value_right;
	bool right_set;

	int value_result;
public:
	sum_worker &setLeft(int left) {value_left = left; left_set = true;  return *this; }
	sum_worker &setRight(int right) {value_right = right; right_set = true; return *this; }
	int getValue() {return value_result;}

	bool run();
	sum_worker()
	{
		value_left = 0;
		value_right = 0;
		value_result = 0;
		left_set = false;
		right_set = false;
	}
};
