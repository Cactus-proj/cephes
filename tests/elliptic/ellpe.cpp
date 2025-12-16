#include <cephes/elliptic.h>
#include <xtest.hpp>

TEST(EllipticE, Branches) {
    // x == 0.0
    EXPECT_REL_NEAR_F64(cephes::ellpe(0.0), 1.0);
}

TEST(EllipticE, SpecialValues) {
    // m1 = 1.0 -> m = 0 -> E(0) = PI/2
    EXPECT_REL_NEAR_F64(cephes::ellpe(1.0), 1.5707963267948966);
}
