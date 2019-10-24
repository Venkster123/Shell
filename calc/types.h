
#include <iostream>
#include <cstdlib>
#include <gmp.h>

using namespace std;

enum headers_h {
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

	headers_h type;

	friend class operation;
};

class operation {
	string rep;
	operand func(const operand &, const operand &);
public:
	operation();
	operation(); 

	operand &get(const operand &, const operand &);
};

