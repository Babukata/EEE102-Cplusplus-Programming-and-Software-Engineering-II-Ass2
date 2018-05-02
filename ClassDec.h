//Header for implement fraction and complex number
//@Zheng.Sun15	ID:1507820
#ifndef ComplexNum_Fraction
#define ComplexNum_Fraction

int commonDivisor(int a, int b);
int intParser();
class Fraction {
private:
	int top;	//Numerator
	int bottom; //Denominator
public:
	Fraction();
	Fraction(int a, int b);
	Fraction(int a);
	void show_Fraction();//formatted 'show' display
	void show_Decimal();//formated display in decimal
	void print_Fraction();//formated display
	void set_numerator(int x);//reset top
	void set_denominator(int x);//reset bottom
	void cmp_Fraction(const Fraction& x) const;//cmp
	Fraction add_Fraction(const Fraction& x) const;//'+'op
	Fraction sub_Fraction(const Fraction& x) const;//'-'op
	Fraction mul_Fraction(const Fraction &x) const;//'*'op
	Fraction div_Fraction(const Fraction &x) const;//'/'op
	double to_Decimal();
};

class ComplexNum:public Fraction {
private:
	Fraction m_r;	//real part of complex
	Fraction m_i;	//imaginary part of complex
public:
	ComplexNum(Fraction r, Fraction i);//constructor
	void print_ComplexNum();// formatted display
	ComplexNum add_ComplexNum(const ComplexNum& y) const;//'+'op
	ComplexNum sub_ComplexNum(const ComplexNum& y) const;//'-'op
	ComplexNum mul_ComplexNum(const ComplexNum& y) const;//'-'op
};

#endif