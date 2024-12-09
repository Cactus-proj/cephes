#include <cephes/elliptic.h>
#include <xtest.hpp>

TEST(EllipticK, Branches)
{
    // (x < 0.0) || (x > 1.0)
    EXPECT_REL_NEAR_F64(cephes::ellpk(-1.0), 0.0);
    EXPECT_REL_NEAR_F64(cephes::ellpk(2.0), 0.0);
}
