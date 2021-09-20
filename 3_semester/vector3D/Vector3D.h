//
// Created by aminjonshermatov on 9/20/2021.
//

#ifndef INFORMATICS_VECTOR3D_H
#define INFORMATICS_VECTOR3D_H

#include <iostream>
#include <cmath>
#include "Point3D.h"

class Vector3D {
public:
    Vector3D();
    Vector3D(Point3D* startP, Point3D* endP);
    Vector3D(Vector3D* v);

    Point3D *getStart() const;
    void setStart(Point3D *start);

    Point3D *getAnEnd() const;
    void setAnEnd(Point3D *anEnd);

    bool operator==(const Vector3D &v) const;
    bool operator!=(const Vector3D &v) const;

    friend std::ostream &operator<<(std::ostream &os, const Vector3D &d);

    double getLen() const;
private:
    Point3D *start, *end;
};


#endif //INFORMATICS_VECTOR3D_H
