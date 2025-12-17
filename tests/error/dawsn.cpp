#include <cephes/error.h>
#include <xtest.hpp>
#include <random>

TEST(Dawson, SpecialValues) {
    // x = 0 -> D(0) = 0
    EXPECT_EQ(cephes::dawsn(0.0), 0.0);
    EXPECT_EQ(cephes::dawsn(-0.0), -0.0);

    // +-Inf, NaN
    EXPECT_EQ(cephes::dawsn(xtest::Inf64), 0.0);
    EXPECT_EQ(cephes::dawsn(-xtest::Inf64), 0.0);
    EXPECT_TRUE(std::isnan(cephes::dawsn(xtest::NaN64)));
}

TEST(Dawson, OddPropertyRandom) {
    // Odd function: D(-x) = -D(x)
    EXPECT_REL_NEAR_F64(cephes::dawsn(-1.0), -cephes::dawsn(1.0));

    std::mt19937 rng(0xC0FFEEu);
    std::uniform_real_distribution<double> dist(0.0, 10.0);
    for (int i = 0; i < 128; ++i) {
        double x = dist(rng);
        EXPECT_REL_NEAR_F64(cephes::dawsn(-x), -cephes::dawsn(x));
    }
}
