#include <cephes/gamma.h>
#include <xtest.hpp>

TEST(GammaInc, BasicAssertions) {}
TEST(GammaInc, Branches) {
    // x == 0
    EXPECT_REL_NEAR_F64(cephes::igam(1.0, 0.0), 0.0);
    // x < 0
    EXPECT_TRUE(std::isnan(cephes::igam(1.0, -1.0)));
    // a <= 0
    EXPECT_TRUE(std::isnan(cephes::igam(0.0, 1.0)));
    EXPECT_TRUE(std::isnan(cephes::igam(-1.0, 1.0)));
}
