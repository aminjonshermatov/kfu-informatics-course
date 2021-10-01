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
    Vector3D(Point3D*, Point3D*);
    Vector3D(Vector3D*);

    Point3D *getStart() const;
    void setStart(Point3D*);

    Point3D *getAnEnd() const;
    void setAnEnd(Point3D*);

    bool operator==(const Vector3D&) const;
    bool operator!=(const Vector3D&) const;

    friend std::ostream &operator<<(std::ostream&, const Vector3D&);

    double getLen() const;
private:
    Point3D *_start, *_end;
};


#endif //INFORMATICS_VECTOR3D_H
