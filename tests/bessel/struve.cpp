#include <xtest.hpp>
#include <cephes/bessel.h>

/*
    Table[NumberForm[PolyGamma[0, x], 16],
        {x, {0.0, -10., 1.0, 8.0, 9.0, 10.0, 100.}}]
*/
TEST(StruveH, Branches) {
    // EXPECT_REL_NEAR_F64(cephes::struve(0.0, 0.0), 0.0);
    EXPECT_REL_NEAR_F64(cephes::struve(1.0, 0.0), 0.0);
}
