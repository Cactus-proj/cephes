#include <cephes/misc.h>
#include <xtest.hpp>

/*

*/
TEST(Spence, Branches)
{
    // x < 0
    EXPECT_REL_NEAR_F64(cephes::spence(-1.0), 0.0);
    // x == 1.0
    EXPECT_REL_NEAR_F64(cephes::spence(1.0), 0.0);
    // x == 0.0
    // EXPECT_REL_NEAR_F64(cephes::spence(0.0), pi*pi/6.0);
}
