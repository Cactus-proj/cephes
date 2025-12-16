#include <cephes/bessel.h>
#include <xtest.hpp>

/**
    Table[NumberForm[Exp[-Abs[x]]*BesselI[1, x], 16],
        {x, {0.0, -10., 1.0, 8.0, 9.0, 10.0, 100.}}]
 */
TEST(BesselI1Exp, Branches) {
    EXPECT_REL_NEAR_F64(cephes::i1e(0.0), 0.0);

    // x < 0
    EXPECT_REL_NEAR_F64(cephes::i1e(-0.0), 0.0);
    // EXPECT_REL_NEAR_F64(cephes::i1e(-10.0), );

    // // x <= 8.0
    // EXPECT_REL_NEAR_F64(cephes::i1e(1.0), );
    // EXPECT_REL_NEAR_F64(cephes::i1e(8.0), );

    // // x > 8.0
    // EXPECT_REL_NEAR_F64(cephes::i1e(9.0),  );
    // EXPECT_REL_NEAR_F64(cephes::i1e(10.0), );
    // EXPECT_REL_NEAR_F64(cephes::i1e(100.0), );
}
