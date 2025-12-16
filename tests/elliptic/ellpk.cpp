#include <cephes/elliptic.h>
#include <xtest.hpp>

TEST(EllipticK, Branches) {
    // (x < 0.0) || (x > 1.0)
    EXPECT_REL_NEAR_F64(cephes::ellpk(-1.0), 0.0);
    EXPECT_REL_NEAR_F64(cephes::ellpk(2.0), 0.0);
}

TEST(EllipticK, SpecialValues) {
    // m1 = 1.0 -> m = 0 -> K(0) = PI/2
    EXPECT_REL_NEAR_F64(cephes::ellpk(1.0), 1.5707963267948966);
}
