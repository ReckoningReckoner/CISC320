#pragma once
/*
* fraction_14vb16.h
*
*  Created on: Oct 18, 2017
*      Author: Viraj Bangari
*
*  A class for holding fraction objects, as well as its
*  operators and exceptions.
*/

#define DllExport   __declspec( dllexport )

#include <iostream>
#include <string>

class DllExport Fraction {
public:
	/* Creates a fraction of 0/1 */
	Fraction();

	/* Creates a fraction of numerator/1 */
	Fraction(int numerator);

	/* Creates a fraction of numerator/denominator */
	Fraction(int numerator, int denominator);

	/* Calculates the GCD between two numbers */
	static int GCD(const int n, const int m);

	/* Calculates the LCM between two numbers */
	static int LCM(const int n, const int m);


	int numerator() const;
	int denominator() const;

	Fraction operator-();
	Fraction operator++(int);
	Fraction& operator++();
	Fraction& operator+=(const Fraction& rhs);
private:
	int numeratorInternal;
	int denominatorInternal;
	static void charsToFraction(const char * buffer, Fraction * fraction);
	friend std::istream& operator >> (std::istream& in, Fraction& fraction);
};

DllExport Fraction operator*(const Fraction& left, const Fraction& right);
DllExport Fraction operator/(const Fraction& left, const Fraction& right);
DllExport Fraction operator+(const Fraction& left, const Fraction& right);
DllExport Fraction operator-(const Fraction& left, const Fraction& right);
DllExport bool operator==(const Fraction& left, const Fraction& right);
DllExport bool operator!=(const Fraction& left, const Fraction& right);
DllExport bool operator<(const Fraction& left, const Fraction& right);
DllExport bool operator>(const Fraction& left, const Fraction& right);
DllExport bool operator<=(const Fraction& left, const Fraction& right);
DllExport bool operator>=(const Fraction& left, const Fraction& right);
DllExport std::ostream& operator<<(std::ostream& out, const Fraction& fraction);


class FractionException : public std::runtime_error
{
public:
	FractionException(std::string message) : std::runtime_error(message) {};
};