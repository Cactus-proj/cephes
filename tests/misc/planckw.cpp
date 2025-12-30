#include <cephes/misc.h>
#include <xtest.hpp>
#include <cmath>

TEST(PlanckW, SpecialValues) {
    EXPECT_TRUE(std::isnan(cephes::planckw(xtest::NaN64)));
    EXPECT_TRUE(std::isnan(cephes::planckw(-xtest::NaN64)));

    EXPECT_EQ(cephes::planckw(xtest::Inf64), 0.0);
    EXPECT_EQ(cephes::planckw(-xtest::Inf64), -0.0);

    // Wien's constant approx 2.898e-3 m K
    // w should be approx 2.898e-6 m
    EXPECT_NEAR(cephes::planckw(1e3), 2.898e-6, 1e-8);
}
