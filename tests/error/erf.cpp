#include <cephes/error.h>
#include <random>
#include <xtest.hpp>

TEST(Erf, SpecialValues) {
    // NaN propagates
    EXPECT_TRUE(std::isnan(cephes::erf(xtest::NaN64)));
    // erf(±0) returns ±0
    EXPECT_EQ(cephes::erf(0.0), 0.0);
    EXPECT_EQ(cephes::erf(-0.0), -0.0);
    // erf(±∞) returns ±1
    EXPECT_EQ(cephes::erf(xtest::Inf64), 1.0);
    EXPECT_EQ(cephes::erf(-xtest::Inf64), -1.0);

    // Large-argument limit: |x| >> 1 -> erf(x) -> ±1
    EXPECT_REL_NEAR_F64(cephes::erf(20.0), 1.0);
    EXPECT_REL_NEAR_F64(cephes::erf(-20.0), -1.0);
}

TEST(Erf, OddPropertyRandom) {
    // Odd function: erf(-x) = -erf(x)
    EXPECT_REL_NEAR_F64(cephes::erf(-1.0), -cephes::erf(1.0));

    std::mt19937 rng(0xC0FFEEu);
    std::uniform_real_distribution<double> dist(0.0, 10.0);
    for (int i = 0; i < 128; ++i) {
        double x = dist(rng);
        EXPECT_REL_NEAR_F64(cephes::erf(-x), -cephes::erf(x));
    }
}

TEST(Erf, Branches) {
    // fabs(x) > 1.0
    EXPECT_REL_NEAR_F64(cephes::erf(20.0), 1.0);
}
