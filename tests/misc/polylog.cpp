#include <cephes/misc.h>
#include <xtest.hpp>

/*

*/
TEST(PloyLog, Branches) {
    // x > 1.0 || n < -1
    EXPECT_REL_NEAR_F64(cephes::polylog(1, 2.0), 0.0);
    EXPECT_REL_NEAR_F64(cephes::polylog(-2, 0.0), 0.0);
}
