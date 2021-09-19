//
// Created by aminjonshermatov on 19.09.2021.
//

#ifndef INFORMATICS_STRAIGHTLINE_H
#define INFORMATICS_STRAIGHTLINE_H

#include <utility>
#include <iostream>
#include <exception>

using pDD = std::pair<double, double>;

// y = k*x + b
class StraightLine {
public:
    StraightLine();
    StraightLine(double k, double b);
    StraightLine(const StraightLine &sl);


    void rotate_line(double p);
    void parallel_transfer(double d);
    pDD lines_intersection(const StraightLine *sl);
    bool isParallel(const StraightLine *sl);
    bool operator==(const StraightLine &sl) const;

    double getK() const;
    void setK(double k);

    double getB() const;
    void setB(double b);

    friend std::ostream &operator<<(std::ostream &os, const StraightLine &line);

private:
    double k, b;
};


#endif //INFORMATICS_STRAIGHTLINE_H
