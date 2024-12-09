#include <xtest.hpp>
#include <cephes/elliptic.h>


TEST(EllipticE, Branches) {
    // x == 0.0
    EXPECT_REL_NEAR_F64(cephes::ellpe(0.0), 1.0);
}
