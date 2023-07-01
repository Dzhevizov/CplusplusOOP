#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


struct Point
{
    double x;
    double y;

    Point(int a, int b)
        : x(a)
        , y(b)
    {
    }
};

class EuclideanCalculator
{
    Point m_oPoint1;
    Point m_oPoint2;

public:

    EuclideanCalculator(Point p1, Point p2)
        : m_oPoint1(p1)
        , m_oPoint2(p2)
    {
    }

    ~EuclideanCalculator()
    {
    }

    double CalculateDistance()
    {
        double dResult = 0;

        dResult = sqrt(pow((m_oPoint1.x - m_oPoint2.x), 2.0) + pow((m_oPoint1.y - m_oPoint2.y), 2.0));

        return dResult;
    }
};

int main()
{
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    cin >> x1 >> y1 >> x2 >> y2;

    Point oPoint1(x1, y1);
    Point oPoint2(x2, y2);

    EuclideanCalculator oMyCalc(oPoint1, oPoint2);

    cout << fixed << setprecision(3) << oMyCalc.CalculateDistance() << endl;

    return 0;
}
