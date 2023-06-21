//#pragma once

#ifndef EXP_H
#define EXP_H

class Exp {
	int base;
	int exp;
public:
	Exp();
	Exp(int base, int exp);
	Exp(int base);
	int getValue();
	int getBase();
	int getExp();
	bool equals(Exp b);
};


#endif