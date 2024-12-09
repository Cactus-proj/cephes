#include <cephes/misc.h>
#include <xtest.hpp>

/*

*/
TEST(Ei, Branches)
{
    // x <= 0.0
    EXPECT_REL_NEAR_F64(cephes::ei(0.0), 0.0);
}
