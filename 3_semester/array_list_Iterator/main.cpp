//
// Created by aminjonshermatov on 12/3/2021.
//

#include "bits/stdc++.h"

#include "ArrayList.h"

using namespace std;

int main() {
    ArrayList<int> arr{1,2,3,4,5,6};

    // standard
    cout << "standard:\t";
    auto it = arr.begin();
    *it = 2;
    while (it != arr.end()) {
        cout << *it << ' ';
        ++it;
    }
    cout << '\n';

    // reversed
    cout << "reversed:\t";
    auto rit = arr.rbegin();
    while (rit != arr.rend()) {
        cout << *rit << ' ';
        ++rit;
    }
    cout << '\n';

    auto cit = arr.cbegin();
    // *cit = 3; error

    // range_based for
    for (const auto& el : arr) cout << el << ' ';
    cout << '\n';
}