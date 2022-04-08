//
// Created by aminjonshermatov on 10/20/2021.
//

#include "Heap.h"

#define all(x) begin(x), end(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;

enum HeapTypes { MIN, MAX };

template<typename T>
void ExtractAndPrintHeap(Heap<T>& h, HeapTypes type) {
    cout << (type == HeapTypes::MIN ? "Min" : "Max") << "Heap\n";
    size_t initialSize = h.size();
    for (size_t i = 0; i < initialSize; ++i) {
        cout << h.extractTop() << ' ';
    }
    cout << '\n';
}

int main() try {
    Heap<ll> h_1;
    for (const auto& el : {7,1,90,7,3})
        h_1.insert(el);

    ExtractAndPrintHeap(h_1, HeapTypes::MIN);

    auto minHeapLambda = [&](int lhs, int rhs) -> bool {
        return lhs < rhs;
    };

    Heap<int> h_2({4, 3, 1, 6, 8}, minHeapLambda);
    ExtractAndPrintHeap(h_2, HeapTypes::MIN);

    Heap<int> h_3({4, 3, 1, 6, 8, 90}, [&](int lhs, int rhs) -> bool {
        return lhs > rhs;
    });
    ExtractAndPrintHeap(h_3, HeapTypes::MAX);

    return 0;
} catch(const exception& ex) {
    cout << ex.what() << '\n';
}
