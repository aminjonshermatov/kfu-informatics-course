//
// Created by aminjonshermatov on 9/20/2021.
//

#include "Vector3D.h"

Vector3D::Vector3D() {
    this->setStart(new Point3D());
    this->setAnEnd(new Point3D());
}

Vector3D::Vector3D(Point3D *startP, Point3D *endP) {
    this->setStart(startP);
    this->setAnEnd(endP);
}

Vector3D::Vector3D(Vector3D *v) {
    this->setStart(v->getStart());
    this->setAnEnd(v->getAnEnd());
}

Point3D *Vector3D::getStart() const {
    return this->_start;
}

void Vector3D::setStart(Point3D *start) {
    this->_start = start;
}

Point3D *Vector3D::getAnEnd() const {
    return this->_end;
}

void Vector3D::setAnEnd(Point3D *anEnd) {
    this->_end = anEnd;
}

bool Vector3D::operator==(const Vector3D &v) const {
    return *this->_start == *v._start && *this->_end == *v._end;
}

bool Vector3D::operator!=(const Vector3D &v) const {
    return !this->operator==(v);
}

std::ostream &operator<<(std::ostream &os, const Vector3D &v) {
    return os << "start: " << *v._start << " end: " << *v._end;
}

double Vector3D::getLen() const {
    return sqrt(
            pow(this->getAnEnd()->getX() - this->getStart()->getX(), 2) +
            pow(this->getAnEnd()->getY() - this->getStart()->getY(), 2) +
            pow(this->getAnEnd()->getZ() - this->getStart()->getZ(), 2)
    );
};
