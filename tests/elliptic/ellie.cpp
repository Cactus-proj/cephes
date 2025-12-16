#include <cephes/elliptic.h>
#include <xtest.hpp>

TEST(EllipticEInc, Branches) {
    // m == 0.0
    EXPECT_REL_NEAR_F64(cephes::ellie(3.0, 0.0), 3.0);
}

TEST(EllipticEInc, SpecialValues) {
    // m = 0 -> E(phi, 0) = phi
    EXPECT_REL_NEAR_F64(cephes::ellie(1.0, 0.0), 1.0);
    // m = 1 -> E(phi, 1) = sin(phi)
    EXPECT_REL_NEAR_F64(cephes::ellie(1.5707963267948966, 1.0), 1.0);
    // phi = 0 -> E(0, m) = 0
    EXPECT_REL_NEAR_F64(cephes::ellie(0.0, 0.5), 0.0);
}
