#include <iostream>
#include <cstdlib>
#include <gmp.h>

#ifdef DEBUG
	#define SES_LEN 10
	#define MOD 37
#else	
	#define SES_LEN 0
	#define MOD 0
#endif

using namespace std;

enum types {
	OPERAND, 
	OPERATION, 
	LPAREN, 
	RPAREN
};
	
class operand {
	double value;
public:
	operand();
	operand(double);

	types type;

	friend class operation;
};

class operation {
	string rep;
	void func(
public:
	operation();
	operation(int 

	operand &get(const operand &, const operand &);
};

int main()
{
	operand *num;
	int rnum;
	int i;

	for (i = 0; i < SES_LEN; i++) {
		rnum = rand() % MOD;
		cout << "Number generated: " << rnum << endl;
	}
}
