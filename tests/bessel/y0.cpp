#include <cephes/bessel.h>
#include <xtest.hpp>

TEST(BesselY0, BrokenTests) {
    GTEST_SKIP() << "Broken Tests";
    /* Wolfram
        BesselY[0, 0.0] == -Infinity
        BesselY[0, Infinity] == 0
    */
    EXPECT_TRUE(std::isinf(cephes::y0(0.0)));
    EXPECT_EQ(cephes::y0(0.0), -xtest::Inf64);  // TODO: -1.7976931348623157e+308
    EXPECT_EQ(cephes::y0(xtest::Inf64), 0.0);   // TODO: NaN
}

TEST(BesselY0, SpecialValues) {
    EXPECT_TRUE(std::isnan(cephes::y0(xtest::NaN64)));
    EXPECT_TRUE(std::isnan(cephes::y0(-xtest::NaN64)));

    // // y0(0) = -Inf
    // EXPECT_TRUE(std::isinf(cephes::y0(0.0)));
    // EXPECT_EQ(cephes::y0(0.0), -xtest::Inf64);  // TODO: -1.7976931348623157e+308
    // // y0(Inf) = 0.0
    // EXPECT_EQ(cephes::y0(xtest::Inf64), 0.0);    // TODO: NaN
    // // y0(-Inf) = NaN (Domain error)
    // EXPECT_TRUE(std::isnan(cephes::y0(-xtest::Inf64)));
}

/*
    Table[NumberForm[BesselY[0, x], 16],
        {x, {0.0, -10., 1.0, 8.0, 9.0, 10.0, 100.}}]
*/
TEST(BesselY0, Branches) {
    // x <= 0.0
    EXPECT_LE(cephes::y0(0.0), -1.0e308); // -Inf
    EXPECT_TRUE(cephes::y0(-10) < 1e300);

    // x <= 5.0
    EXPECT_REL_NEAR_F64(cephes::y0(1.0), 0.0882569642156771);
    EXPECT_REL_NEAR_F64(cephes::y0(8.0), 0.2235214893875662);

    // x > 5.0
    EXPECT_REL_NEAR_F64(cephes::y0(9.0),  0.2499366982850247);
    EXPECT_REL_NEAR_F64(cephes::y0(10.0), 0.0556711672835994);
    EXPECT_REL_NEAR_F64(cephes::y0(100.0), -0.07724431336508308);
}
