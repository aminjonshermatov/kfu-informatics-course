//
// Created by aminjonshermatov on 11/10/2021.
//

#include "iomanip"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

using std::setprecision;
using std::fixed;
using std::vector;
using std::max_element;
using std::cerr;

int main() try {
    vector<Shape*> shapes;

    ScaleneTriangle st(6, 7, 9);
    st.printType();
    cout << fixed << setprecision(6) << st.getArea() << '\n';
    shapes.push_back(&st);

    cout << "---------------\n";

    RightTriangle rt(3, 4, 5);
    rt.printType();
    cout << fixed << setprecision(6) << rt.getArea() << '\n';
    shapes.push_back(&rt);

    cout << "---------------\n";

    IsoscelesTriangle it(4, 4, 2);
    it.printType();
    cout << fixed << setprecision(6) << it.getArea() << '\n';
    shapes.push_back(&it);

    cout << "---------------\n";

    Rectangle r(5, 6);
    r.printType();
    cout << fixed << setprecision(6) << r.getArea() << '\n';
    shapes.push_back(&r);

    cout << "---------------\n";

    Square s(9);
    s.printType();
    cout << fixed << setprecision(6) << s.getArea() << '\n';
    shapes.push_back(&s);

    cout << "---------------\n";

    Circle c(10);
    c.printType();
    cout << fixed << setprecision(6) << c.getArea() << '\n';
    shapes.push_back(&c);

    cout << "---------------\n";

    auto shapeWithMaxArea = max_element(shapes.begin(), shapes.end(), [&](Shape const *lhs, Shape const *rhs) -> bool {
       return rhs->getArea() > lhs->getArea();
    });

    cout << "Shape with max area is " << (*shapeWithMaxArea)->getType() << "(area: " << (*shapeWithMaxArea)->getArea() << ")\n";
} catch(exception& ex) {
    cerr << "Exception occurred:\t" << ex.what() << '\n';
}
