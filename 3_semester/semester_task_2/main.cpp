#include "bits/stdc++.h"

using namespace std;

#include "src/Polynomial.h"
#include "test/TestPolynomial.h"

int main() try {
    TestPolynomial();
    return 0;
} catch (const exception &ex) {
    cerr << "Exception occurred:\t" << ex.what() << '\n';
}