#include "bits/stdc++.h"

using namespace std;

#include "src/Polynomial.h"
#include "src/Exponent.h"
#include "src/Interactive.h"

#include "test/TestPolynomial.h"
#include "test/TestExponent.h"

int main() try {
    TestPolynomial();
    TestExponent();

    InterActive interActive;
    interActive.run();
    return 0;
} catch (const exception &ex) {
    cerr << "Exception occurred:\t" << ex.what() << '\n';
}