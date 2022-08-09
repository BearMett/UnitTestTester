#include "iostream"
#include "sum.h"
#include "stdio.h"
int main()
{
	sum_worker sumworker;
	sumworker.setLeft(1).setRight(3).run();

	printf("%d\n", sumworker.getValue());
	
	return 0;
}
