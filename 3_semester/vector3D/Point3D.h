//
// Created by aminjonshermatov on 9/20/2021.
//

#ifndef INFORMATICS_POINT3D_H
#define INFORMATICS_POINT3D_H


#include <ostream>

class Point3D {
public:
    Point3D();
    Point3D(int x, int y, int z);
    Point3D(const Point3D& p);

    int getX() const;
    void setX(int x);

    int getY() const;
    void setY(int y);

    int getZ() const;
    void setZ(int z);

    bool operator==(const Point3D &p) const;
    bool operator!=(const Point3D &p) const;

    friend std::ostream &operator<<(std::ostream &os, const Point3D &p);

private:
    int x{}, y{}, z{};
};


#endif //INFORMATICS_POINT3D_H
