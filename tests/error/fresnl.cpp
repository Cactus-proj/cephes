#include <cephes/error.h>
#include <random>
#include <xtest.hpp>

TEST(Fresnel, SpecialValues) {
    double s, c;
    // x = 0 -> S(0) = 0, C(0) = 0
    EXPECT_EQ(cephes::fresnl(0.0, &s, &c), 0);
    EXPECT_EQ(s, 0.0);
    EXPECT_EQ(c, 0.0);

    // +-Inf
    EXPECT_EQ(cephes::fresnl(xtest::Inf64, &s, &c), 0);
    EXPECT_REL_NEAR_F64(s, 0.5);
    EXPECT_REL_NEAR_F64(c, 0.5);
    EXPECT_EQ(cephes::fresnl(-xtest::Inf64, &s, &c), 0);
    EXPECT_REL_NEAR_F64(s, -0.5);
    EXPECT_REL_NEAR_F64(c, -0.5);
    // NaN
    EXPECT_EQ(cephes::fresnl(xtest::NaN64, &s, &c), 0);
    EXPECT_TRUE(std::isnan(s));
    EXPECT_TRUE(std::isnan(c));

    // Large-argument limit: for big x -> S(x) ≈ 0.5, C(x) ≈ 0.5
    //  N[FresnelS[10^20], 18] = 0.500000000000000000
    //  N[FresnelC[10^20], 18] = 0.500000000000000000
    EXPECT_EQ(cephes::fresnl(1e20, &s, &c), 0);
    EXPECT_REL_NEAR_F64(s, 0.5);
    EXPECT_REL_NEAR_F64(c, 0.5);
}

TEST(Fresnel, OddPropertyRandom) {
    // Odd functions: S(-x) = -S(x), C(-x) = -C(x)
    double s_pos, c_pos, s_neg, c_neg;
    EXPECT_EQ(cephes::fresnl(1.0, &s_pos, &c_pos), 0);
    EXPECT_EQ(cephes::fresnl(-1.0, &s_neg, &c_neg), 0);
    EXPECT_REL_NEAR_F64(s_neg, -s_pos);
    EXPECT_REL_NEAR_F64(c_neg, -c_pos);

    std::mt19937 rng(0xC0FFEEu);
    std::uniform_real_distribution<double> dist(0.0, 10.0);
    for (int i = 0; i < 128; ++i) {
        double x = dist(rng);
        double s_pos, c_pos, s_neg, c_neg;
        EXPECT_EQ(cephes::fresnl(x, &s_pos, &c_pos), 0);
        EXPECT_EQ(cephes::fresnl(-x, &s_neg, &c_neg), 0);
        EXPECT_REL_NEAR_F64(s_neg, -s_pos);
        EXPECT_REL_NEAR_F64(c_neg, -c_pos);
    }
}
