//
// Created by aminjonshermatov on 9/20/2021.
//

#include "Point3D.h"

Point3D::Point3D() {
    this->setX(0);
    this->setY(0);
    this->setZ(0);
}

Point3D::Point3D(int x, int y, int z) {
    this->setX(x);
    this->setY(y);
    this->setZ(z);
}

Point3D::Point3D(const Point3D &p) {
    this->setX(p.getX());
    this->setY(p.getY());
    this->setZ(p.getZ());
}

int Point3D::getX() const {
    return this->x;
}

void Point3D::setX(int x) {
    this->x = x;
}

int Point3D::getY() const {
    return this->y;
}

void Point3D::setY(int y) {
    this->y = y;
}

int Point3D::getZ() const {
    return this->z;
}

void Point3D::setZ(int z) {
    this->z = z;
}

bool Point3D::operator==(const Point3D &p) const {
    return this->x == p.x && this->y == p.y && this->z == p.z;
}

bool Point3D::operator!=(const Point3D &p) const {
    return !this->operator==(p);
}

std::ostream &operator<<(std::ostream &os, const Point3D &p) {
    return os << "(" << p.getX() << ", " << p.getY() << ", " << p.getZ() << ")";
}
