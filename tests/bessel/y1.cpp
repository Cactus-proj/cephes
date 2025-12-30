#include <cephes/bessel.h>
#include <xtest.hpp>

TEST(BesselY1, BrokenTests) {
    GTEST_SKIP() << "Broken Tests";
    /* Wolfram
        BesselY[1, 0.0] == ComplexInfinity
        BesselY[1, Infinity] == 0
    */
    EXPECT_TRUE(std::isinf(cephes::y1(0.0)));
    EXPECT_EQ(cephes::y1(0.0), -xtest::Inf64);  // TODO: -1.7976931348623157e+308
    EXPECT_EQ(cephes::y1(xtest::Inf64), 0.0);   // TODO: NaN
}

TEST(BesselY1, SpecialValues) {
    EXPECT_TRUE(std::isnan(cephes::y1(xtest::NaN64)));
    EXPECT_TRUE(std::isnan(cephes::y1(-xtest::NaN64)));

    // // y1(0) = -Inf
    // EXPECT_TRUE(std::isinf(cephes::y1(0.0)));
    // EXPECT_EQ(cephes::y1(0.0), -xtest::Inf64);  // TODO: -1.7976931348623157e+308
    // // y1(Inf) = 0.0
    // EXPECT_EQ(cephes::y1(xtest::Inf64), 0.0);    // TODO: NaN
    // // y1(-Inf) = NaN (Domain error)
    // EXPECT_TRUE(std::isnan(cephes::y1(-xtest::Inf64)));
}

/*
    Table[NumberForm[BesselY[1, x], 16],
        {x, {0.0, -10., 1.0, 8.0, 9.0, 10.0, 100.}}]
*/
TEST(BesselY1, Branches) {
    // x <= 0.0
    EXPECT_LE(cephes::y1(0.0), -1.0e308); // -Inf
    EXPECT_LE(cephes::y1(-10.0), -1.0e308); // -Inf

    // x <= 5.0
    EXPECT_REL_NEAR_F64(cephes::y1(1.0), -0.7812128213002887);
    EXPECT_REL_NEAR_F64(cephes::y1(8.0), -0.1580604617312475);

    // x > 5.0
    EXPECT_REL_NEAR_F64(cephes::y1(9.0),  0.1043145751967159);
    EXPECT_REL_NEAR_F64(cephes::y1(10.0), 0.2490154242069539);
    EXPECT_REL_NEAR_F64(cephes::y1(100.0), -0.02037231200275932);
}
