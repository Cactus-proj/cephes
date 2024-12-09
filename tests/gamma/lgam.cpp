#include <cephes/gamma.h>
#include <xtest.hpp>

TEST(LnGamma, BasicAssertions)
{
    EXPECT_TRUE(std::isnan(cephes::lgam(xtest::NaN64)));
    EXPECT_TRUE(std::isinf(cephes::lgam(xtest::Inf64)));
    EXPECT_TRUE(std::isinf(cephes::lgam(0.0)));

    EXPECT_REL_NEAR_F64(cephes::lgam(1.0), 0.0);
}
