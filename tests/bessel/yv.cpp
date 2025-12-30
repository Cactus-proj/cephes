#include <cephes/bessel.h>
#include <xtest.hpp>

TEST(BesselYv, SpecialValues) {
    double nv;

    nv = 5 + 1.0/4;
    EXPECT_TRUE(std::isnan(cephes::yv(nv, xtest::NaN64)));
    EXPECT_TRUE(std::isnan(cephes::yv(nv, -xtest::NaN64)));
    // EXPECT_LE(cephes::yv(nv, -2.71), -1.0e308);  // -Inf
    // EXPECT_LE(cephes::yv(nv, -3.14), -1.0e308);  // -Inf
}

/*
    Table[NumberForm[Exp[-Abs[x]]*BesselY[nv, x], 16],
        {nv, {0, 1, 10}},
        {x, {0.0, 1.0, 8.0, 9.0, 1.0, 100.}}]
*/
TEST(BesselYv, Branches) {
    double nv, x;

    // if (y == v):  call yn(n, x)
    nv = 0.0;
    EXPECT_LE(cephes::yv(0+nv, 0.0), -1.0e308);  // -Inf
    EXPECT_LE(cephes::yv(5+nv, 0.0), -1.0e308);  // -Inf
    EXPECT_LE(cephes::yv(10+nv, 0.0), -1.0e308); // -Inf

    // float order
    nv = 1 / 4;
    EXPECT_LE(cephes::yv(0+nv, 0.0), -1.0e308);  // -Inf
    EXPECT_LE(cephes::yv(5+nv, 0.0), -1.0e308);  // -Inf
    EXPECT_LE(cephes::yv(10+nv, 0.0), -1.0e308); // -Inf
}
