#include "sum.h"
bool sum_worker::run()
{
	assert(left_set);
	assert(right_set);

	value_result = value_left + value_right;
	return left_set & right_set;
}
