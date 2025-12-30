#include <cephes/bessel.h>
#include <xtest.hpp>
#include <random>

TEST(BesselI1Exp, SpecialValues) {
    EXPECT_TRUE(std::isnan(cephes::i1e(xtest::NaN64)));
    EXPECT_TRUE(std::isnan(cephes::i1e(-xtest::NaN64)));

    EXPECT_EQ(cephes::i1e(0.0), 0.0);
}

TEST(BesselI1Exp, OddPropertyRandom) {
    // Odd function: i1e(-z) = -i1e(z)
    std::mt19937 rng(0xC0FFEEu);
    std::uniform_real_distribution<double> dist(0.0, 1e10);
    for (int i = 0; i < 128; ++i) {
        double x = dist(rng);
        EXPECT_REL_NEAR_F64(cephes::i1e(-x), -cephes::i1e(x));
    }
}

/**
    Table[NumberForm[Exp[-Abs[x]]*BesselI[1, x], 16],
        {x, {0.0, -10., 1.0, 8.0, 9.0, 10.0, 100.}}]
 */
TEST(BesselI1Exp, Branches) {
    // x < 0
    EXPECT_REL_NEAR_F64(cephes::i1e(-0.0), 0.0);
    EXPECT_REL_NEAR_F64(cephes::i1e(-10.0), -0.1212626813844555);

    // x <= 8.0
    EXPECT_REL_NEAR_F64(cephes::i1e(1.0), 0.2079104153497085);
    EXPECT_REL_NEAR_F64(cephes::i1e(8.0), 0.1341424932926982);

    // x > 8.0
    EXPECT_REL_NEAR_F64(cephes::i1e(9.0), 0.1272249839358912);
    EXPECT_REL_NEAR_F64(cephes::i1e(10.0), 0.1212626813844555);
    EXPECT_REL_NEAR_F64(cephes::i1e(100.0), 0.03974415302513026);
}
