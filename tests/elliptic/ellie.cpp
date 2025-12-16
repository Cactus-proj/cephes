#include <cephes/elliptic.h>
#include <xtest.hpp>

TEST(EllipticEInc, SpecialValues) {
    // m = 0 -> E(phi, 0) = phi
    EXPECT_REL_NEAR_F64(cephes::ellie(1.0, 0.0), 1.0);
    // m = 1 -> E(phi, 1) = sin(phi)
    EXPECT_REL_NEAR_F64(cephes::ellie(1.5707963267948966, 1.0), 1.0);
    // phi = 0 -> E(0, m) = 0
    EXPECT_REL_NEAR_F64(cephes::ellie(0.0, 0.5), 0.0);
}

TEST(EllipticEInc, ImplementationBranches) {
    // Code: if (m == 0.0) return (phi);
    EXPECT_REL_NEAR_F64(cephes::ellie(0.5, 0.0), 0.5);
    
    // Code: a = 1.0 - m; ... if (a == 0.0) { temp = sin(lphi); goto done; }
    // m == 1.0 (a == 0.0) -> sin(phi)
    EXPECT_REL_NEAR_F64(cephes::ellie(0.5, 1.0), std::sin(0.5));
}
