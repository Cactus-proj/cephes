#include <cephes/gamma.h>
#include <xtest.hpp>

TEST(GammaIncc, BasicAssertions) {}
TEST(GammaIncc, Branches) {
    // x < 0
    EXPECT_TRUE(std::isnan(cephes::igamc(1.0, -1.0)));
    // a <= 0
    EXPECT_TRUE(std::isnan(cephes::igamc(0.0, 1.0)));
    EXPECT_TRUE(std::isnan(cephes::igamc(-1.0, 1.0)));
}
