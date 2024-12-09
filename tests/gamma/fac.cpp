#include <cephes/gamma.h>
#include <xtest.hpp>

TEST(Fac, BasicAssertions)
{
    EXPECT_REL_NEAR_F64(cephes::fac(0.0), 1.0);
    EXPECT_REL_NEAR_F64(cephes::fac(1.0), 1.0);
    EXPECT_REL_NEAR_F64(cephes::fac(2.0), 2.0);
    EXPECT_REL_NEAR_F64(cephes::fac(3.0), 6.0);
    EXPECT_REL_NEAR_F64(cephes::fac(10.0), 3628800.0);
}
