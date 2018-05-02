//Main file for demonstrate fraction and complex number
//@Zheng.Sun15	ID:1507820
#include <iostream>
#include "ClassDec.h"

const int MAX = 4; // Size of the implemented class array

int main() {
	using namespace std;
	int i = 0;		//loop counter for initialize Fraction array
	int numerator;	//temporary storage for top and bottom of Fraction
	int denominator;
	Fraction F[MAX];//array to store Fraction objects
	cout << "This program demostrates some simple behaviors of Fraction class and ComplexNum class" << endl;
	cout << "Please Enter 4 fractions for demostration." << endl;
	for (i = 0; i < MAX; i++) {//read and parse int type data into objets
	cout << "fraction #" << i + 1 << ":";
	cout << "\tEnter the numerator:";
	numerator = intParser();
	cout << "\t\tEnter the denominator:";
	while ((denominator = intParser()) == 0)//exlude denominator = 0
		cout << "\t\tDenominator cannot be 0. Try again: ";
	F[i] = Fraction(numerator, denominator);//construct Fraction into array
	}
	//display the fraction in Fraction format and decimal format respectively
	cout << "\nThe First 2 fractions demostrate the Fraction class: "<<endl;
	cout << "The fraction is "; F[0].print_Fraction(); cout << " "; F[0].show_Decimal();
	cout << "The fraction is "; F[1].print_Fraction(); cout << " "; F[1].show_Decimal();
	cout << endl;
	//display the results of the operations(+-*/cmp) on the first 2 Fractions
	cout << "By addition: ";
	F[0].add_Fraction(F[1]).show_Fraction();
	cout << "By subtraction: ";
	F[0].sub_Fraction(F[1]).show_Fraction();
	cout << "By multiplication: ";
	F[0].mul_Fraction(F[1]).show_Fraction();
	cout << "By division: ";
	if (F[1].to_Decimal() != 0){//avoid denominator = 0
		F[0].div_Fraction(F[1]).show_Fraction();
	}
	else{
		F[0].print_Fraction(); cout << "cannot divided by 0" << endl;
	}
	cout << "By comparison: ";
	F[0].cmp_Fraction(F[1]);
	cout << endl << endl;
	//Construct 2 ComplexNum objects with 4 Fractions for demostration
	ComplexNum im1 = ComplexNum(F[0], F[1]);
	ComplexNum im2 = ComplexNum(F[2], F[3]);
	cout << "Now, demonstrate the Complex class with all 4 Fraction objects." << endl;
	cout << "First, form 2 ComplexNum objects with the input Fractions:" << endl;
	cout << "One complex number is "; im1.print_ComplexNum(); cout << endl;//display ComplexNum objects attributes in format
	cout << "The other complex is "; im2.print_ComplexNum(); cout << endl;

	cout << endl;//display the results of the operations(+-*) on the 2 ComplexNums
	cout << "By addition we have: "; im1.add_ComplexNum(im2).print_ComplexNum(); cout << endl;
	cout << "By subtraction we have: "; im1.sub_ComplexNum(im2).print_ComplexNum(); cout << endl;
	cout << "By mulplication we have: "; im1.mul_ComplexNum(im2).print_ComplexNum(); cout << endl;

	return 0;
}

//Euclidean algorithm to solve the biggest common divissor
int commonDivisor(int a, int b) {

	int r;
	for (; b != 0;) {
		r = a%b;
		a = b;
		b = r;
	}

	return a;
}
//to Parse an int type value from the input 
int intParser() {
	using std::cin;
	using std::cout;
	
	int temp;
	while (!(cin >> temp)) {
		cin.clear();//reset cin

		while (cin.get() != '\n')//clear a whole line
			continue;
		cout << "\t\tPlease enter an integer:";
	}

	return temp;
}