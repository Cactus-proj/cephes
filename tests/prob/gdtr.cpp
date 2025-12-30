#include <cephes/prob.h>
#include <xtest.hpp>
#include <cmath>

TEST(gdtr, Branches) {
    // a=1, b=1 -> Exp(1). CDF(1) = 1 - 1/e
    EXPECT_NEAR(cephes::gdtr(1.0, 1.0, 1.0), 1.0 - std::exp(-1.0), 1e-15);
}
