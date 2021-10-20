//
// Created by aminjonshermatov on 10/20/2021.
//

#include "MinHeap.h"

#define all(x) begin(x), end(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;

int main() try {
    vector<ll> v = {1,2,3,4,5,6};

    sort(all(v), [&](ll a, ll b) -> bool {
        return a < b;
    });

    MinHeap<ll> h_1;

    for (const auto& el : {7,1,90,7,3})
        h_1.insert(el);

    for (ll i = 0; i < 5; ++i) {
         cout << h_1.extract() << ' ';
    }
    cout << '\n';

//    MinHeap<int> h_2({4, 3, 1, 6, 8, 90}, [&](int lhs, int rhs) -> bool {
//        return lhs < rhs;
//    });

    MinHeap<int> h_2(5, [&](int lhs, int rhs) -> bool {
        return lhs < rhs;
    });

    for (ll i = 0; i < 6; ++i) {
        cout << h_2.extract() << ' ';
    }

    return 0;
} catch(exception& ex) {
    cout << ex.what() << '\n';
}
