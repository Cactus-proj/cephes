#include <cephes/gamma.h>
#include <xtest.hpp>

TEST(LnBeta, SpecialValues) {
    // EXPECT_TRUE(std::isnan(cephes::lbeta(0.0, xtest::NaN64)));  // 0.0
    // EXPECT_TRUE(std::isnan(cephes::lbeta(xtest::NaN64, 0.0)));  // 0.0
    EXPECT_GE(cephes::lbeta(0.0, 1.0), 1e300); 
    EXPECT_GE(cephes::lbeta(1.0, 0.0), 1e300);
}

TEST(LnBeta, Branches) {
    EXPECT_GT(cephes::lbeta(0.0, 0.0), 1.0e308); // +Inf
}
