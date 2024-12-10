#include <cephes/gamma.h>
#include <xtest.hpp>

TEST(BetaInc, BasicAssertions)
{
}
TEST(BetaInc, Branches)
{
    // aa <= 0.0 || bb <= 0.0
    EXPECT_REL_NEAR_F64(cephes::incbet(0.0, 1.0, 1.0), 0.0);
    EXPECT_REL_NEAR_F64(cephes::incbet(1.0, 0.0, 1.0), 0.0);
}
