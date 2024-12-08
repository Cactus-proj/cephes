#include <xtest.hpp>
#include <cephes/bessel.h>

/*
    Table[NumberForm[Exp[-Abs[x]]*BesselY[nv, x], 16],
        {nv, {0, 1, 10}},
        {x, {0.0, 1.0, 8.0, 9.0, 1.0, 100.}}]
*/
TEST(BesselYn, Branches) {
    EXPECT_LE(cephes::yn(0, 0.0), -1.0e308);  // -Inf
    EXPECT_LE(cephes::yn(1, 0.0), -1.0e308);  // -Inf
    EXPECT_LE(cephes::yn(10, 0.0), -1.0e308);  // -Inf

    // x < 0
    // EXPECT_REL_NEAR_F64(cephes::yn(-10.0), );

    // // x <= 8.0
    // EXPECT_REL_NEAR_F64(cephes::yn(1.0), );
    // EXPECT_REL_NEAR_F64(cephes::yn(8.0), );

    // // x > 8.0
    // EXPECT_REL_NEAR_F64(cephes::yn(9.0),  );
    // EXPECT_REL_NEAR_F64(cephes::yn(10.0), );
    // EXPECT_REL_NEAR_F64(cephes::yn(100.0), );
}
