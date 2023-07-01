#include <iostream>
#include <set>
#include "Fraction.h"

using namespace std;

int main()
{
    set<Fraction> fractions {Fraction{ 1, 3 }, Fraction{ 2, 10 }, Fraction{ 2, 6 }};

    cout << Fraction{ 1, 3 } << endl;

    Fraction frac(0, 1);
    cin >> frac;

    cout << frac << endl;

    frac++;

    cout << frac << endl;

    ++frac;

    cout << frac << endl;

    bool bEqual = Fraction{ 1, 3 } == Fraction{ 2, 7 };
    cout << bEqual << endl;

    Fraction f1(1, 3);
    Fraction f2(2, 10);

    cout << f1 + f2 << endl;
    cout << f1 - f2 << endl;

    f2.normalize();

    cout << f2 << endl;

    return 0;
}
