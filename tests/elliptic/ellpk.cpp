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

TEST(EllipticK, ImplementationBranches) {
    // Code: if (x == 0.0) { mtherr("ellpk", SING); return (MAXNUM); }
    // x == 0.0 (m=1) -> MAXNUM (Singularity)
    EXPECT_GT(cephes::ellpk(0.0), 1e300);

    // Code: if (x > MACHEP) ... else return (C1 - 0.5 * log(x));
    // Small x (m near 1) -> Logarithmic approximation
    double x_small = 1e-20; 
    double expected = 1.3862943611198906188 - 0.5 * std::log(x_small);
    EXPECT_REL_NEAR_F64(cephes::ellpk(x_small), expected);
}
