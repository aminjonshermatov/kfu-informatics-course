#include "bits/stdc++.h"

using namespace std;

#include "SorterLinkedList.h"

void TestLinkedList() {
    LinkedList<int> ll{};

    ll.add_after(1);
    ll.add_after(2);
    ll.add_after(3);

    auto it = ll.iterator();

    while (!it.isNull()) {
        cout << it << ' ';
        it++;
    }
    cout << '\n';

    cout << ll << '\n';

    it = ll.iterator();
    cout << it << '\n';
    ll.reset();
    it = ll.iterator();
    cout << it << '\n';
    ll.move();
    it = ll.iterator();
    cout << it << '\n';
    ll.del();
    it = ll.iterator();
    cout << it << '\n';
    cout << ll << '\n';
    ll.reset();
    it = ll.iterator();
    cout << it << '\n';
    ll.add_before(-1);
    cout << ll << '\n';
}

void TestSortedLinkedList() {
    SorterLinkedList<int> sll;
    sll.add_before(1);
    sll.add_before(3);
    sll.add_before(5);
    sll.add_after(4);
    sll.add_before(2);

    auto it = sll.iterator();

    cout << it << '\n';
    ++it;
    cout << it << '\n';
    sll.move(3);
    it = sll.iterator();
    cout << it << '\n';
    cout << sll;
}

int main() try {
    TestLinkedList();
//    TestSortedLinkedList();
} catch (exception& ex) {
    cerr << "Exception occurred:\t" << ex.what() << '\n';
}