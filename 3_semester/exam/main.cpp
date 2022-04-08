//
// Created by aminjonshermatov on 1/17/2022.
//

#include <iostream>
#include "BoolMatrix.h"
#include "dynamic_array.h"

using namespace std;

void TestBoolMatrix {
    BoolMatrix matrix;

    ifstream inFile("../3_semester/class_work/input.txt");

    if (!inFile) {
        cout << "File is not found" << '\n';
        exit(0);
    }

    inFile >> matrix;

    cout << matrix;
    cout << matrix.Tr();
};

void TestDynamicArray {
    dynamic_array<int> arr{4};

    cout << arr;
};

int main() {
    TestBoolMatrix();

    return 0;
}