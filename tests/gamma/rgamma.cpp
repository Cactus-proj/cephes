#include <cephes/gamma.h>
#include <xtest.hpp>

TEST(RGamma, BasicAssertions)
{
    EXPECT_REL_NEAR_F64(cephes::rgamma(0.0), 0.0);
    EXPECT_REL_NEAR_F64(cephes::rgamma(1.0), 1.0);
    EXPECT_REL_NEAR_F64(cephes::rgamma(2.0), 1.0);
}
TEST(RGamma, Branches)
{
}
