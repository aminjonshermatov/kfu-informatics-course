//
// Created by aminjonshermatov on 10/20/2021.
//

#include "MinHeap.h"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;

int main() try {
    MinHeap<ll> h_1;

    for (const auto& el : {7,1,90,7,3})
        h_1.insert(el);

    for (ll i = 0; i < 5; ++i) {
         cout << h_1.extractMin() << ' ';
    }
    cout << '\n';

    MinHeap<int> h_2({4, 3, 1, 6, 8, 90});

    for (ll i = 0; i < 6; ++i) {
        cout << h_2.extractMin() << ' ';
    }

    return 0;
} catch(exception& ex) {
    cout << ex.what() << '\n';
}
