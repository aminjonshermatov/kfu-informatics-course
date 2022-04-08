//
// Created by aminjonshermatov on 19.09.2021.
//

#include "StraightLine.h"

StraightLine::StraightLine() {
    this->setK(0);
    this->setB(0);
}

StraightLine::StraightLine(double k, double b) {
    this->setK(k);
    this->setB(b);
}

StraightLine::StraightLine(const StraightLine& sl) {
    this->setK(sl.getK());
    this->setB(sl.getB());
}

void StraightLine::rotate_line(double p) {
    this->_k *= p;
}

void StraightLine::parallel_transfer(double d) {
    this->_b += d;
}

pDD StraightLine::lines_intersection(const StraightLine* sl) const {
    pDD point;

    if (this->getK() == sl->getK()) {
        if (this->getB() == sl->getB()) {
            throw std::runtime_error("Infinity solutions");
        }
        else
            throw std::runtime_error("No solution");
    }
    else {
        point.first = (sl->getB() - this->getB()) / (this->getK() - sl->getK());
        point.second = this->getK() * point.first + this->getB();
    }

    return point;
}

bool StraightLine::isParallel(const StraightLine* sl) const {
    return this->getK() == sl->getK();
}

bool StraightLine::operator==(const StraightLine& sl) const {
    return this->getB() == sl.getB() && this->getK() == sl.getK();
}

double StraightLine::getK() const {
    return this->_k;
}

void StraightLine::setK(double k) {
    this->_k = k;
}

double StraightLine::getB() const {
    return this->_b;
}

void StraightLine::setB(double b) {
    this->_b = b;
}

std::ostream &operator<<(std::ostream &os, const StraightLine &line) {
    os << "y(x) = ";
    if (line.getK() != 1) {
        os << line.getK() << "*";
    }
    os  << "x ";
    if (line.getB() < 0) {
        os << line.getB();
    } else if (line.getB() > 0) {
        os << "+ " << line.getB();
    }

    return os;
}
