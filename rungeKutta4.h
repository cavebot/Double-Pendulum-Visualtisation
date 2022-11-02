#pragma once

#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

class point
{
public:
    double x, y;

    //constructor
    point(double xp, double yp)
    {
        x = xp;
        y = yp;
    }


    /// Stream insertion operator overload for Point class
    friend ostream& operator<<(ostream& out, const point& pt)
    {
        out << "(x = " << pt.x << "," << " y = " << pt.y << ")";
        return out;
    }
};

double derivRK4(double x, double y)
{
    double deriv;

    deriv = cos(x * y);

    return deriv;
}



point evaluateRK4(double tp, point& point1)
{
    double k1, k2, k3, k4, k, x, y;

    x = point1.x;
    y = point1.y;

    //cout << point1 << " ";
    k1 = derivRK4(x, y);
    //cout << k1 << endl;
    k2 = derivRK4(x + tp / 2, y + tp * k1 / 2);
    //cout << k2 << endl;
    k3 = derivRK4(x + tp / 2, y + tp * k2 / 2);
    //cout << k3 << endl;
    k4 = derivRK4(x + tp, y + tp * k3);
    //cout << k4 << endl;

    k = tp * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    // cout << k << endl;


    point point2(point1.x + tp, point1.y + k);

    return point2;

}