#include <cephes/bessel.h>
#include <xtest.hpp>

/*
    Table[NumberForm[BesselK[nv, x], 16],
        {nv, {0, 1, 10}},
        {x, {0.0, 1.0, 8.0, 9.0, 1.0, 100.}}]
*/
TEST(BesselYn, Branches) {
    EXPECT_GT(cephes::kn(0, 0.0), 1.0e308);  // +Inf
    EXPECT_GT(cephes::kn(1, 0.0), 1.0e308);  // +Inf
    EXPECT_GT(cephes::kn(10, 0.0), 1.0e308); // +Inf

    // x < 0
    // EXPECT_REL_NEAR_F64(cephes::kn(-10.0), );

    // // x <= 8.0
    // EXPECT_REL_NEAR_F64(cephes::kn(1.0), );
    // EXPECT_REL_NEAR_F64(cephes::kn(8.0), );

    // // x > 8.0
    // EXPECT_REL_NEAR_F64(cephes::kn(9.0),  );
    // EXPECT_REL_NEAR_F64(cephes::kn(10.0), );
    // EXPECT_REL_NEAR_F64(cephes::kn(100.0), );
}
