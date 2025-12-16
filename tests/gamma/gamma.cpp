#include <xtest.hpp>
#include <cephes/gamma.h>


TEST(Gamma, BasicAssertions) {
    EXPECT_TRUE(std::isnan(cephes::gamma(xtest::NaN64)));
    EXPECT_TRUE(std::isnan(cephes::gamma(0.0)));

    EXPECT_REL_NEAR_F64(cephes::gamma(1.0), 1.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(2.0), 1.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(3.0), 2.0);
    EXPECT_REL_NEAR_F64(cephes::gamma(10.0), 362880.0);
}
