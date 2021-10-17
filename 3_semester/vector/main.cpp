//
// Created by aminjonshermatov on 10/17/2021.
//

#include "vector.h"

int main() {
    Vector<int> arr;

    for (auto& i : {1,2,3,4,5,6,7}) {
        arr.push_back(i);
    }

    std::cout << arr << '\n';
    Vector<int> arr2 = arr;
    std::cout << arr2 << '\n';

    std::cout << (arr == arr2) << '\n';
    std::cout << (arr != arr2) << '\n';

    arr.erase(4);
    std::cout << arr << '\n';
    std::cout << arr2 << '\n';

    arr2.clear();

    std::cout << arr << '\n';
    std::cout << arr2 << '\n';

    return 0;
}
