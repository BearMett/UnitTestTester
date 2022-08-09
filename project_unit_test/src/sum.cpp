#include "sum.h"
bool sum_worker::run()
{
	if (left_set == false || right_set == false)
	{
		return false;
	}

	value_result = value_left + value_right;
	return true;
}
