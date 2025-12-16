#include <xtest.hpp>
#include <cephes/misc.h>

/*

*/
TEST(ZetaC, Branches) {
    // x < -170.6243
    EXPECT_REL_NEAR_F64(cephes::zetac(-175.0), 0.0);
}
