#include <cephes/bessel.h>
#include <xtest.hpp>
#include <random>

TEST(BesselI1, SpecialValues) {
    EXPECT_TRUE(std::isnan(cephes::i1(xtest::NaN64)));
    EXPECT_TRUE(std::isnan(cephes::i1(-xtest::NaN64)));

    EXPECT_EQ(cephes::i1(0.0), 0.0);
}

TEST(BesselI1, OddPropertyRandom) {
    // Odd function: i1(-z) = -i1(z)
    std::mt19937 rng(0xC0FFEEu);
    std::uniform_real_distribution<double> dist(0.0, 1e10);
    for (int i = 0; i < 128; ++i) {
        double x = dist(rng);
        EXPECT_REL_NEAR_F64(cephes::i1(-x), -cephes::i1(x));
    }
}

/*
    Table[NumberForm[BesselI[1, x], 16],
        {x, {0.0, -10., 1.0, 8.0, 9.0, 10.0, 100.}}]
*/
TEST(BesselI1, Branches) {
    EXPECT_REL_NEAR_F64(cephes::i1(0.0), 0.0);

    // x < 0
    EXPECT_REL_NEAR_F64(cephes::i1(-0.0), 0.0);
    EXPECT_REL_NEAR_F64(cephes::i1(-10.0), -2670.988303701254);

    // x <= 8.0
    EXPECT_REL_NEAR_F64(cephes::i1(1.0), 0.5651591039924851);
    EXPECT_REL_NEAR_F64(cephes::i1(8.0), 399.8731367825601);

    // x > 8.0
    EXPECT_REL_NEAR_F64(cephes::i1(9.0), 1030.914722516956);
    EXPECT_REL_NEAR_F64(cephes::i1(10.0), 2670.988303701254);
    EXPECT_REL_NEAR_F64(cephes::i1(100.0), 1.068369390338163e+42);
}
