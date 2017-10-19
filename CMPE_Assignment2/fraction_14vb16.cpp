/*
 * fraction_14vb16.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: Viraj Bangari
 */

#include <stdlib.h>
#include <string>
#include <streambuf>
#include <cmath>
#include "fraction_14vb16.h"

Fraction::Fraction() : numeratorInternal(0), denominatorInternal(1) { }

Fraction::Fraction(int numerator) : numeratorInternal(numerator),
                                    denominatorInternal(1) { }
Fraction::Fraction(int numerator, int denominator) {
  if (numerator == 0) {
    numeratorInternal = 0;
    denominatorInternal = 1;
    return;
  }

  if (denominator == 0) {
    throw FractionException("Divide by zero encountered.");
  }

  const int sign = (numerator < 0 || denominator < 0) && !(numerator < 0 && numerator < 0) ? -1 : 1;

  numerator = abs(numerator);
  denominator = abs(denominator);

  int gcd = Fraction::GCD(numerator, denominator);

  numeratorInternal = sign * numerator/gcd;
  denominatorInternal = denominator/gcd;
}

int Fraction::GCD(const int n, const int m) {
  if (n == 0 || m == 0) {
    return 0;
  }

  if (n < m) {
    return GCD(m, n);
  }

  if (n % m == 0) {
    return m;
  }

  return Fraction::GCD(m, n%m);
}

int Fraction::LCM(const int n, const int m) {
  return abs(n * m)/GCD(n, m);
}

int Fraction::numerator() const {
  return numeratorInternal;
}

int Fraction::denominator() const {
  return denominatorInternal;
}

/*
 * Operator overloading
 */
Fraction operator*(const Fraction& left, const Fraction& right) {
  return Fraction(left.numerator() * right.numerator(),
                  left.denominator() * right.denominator());
}

Fraction operator/(const Fraction& left, const Fraction& right) {
  return Fraction(left.numerator() * right.denominator(),
                  left.denominator() * right.numerator());
}

Fraction operator+(const Fraction& left, const Fraction& right) {
  int lowestCommonMultiple = Fraction::LCM(left.denominator(), right.denominator());
  int numerator = left.numerator() * lowestCommonMultiple/left.denominator() +
      right.numerator() * lowestCommonMultiple/right.denominator();

  return Fraction(numerator, lowestCommonMultiple);
}

Fraction operator-(const Fraction& left, const Fraction& right) {
  int lowestCommonMultiple = Fraction::LCM(left.denominator(), right.denominator());
  int leftNumerator = left.numerator() * lowestCommonMultiple/left.denominator();
  int rightNumerator = right.numerator() * lowestCommonMultiple/right.denominator();

  return Fraction(leftNumerator - rightNumerator, lowestCommonMultiple);
}

Fraction Fraction::operator-() {
  return Fraction(this->numerator() * -1, this->denominator());
}

Fraction Fraction::operator++(int) {
  Fraction old = *this;
  *this = *this + 1;
  return old;
}

Fraction& Fraction::operator++() {
  *this = *this + 1;
  return *this;
}

Fraction& Fraction::operator+=(const Fraction& rhs) {
  *this = *this + rhs;
  return *this;
}

void Fraction::charsToFraction(const char* buffer, Fraction* fraction) {
  const int zeroDigitAsciiIndex = 48;

  int numerator = 0;
  int denominator = 1;
  int numeratorCoefficient = 1;
  int denominatorCoefficient = 1;
  int* n = &numerator;

  int i = 0;
  if (buffer[0] == '-') {
    numeratorCoefficient = -1;
    i++;
  }

  while (buffer[i] != '\0') {
    char c = buffer[i];

    if ('0' <= c && c <= '9') {
      int charAsDigit = c - zeroDigitAsciiIndex;
      *n *= 10;
      *n += charAsDigit;
    }
    else if (c == '/') {
      if (n == &denominator) {
        throw FractionException("There can only be one '/' symbol at a time.");
      }

      if (buffer[i + 1] == '-') {
        denominatorCoefficient = -1;
        i++;
      }
      else if (buffer[i + 1] < '0' || buffer[i + 1] > '9') {
        throw FractionException("There must be at least one digit following the '/' symbol.");
      }

      denominator = 0;
      n = &denominator;
    }
    else {
      throw FractionException("Invalid character encountered.");
    }
    i++;
  }

  *fraction = Fraction(numeratorCoefficient * numerator, denominatorCoefficient * denominator);
}

bool operator==(const Fraction& left, const Fraction& right) {
  return left.numerator() == right.numerator() && left.denominator() == right.denominator();
}

bool operator!=(const Fraction& left, const Fraction& right) {
  return !(left == right);
}

bool operator<(const Fraction& left, const Fraction& right) {
  return (left - right).numerator() < 0;
}

bool operator>(const Fraction& left, const Fraction& right) {
  return (left - right).numerator() > 0;
}

bool operator<=(const Fraction& left, const Fraction& right) {
  return left < right || left == right;
}

bool operator>=(const Fraction& left, const Fraction& right) {
  return left > right || left == right;
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
  out << fraction.numerator() << "/" << fraction.denominator();
  return out;
}

std::istream& operator>>(std::istream& in, Fraction& fraction) {
  const int bufferSize = 256;
  char buffer[bufferSize];
  in >> buffer;

  Fraction::charsToFraction(buffer, &fraction);


  return in;
}
