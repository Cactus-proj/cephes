#include <xtest.hpp>
#include <cephes/misc.h>

/*

*/
TEST(Ei, Branches) {
    // x <= 0.0
    EXPECT_REL_NEAR_F64(cephes::ei(0.0), 0.0);
}
