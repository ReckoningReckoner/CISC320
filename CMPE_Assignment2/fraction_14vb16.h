/*
 * fraction_14vb16.h
 *
 *  Created on: Oct 18, 2017
 *      Author: Viraj Bangari
 *
 *  A class for holding fraction objects, as well as its
 *  operators and exceptions.
 */

#ifndef FRACTION_14VB16_H_
#define FRACTION_14VB16_H_

#include <iostream>
#include <string>

class Fraction {
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
    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
};

Fraction operator*(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);
bool operator==(const Fraction& left, const Fraction& right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator<(const Fraction& left, const Fraction& right);
bool operator>(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);
bool operator>=(const Fraction& left, const Fraction& right);
std::ostream& operator<<(std::ostream& out, const Fraction& fraction);


class FractionException : public std::runtime_error
{
  public:
    FractionException(std::string message) : std::runtime_error(message) {};
};

#endif /* FRACTION_14VB16_H_ */
