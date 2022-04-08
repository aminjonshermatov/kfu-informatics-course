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
    StraightLine(double, double);
    StraightLine(const StraightLine&);


    void rotate_line(double);
    void parallel_transfer(double);
    pDD lines_intersection(const StraightLine*) const;
    bool isParallel(const StraightLine*) const;
    bool operator==(const StraightLine&) const;

    double getK() const;
    void setK(double);

    double getB() const;
    void setB(double);

    friend std::ostream &operator<<(std::ostream&, const StraightLine&);

private:
    double _k{}, _b{};
};


#endif //INFORMATICS_STRAIGHTLINE_H
