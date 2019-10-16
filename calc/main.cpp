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
};

class operation {
	string rep;
public:
	operation();

	operand &get(const operand &, const operand &);
};

int main()
{
	operand *num;
	int i;

	for (i = 0; i < SES_LEN; i++) {

	}
}
