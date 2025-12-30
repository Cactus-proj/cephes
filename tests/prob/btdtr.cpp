#include <cephes/prob.h>
#include <xtest.hpp>

TEST(btdtr, Branches) {
    // a=1, b=1 is Uniform(0,1). CDF(0.5) = 0.5
    EXPECT_NEAR(cephes::btdtr(1.0, 1.0, 0.5), 0.5, 1e-15);
}
