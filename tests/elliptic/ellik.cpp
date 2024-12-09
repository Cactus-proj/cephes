#include <xtest.hpp>
#include <cephes/elliptic.h>


TEST(EllipticKInc, Branches) {
    // m == 0.0
    EXPECT_REL_NEAR_F64(cephes::ellik(3.0, 0.0), 3.0);
}
