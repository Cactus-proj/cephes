#include <xtest.hpp>
#include <cephes/bessel.h>

/*
    Table[NumberForm[Exp[-Abs[x]]*BesselK[1, x], 16],
        {x, {0.0, -10., 1.0, 8.0, 9.0, 10.0, 100.}}]
*/
TEST(BesselK1Exp, Branches) {
    EXPECT_GT(cephes::k1e(0.0), 1.0e308);  // +Inf

    // x < 0
    // EXPECT_REL_NEAR_F64(cephes::k1e(-10.0), );

    // // x <= 8.0
    // EXPECT_REL_NEAR_F64(cephes::k1e(1.0), );
    // EXPECT_REL_NEAR_F64(cephes::k1e(8.0), );

    // // x > 8.0
    // EXPECT_REL_NEAR_F64(cephes::k1e(9.0),  );
    // EXPECT_REL_NEAR_F64(cephes::k1e(10.0), );
    // EXPECT_REL_NEAR_F64(cephes::k1e(100.0), );
}
