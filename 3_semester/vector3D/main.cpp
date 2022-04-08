//
// Created by aminjonshermatov on 9/20/2021.
//

#include "Vector3D.h"

int main() try {
    auto* pStart = new Point3D(1,2,3);
    std::cout << "pStart: " << *pStart << "\n";
    auto* pEnd = new Point3D(4,5,6);
    std::cout << "pEnd: " << *pEnd << "\n";

    auto* v1 = new Vector3D(pStart, pEnd);

    std::cout << "vector: " << *v1 << "\n";
    std::cout << "vector len: " << v1->getLen() << "\n";

    auto* v1_copy = new Vector3D(v1);
    std::cout << "equality with pointers: v1: " << v1 << ", copy: " << v1_copy << " == " << (v1 == v1_copy) << "\n";
    std::cout << "equality with override operator(==) " << (*v1 == *v1_copy) << "\n";
} catch (std::exception& ex) {
    std::cout << ex.what() << "\n";
};

