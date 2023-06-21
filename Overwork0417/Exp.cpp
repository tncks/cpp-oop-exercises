#include "Exp.h"

Exp::Exp() {
	base = 1;
	exp = 1;
}
Exp::Exp(int base, int exp) {
	this->base = base;
	this->exp = exp;
}
Exp::Exp(int base) {
	this->base = base;
	exp = 1;
}
int Exp::getValue() {
	int value = 1;
	for (int i = 0; i < exp; i++)
		value *= base;
	return value;
}
int Exp::getBase() {
	return base;
}
int Exp::getExp() {
	return exp;
}
bool Exp::equals(Exp b) {
	return b.getValue() == this->getValue();
}