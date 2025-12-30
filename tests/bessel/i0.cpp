#include <cephes/bessel.h>
#include <xtest.hpp>
#include <random>

TEST(BesselI0, SpecialValues) {
    EXPECT_TRUE(std::isnan(cephes::i0(xtest::NaN64)));
    EXPECT_TRUE(std::isnan(cephes::i0(-xtest::NaN64)));

    EXPECT_EQ(cephes::i0(0.0), 1.0);
}

TEST(BesselI0, EvenPropertyRandom) {
    // Even function: i0(z) = i0(-z)
    std::mt19937 rng(0xC0FFEEu);
    std::uniform_real_distribution<double> dist(0.0, 1e10);
    for (int i = 0; i < 128; ++i) {
        double x = dist(rng);
        EXPECT_REL_NEAR_F64(cephes::i0(-x), cephes::i0(x));
    }
}

TEST(BesselI0, Branches) {
    EXPECT_REL_NEAR_F64(cephes::i0(0.0), 1.0);

    // x < 0
    EXPECT_REL_NEAR_F64(cephes::i0(-0.0), 1.0);
    EXPECT_REL_NEAR_F64(cephes::i0(-10.0), 2815.716628466253);

    // x <= 8.0
    EXPECT_REL_NEAR_F64(cephes::i0(1.0), 1.266065877752008);
    EXPECT_REL_NEAR_F64(cephes::i0(8.0), 427.5641157218048);

    // x > 8.0
    EXPECT_REL_NEAR_F64(cephes::i0(9.0), 1093.588354511374);
    EXPECT_REL_NEAR_F64(cephes::i0(10.0), 2815.716628466253);
    EXPECT_REL_NEAR_F64(cephes::i0(100.0), 1.073751707131074e42);
}
