#include <xtest.hpp>
#include <cephes/elliptic.h>


TEST(EllipticEInc, Branches) {
    // m == 0.0
    EXPECT_REL_NEAR_F64(cephes::ellie(3.0, 0.0), 3.0);
}
