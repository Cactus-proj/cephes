#include <cephes/elliptic.h>
#include <xtest.hpp>

TEST(EllipticEInc, Branches) {
    // m == 0.0
    EXPECT_REL_NEAR_F64(cephes::ellie(3.0, 0.0), 3.0);
}
