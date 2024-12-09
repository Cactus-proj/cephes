#include <cephes/elliptic.h>
#include <xtest.hpp>

TEST(EllipticE, Branches)
{
    // x == 0.0
    EXPECT_REL_NEAR_F64(cephes::ellpe(0.0), 1.0);
}
