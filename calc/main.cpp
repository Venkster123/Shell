#include "types.h"

int main()
{
	operand *num;
	int rnum;
	int i;

	for (i = 0; i < 100; i++) {
		rnum = rand() % 100;
		cout << "Number generated: " << rnum << endl;
	}
}
