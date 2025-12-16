#include <cephes/elliptic.h>
#include <xtest.hpp>

TEST(EllipticKInc, Branches) {
    // m == 0.0
    EXPECT_REL_NEAR_F64(cephes::ellik(3.0, 0.0), 3.0);
}

TEST(EllipticKInc, SpecialValues) {
    // m = 0 -> F(phi, 0) = phi
    EXPECT_REL_NEAR_F64(cephes::ellik(1.0, 0.0), 1.0);
    // phi = 0 -> F(0, m) = 0
    EXPECT_REL_NEAR_F64(cephes::ellik(0.0, 0.5), 0.0);
}
