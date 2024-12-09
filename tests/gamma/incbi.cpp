#include <xtest.hpp>
#include <cephes/gamma.h>


TEST(BetaIncInv, BasicAssertions) {
    
}
TEST(BetaIncInv, Branches) {
    // yy0 <= 0
    EXPECT_REL_NEAR_F64(cephes::incbi(1.0, 1.0, -1.0), 0.0);
}
