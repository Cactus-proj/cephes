#include <xtest.hpp>
#include <cephes/bessel.h>

/*
    Table[NumberForm[BesselY[1, x], 16],
        {x, {0.0, -10., 1.0, 8.0, 9.0, 10.0, 100.}}]
*/
TEST(BesselY1, Branches) {
    EXPECT_LE(cephes::y1(0.0), -1.0e308);  // -Inf

    // x < 0
    // EXPECT_REL_NEAR_F64(cephes::y1(-10.0), );

    // // x <= 8.0
    // EXPECT_REL_NEAR_F64(cephes::y1(1.0), );
    // EXPECT_REL_NEAR_F64(cephes::y1(8.0), );

    // // x > 8.0
    // EXPECT_REL_NEAR_F64(cephes::y1(9.0),  );
    // EXPECT_REL_NEAR_F64(cephes::y1(10.0), );
    // EXPECT_REL_NEAR_F64(cephes::y1(100.0), );
}
