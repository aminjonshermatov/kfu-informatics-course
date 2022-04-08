//
// Created by aminjonshermatov on 9/20/2021.
//

#ifndef INFORMATICS_POINT3D_H
#define INFORMATICS_POINT3D_H


#include <ostream>

class Point3D {
public:
    Point3D();
    Point3D(int, int, int);
    Point3D(const Point3D&);

    int getX() const;
    void setX(int);

    int getY() const;
    void setY(int);

    int getZ() const;
    void setZ(int);

    bool operator==(const Point3D&) const;
    bool operator!=(const Point3D&) const;

    friend std::ostream &operator<<(std::ostream&, const Point3D&);

private:
    int _x{}, _y{}, _z{};
};


#endif //INFORMATICS_POINT3D_H
