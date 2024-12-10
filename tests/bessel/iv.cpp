#include <cephes/bessel.h>
#include <xtest.hpp>

/**
    Table[NumberForm[Exp[-Abs[x]]*BesselI[nv, x], 16],
        {nv, {0, 1}},
        {x, {0.0, 1.0, 8.0, 9.0, 1.0, 100.}}]
 */
TEST(BesselIv, Branches)
{
    EXPECT_REL_NEAR_F64(cephes::iv(0, 0.0), 1.0);
    EXPECT_REL_NEAR_F64(cephes::iv(1, 0.0), 0.0);
    EXPECT_REL_NEAR_F64(cephes::iv(-1, 0.0), 0.0);

    // x < 0
    EXPECT_REL_NEAR_F64(cephes::iv(0, -0.0), 1.0);
    // EXPECT_REL_NEAR_F64(cephes::iv(-10.0), );

    // // x <= 8.0
    // EXPECT_REL_NEAR_F64(cephes::iv(1.0), );
    // EXPECT_REL_NEAR_F64(cephes::iv(8.0), );

    // // x > 8.0
    // EXPECT_REL_NEAR_F64(cephes::iv(9.0),  );
    // EXPECT_REL_NEAR_F64(cephes::iv(10.0), );
    // EXPECT_REL_NEAR_F64(cephes::iv(100.0), );
}
