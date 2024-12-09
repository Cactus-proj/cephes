#include <xtest.hpp>
#include <cephes/misc.h>

/*

*/
TEST(Zeta, Branches) {
    // x == 1.0
    EXPECT_GT(cephes::zeta(1.0, 1.0), 1e308);
}
