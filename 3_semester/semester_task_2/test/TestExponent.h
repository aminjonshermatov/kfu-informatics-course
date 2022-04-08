//
// Created by aminjonshermatov on 12/10/2021.
//

#ifndef INFORMATICS_TESTEXPONENT_H
#define INFORMATICS_TESTEXPONENT_H

#include "bits/stdc++.h"

using namespace std;

void TestExponent() {
    {
        // e^(10)
        Exponent<> exponent1(10);

        // e^(2x^2+3x+4)
        Exponent<> exponent2({2,3,4});

        {
            // e^(10) * e^(2x^2+3x+4) = e^(2x^2+3x+14)
            assert(((exponent1 * exponent2) == Exponent<>{{2, 3, 14}}));

            assert((exponent1 == Exponent<>{10}));
            assert((exponent2 == Exponent<>{{2, 3, 4}}));
        }
        {
            // e^(10) / e^(2x^2+3x+4) = e^(-2x^2-3x+6)
            assert(((exponent1 / exponent2) == Exponent<>{{-2, -3, 6}}));

            assert((exponent1 == Exponent<>{10}));
            assert((exponent2 == Exponent<>{{2, 3, 4}}));
        }
        {
            // inverse(e^(x^2+x-2)) = e^(-x^2-x+2)
            assert(((Exponent<>{{1, 1, -2}}).inverse() == Exponent<>{{-1, -1, 2}}));
        }
        {
            // inverse(e^(0)) = e^(0)
            assert(((Exponent<>{0}).inverse() == Exponent<>{0}));
        }
        {
            // inverse(e^(10)) = e^(-10)
            assert(((Exponent<>{10}).inverse() == Exponent<>{-10}));
        }
        {
            auto temp{exponent1};
            // e^(2x^2+3x+14)
            temp *= exponent2;
            assert((temp == Exponent<>{{2, 3, 14}}));

            assert((exponent1 == Exponent<>{10}));
            assert((exponent2 == Exponent<>{{2, 3, 4}}));
        }
        {
            auto temp{exponent1};
            // e^(-2x^2-3x+6)
            temp /= exponent2;
            assert((temp == Exponent<>{{-2, -3, 6}}));

            assert((exponent1 == Exponent<>{10}));
            assert((exponent2 == Exponent<>{{2, 3, 4}}));
        }
    }
    {
        // e^(x^2-3x+4)
        Exponent<> exponent1({1,-3,4});

        // e^(x^3-2x^2+3x-9)
        Exponent<> exponent2({1,-2,3,-9});

        {
            // e^(x^2-3x+4) * e^(x^3-2x^2+3x-9) = e^(x^3-x^2-5)
            assert(((exponent1 * exponent2) == Exponent<>{{1, -1, 0, -5}}));

            assert((exponent1 == Exponent<>{{1,-3,4}}));
            assert((exponent2 == Exponent<>{{1,-2,3,-9}}));
        }
        {
            // e^(x^2-3x+4) / e^(x^3-2x^2+3x-9) = e^(-x^3+3x^2-6x+13)
            assert(((exponent1 / exponent2) == Exponent<>{{-1, 3, -6, 13}}));

            assert((exponent1 == Exponent<>{{1,-3,4}}));
            assert((exponent2 == Exponent<>{{1,-2,3,-9}}));
        }
        {
            // inverse(e^(x^2-3x+4)) = e^(-x^2+3x-4)
            assert((exponent1.inverse() == Exponent<>{{-1, 3, -4}}));
        }
        {
            // inverse(e^(x^3-2x^2+3x-9)) = e^(-x^3+2x^2-3x+9)
            assert((exponent2.inverse() == Exponent<>{{-1, 2, -3, 9}}));
        }
        {
            auto temp{exponent1};
            // e^(x^3-x^2-5)
            temp *= exponent2;
            assert((temp == Exponent<>{{1, -1, 0, -5}}));

            assert((exponent1 == Exponent<>{{1,-3,4}}));
            assert((exponent2 == Exponent<>{{1,-2,3,-9}}));
        }
        {
            auto temp{exponent1};
            // e^(-x^3+3x^2-6x+13)
            temp /= exponent2;
            assert((temp == Exponent<>{{-1, 3, -6, 13}}));

            assert((exponent1 == Exponent<>{{1,-3,4}}));
            assert((exponent2 == Exponent<>{{1,-2,3,-9}}));
        }
    }
    {
        // e^(-x^2+x-2)
        Exponent<> exponent1({-1,1,-2});

        // e^(x^2-x+2)
        Exponent<> exponent2({1,-1,2});

        assert(((exponent1 * exponent2) == Exponent<>{{0, 0, 0}}));
    }

    cout << '\t' << "Exponent Tests Successfully passed!" << '\n';
}

#endif //INFORMATICS_TESTEXPONENT_H
