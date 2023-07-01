#include <iostream>
#include <set>

class Fraction {
	int numerator;
	int denominator;

public:
	Fraction(int num, int denom) : numerator(num), denominator(denom) { normalize(); }

	int getNumerator() const {
		return this->numerator;
	}

	int getDenominator() const {
		return this->denominator;
	}

	bool operator<(const Fraction& other) const {
		return this->numerator * other.denominator < other.numerator * this->denominator;
	}

	Fraction operator++(int)
	{
		numerator += denominator;
		normalize();
		return Fraction(numerator, denominator);
	}

	Fraction& operator++()
	{
		numerator += denominator;
		normalize();
		return *this;
	}

	bool operator==(const Fraction& other) const
	{
		return this->numerator * other.denominator == other.numerator * this->denominator;
	}

	Fraction operator+(const Fraction& other) const
	{
		Fraction f = Fraction(this->numerator * other.denominator + other.numerator * this->denominator, this->denominator * other.denominator);
		f.normalize();
		return f;
	}

	Fraction operator-(const Fraction& other) const
	{
		Fraction f = Fraction(this->numerator * other.denominator - other.numerator * this->denominator, this->denominator * other.denominator);
		f.normalize();
		return f;
	}

	int findGCD(int a, int b)
	{
		if (b == 0)
			return a;

		return findGCD(b, a % b);
	}

	void normalize()
	{
		int gcd = findGCD(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;
	}

	friend std::istream& operator>>(std::istream& iStr, Fraction& frac);
};

std::ostream& operator<<(std::ostream& oStr, const Fraction& frac)
{
	return oStr << frac.getNumerator() << "/" << frac.getDenominator();
}

std::istream& operator>>(std::istream& iStr, Fraction& frac)
{
	return iStr >> frac.numerator >> frac.denominator;
}
