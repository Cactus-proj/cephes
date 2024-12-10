#include <cephes/bessel.h>
#include <xtest.hpp>

/**
    Table[NumberForm[Exp[-Abs[x]]*BesselI[nv, x], 16],
        {x, {0.0, -10., 1.0, 8.0, 9.0, 10.0, 100.}}, {nv, {0}}]
 */
TEST(BesselI0Exp, Branches)
{
    EXPECT_REL_NEAR_F64(cephes::i0e(0.0), 1.0);

    // x < 0
    EXPECT_REL_NEAR_F64(cephes::i0e(-0.0), 1.0);
    EXPECT_REL_NEAR_F64(cephes::i0e(-10.0), 0.1278333371634286);

    // x <= 8.0
    EXPECT_REL_NEAR_F64(cephes::i0e(1.0), 0.4657596075936404);
    EXPECT_REL_NEAR_F64(cephes::i0e(8.0), 0.1434317818568503);

    // x > 8.0
    EXPECT_REL_NEAR_F64(cephes::i0e(9.0), 0.134959524581723);
    EXPECT_REL_NEAR_F64(cephes::i0e(10.0), 0.1278333371634286);
    EXPECT_REL_NEAR_F64(cephes::i0e(100.0), 0.03994437929909669);
}
