#include <xtest.hpp>
#include <cephes/gamma.h>


TEST(GammaInccInv, BasicAssertions) {
    EXPECT_REL_NEAR_F64(cephes::igami(0.5, 1.0), 0.0);
}
TEST(GammaInccInv, Branches) {
}
