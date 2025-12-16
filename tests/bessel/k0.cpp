#include <cephes/bessel.h>
#include <xtest.hpp>

/*
    Table[NumberForm[BesselK[0, x], 16],
        {x, {0.0, -10., 1.0, 8.0, 9.0, 10.0, 100.}}]
*/
TEST(BesselK0, Branches) {
    EXPECT_GT(cephes::k0(0.0), 1.0e308); // +Inf

    // x < 0
    // EXPECT_REL_NEAR_F64(cephes::k0(-10.0), );

    // // x <= 8.0
    // EXPECT_REL_NEAR_F64(cephes::k0(1.0), );
    // EXPECT_REL_NEAR_F64(cephes::k0(8.0), );

    // // x > 8.0
    // EXPECT_REL_NEAR_F64(cephes::k0(9.0),  );
    // EXPECT_REL_NEAR_F64(cephes::k0(10.0), );
    // EXPECT_REL_NEAR_F64(cephes::k0(100.0), );
}
