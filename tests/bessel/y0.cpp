#include <cephes/bessel.h>
#include <xtest.hpp>

/*
    Table[NumberForm[BesselY[0, x], 16],
        {x, {0.0, -10., 1.0, 8.0, 9.0, 10.0, 100.}}]
*/
TEST(BesselY0, Branches)
{
    EXPECT_LE(cephes::y0(0.0), -1.0e308); // -Inf

    // x < 0
    // EXPECT_REL_NEAR_F64(cephes::y0(-10.0), );

    // // x <= 8.0
    // EXPECT_REL_NEAR_F64(cephes::y0(1.0), );
    // EXPECT_REL_NEAR_F64(cephes::y0(8.0), );

    // // x > 8.0
    // EXPECT_REL_NEAR_F64(cephes::y0(9.0),  );
    // EXPECT_REL_NEAR_F64(cephes::y0(10.0), );
    // EXPECT_REL_NEAR_F64(cephes::y0(100.0), );
}
