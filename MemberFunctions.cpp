//Source file for menber function of class Fraction and ComplexNum
//@Zheng.Sun15	ID:1507820
#include<iostream>
#include"ClassDec.h"

//defult constructor for Fraction
Fraction::Fraction() {
	top = 0;
	bottom = 1;
}
//constructor
Fraction::Fraction(int a, int b) {
	int cd = commonDivisor(a, b);// checkout the greatest commom divisor and elimiate
	a /= cd;
	b /= cd;
	if (a < 0, b < 0) {		//normalzie the fraction -- the nominator carrys '+-' sign
		top = a * (-1);
		bottom = b*(-1);
	}
	else if (a > 0, b < 0) {
		top = a * (-1);
		bottom = b*(-1);
	}
	else {
		top = a;
		bottom = b;
	}
}
//constructor
Fraction::Fraction(int a) {
	top = a;
	bottom = 1;
}
//print Fraction attributes in 'show' format 
void Fraction::show_Fraction() {
	std::cout << "The Fraction: " << top << "/" << bottom << std::endl;
}
//show Fraction in decimal represnetation
void Fraction::show_Decimal() {
	std::cout << "In Decimal is: " << this->to_Decimal() << std::endl;
}
//print Fraction in decimal format 
void Fraction::print_Fraction() {
	std::cout << top << "/" << bottom << "";
}
//add up current Fraction with implicit referenced Fraction
Fraction Fraction::add_Fraction(const Fraction& x) const {
	int newTop;
	int newBottom;
	newTop = (top)* (x.bottom) + bottom* (x.top);
	newBottom = (bottom)* (x.bottom);
	return Fraction(newTop, newBottom);
}
//solve differnce of current Fraction and implicit referenced Fraction
Fraction Fraction::sub_Fraction(const Fraction& x)const {
	int newTop;
	int newBottom;
	newTop = (top)* (x.bottom) - bottom* (x.top);
	newBottom = (bottom)* (x.bottom);
	return Fraction(newTop, newBottom);
}
//multiply current Fraction and implicit referenced Fraction
Fraction Fraction::mul_Fraction(const Fraction &x)const {
	int newTop;
	int newBottom;
	newTop = top* x.top;
	newBottom = bottom * x.bottom;
	return Fraction(newTop, newBottom);
};
//solve quotient of current Fraction and implicit referenced Fraction
Fraction Fraction::div_Fraction(const Fraction &x)const {
	int newTop;
	int newBottom;
	newTop = top* x.bottom;
	newBottom = bottom * x.top;
	return Fraction(newTop, newBottom);
}
//compare current Fraction and implicit referenced Fraction
void Fraction::cmp_Fraction(const Fraction& x) const {
	int temp = this->sub_Fraction(x).top;
	if (temp > 0)
		std::cout << "The former is greater.";
	else if (temp < 0)
		std::cout << "The latter fraction is greater.";
	else
		std::cout << "The two fractions are equal.";

}
//change top 
void Fraction::set_numerator(int x) {
	top = x;
}
//chaneg bottom
void Fraction::set_denominator(int x) {
	bottom = x;
}
//convert current Fraction to decimal representation
double Fraction::to_Decimal() {
	double dec = (double)(this->top) / (double)(this->bottom);
	return dec;
}

//ComplexNum Methods Begins

//Constructor method from base class Fraction
ComplexNum::ComplexNum(Fraction r, Fraction i): m_r(r), m_i(i){}
//Print attributes of ComplexNum in format
void ComplexNum::print_ComplexNum() {
	std::cout << "(";
	m_r.print_Fraction();
	std::cout << ") + ";
	std::cout << "(";
	m_i.print_Fraction();
	std::cout << ")";
	std::cout << "i";
}
//add up current ComplexNum with implicit referenced ComplexNum
ComplexNum ComplexNum::add_ComplexNum(const ComplexNum& y) const {
	Fraction newR = m_r.add_Fraction(y.m_r);
	Fraction newI = m_i.add_Fraction(y.m_i);
	return ComplexNum(newR, newI);
}
//subtract current ComplexNum with implicit referenced ComplexNum
ComplexNum ComplexNum::sub_ComplexNum(const ComplexNum& y) const {
	Fraction newR = m_r.sub_Fraction(y.m_r);
	Fraction newI = m_i.sub_Fraction(y.m_i);
	return ComplexNum(newR, newI);
}
//multiply current ComplexNum with implicit referenced ComplexNum
ComplexNum ComplexNum::mul_ComplexNum(const ComplexNum& y) const {
	Fraction newR = m_r.mul_Fraction(y.m_r).sub_Fraction(m_i.mul_Fraction(y.m_i));
	Fraction newI = m_r.mul_Fraction(y.m_i).add_Fraction(m_i.mul_Fraction(y.m_r));
	return ComplexNum(newR, newI);
}