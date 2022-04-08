//
// Created by aminjonshermatov on 12/8/2021.
//

#ifndef INFORMATICS_TESTPOLYNOMIAL_H
#define INFORMATICS_TESTPOLYNOMIAL_H

#include "bits/stdc++.h"

using namespace std;

void TestPolynomial() {
    {
        // (10)
        Polynomial<> polynomial1(10);
        // (2x^2+3x+4)
        Polynomial<> polynomial2({2,3,4});

        {
            // (10) + (2x^2+3x+4) = (2x^2+3x+14)
            assert(((polynomial1 + polynomial2) == Polynomial<>{{2, 3, 14}}));

            assert((polynomial1 == Polynomial<>{10}));
            assert((polynomial2 == Polynomial<>{{2, 3, 4}}));
        }
        {
            // (-2x^2-3x+6)
            assert(((polynomial1 - polynomial2) == Polynomial<>{{-2, -3, 6}}));

            assert((polynomial1 == Polynomial<>{10}));
            assert((polynomial2 == Polynomial<>{{2, 3, 4}}));
        }
        {
            // (20x^2+30x+40)
            assert(((polynomial1 * polynomial2) == Polynomial<>{{20, 30, 40}}));

            assert((polynomial1 == Polynomial<>{10}));
            assert((polynomial2 == Polynomial<>{{2, 3, 4}}));
        }
        {
            auto temp{polynomial1};
            // (2x^2+3x+14)
            temp += polynomial2;
            assert((temp == Polynomial<>{{2, 3, 14}}));

            assert((polynomial1 == Polynomial<>{10}));
            assert((polynomial2 == Polynomial<>{{2, 3, 4}}));
        }
        {
            auto temp{polynomial1};
            // (-2x^2-3x+6)
            temp -= polynomial2;
            assert((temp == Polynomial<>{{-2, -3, 6}}));

            assert((polynomial1 == Polynomial<>{10}));
            assert((polynomial2 == Polynomial<>{{2, 3, 4}}));
        }
        {
            auto temp{polynomial1};
            // (20x^2+30x+40)
            temp *= polynomial2;
            assert((temp == Polynomial<>{{20, 30, 40}}));

            assert((polynomial1 == Polynomial<>{10}));
            assert((polynomial2 == Polynomial<>{{2, 3, 4}}));
        }
    }
    {
        // (x+2)
        Polynomial<> polynomial1({1, 2});
        // (2x-6)
        Polynomial<> polynomial2({2, -6});

        {
            // (3x-4)
            assert(((polynomial1 + polynomial2) == Polynomial<>{{3, -4}}));

            assert((polynomial1 == Polynomial<>{{1, 2}}));
            assert((polynomial2 == Polynomial<>{{2, -6}}));
        }
        {
            // (-x+8)
            assert(((polynomial1 - polynomial2) == Polynomial<>{{-1, 8}}));

            assert((polynomial1 == Polynomial<>{{1, 2}}));
            assert((polynomial2 == Polynomial<>{{2, -6}}));
        }
        {
            // (2x^2-2x-12)
            assert(((polynomial1 * polynomial2) == Polynomial<>{{2, -2, -12}}));

            assert((polynomial1 == Polynomial<>{{1, 2}}));
            assert((polynomial2 == Polynomial<>{{2, -6}}));
        }
        {
            auto temp{polynomial1};
            // (3x-4)
            temp += polynomial2;
            assert((temp == Polynomial<>{{3, -4}}));

            assert((polynomial1 == Polynomial<>{{1, 2}}));
            assert((polynomial2 == Polynomial<>{{2, -6}}));
        }
        {
            auto temp{polynomial1};
            // (-x+8)
            temp -= polynomial2;
            assert((temp == Polynomial<>{{-1, 8}}));

            assert((polynomial1 == Polynomial<>{{1, 2}}));
            assert((polynomial2 == Polynomial<>{{2, -6}}));
        }
        {
            auto temp{polynomial1};
            // (2x^2-2x-12)
            temp *= polynomial2;
            assert((temp == Polynomial<>{{2, -2, -12}}));

            assert((polynomial1 == Polynomial<>{{1, 2}}));
            assert((polynomial2 == Polynomial<>{{2, -6}}));
        }
    }
    {
        // (-x+1)
        Polynomial<> polynomial1({-1, 1});
        // (x-1)
        Polynomial<> polynomial2({1, -1});

        // (0x+0)
        assert(((polynomial1 + polynomial2) == Polynomial<>{{0, 0}}));
    }
    {
        // (0)
        Polynomial<> polynomial1{0};
        // (x^3+2x^2+3x+4)
        Polynomial<> polynomial2{{1, 2, 3, 4}};

        // (0x^3+0x^2+0x+0)
        assert(((polynomial1 * polynomial2) == Polynomial<>{{0, 0, 0, 0}}));
    }
    {
        // (x^3+2x^2+3x+4)
        Polynomial<> polynomial({1, 2, 3, 4});

        {
            // (0^3+2*0^2+3*0+4)=(4)
            assert(polynomial(0) == 4);
        }
        {
            // (1^3+2*1^2+3*1+4)=(10)
            assert(polynomial(1) == 10);
        }
        {
            // (-1^3+2*1^2-3*1+4)=(2)
            assert(polynomial(-1) == 2);
        }
        {
            // (10^3+2*10^2+3*10+4)=(1234)
            assert(polynomial(10) == 1234);
        }
    }

    cout << '\t' << "Polynomial Tests Successfully passed!" << '\n';
}

#endif //INFORMATICS_TESTPOLYNOMIAL_H
