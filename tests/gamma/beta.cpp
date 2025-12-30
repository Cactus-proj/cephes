#include <cephes/gamma.h>
#include <xtest.hpp>

TEST(Beta, SpecialValues) {
    // EXPECT_TRUE(std::isnan(cephes::beta(0.0, xtest::NaN64)));  // 0.0
    // EXPECT_TRUE(std::isnan(cephes::beta(xtest::NaN64, 0.0)));  // 0.0
    EXPECT_GE(cephes::beta(0.0, 1.0), 1e300); 
    EXPECT_GE(cephes::beta(1.0, 0.0), 1e300);
}

TEST(Beta, Branches) {
    EXPECT_GT(cephes::beta(0.0, 0.0), 1.0e308); // +Inf
}
