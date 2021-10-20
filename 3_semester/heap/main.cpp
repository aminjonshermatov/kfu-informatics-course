//
// Created by aminjonshermatov on 10/20/2021.
//

#include "Heap.h"

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

    Heap<ll> h_1;

    for (const auto& el : {7,1,90,7,3})
        h_1.insert(el);

    cout << "Heap 1, min:\n";
    for (ll i = 0; i < 5; ++i) {
         cout << h_1.extract() << ' ';
    }
    cout << '\n';

    auto left = [&](int lhs, int rhs) -> bool {
        return lhs < rhs;
    };

    Heap<int> h_2({4, 3, 1, 6, 8, 90}, left);

    cout << "Heap 2, min:\n";
    for (ll i = 0; i < 6; ++i) {
        cout << h_2.extract() << ' ';
    }
    cout << '\n';

    Heap<int> h_3({4, 3, 1, 6, 8, 90}, [&](int lhs, int rhs) -> bool {
        return lhs > rhs;
    });
    cout << "Heap 3, max:\n";
    for (ll i = 0; i < 6; ++i) {
        cout << h_3.extract() << ' ';
    }
    cout << '\n';

    return 0;
} catch(exception& ex) {
    cout << ex.what() << '\n';
}
